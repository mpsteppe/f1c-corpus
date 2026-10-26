// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438CC0
// Canonical corpus name: BrakeBiasSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BrakeBiasSetup_00438cc0.c

void UnknownObject::BrakeBiasSetup()
{
    // Initializes per-object control configuration from the global settings block: copies eleven configuration bytes from globals dword_7CE6F4..dword_7CE7A8 into object bytes at fields 0x72..0x7C, derives a control-mode selector at field 0x80 from the two globals byte_7CE874 and byte_7CE88C, zeroes any byte whose option bitmask fails BitmaskStateTest, applies two cross-field fix-ups, and stores a scaled double driver factor at field 0x9C. Returns the byte at field 0x75.
    // ASSIGNMENT: Copy eleven configuration bytes from globals dword_7CE6F4, dword_7CE73C, dword_7CE7F0, dword_7CE8A4, dword_7CE850, dword_7CE784, dword_7CE7CC, dword_7CE6AC, dword_7CE718, dword_7CE760 and dword_7CE7A8 into the object bytes at fields 0x72..0x7C. [global:0x007CE6F4, global:0x007CE73C, global:0x007CE7F0, global:0x007CE8A4, global:0x007CE850, global:0x007CE784, global:0x007CE7CC, global:0x007CE6AC, global:0x007CE718, global:0x007CE760, global:0x007CE7A8, field:this:0x00000072, field:this:0x00000073, field:this:0x00000074, field:this:0x00000075, field:this:0x00000076, field:this:0x00000077, field:this:0x00000078, field:this:0x00000079, field:this:0x0000007A, field:this:0x0000007B, field:this:0x0000007C, source:raw]
    // CALCULATION: Derive the control-mode selector at field 0x80 from globals byte_7CE874 and byte_7CE88C: 2 * (byte_7CE88C != 0) + 1 when byte_7CE874 is set, otherwise byte_7CE88C != 0 ? 2 : 0. [field:this:0x00000080, global:0x007CE874, global:0x007CE88C, source:raw]
    // LOOP: For each of the 11 copied bytes (fields 0x72..0x7C), zero it when BitmaskStateTest(i) returns false for that index. [callee:0x004B15D0, field:this:0x00000072, source:raw]
    // GUARD: If either field 0x74 or field 0x7A is non-zero, force field 0x73 to 2. [field:this:0x00000074, field:this:0x0000007A, field:this:0x00000073, source:raw]
    // GUARD: If field 0x75 is non-zero, force field 0x76 to 1. [field:this:0x00000075, field:this:0x00000076, source:raw]
    // ASSIGNMENT: Store the double at field 0x9C as the value of global flt_7CE934 scaled by 0.95. [field:this:0x0000009C, global:0x007CE934, source:raw]
    // RETURN: Return the byte stored at field 0x75. [field:this:0x00000075, source:raw]

    // Conservative worker pseudocode:
    //   char BrakeBiasSetup(int this) {
    //       *(char*)(this+114) = dword_7CE6F4; *(char*)(this+115) = dword_7CE73C;
    //       *(char*)(this+116) = dword_7CE7F0; *(char*)(this+117) = dword_7CE8A4;
    //       *(char*)(this+118) = dword_7CE850; *(char*)(this+119) = dword_7CE784;
    //       *(char*)(this+120) = dword_7CE7CC; *(char*)(this+121) = dword_7CE6AC;
    //       *(char*)(this+122) = dword_7CE718; *(char*)(this+123) = dword_7CE760;
    //       *(char*)(this+124) = dword_7CE7A8;
    //       if (byte_7CE874) *(int*)(this+128) = 2 * (byte_7CE88C != 0) + 1;
    //       else *(int*)(this+128) = byte_7CE88C != 0 ? 2 : 0;
    //       for (int i = 0; i < 11; ++i)
    //           if (!BitmaskStateTest(i)) *(char*)(this+i+114) = 0;
    //       if (*(char*)(this+116) || *(char*)(this+122)) *(char*)(this+115) = 2;
    //       char result = *(char*)(this+117);
    //       if (result) *(char*)(this+118) = 1;
    //       *(double*)(this+156) = flt_7CE934 * 0.95;
    //       return result;
    //   }
    // UNRESOLVED: Read-only globals dbl_59EB98 and byte_7CE498 are listed in the packet but do not appear in the raw source text; their exact role is unplaced.
    // UNRESOLVED: Meaning of the eleven copied bytes and the encoding of the control-mode selector at field 0x80 is inferred from existing analysis naming only; no runtime contract confirms it.
}
