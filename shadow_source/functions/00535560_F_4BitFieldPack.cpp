// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00535560
// Canonical corpus name: F_4BitFieldPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4BitFieldPack_00535560.c

void UnknownObject::F_4BitFieldPack()
{
    // Reads four bytes from a buffered stream (one byte per call to sub_534E70) and packs them into a 32-bit little-endian integer. If the fourth byte read returns -1 (EOF), sets the error field this[14] (offset 0x38) to -3. Returns the packed 32-bit value even on a partial/EOF read. Used by BufferedFileReader (0x00534F90) on the per-frame path.
    // CALL: Read byte 1 of the stream via sub_534E70(this) and store as v2. [callee:0x00534E70, source:raw]
    // CALL: Read byte 2 of the stream via sub_534E70(this) and store as the second byte. [callee:0x00534E70, source:raw]
    // CALL: Read byte 3 of the stream via sub_534E70(this) and store as the third byte. [callee:0x00534E70, source:raw]
    // CALL: Read byte 4 of the stream via sub_534E70(this) and store as v5. [callee:0x00534E70, source:raw]
    // CALCULATION: Pack the four bytes into a 32-bit little-endian value: v2 + (v3 << 8) + (v4 << 16) + (v5 << 24). [source:raw]
    // GUARD: Guard: if the fourth byte read (v5) equals -1 (EOF), set the error code. [source:raw]
    // ASSIGNMENT: Write error code -3 into this[14] (dword field at offset 0x38) when the fourth byte read hit EOF. [field:this:0x00000038, source:raw]
    // RETURN: Return the packed 32-bit value (the last byte may be an EOF marker). [source:raw]
    // CALL: Called by BufferedFileReader (0x00534F90) as part of buffered binary stream reads. [caller:0x00534F90, source:raw]

    // Conservative worker pseudocode:
    //   int F_4BitFieldPack(int *this) {
    //     int b0 = sub_534E70(this);
    //     int b1 = sub_534E70(this);
    //     int b2 = sub_534E70(this);
    //     int b3 = sub_534E70(this);
    //     if (b3 == -1)
    //       this[14] = -3;
    //     return b0 + (b1 << 8) + (b2 << 16) + (b3 << 24);
    //   }
    // UNRESOLVED: The packet's canonical name F_4BitFieldPack packs four stream bytes rather than bit fields; name may be a legacy artifact.
    // UNRESOLVED: Whether the packed result is used as a signed or unsigned value by callers is unknown.
}
