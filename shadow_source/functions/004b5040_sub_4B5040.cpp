// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5040
// Canonical corpus name: sub_4B5040
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B5040_004b5040.c

void UnknownObject::sub_4B5040()
{
    // Writes a fixed-format binary block through FileWriteWithBackendDispatch: a length byte a2 is used as the payload length, a header byte 1, then a2 bytes copied from this+1, the payload is null-terminated at this[a2+1], and three trailing fixed-size regions at this+65 (32), this+97 (32), and this+132 (4) plus a final 4-byte region at this+136 are flushed. Always returns 1.
    // CALL: Write 1 byte from this (a header byte) via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Write 1 byte from the length variable a2 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Write a2 bytes from this+1 (the payload) via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // ASSIGNMENT: Null-terminate the payload: this[a2 + 1] = 0. [source:raw]
    // CALL: Write 32 bytes from this+65 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Write 32 bytes from this+97 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Write 4 bytes from this+132 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Write 4 bytes from this+136 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // RETURN: Return constant 1 as success. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B5040(BYTE *buf, BYTE len) {
    //     FileWriteWithBackendDispatch(buf, 1);
    //     FileWriteWithBackendDispatch(&len, 1);
    //     FileWriteWithBackendDispatch(buf + 1, len);
    //     buf[len + 1] = 0;
    //     FileWriteWithBackendDispatch(buf + 65, 32);
    //     FileWriteWithBackendDispatch(buf + 97, 32);
    //     FileWriteWithBackendDispatch(buf + 132, 4);
    //     FileWriteWithBackendDispatch(buf + 136, 4);
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the on-disk block: fields at +65/+97 (32 bytes each) and +132/+136 (4 bytes each) are unnamed.
    // UNRESOLVED: Meaning of the length byte a2 and how this block is consumed by the ModelSceneFileLoader caller.
    // UNRESOLVED: Which backend FileWriteWithBackendDispatch selects is not resolvable from this function alone.
}
