// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005117C8
// Canonical corpus name: sub_5117C8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5117C8_005117c8.c

void UnknownObject::WriteEscapedHexRecord()
{
    // cdecl text serializer. Iterates four bytes at a1+268; a byte outside the printable alphanumeric range (below 41, above 122, or in 91..96) is escaped as '[' + two hex digits from the byte_5AF210 lookup + ']', otherwise the byte is copied verbatim. When a2 is non-null it then appends ': ' and copies a 0x40-byte payload from a2, forcing the 64th byte to 0; otherwise it appends a null terminator. Returns the end-of-buffer pointer. Used by DoubleBufferInit (0x0051189C) and TwoStepDelegation (0x005118C1) to serialize a small record.
    // LOOP: Loop over i in 0..3 reading the byte at a1+i+268 for escape/verbatim handling. [source:raw]
    // GUARD: Escape branch is taken when the byte is below 41, above 122, or strictly between 90 and 97 (i.e. not a printable alphanumeric); otherwise the byte is emitted verbatim. [source:raw]
    // CALCULATION: Writes '[' (91), then two hex digits taken from byte_5AF210 indexed by (v5>>4)&0xF and v5&0xF, then ']' (93). [global:0x005AF210, source:raw]
    // ASSIGNMENT: Copies the printable byte into the output verbatim on the non-escape path. [source:raw]
    // GUARD: If a2 is non-null, appends ':' (58) and ' ' (32), copies 0x40 bytes from a2 and forces the 64th byte to 0; otherwise appends a single 0 terminator. [source:raw]
    // CALCULATION: qmemcpy of 0x40 bytes from a2 into the output buffer after the ': ' prefix. [source:raw]
    // ASSIGNMENT: Writes 0 at result[63] to bound the copied payload, or a 0 terminator when a2 is null. [source:raw]
    // RETURN: Returns the current buffer pointer, i.e. one past the last byte written. [source:raw]
    // CALL: Consumed by DoubleBufferInit (0x0051189C) and TwoStepDelegation (0x005118C1) as a shared record serialization step. [caller:0x0051189C, caller:0x005118C1, source:raw]

    // Conservative worker pseudocode:
    //   char* WriteEscapedHexRecord(char* a1, const void* a2) {
    //     char* out = result; /* buffer base not recovered * /
    //     for (i = 0; i < 4; ++i) {
    //       int c = a1[i + 268];
    //       if (c < 41 || c > 122 || (c > 90 && c < 97)) {
    //         *out++ = '['; *out++ = byte_5AF210[(c>>4)&0xF]; *out++ = byte_5AF210[c&0xF]; *out++ = ']';
    //       } else *out++ = c;
    //     }
    //     if (a2) { *out++ = ':'; *out++ = ' '; memcpy(out, a2, 0x40); out[63] = 0; }
    //     else *out = 0;
    //     return out;
    //   }
    // UNRESOLVED: v2 (ecx) is uninitialized in the decompiler output and all writes are indexed by it; the buffer base that `result` points into is not recovered from this packet.
    // UNRESOLVED: byte_5AF210 is assumed to be a hex-digit lookup table (values 0-15 mapping to '0'-'9'/'A'-'F') but its contents are not evidenced here.
    // UNRESOLVED: Whether the four bytes at a1+268 form a fixed identifier/name field, and whether the output is required to fit a caller-sized buffer, is not established.
    // UNRESOLVED: The 0x40-byte payload structure copied from a2 (field layout, text or binary) is unknown.
}
