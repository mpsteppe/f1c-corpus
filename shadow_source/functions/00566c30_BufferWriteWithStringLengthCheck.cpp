// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566C30
// Canonical corpus name: BufferWriteWithStringLengthCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferWriteWithStringLengthCheck_00566c30.c

void UnknownObject::BufferWriteWithStringLengthCheck()
{
    // Variadic formatted-write dispatcher. When the mode flag at this+0x10 is zero, formats and writes directly to a file handle via the locked file write wrapper and returns 0. Otherwise formats into a local buffer, computes the length including terminator, and writes all formatted bytes through the buffer fill wrapper, returning true only when every byte was written.
    // GUARD: If the mode flag at this+0x10 is zero, take the direct file-write path. [field:this:0x00000010, source:raw]
    // CALL: Write the formatted string directly to the file handle with locking and return 0. [callee:0x0058A163, field:this:0x00000000, source:raw]
    // CALL: Format the variadic arguments into the local 2048-byte buffer safely. [callee:0x0058AC95, source:raw]
    // CALCULATION: Compute the formatted length plus terminator: strlen(buffer) + 1. [source:raw]
    // GUARD: If the content length minus terminator is not positive, return 0. [source:raw]
    // CALL: Write the formatted bytes (length minus terminator) into the buffer sink with timeout. [callee:0x00535220, field:this:0x00000000, source:raw]
    // RETURN: Return true only if the number of bytes written equals the full formatted length. [source:raw]

    // Conservative worker pseudocode:
    //   if (sink[4] == 0) {
    //       FileWriteWrapperWithLock(*sink, format, va);
    //       return 0;
    //   }
    //   SafeStringFormat(format_buffer, format, va);
    //   len = strlen(format_buffer) + 1;
    //   if ((int)(len - 1) <= 0) return 0;
    //   return BufferFillWithTimeout(*sink, format_buffer, len - 1) == (len - 1);
    // UNRESOLVED: The exact type and lifecycle of the sink object (file handle vs buffer descriptor) is not derivable from this function alone.
}
