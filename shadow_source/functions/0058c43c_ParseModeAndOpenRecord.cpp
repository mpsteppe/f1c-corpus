// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C43C
// Canonical corpus name: sub_58C43C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C43C_0058c43c.c

void UnknownObject::ParseModeAndOpenRecord()
{
    // Parses a mode/format string a2 (first character 'a'/'r'/'w', then modifier letters) into a flag word and an access word seeded from global dword_8D41BC, then calls sub_595AF9(lpFileName, flags, Buffer, 420) to open/read the resource named by lpFileName. Returns 0 on a malformed string or a negative sub_595AF9 result. On success increments global dword_8D3EC8 and fills the output record a4: a4[0]=0, a4[1]=0, a4[2]=0, a4[3]=access word v7, a4[4]=sub_595AF9 result, a4[7]=0; returns a4.
    // GUARD: Rejects strings whose first character is not 'a' (97), 'r' (114) or 'w' (119): returns 0. [source:raw]
    // ASSIGNMENT: Seeds the flag word v6 (0x109 for 'a', 0 for 'r', 0x301 for 'w') and the access word v7 = dword_8D41BC | 2 (write/append) for 'a'/'w' or dword_8D41BC | 1 (read) for 'r'. [global:0x008D41BC, source:raw]
    // LOOP: Iterates the remaining mode characters and maps each to flag bits in v6/v7: '+' sets the two lowest flag bits and access bit 0x80 (clearing the other low access bits), 'D' sets v6 0x40, 'R' sets v6 0x10, 'S' sets v6 0x20, 'T' sets v6 0x1000, 'b' sets the byte-1 bit 0x80 of v6, 'c' sets the byte-1 bit 0x40 of v6, 'd' sets v7 0x4000, 'e' clears v7 0x4000. Duplicate letters (guarded by v18/v19 and bit tests) or unrecognized characters fail the parse (v8=0) and stop the loop. [source:raw]
    // CALL: Calls sub_595AF9(lpFileName, v6, Buffer, 420); returns 0 if the result is negative. [callee:0x00595AF9, source:raw]
    // ASSIGNMENT: Increments global dword_8D3EC8 on a successful open. [global:0x008D3EC8, source:raw]
    // ASSIGNMENT: Fills the output record a4: a4[0]=0, a4[1]=0, a4[2]=0, a4[3]=v7 (access word), a4[4]=result of sub_595AF9, a4[7]=0; returns a4. [source:raw]
    // RETURN: Returns the filled output record a4 on success, or 0 on parse failure / negative sub_595AF9 result. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2[0] != 'a' && a2[0] != 'r' && a2[0] != 'w') return 0;
    //   flags = (a2[0]=='a') ? 0x109 : (a2[0]=='w') ? 0x301 : 0;
    //   access = dword_8D41BC | ((a2[0]=='r') ? 1 : 2);
    //   for each remaining char c:
    //       map c to flags/access bits, failing on duplicate or invalid char;
    //   h = sub_595AF9(lpFileName, flags, Buffer, 420);
    //   if (h < 0) return 0;
    //   ++dword_8D3EC8;
    //   a4[0]=0; a4[1]=0; a4[2]=0; a4[3]=access; a4[4]=h; a4[7]=0;
    //   return a4;
    // UNRESOLVED: Exact real-world meaning of the parsed flag bits and of sub_595AF9 (which resource/file lpFileName addresses) is not confirmed.
    // UNRESOLVED: Character-to-bit mapping for 'b'/'c' (byte-1 bits of v6) and the role of the marker/size field a4[4] are inferred from the raw code only.
}
