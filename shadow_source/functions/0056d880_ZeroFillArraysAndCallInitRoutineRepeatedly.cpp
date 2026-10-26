// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D880
// Canonical corpus name: ZeroFillArraysAndCallInitRoutineRepeatedly
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroFillArraysAndCallInitRoutineRepeatedly_0056d880.c

void UnknownObject::ZeroFillArraysAndCallInitRoutineRepeatedly()
{
    // Zero-fills arrays of 8-byte elements behind each pointer in the pointer list a2, then calls sub_568FB0 on each of *this vehicle physics joint structs in the this[1] array (stride 580). The first block iterates a3 pointers, zeroing a3 elements of 8 bytes each per pointer. The second block walks this[1] with byte stride 580 and calls sub_568FB0 for each of the *this structs, passing a2 as the second argument. Called by VehiclePhysicsJointSystemLoader.
    // GUARD: When a3 > 0 the zero-fill pass over the a2 pointer list runs; otherwise it is skipped [source:raw]
    // LOOP: Outer loop iterates the a3 pointers in a2; per pointer the inner loop zeroes a3 elements of 8 bytes each (dword at base+8*i and base+8*i+4) [source:raw]
    // GUARD: When *this > 0 the joint-struct initialization pass runs; otherwise it is skipped [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Iterates *this structs in the this[1] array, advancing the byte offset v8 by 580 per iteration (struct stride 580) [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: sub_568FB0((joint_struct*)(v8 + this[1]), a2) initializes one vehicle physics joint struct in the array [callee:0x00568FB0, field:this:0x00000004, source:raw]
    // CALL: Invoked by VehiclePhysicsJointSystemLoader (0056d930) [caller:0x0056D930]

    // Conservative worker pseudocode:
    //   v3 = 0;
    //   if (a3 > 0) {
    //       v5 = a2;
    //       v9 = a3;
    //       do {
    //           for (i = 0; i < a3; ++i) {
    //               v7 = *v5;
    //               *(v7 + 8*i) = 0;
    //               *(v7 + 8*i + 4) = 0;
    //           }
    //           ++v5; --v9;
    //       } while (v9);
    //   }
    //   if (*this > 0) {
    //       v8 = 0;
    //       do {
    //           sub_568FB0((v8 + this[1]), a2);
    //           ++v3; v8 += 580;
    //       } while (v3 < *this);
    //   }
    // UNRESOLVED: sub_568FB0's internal initialization semantics and the meaning of the a2 argument passed to it are not documented in this packet
    // UNRESOLVED: The identity of the element type behind the 8-byte zero-fill slots (two dwords per slot) is unknown
    // UNRESOLVED: The relationship between a3 (pointer count) and the per-pointer element count a3 is taken from the raw loop bounds; no independent packet constant confirms the intended array geometry
}
