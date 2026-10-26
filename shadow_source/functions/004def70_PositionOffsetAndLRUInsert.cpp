// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DEF70
// Canonical corpus name: sub_4DEF70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DEF70_004def70.c

void UnknownObject::PositionOffsetAndLRUInsert()
{
    // Builds a cache entry from a2 and the a3 position triple, subtracts a stored origin (this+0x4 struct) from the triple when the flag byte at that struct's offset 0x42 is set, copies the a4 triple and computes its magnitude (v18 = sqrt of the sum of squares), then inserts the entry into a sorted LRU array via SortedArrayInsertWithLRUEviction when the magnitude is positive. Spatial cache population.
    // ASSIGNMENT: Seed the entry buffer: v11[0] = 0.0 and v11[1] = a2. [source:raw]
    // ASSIGNMENT: Copy the a3 position triple into the entry: v12 = *a3, v13 = a3[1], v14 = a3[2]. [source:raw]
    // CALCULATION: Dereference this+0x4 into v5, the sub-struct holding position data. [field:this:0x00000004, source:raw]
    // GUARD: Read the flag byte at *(this+0x4)+0x42; when non-zero the position-offset subtraction is enabled. [field:*(this+0x4):0x00000042, source:raw]
    // CALCULATION: When the flag is set, subtract the stored origin from the copied triple: v12 -= *(v5+4), v13 -= *(v5+8), v14 -= *(v5+12). [field:*(this+0x4):0x00000004, field:*(this+0x4):0x00000008, field:*(this+0x4):0x0000000C, source:raw]
    // CALCULATION: Copy the a4 triple into v15/v16/v17 (v16 and v17 captured as dwords). [source:raw]
    // CALCULATION: Compute the magnitude of a4: v18 = sqrt(v8*v8 + v7*v7 + v6*v6), the length of the a4 vector. [source:raw]
    // GUARD: Guard on the computed magnitude v18 being greater than 0.0, using the threshold constant flt_59E440 (approximately 0.0); insertion is skipped when the magnitude is non-positive. [global:0x0059E440, source:raw]
    // CALL: When the magnitude is positive, call SortedArrayInsertWithLRUEviction(this, v11) to insert the built entry into the sorted LRU cache array. [callee:0x004DEDB0, source:raw]

    // Conservative worker pseudocode:
    //   void PositionOffsetAndLRUInsert(int this, float a2, float* a3, float* a4) {
    //     float entry[9];
    //     entry[0] = 0.0;
    //     entry[1] = a2;
    //     float x = a3[0], y = a3[1], z = a3[2];
    //     int pos = *(int*)(this + 4);
    //     if (*(char*)(pos + 0x42)) {
    //       x -= *(float*)(pos + 4);
    //       y -= *(float*)(pos + 8);
    //       z -= *(float*)(pos + 12);
    //     }
    //     entry[2] = x; entry[3] = y; entry[4] = z;
    //     entry[5] = a4[0]; entry[6] = a4[1]; entry[7] = a4[2];
    //     double mag = sqrt(a4[0]*a4[0] + a4[1]*a4[1] + a4[2]*a4[2]);
    //     entry[8] = (float)mag;
    //     if (mag > 0.0) SortedArrayInsertWithLRUEviction((float*)this, entry);
    //   }
    // UNRESOLVED: The exact entry layout is uncertain: the raw source's locals (v11 float pair plus v12..v18) form a flat 9-float record, but its field meanings beyond position and magnitude are unknown.
    // UNRESOLVED: The v16/v17 fields capture a4 elements as raw dwords; whether a4 is a vector, a direction, or a packed record is unresolved.
    // UNRESOLVED: The identity of the this+0x4 sub-struct (a shared origin/position holder) and the semantics of the offset 0x42 flag are not established.
    // UNRESOLVED: The owning object is unknown; the sorted-LRU insertion implies a spatial cache, which is DERIVED from the callee name only.
    // UNRESOLVED: Caller RepeatedPositionOffsetTransform (0x004E3940) is recorded but its call context is not in the packet.
}
