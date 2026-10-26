// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005687F0
// Canonical corpus name: sub_5687F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5687F0_005687f0.c

void UnknownObject::IsReservedDosDeviceName()
{
    // Determines whether the input device-name string (this) is a reserved DOS device name. Builds a 23-entry candidate table (CON via off_5E5230, PRN, AUX via off_5D4D10, CLOCK$, COM1-COM9, LPT1-LPT9, ending at off_5E5190), copies up to 7 characters of the input into a local buffer, truncates it at the first path separator or dot (backslash, slash, colon, dot), then compares it against each candidate. Returns 1 when a candidate matches, 0 when none of the 23 matches.
    // ASSIGNMENT: Initialize the local candidate table v6[0..22] with the reserved DOS device-name strings: off_5E5230, aPrn, off_5D4D10, aClock, aCom1 through aCom9, aLpt1 through aLpt9, then off_5E5190. [global:0x005E5230, global:0x005E522C, global:0x005D4D10, global:0x005E5224, global:0x005E521C, global:0x005E5214, global:0x005E520C, global:0x005E5204, global:0x005E51FC, global:0x005E51F4, global:0x005E51EC, global:0x005E51E4, global:0x005E51DC, global:0x005E51D4, global:0x005E51CC, global:0x005E51C4, global:0x005E51BC, global:0x005E51B4, global:0x005E51AC, global:0x005E51A4, global:0x005E519C, global:0x005E5194, global:0x005E5190]
    // CALL: Copy up to 7 bytes from the input device-name string into the local buffer v5 via sub_587DD0(v5, this, 7). [callee:0x00587DD0]
    // ASSIGNMENT: Force a NUL terminator at local buffer index 7. [source:raw]
    // LOOP: Scan v5 for the first path separator or dot character (backslash 92, slash 47, colon 58, dot 46) and terminate the buffer there; stop early when none is found before index 8. [source:raw]
    // LOOP: Compare the truncated name against each candidate table entry in order via sub_588410(v5, v6[v3]); advance v3 over the 23 entries and stop when a candidate compares equal. [callee:0x00588410]
    // RETURN: Return 1 when a candidate matched (the equality check broke the loop), otherwise return 0 after all 23 candidates were rejected. [source:raw]

    // Conservative worker pseudocode:
    //   char IsReservedDosDeviceName(const char *name) {
    //     const char *candidates[23] = { off_5E5230, aPrn, off_5D4D10, aClock,
    //       aCom1, aCom2, aCom3, aCom4, aCom5, aCom6, aCom7, aCom8, aCom9,
    //       aLpt1, aLpt2, aLpt3, aLpt4, aLpt5, aLpt6, aLpt7, aLpt8, aLpt9, off_5E5190 };
    //     char buf[8];
    //     sub_587DD0(buf, name, 7);
    //     buf[7] = 0;
    //     for (int i = 0; i < 8; ++i) {
    //       char c = buf[i];
    //       if (c == 92 || c == 47 || c == 58 || c == 46) { buf[i] = 0; break; }
    //     }
    //     for (int i = 0; i < 23; ++i)
    //       if (!sub_588410(buf, candidates[i])) return 1;
    //     return 0;
    //   }
}
