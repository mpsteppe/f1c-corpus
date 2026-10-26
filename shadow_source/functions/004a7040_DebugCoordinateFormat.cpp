// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A7040
// Canonical corpus name: DebugCoordinateFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DebugCoordinateFormat_004a7040.c

void UnknownObject::DebugCoordinateFormat()
{
    // Writes two constant global strings into the caller-supplied buffer a1 via BufferWriteWithStringLengthCheck (callee 0x00566C30): first the string literal aSDD (global 0x005CD6B0), then word_5C30B4 (global 0x005C30B4, passed by address). Returns 0. ABI lead name suggests debug coordinate/position formatting output, but the two strings' content and the buffer semantics are not established by this packet.
    // CALL: Write the constant string aSDD (global 0x005CD6B0) into buffer a1 via BufferWriteWithStringLengthCheck (callee 0x00566C30). [callee:0x00566C30, global:0x005CD6B0, source:raw]
    // CALL: Write the constant string word_5C30B4 (global 0x005C30B4) into buffer a1 via BufferWriteWithStringLengthCheck (callee 0x00566C30). [callee:0x00566C30, global:0x005C30B4, source:raw]
    // RETURN: Return 0 as the function result. [function:0x004A7040, source:raw]

    // Conservative worker pseudocode:
    //   char DebugCoordinateFormat(int a1) {
    //     BufferWriteWithStringLengthCheck(a1, aSDD);
    //     BufferWriteWithStringLengthCheck(a1, &word_5C30B4);
    //     return 0;
    //   }
    // UNRESOLVED: The content of the two written strings (aSDD at 0x005CD6B0 and word_5C30B4 at 0x005C30B4) is not present in the packet; the existing analysis's '%s %d %d' format guess is DERIVED and unverified.
    // UNRESOLVED: byte_5EA438 (global 0x005EA438) appears only in the existing analysis (DERIVED 'unknown directory/default application directory path') and is not referenced by the raw source, so its role in this function is unknown.
    // UNRESOLVED: Buffer a1's type, ownership and the purpose of the two writes are not established; no caller or field evidence exists in the packet.
    // UNRESOLVED: No owner evidence exists; the function's owning object is unknown.
}
