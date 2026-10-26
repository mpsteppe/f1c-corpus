// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584FF0
// Canonical corpus name: StringCopyToBufferWithLengthCap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyToBufferWithLengthCap_00584ff0.c

void UnknownObject::StringCopyToBufferWithLengthCap()
{
    // Clears an internal 16-byte string buffer at this+0x64 and, when the source pointer a2 is non-NULL, copies at most 16 characters into it via a capped copy helper, then forces a null terminator at this+0x74. Returns the source pointer a2.
    // ASSIGNMENT: Save the source pointer: result = a2. [source:raw]
    // ASSIGNMENT: Clear the start of the internal 16-byte buffer: this[100] = 0 (field 0x64). [source:raw, field:this:0x00000064]
    // GUARD: Guard on a2 non-NULL; when NULL the copy is skipped and the buffer stays cleared. [source:raw]
    // CALL: Call capped copy helper sub_587DD0(this + 100, a2, 16) with maximum length 16 and store its result. [source:raw, callee:0x00587DD0]
    // ASSIGNMENT: Force null terminator at the end of the 16-byte buffer: v3[16] = 0 (field 0x74). [source:raw, field:this:0x00000074]
    // RETURN: Return result, which is the source pointer a2. [source:raw]

    // Conservative worker pseudocode:
    //   int StringCopyToBufferWithLengthCap(char* this, int src) {
    //     char* buf = this + 100;
    //     int result = src;
    //     buf[0] = 0;
    //     if (src) {
    //       result = sub_587DD0(this + 100, src, 16);
    //       buf[16] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic role of the internal 16-byte buffer and the owning object are not established from this packet.
    // UNRESOLVED: Meaning of the returned source pointer and how caller 0057a4f0 consumes it is not known here.
}
