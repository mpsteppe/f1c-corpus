// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432BF0
// Canonical corpus name: AutoLoadEntryWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AutoLoadEntryWriter_00432bf0.c

void UnknownObject::WriteAutoLoadEntry()
{
    // Writes a fixed sequence of six format-string literals into a caller-owned write buffer through BufferWriteWithStringLengthCheck, composing an auto-load configuration entry used during config file parsing by ConfigFileParser. Returns 0 after the sequence on success; returns 1 when the buffer pointer a1 or its first DWORD (*a1) is null.
    // GUARD: Return 1 when a1 is null or *a1 (buffer validity flag / buffer pointer) is zero. [field:this:0x00000000, source:raw]
    // CALL: Write format-string aS_7 into the buffer with length check. [callee:0x00566C30, global:0x005C4064, source:raw]
    // CALL: Write format-string asc_5C4060 into the buffer with length check. [callee:0x00566C30, global:0x005C4060, source:raw]
    // CALL: Write format-string aSS_4 into the buffer with length check (first of three occurrences). [callee:0x00566C30, global:0x005C4054, source:raw]
    // CALL: Write format-string aSS_4 into the buffer with length check (second occurrence). [callee:0x00566C30, global:0x005C4054, source:raw]
    // CALL: Write format-string aSD into the buffer with length check. [callee:0x00566C30, global:0x005C4048, source:raw]
    // CALL: Write format-string aSS_4 into the buffer with length check (third occurrence). [callee:0x00566C30, global:0x005C4054, source:raw]
    // CALL: Write format-string asc_5C4044 into the buffer with length check. [callee:0x00566C30, global:0x005C4044, source:raw]
    // RETURN: Return 0 to signal the complete entry was written successfully. [function:0x00432BF0, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1 || !*a1) return 1;
    //   BufferWriteWithStringLengthCheck(a1, aS_7);
    //   BufferWriteWithStringLengthCheck(a1, asc_5C4060);
    //   BufferWriteWithStringLengthCheck(a1, aSS_4);
    //   BufferWriteWithStringLengthCheck(a1, aSS_4);
    //   BufferWriteWithStringLengthCheck(a1, aSD);
    //   BufferWriteWithStringLengthCheck(a1, aSS_4);
    //   BufferWriteWithStringLengthCheck(a1, asc_5C4044);
    //   return 0;
    // UNRESOLVED: Textual contents of the six format strings are not present in the packet.
    // UNRESOLVED: Globals off_5C3F88, off_5C3F8C, off_5C3F90, off_5C3F94, off_5C3F98 and byte_5EA438 are listed in the packet but not referenced by the decompiled body.
    // UNRESOLVED: How the produced entry is consumed by the ConfigFileParser caller (004330d0).
}
