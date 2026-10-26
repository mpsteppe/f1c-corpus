// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005921F3
// Canonical corpus name: sub_5921F3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5921F3_005921f3.c

void UnknownObject::InitTimezoneGlobals()
{
    // CRT-style timezone initializer. Resets timezone globals under a critical section, then either reads the TZ environment string (via sub_596D81) and parses its GMT-offset hh:mm:ss and DST designator, or falls back to the Windows GetTimeZoneInformation API. Both paths populate dword_5E7758 (bias in seconds/minutes), dword_5E775C (DST active flag), dword_5E7760 (DST offset), and the two multi-byte timezone name buffers lpMultiByteStr / off_5E77E8.
    // ASSIGNMENT: Initialize local parse flag v7 = 0 (no negative sign seen yet). [source:raw]
    // CALL: Enter critical section 12 via CriticalSectionLazyInitEnter. [source:raw, callee:0x0058DFEA]
    // ASSIGNMENT: Reset timezone globals: dword_5E7800 = -1, dword_5E77F0 = -1, dword_8D3FC0 = 0. [source:raw, global:0x005E7800, global:0x005E77F0, global:0x008D3FC0]
    // CALL: Look up the TZ environment string via sub_596D81("TZ"), reading the string literal aTz. [source:raw, callee:0x00596D81, global:0x005B9620]
    // GUARD: Branch on whether the TZ environment lookup returned a null pointer; null selects the Windows API path. [source:raw]
    // CALL: Leave critical section 12 before using the Windows timezone API. [source:raw, callee:0x0058E04B]
    // GUARD: Call GetTimeZoneInformation(&TimeZoneInformation); if it returns -1, return early. [source:raw, global:0x0059E1E8, global:0x008D3FC8]
    // ASSIGNMENT: Set dword_5E7758 = 60 * TimeZoneInformation.Bias and mark init flag dword_8D3FC0 = 1. [source:raw, global:0x005E7758, global:0x008D3FC0, global:0x008D3FC8]
    // CALCULATION: If StandardDate.wMonth is nonzero, add the standard bias: dword_5E7758 = 60 * StandardBias + 60 * Bias. [source:raw, global:0x005E7758, global:0x008D3FC8]
    // ASSIGNMENT: If DaylightDate.wMonth and DaylightBias are both nonzero set dword_5E775C = 1 and dword_5E7760 = 60 * (DaylightBias - StandardBias); otherwise clear both to 0. [source:raw, global:0x005E775C, global:0x005E7760, global:0x008D3FC8]
    // CALL: Convert StandardName (wide-char buffer starting at byte_8D3FCC) to multi-byte into lpMultiByteStr via WideCharToMultiByte with CodePage; if it fails or UsedDefaultChar is set, null out the buffer, else terminate at index 63. [source:raw, global:0x0059E228, global:0x008D3F48, global:0x008D3FCC, global:0x005E77E4]
    // CALL: Convert DaylightName (wide-char buffer starting at byte_8D4020) into off_5E77E8 via WideCharToMultiByte; on success and no UsedDefaultChar terminate at index 63 and return, otherwise clear the buffer (LABEL_41) and return. [source:raw, global:0x0059E228, global:0x008D3F48, global:0x008D4020, global:0x005E77E8]
    // GUARD: TZ string path: if first byte of the TZ string is nonzero and (no cached dword_8D4074, or sub_58FB90(v0, dword_8D4074) matches), proceed to cache it. [source:raw, global:0x008D4074, callee:0x0058FB90]
    // CALL: Release the previously cached TZ string via sub_58AA6F(dword_8D4074). [source:raw, callee:0x0058AA6F, global:0x008D4074]
    // CALL: Measure the TZ string with Strlen(v1) and allocate a copy of length + 1 via MallocWrapperForNhMalloc; store the new pointer in dword_8D4074. [source:raw, callee:0x0058E1B0, callee:0x0058A935, global:0x008D4074]
    // GUARD: If the allocation succeeded, parse the TZ string; otherwise fall through to the final CritSectLeave. [source:raw]
    // CALL: Call helper sub_58FCA0(), then leave critical section 12 before parsing. [source:raw, callee:0x0058FCA0, callee:0x0058E04B]
    // CALL: Copy the first 3 TZ characters into the timezone name buffer via sub_587DD0(lpMultiByteStr, v1, 3u). [source:raw, callee:0x00587DD0, global:0x005E77E4]
    // ASSIGNMENT: Null-terminate lpMultiByteStr[3] = 0 and advance the parse pointer past the 3-char name. [source:raw, global:0x005E77E4]
    // GUARD: If the next character is '-' (ASCII 45), set negative flag v7 = 1 and advance. [source:raw]
    // CALCULATION: Parse the hours field: v4 = 3600 * sub_587ECE(v3) and store into dword_5E7758. [source:raw, callee:0x00587ECE, global:0x005E7758]
    // LOOP: Skip an optional '+' and any run of digit characters. [source:raw]
    // CALCULATION: If a ':' separator follows, add 60 * sub_587ECE(minutes) to dword_5E7758, skip digits, and if a second ':' follows add sub_587ECE(seconds). [source:raw, callee:0x00587ECE, global:0x005E7758]
    // CALCULATION: If the negative flag v7 was set, negate the parsed offset: dword_5E7758 = -v4. [source:raw, global:0x005E7758]
    // ASSIGNMENT: Store the DST designator character in dword_5E775C. [source:raw, global:0x005E775C]
    // CALL: If the DST character is nonzero, copy the 3-char DST name into off_5E77E8 via sub_587DD0(off_5E77E8, v3, 3u) and return. [source:raw, callee:0x00587DD0, global:0x005E77E8]
    // ASSIGNMENT: Otherwise clear off_5E77E8 (LABEL_41) and return. [source:raw, global:0x005E77E8]
    // RETURN: Exit path leaves critical section 12 via CritSectLeave when no early return was taken. [source:raw, callee:0x0058E04B]

    // Conservative worker pseudocode:
    //   void InitTimezoneGlobals(void) {
    //     CriticalSectionLazyInitEnter(12);
    //     dword_5E7800 = -1; dword_5E77F0 = -1; dword_8D3FC0 = 0;
    //     char *tz = sub_596D81("TZ");
    //     if (!tz) {
    //       CritSectLeave(12);
    //       if (GetTimeZoneInformation(&TimeZoneInformation) == -1) return;
    //       dword_5E7758 = 60 * TimeZoneInformation.Bias; dword_8D3FC0 = 1;
    //       if (TimeZoneInformation.StandardDate.wMonth)
    //         dword_5E7758 = 60 * (TimeZoneInformation.StandardBias + TimeZoneInformation.Bias);
    //       if (TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias) {
    //         dword_5E775C = 1;
    //         dword_5E7760 = 60 * (TimeZoneInformation.DaylightBias - TimeZoneInformation.StandardBias);
    //       } else { dword_5E775C = 0; dword_5E7760 = 0; }
    //       if (!WideCharToMultiByte(CodePage, 0x220, TimeZoneInformation.StandardName, -1,
    //                                 lpMultiByteStr, 63, 0, &UsedDefaultChar) || UsedDefaultChar)
    //         *lpMultiByteStr = 0; else lpMultiByteStr[63] = 0;
    //       if (WideCharToMultiByte(CodePage, 0x220, TimeZoneInformation.DaylightName, -1,
    //                                 off_5E77E8, 63, 0, &UsedDefaultChar) && !UsedDefaultChar)
    //         { off_5E77E8[63] = 0; return; }
    //       *off_5E77E8 = 0; return;
    //     }
    //     if (*tz && (!dword_8D4074 || sub_58FB90(tz, dword_8D4074))) {
    //       sub_58AA6F(dword_8D4074);
    //       dword_8D4074 = MallocWrapperForNhMalloc(Strlen(tz) + 1);
    //       if (dword_8D4074) {
    //         sub_58FCA0(); CritSectLeave(12);
    //         sub_587DD0(lpMultiByteStr, tz, 3u);
    //         char *p = tz + 3; lpMultiByteStr[3] = 0;
    //         int neg = 0; if (*p == '-') { neg = 1; ++p; }
    //         int secs = 3600 * sub_587ECE(p); dword_5E7758 = secs;
    //         while (*p == '+' || (*p >= '0' && *p <= '9')) ++p;
    //         if (*p == ':') {
    //           secs = 60 * sub_587ECE(++p) + dword_5E7758; dword_5E7758 = secs;
    //           while (*p >= '0' && *p <= '9') ++p;
    //           if (*p == ':') {
    //             secs = sub_587ECE(++p) + dword_5E7758; dword_5E7758 = secs;
    //             while (*p >= '0' && *p <= '9') ++p;
    //           }
    //         }
    //         if (neg) dword_5E7758 = -secs;
    //         char dst = *p; dword_5E775C = dst;
    //         if (dst) { sub_587DD0(off_5E77E8, p, 3u); off_5E77E8[3] = 0; return; }
    //         *off_5E77E8 = 0; return;
    //       }
    //     }
    //     CritSectLeave(12);
    //   }
    // UNRESOLVED: Eight byte_FF0000000000545x/54xx evidence refs are decompiler artifacts of byte reads through the TZ string pointers (v0/v3); the exact provenance of each byte address is not resolvable from the raw source text.
    // UNRESOLVED: byte_8D400E, byte_8D401C, byte_8D4062 and byte_8D4070 are per-byte views of the TimeZoneInformation struct region (standard-date, bias and daylight fields); their precise member assignment is not visible in the decompiled C.
    // UNRESOLVED: Semantics of the sub_587ECE numeric parser and the sub_58FCA0 / sub_587DD0 helper contracts are defined by the callees, not here.
}
