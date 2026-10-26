// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6AB0
// Canonical corpus name: GlobalTableInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalTableInitialization_004f6ab0.c

void UnknownObject::GlobalTableInitialization()
{
    // Initializes a 45-entry global table centered on dword_8AF8F8. Each entry (5 dwords, 20 bytes) is reset: the two dwords before the entry center are zeroed and set to -1, the entry itself is set to -1 with the following dword -1 and the 9th byte zeroed. Each iteration calls StringCopyWithBufferRealloc(byte_5EA438) and discards its return value.
    // ASSIGNMENT: Point v0 at the global table base dword_8AF8F8. [global:0x008AF8F8, source:raw]
    // ASSIGNMENT: Seed loop counter v1 = 45 (table entry count). [source:raw]
    // LOOP: do-while loop running 45 iterations, advancing v0 by 5 dwords (20 bytes) per iteration. [function:0x004F6AB0, source:raw]
    // ASSIGNMENT: Zero the dword at v0 - 2 (two dwords before the entry center). [global:0x008AF8F8, source:raw]
    // ASSIGNMENT: Set the dword at v0 - 1 to -1. [global:0x008AF8F8, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(byte_5EA438) each iteration; the returned buffer pointer is not stored. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Set the entry center dword *v0 to -1. [global:0x008AF8F8, source:raw]
    // ASSIGNMENT: Set the following dword v0[1] to -1. [global:0x008AF8F8, source:raw]
    // ASSIGNMENT: Zero the byte at v0 + 8 (9th byte of the 20-byte entry). [global:0x008AF8F8, source:raw]
    // RETURN: Return the result of the last StringCopyWithBufferRealloc call. [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalTableInitialization() {
    //     int *entry = &dword_8AF8F8;
    //     int n = 45;
    //     int result;
    //     do {
    //       *(entry - 2) = 0;
    //       *(entry - 1) = -1;
    //       result = StringCopyWithBufferRealloc(byte_5EA438);
    //       entry[0] = -1;
    //       entry[1] = -1;
    //       *((char *)entry + 8) = 0;
    //       entry += 5;
    //     } while (--n);
    //     return result;
    //   }
    // UNRESOLVED: The table spans addresses before dword_8AF8F8 (writes at v0 - 2 and v0 - 1 reach 0x8AF8F8 - 8 and - 4); the table's start and its semantic meaning are unknown.
    // UNRESOLVED: Purpose of the discarded StringCopyWithBufferRealloc return value per entry is unknown.
    // UNRESOLVED: Structure of the 5-dword entry (which fields are -1 sentinels vs. pointers) is not evidenced.
}
