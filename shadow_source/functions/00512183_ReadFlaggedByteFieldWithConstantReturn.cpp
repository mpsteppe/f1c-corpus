// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512183
// Canonical corpus name: FlagGuardedByteReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagGuardedByteReader_00512183.c

void UnknownObject::ReadFlaggedByteFieldWithConstantReturn()
{
    // Flag-guarded byte-field reader with a constant success code. Returns 0 when a1 is null, a2 is null, bit 0x800 of the dword at a2 + 8 is clear, or output pointer a3 is null. On success writes the unsigned byte at a2 + 44 into *a3 and returns the constant 2048.
    // GUARD: Guard on a1 being non-null; when null return 0. [source:raw, function:0x00512183]
    // GUARD: Guard on a2 being non-null; when null return 0. [source:raw, function:0x00512183]
    // GUARD: Guard on bit 0x800 of the dword at a2 + 8 being set; when clear return 0. [source:raw, function:0x00512183]
    // GUARD: Guard on output pointer a3 being non-null; when null return 0. [source:raw, function:0x00512183]
    // ASSIGNMENT: Initialize result to the constant 2048 before the flag/output guards. [source:raw]
    // ASSIGNMENT: Write the unsigned byte at a2 + 44 into *a3. [source:raw]
    // RETURN: Return the constant 2048 on success, 0 when any guard fails. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_512183(int a1, int a2, unsigned int *a3) {
    //     if (!a1 || !a2)
    //       return 0;
    //     int result = 2048;
    //     if ((*(unsigned int *)(a2 + 8) & 0x800) == 0 || !a3)
    //       return 0;
    //     *a3 = *(unsigned char *)(a2 + 44);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the constant 2048 as a success code is not established; it may encode a field id or size.
    // UNRESOLVED: Semantics of bit 0x800 at a2 + 8 are not proven; byte at +44's meaning is unknown.
    // UNRESOLVED: Decompiler names a3 as _DWORD but it is written as an unsigned byte read.
}
