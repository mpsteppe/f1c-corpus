// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462FF0
// Canonical corpus name: ClampedPhysicsScaleWithThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedPhysicsScaleWithThreshold_00462ff0.c

void UnknownObject::ClampedPhysicsScaleWithThreshold()
{
    // Computes a clamped physics scale factor for a vehicle: picks the input a3 or, when a3 <= 0, a default base scale read through the object's primary pointer, applies a speed-based multiplier when the vehicle's 3D velocity magnitude (converted to mph) is below 25, applies a 4x scale when a flag bit at vehicle+0x48BC is clear, and clamps the result to [0.0, 0.5]. Indexes the vehicle array at unk_5EC6D8 by a2 with stride 18624.
    // CALCULATION: Compute the vehicle element pointer v3 = (float*)((char*)&unk_5EC6D8 + 18624 * a2), indexing the vehicle array by index a2. [global:0x005EC6D8]
    // GUARD: Guard on input a3: when a3 <= 0.0, read the default base scale as the float at pointee+4 reached through the primary pointer stored at this+0x0; otherwise use a3 as the base scale. [field:this:0x00000000, field:obj:0x00000004]
    // CALCULATION: Compute speed magnitude v5 = fabs(sqrt(v3[3390]^2 + v3[3391]^2 + v3[3392]^2) * 2.2369363), the vehicle velocity vector scaled into mph. [source:raw]
    // GUARD: Guard: if v5 < 25.0, scale result by the linear factor (1.25 - v5 * 0.039999999 * 1.25 + 1.0), reducing scale at low speed. [source:raw]
    // GUARD: Guard on vehicle flag word v3[4655]: when bit 2 is clear (value & 2 == 0), multiply result by 4.0. [source:raw]
    // RETURN: Clamp result: return 0.0 when negative, 0.5 when above 0.5, otherwise return the computed result. [source:raw]

    // Conservative worker pseudocode:
    //   double ClampedPhysicsScaleWithThreshold(void *this, int vehIndex, float a3) {
    //     float *v3 = (float*)&unk_5EC6D8 + 18624 * vehIndex;
    //     double result = (a3 <= 0.0f) ? *(float*)(*(int*)this + 4) : (double)a3;
    //     double v5 = fabs(sqrt(v3[3390]*v3[3390] + v3[3391]*v3[3391] + v3[3392]*v3[3392]) * 2.2369363);
    //     if (v5 < 25.0) result = result * (1.25 - v5 * 0.039999999 * 1.25 + 1.0);
    //     if (((unsigned)v3[4655] & 2) == 0) result = result * 4.0;
    //     if (result < 0.0) return 0.0;
    //     if (result > 0.5) return 0.5;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object (this) whose primary pointer at +0x0 leads to a default base scale float at pointee+4.
    // UNRESOLVED: The exact mapping of the literal constants (2.2369363 mph factor, 25.0, 4.0, 0.5) to the listed global float constants is not established.
    // UNRESOLVED: The role of the flag bit 2 at v3[4655] and the meaning of the final clamped scale value are unknown.
}
