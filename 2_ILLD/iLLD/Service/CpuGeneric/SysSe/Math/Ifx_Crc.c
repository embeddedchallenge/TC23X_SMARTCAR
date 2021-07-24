/**
 * \file Ifx_Crc.c
 * \brief CRC algorithm
 *
 * \version disabled
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */
#include "Ifx_Crc.h"

uint32 Ifx_Crc_reflect(uint32 crc, sint32 bitnum);

boolean Ifx_Crc_init(Ifc_Crc *driver, const Ifc_Crc_Table *table, sint32 direct, sint32 refout, uint32 crcinit, uint32 crcxor)
{
    sint32 i;
    uint32 bit, crc;

    if (crcinit != (crcinit & table->crcmask))
    {
        //IfxStdIf_DPipe_print(io,"ERROR, invalid crcinit."ENDL);
        return FALSE;
    }

    if (crcxor != (crcxor & table->crcmask))
    {
        //IfxStdIf_DPipe_print(io,"ERROR, invalid crcxor."ENDL);
        return FALSE;
    }

    driver->table  = table;
    driver->crcxor = crcxor;
    driver->refout = refout;

    // compute missing initial CRC value

    if (!direct)
    {
        driver->crcinit_nondirect = crcinit;
        crc                       = crcinit;

        for (i = 0; i < table->order; i++)
        {
            bit   = crc & table->crchighbit;
            crc <<= 1;

            if (bit)
            {
                crc ^= table->polynom;
            }
        }

        crc                   &= table->crcmask;
        driver->crcinit_direct = crc;
    }

    else
    {
        driver->crcinit_direct = crcinit;
        crc                    = crcinit;

        for (i = 0; i < table->order; i++)
        {
            bit = crc & 1;

            if (bit)
            {
                crc ^= table->polynom;
            }

            crc >>= 1;

            if (bit)
            {
                crc |= table->crchighbit;
            }
        }

        driver->crcinit_nondirect = crc;
    }

    return TRUE;
}


boolean Ifx_Crc_createTable(Ifc_Crc_Table *table, sint32 order, uint32 polynom, sint32 refin)
{
    uint32 crcmask;
    // at first, compute constant bit masks for whole CRC and CRC high bit

    crcmask = ((((uint32)1 << (order - 1)) - 1) << 1) | 1;

    // check parameters

    if ((order < 1) || (order > 32))
    {
        //IfxStdIf_DPipe_print(io,"ERROR, invalid order, it must be between 1..32."ENDL);
        return FALSE;
    }

    if (polynom != (polynom & crcmask))
    {
        //IfxStdIf_DPipe_print(io,"ERROR, invalid polynom."ENDL);
        return FALSE;
    }

    table->order      = order;
    table->polynom    = polynom;
    table->refin      = refin;
    table->crchighbit = (uint32)1 << (order - 1);
    table->crcmask    = crcmask;
    // generate lookup table
    // make CRC lookup table used by table algorithms
    {
        sint32 i, j;
        uint32 bit, crc;

        for (i = 0; i < 256; i++)
        {
            crc = (uint32)i;

            if (refin)
            {
                crc = Ifx_Crc_reflect(crc, 8);
            }

            crc <<= order - 8;

            for (j = 0; j < 8; j++)
            {
                bit   = crc & table->crchighbit;
                crc <<= 1;

                if (bit)
                {
                    crc ^= polynom;
                }
            }

            if (refin)
            {
                crc = Ifx_Crc_reflect(crc, order);
            }

            crc &= crcmask;

            if (order <= 8)
            {
                uint8 *crctab = (uint8 *)((uint32)table + sizeof(Ifc_Crc_Table));
                crctab[i] = (uint8)crc;
            }
            else if (order <= 16)
            {
                uint16 *crctab = (uint16 *)((uint32)table + sizeof(Ifc_Crc_Table));
                crctab[i] = (uint16)crc;
            }
            else
            {
                uint32 *crctab = (uint32 *)((uint32)table + sizeof(Ifc_Crc_Table));
                crctab[i] = crc;
            }
        }
    }
    return TRUE;
}


// subroutines

uint32 Ifx_Crc_reflect(uint32 crc, sint32 bitnum)
{
    // reflects the lower 'bitnum' bits of 'crc'

    uint32 i, j = 1, crcout = 0;

    for (i = (uint32)1 << (bitnum - 1); i; i >>= 1)
    {
        if (crc & i)
        {
            crcout |= j;
        }

        j <<= 1;
    }

    return crcout;
}


uint32 Ifx_Crc_tableFast(Ifc_Crc *driver, uint8 *p, uint32 len)
{
    // fast lookup table algorithm without augmented zero bytes, e.g. used in pkzip.
    // only usable with polynom orders of 8, 16, 24 or 32.

    uint32 crc              = driver->crcinit_direct;
    sint32 orderMinusHeight = driver->table->order - 8;

    if (driver->table->refin)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    if (driver->table->order <= 8)
    {
        uint8 *crctab = (uint8 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = (crc << 8) ^ crctab[((crc >> (orderMinusHeight)) & 0xff) ^ *p++];
            }
        }
        else
        {
            while (len--)
            {
                crc = (crc >> 8) ^ crctab[(crc & 0xff) ^ *p++];
            }
        }
    }
    else if (driver->table->order <= 16)
    {
        uint16 *crctab = (uint16 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = (crc << 8) ^ crctab[((crc >> (orderMinusHeight)) & 0xff) ^ *p++];
            }
        }
        else
        {
            while (len--)
            {
                crc = (crc >> 8) ^ crctab[(crc & 0xff) ^ *p++];
            }
        }
    }
    else
    {
        uint32 *crctab = (uint32 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = (crc << 8) ^ crctab[((crc >> (orderMinusHeight)) & 0xff) ^ *p++];
            }
        }
        else
        {
            while (len--)
            {
                crc = (crc >> 8) ^ crctab[(crc & 0xff) ^ *p++];
            }
        }
    }

    if (driver->refout ^ driver->table->refin)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    crc ^= driver->crcxor;
    crc &= driver->table->crcmask;

    return crc;
}


uint32 Ifx_Crc_table(Ifc_Crc *driver, uint8 *p, uint32 len)
{
    // normal lookup table algorithm with augmented zero bytes.
    // only usable with polynom orders of 8, 16, 24 or 32.

    uint32 crc              = driver->crcinit_nondirect;
    sint32 orderMinusHeight = driver->table->order - 8;

    if (driver->table->refin)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    if (driver->table->order <= 8)
    {
        uint8 *crctab = (uint8 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = ((crc << 8) | *p++) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (len--)
            {
                crc = ((crc >> 8) | (*p++ << (orderMinusHeight))) ^ crctab[crc & 0xff];
            }
        }

        if (!driver->table->refin)
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc << 8) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc >> 8) ^ crctab[crc & 0xff];
            }
        }
    }
    else if (driver->table->order <= 16)
    {
        uint16 *crctab = (uint16 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = ((crc << 8) | *p++) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (len--)
            {
                crc = ((crc >> 8) | (*p++ << (orderMinusHeight))) ^ crctab[crc & 0xff];
            }
        }

        if (!driver->table->refin)
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc << 8) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc >> 8) ^ crctab[crc & 0xff];
            }
        }
    }
    else if (driver->table->order <= 32)
    {
        uint32 *crctab = (uint32 *)((uint32)driver->table + sizeof(Ifc_Crc_Table));

        if (!driver->table->refin)
        {
            while (len--)
            {
                crc = ((crc << 8) | *p++) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (len--)
            {
                crc = ((crc >> 8) | (*p++ << (orderMinusHeight))) ^ crctab[crc & 0xff];
            }
        }

        if (!driver->table->refin)
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc << 8) ^ crctab[(crc >> (orderMinusHeight)) & 0xff];
            }
        }
        else
        {
            while (++len < (driver->table->order >> 3))
            {
                crc = (crc >> 8) ^ crctab[crc & 0xff];
            }
        }
    }

    if (driver->refout ^ driver->table->refin)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    crc ^= driver->crcxor;
    crc &= driver->table->crcmask;

    return crc;
}


uint32 Ifx_Crc_bitByBit(Ifc_Crc *driver, uint8 *p, uint32 len)
{
    // bit by bit algorithm with augmented zero bytes.
    // does not use lookup table, suited for polynom driver->table->orders between 1...32.

    uint32 i, j, c, bit;
    uint32 crc = driver->crcinit_nondirect;

    for (i = 0; i < len; i++)
    {
        c = (uint32)*p++;

        if (driver->table->refin)
        {
            c = Ifx_Crc_reflect(c, 8);
        }

        for (j = 0x80; j; j >>= 1)
        {
            bit   = crc & driver->table->crchighbit;
            crc <<= 1;

            if (c & j)
            {
                crc |= 1;
            }

            if (bit)
            {
                crc ^= driver->table->polynom;
            }
        }
    }

    for (i = 0; i < driver->table->order; i++)
    {
        bit   = crc & driver->table->crchighbit;
        crc <<= 1;

        if (bit)
        {
            crc ^= driver->table->polynom;
        }
    }

    if (driver->refout)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    crc ^= driver->crcxor;
    crc &= driver->table->crcmask;

    return crc;
}


uint32 Ifx_Crc_bitByBitFast(Ifc_Crc *driver, uint8 *p, uint32 len)
{
    // fast bit by bit algorithm without augmented zero bytes.
    // does not use lookup table, suited for polynom driver->table->orders between 1...32.

    uint32 i, j, c, bit;
    uint32 crc = driver->crcinit_direct;

    for (i = 0; i < len; i++)
    {
        c = (uint32)*p++;

        if (driver->table->refin)
        {
            c = Ifx_Crc_reflect(c, 8);
        }

        for (j = 0x80; j; j >>= 1)
        {
            bit   = crc & driver->table->crchighbit;
            crc <<= 1;

            if (c & j)
            {
                bit ^= driver->table->crchighbit;
            }

            if (bit)
            {
                crc ^= driver->table->polynom;
            }
        }
    }

    if (driver->refout)
    {
        crc = Ifx_Crc_reflect(crc, driver->table->order);
    }

    crc ^= driver->crcxor;
    crc &= driver->table->crcmask;

    return crc;
}


#if CRC_ENABLE_DPIPE
void Ifx_Crc_printTable(Ifc_Crc_Table *table, IfxStdIf_DPipe *io)
{
    sint32 i = 0;

    uint32 typeSize;

    if (table->order <= 8)
    {
        typeSize = 8;
    }
    else if (table->order <= 16)
    {
        typeSize = 16;
    }
    else
    {
        typeSize = 32;
    }

    IfxStdIf_DPipe_print(io, ENDL "Ifc_Crc_Table%d <tabe name> = {"ENDL, typeSize);
    IfxStdIf_DPipe_print(io, "    .data.order=%d,"ENDL, table->order);
    IfxStdIf_DPipe_print(io, "    .data.polynom=0x%X,"ENDL, table->polynom);
    IfxStdIf_DPipe_print(io, "    .data.refin=%d,"ENDL, table->refin);
    IfxStdIf_DPipe_print(io, "    .data.crchighbit=%d,"ENDL, table->crchighbit);
    IfxStdIf_DPipe_print(io, "    .data.crcmask=0x%X,"ENDL, table->crcmask);
    IfxStdIf_DPipe_print(io, "    .crctab={"ENDL);
    IfxStdIf_DPipe_print(io, "        ");

    while (i < 256)
    {
        if (table->order <= 4)
        {
            uint8 *crctab = (uint8 *)((uint32)table + sizeof(Ifc_Crc_Table));
            IfxStdIf_DPipe_print(io, "0x%01X, ", crctab[i]);
        }
        else if (table->order <= 8)
        {
            uint8 *crctab = (uint8 *)((uint32)table + sizeof(Ifc_Crc_Table));
            IfxStdIf_DPipe_print(io, "0x%02X, ", crctab[i]);
        }
        else if (table->order <= 16)
        {
            uint16 *crctab = (uint16 *)((uint32)table + sizeof(Ifc_Crc_Table));
            IfxStdIf_DPipe_print(io, "0x%04X, ", crctab[i]);
        }
        else if (table->order <= 24)
        {
            uint32 *crctab = (uint32 *)((uint32)table + sizeof(Ifc_Crc_Table));
            IfxStdIf_DPipe_print(io, "0x%06X, ", crctab[i]);
        }
        else
        {
            uint32 *crctab = (uint32 *)((uint32)table + sizeof(Ifc_Crc_Table));
            IfxStdIf_DPipe_print(io, "0x%08X, ", crctab[i]);
        }

        i++;

        if ((i % 16) == 0)
        {
            IfxStdIf_DPipe_print(io, ENDL "        ");
        }
    }

    IfxStdIf_DPipe_print(io, "    }"ENDL);
    IfxStdIf_DPipe_print(io, "};"ENDL);
}


boolean Ifx_Crc_Test(Ifc_Crc *driver, uint8 *string, uint32 length, IfxStdIf_DPipe *io)
{
    IfxStdIf_DPipe_print(io, ""ENDL);
    IfxStdIf_DPipe_print(io, "CRC tester v1.1 written on 13/01/2003 by Sven Reifegerste (zorc/reflex)"ENDL);
    IfxStdIf_DPipe_print(io, "-----------------------------------------------------------------------"ENDL);
    IfxStdIf_DPipe_print(io, ""ENDL);
    IfxStdIf_DPipe_print(io, "Parameters:"ENDL);
    IfxStdIf_DPipe_print(io, ""ENDL);
    IfxStdIf_DPipe_print(io, " polynom             :  0x%x"ENDL, driver->table->polynom);
    IfxStdIf_DPipe_print(io, " order               :  %d"ENDL, driver->table->order);
    IfxStdIf_DPipe_print(io, " crcinit             :  0x%x direct, 0x%x nondirect"ENDL, driver->crcinit_direct, driver->crcinit_nondirect);
    IfxStdIf_DPipe_print(io, " crcxor              :  0x%x"ENDL, driver->crcxor);
    IfxStdIf_DPipe_print(io, " refin               :  %d"ENDL, driver->table->refin);
    IfxStdIf_DPipe_print(io, " refout              :  %d"ENDL, driver->refout);
    IfxStdIf_DPipe_print(io, ""ENDL);
//    IfxStdIf_DPipe_print(io," data string         :  '%s' (%d bytes)"ENDL, string, stringLength);
    IfxStdIf_DPipe_print(io, ""ENDL);
    IfxStdIf_DPipe_print(io, "Results:"ENDL);
    IfxStdIf_DPipe_print(io, ""ENDL);
#if 0
    IfxCpu_Perf perf;
    uint32      result;

    IfxCpu_resetAndStartCounters(IfxCpu_CounterMode_normal);
    result = Ifx_Crc_bitByBit(driver, (uint8 *)string, length);
    perf   = IfxCpu_stopCounters();
    IfxStdIf_DPipe_print(io, " crc bit by bit      :  0x%X, %d cycles"ENDL, result, perf.clock.counter);

    IfxCpu_resetAndStartCounters(IfxCpu_CounterMode_normal);
    result = Ifx_Crc_bitByBitFast(driver, (uint8 *)string, length);
    perf   = IfxCpu_stopCounters();
    IfxStdIf_DPipe_print(io, " crc bit by bit fast :  0x%X, %d cycles"ENDL, result, perf.clock.counter);

    IfxCpu_resetAndStartCounters(IfxCpu_CounterMode_normal);
    result = Ifx_Crc_table(driver, (uint8 *)string, length);
    perf   = IfxCpu_stopCounters();
    IfxStdIf_DPipe_print(io, " crc table           :  0x%X, %d cycles"ENDL, result, perf.clock.counter);

    IfxCpu_resetAndStartCounters(IfxCpu_CounterMode_normal);
    result = Ifx_Crc_tableFast(driver, (uint8 *)string, length);
    perf   = IfxCpu_stopCounters();
    IfxStdIf_DPipe_print(io, " crc table fast      :  0x%X, %d cycles"ENDL, result, perf.clock.counter);

#endif
    return TRUE;
}


#endif