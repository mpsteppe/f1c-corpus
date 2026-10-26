// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051215A
// Canonical corpus name: GuardedFloatToDoubleConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedFloatToDoubleConversion_0051215a.c

void UnknownObject::ReadFlaggedFloatField()
{
    // Flag-guarded float-to-double field reader. Returns 0 unless all guards pass (a1 non-null, a2 non-null, bit 0 of the dword at a2 + 8 set, a3 non-null). On success writes the float at a2 + 40 into the caller's double *a3 and returns 1.
    // GUARD: Guard on a1 being non-null; when null return 0. [source:raw, function:0x0051215A]
    // GUARD: Guard on a2 being non-null; when null return 0. [source:raw, function:0x0051215A]
    // GUARD: Guard on bit 0 of the dword at a2 + 8 being set ((*(_BYTE *)(a2 + 8) & 1) == 0 fails); when clear return 0. [source:raw, function:0x0051215A]
    // GUARD: Guard on output pointer a3 being non-null; when null return 0. [source:raw, function:0x0051215A]
    // ASSIGNMENT: Write the float value at a2 + 40 into *a3 (widened to double). [source:raw]
    // RETURN: Return 1 on success, 0 when any guard fails. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_51215A(int a1, int a2, double *a3) {
    //     if (!a1 || !a2 || (*(unsigned char *)(a2 + 8) & 1) == 0 || !a3)
    //       return 0;
    //     *a3 = *(float *)(a2 + 40);
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of bit 0 at a2 + 8 (field-valid/present flag) is inferred, not proven.
    // UNRESOLVED: Identity of a1's role is unknown; it acts as an enable guard.
}
