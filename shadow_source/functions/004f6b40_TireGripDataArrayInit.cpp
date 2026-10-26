// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6B40
// Canonical corpus name: TireGripDataArrayInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireGripDataArrayInit_004f6b40.c

void UnknownObject::TireGripDataArrayInit()
{
    // Initializes a 45-entry array of 5-dword (20-byte) tire-grip data records anchored 8 bytes below global dword_8AF570. Each record is filled with sentinel values (dword 0 at offset 0, -1 at offsets 4, 8 and 12, byte 0 at offset 16) while StringCopyWithBufferRealloc is called with byte_5EA438 on every iteration; the last call result is returned.
    // LOOP: Loop exactly 45 times over 5-dword records starting 8 bytes below dword_8AF570, advancing the record pointer by 5 dwords each pass. [global:0x008AF570, source:raw]
    // ASSIGNMENT: Write 0 to the first dword of the current record (8 bytes below dword_8AF570 at iteration 0). [global:0x008AF570, source:raw]
    // ASSIGNMENT: Write -1 to the second dword of the current record (4 bytes below dword_8AF570 at iteration 0). [global:0x008AF570, source:raw]
    // CALL: Call StringCopyWithBufferRealloc with byte_5EA438 on every iteration; discard or carry the returned result. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Write -1 to the third dword of the current record (dword_8AF570 at iteration 0). [global:0x008AF570, source:raw]
    // ASSIGNMENT: Write -1 to the fourth dword of the current record (4 bytes above dword_8AF570 at iteration 0). [global:0x008AF570, source:raw]
    // ASSIGNMENT: Write 0 to the byte at offset 8 within the current record (byte offset 16 of the record). [global:0x008AF570, source:raw]
    // RETURN: Return the last result produced by StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]

    // Conservative worker pseudocode:
    //   record = &dword_8AF570 - 2;
    //   for (i = 45; i != 0; i--) {
    //     record[0] = 0; record[1] = -1;
    //     result = StringCopyWithBufferRealloc(byte_5EA438);
    //     record[2] = -1; record[3] = -1;
    //     record[4] = 0;
    //     record += 5;
    //   }
    //   return result;
}
