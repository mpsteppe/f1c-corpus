// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF560
// Canonical corpus name: SetWheelContactFlags
// Owner: VehicleWheelContact [DERIVED]
// Raw source: functions/SetWheelContactFlags_004ef560.c

void VehicleWheelContact::SetWheelContactFlags()
{
    // Per-wheel contact writer reached from the tire slip-force path. Indexes this by 28-byte stride a2 to select one wheel record, stores two contact/state flag bytes at byte offsets 15224 and 15225 of that record, then copies a 3-dword vector from a5 into byte offset 15240 and returns a pointer to the copied vector.
    // CALCULATION: Compute the per-wheel record pointer v5 = this + 28 * a2 (28-byte stride per wheel index a2). [source:raw]
    // ASSIGNMENT: Store contact/state flag byte a3 at v5[15224]. [source:raw]
    // ASSIGNMENT: Store contact/state flag byte a4 at v5[15225]. [source:raw]
    // ASSIGNMENT: Copy the 3-dword vector at a5 into v5 + 15240: result[0] = a5[0], result[1] = a5[1], result[2] = a5[2]. [source:raw]
    // RETURN: Return result (pointer to v5 + 15240, the copied 3-dword vector). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4EF560(char *this, int wheelIdx, char flagA, char flagB, _DWORD *vec) {
    //     char *w = &this[28 * wheelIdx];
    //     w[15224] = flagA;
    //     w[15225] = flagB;
    //     _DWORD *out = (_DWORD *)(w + 15240);
    //     out[0] = vec[0]; out[1] = vec[1]; out[2] = vec[2];
    //     return out;
    //   }
    // UNRESOLVED: Exact meanings of flag bytes a3/a4 and of the 3-dword vector (forces, slip, or contact data) are not established from this packet.
    // UNRESOLVED: Identity of the enclosing object (this) and the wheel-array layout is inferred only from the caller TireSlipForceCalculation.
}
