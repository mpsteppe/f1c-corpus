// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B41E0
// Canonical corpus name: FileStreamWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileStreamWriter_004b41e0.c

void UnknownObject::FilePathStreamWriter()
{
    // Writes a string through a conditional dispatch stream. First dispatches the container header (this, 4 bytes), then the string length (1 byte), then the string content. The string pointer is read at this+0x4 and falls back to the global byte_5EA438 when NULL; a2 is overwritten by strlen of the resolved string. Returns 1 unconditionally. Called by VehicleForceAerodynamicsComputation.
    // CALL: ConditionalDispatch_6bd0(this, 4) writes the container header (the first 4 bytes of this) to the dispatch stream [callee:0x00566BD0, source:raw]
    // GUARD: Resolve the string pointer at this+0x4; when NULL, substitute the global byte_5EA438 as the default path [field:this:0x00000004, global:0x005EA438, source:raw]
    // CALCULATION: a2 = strlen(v3) computes the string length, overwriting the incoming parameter value [source:raw]
    // CALL: ConditionalDispatch_6bd0(&a2, 1) writes the length byte to the dispatch stream [callee:0x00566BD0, source:raw]
    // GUARD: Only dispatch the string content when the computed length a2 is non-zero [source:raw]
    // ASSIGNMENT: Re-resolve the content pointer from this+0x4 with the same byte_5EA438 fallback used for the length computation [field:this:0x00000004, global:0x005EA438, source:raw]
    // CALL: ConditionalDispatch_6bd0(v4, a2) writes the string content (a2 bytes) to the dispatch stream [callee:0x00566BD0, source:raw]
    // RETURN: Return 1 on every path; invoked by VehicleForceAerodynamicsComputation [function:0x004B41E0, caller:0x004B6A10, source:raw]

    // Conservative worker pseudocode:
    //   ConditionalDispatch_6bd0(this, 4);
    //   s = this[1] ? this[1] : byte_5EA438;
    //   len = strlen(s);
    //   ConditionalDispatch_6bd0(&len, 1);
    //   if (len) {
    //     s2 = this[1] ? this[1] : byte_5EA438;
    //     ConditionalDispatch_6bd0(s2, len);
    //   }
    //   return 1;
    // UNRESOLVED: ConditionalDispatch_6bd0's output target and buffering semantics are not documented in this packet; the file-stream label comes only from caller context
    // UNRESOLVED: The 4-byte header written by ConditionalDispatch_6bd0(this, 4) includes the string pointer at this+0x4, so the pointer is serialized both in the header and as the dispatched content
    // UNRESOLVED: The intended meaning of a2's incoming value is not established because it is unconditionally overwritten by strlen
}
