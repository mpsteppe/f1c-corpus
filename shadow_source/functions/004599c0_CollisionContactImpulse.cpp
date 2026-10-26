// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004599C0
// Canonical corpus name: CollisionContactImpulse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionContactImpulse_004599c0.c

void UnknownObject::CollisionContactImpulse()
{
    // Computes a collision contact impulse term. Stores the input magnitude a3 at this+0x24 and a3 + 100.0 at this+0x20. Builds a direction vector v7 by scaling the a2 direction components (float indices 8, 9, 10) by the magnitude factor a2[1], and a delta vector v6 by subtracting the a2 position components (float indices 5, 6, 7) from three double values read at this+0xD8, this+0xE0 and this+0xE8. Returns the result of F_3DVectorCrossProductRotationAccumulation(v7, v6), the cross-product rotation accumulation term for the contact. Part of the collision response system invoked by ModeDispatchWithSwitch.
    // ASSIGNMENT: Store a3 + 100.0 into float this+0x20. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store the input magnitude a3 into float this+0x24. [field:this:0x00000024, source:raw]
    // CALCULATION: Scale direction vector v7 = (a2[8] * a2[1], a2[9] * a2[1], a2[10] * a2[1]) using the a2 magnitude factor a2[1]. [source:raw]
    // CALCULATION: Build delta v6 = (double(this+0xD8) - a2[5], double(this+0xE0) - a2[6], double(this+0xE8) - a2[7]) between this body state and the a2 position. [field:this:0x000000D8, field:this:0x000000E0, field:this:0x000000E8, source:raw]
    // CALL: Call F_3DVectorCrossProductRotationAccumulation(v7, v6) to accumulate the rotational impulse contribution. [callee:0x00569670, source:raw]
    // RETURN: Return the cross-product accumulation result. [callee:0x00569670, source:raw]
    // CALL: Invoked from the frame-path caller ModeDispatchWithSwitch (0x0040F4B0). [caller:0x0040F4B0, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionContactImpulse(float *this, float *a2, float a3) {
    //     this[8] = a3 + 100.0f;
    //     this[9] = a3;
    //     double v3 = a2[1];
    //     double v7[3] = { a2[8] * v3, a2[9] * v3, a2[10] * v3 };
    //     float *v4 = this + 53;
    //     double v6[3] = { *(double *)(v4 + 1) - a2[5],
    //                      *(double *)(v4 + 3) - a2[6],
    //                      *(double *)(v4 + 5) - a2[7] };
    //     return F_3DVectorCrossProductRotationAccumulation(v7, v6);
    //   }
    // UNRESOLVED: Global flt_59E6F8 is listed in the packet globals but does not appear in the raw source text of this function; its role here is unclear.
    // UNRESOLVED: The a2 vector layout (magnitude at index 1, direction at indices 8-10, position at indices 5-7) is inferred from the raw float indexing and is not independently confirmed.
    // UNRESOLVED: The double reads at this+0xD8, this+0xE0 and this+0xE8 via the float pointer this+53 are interpreted as contact body state deltas from existing analysis prose (DERIVED).
    // UNRESOLVED: The owning object type is unknown (owner UnknownObject).
}
