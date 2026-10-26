// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045E620
// Canonical corpus name: PhysicsIntegrationStep_e620
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsIntegrationStep_e620_0045e620.c

void UnknownObject::PhysicsIntegrationStep_e620()
{
    // Per-axle physics integration step for one wheel slot. Clamps the fixed time step from a global, resolves the wheel's state arrays from a1 by the wheel index at a3, computes the wheel velocity delta, samples terrain height/roughness, and, when the contact gate passes, integrates suspension velocity and displacement with a semi-implicit Euler scheme under clamping. Writes the integrated velocity back to a3 and stores the updated wheel state; a fallback path stores current values without integrating.
    // ASSIGNMENT: Load and clamp the fixed time step: start from dbl_8AFE98, clamp non-negative values to a maximum of 0.033333335 (one thirtieth), and clamp negative values to 0.0. [global:0x008AFE98, source:raw]
    // ASSIGNMENT: Select the per-axle wheel slot from the byte at a3 and compute pointers into the wheel state arrays (base a1+112544, 56-byte stride per slot). [source:raw]
    // CALCULATION: Compute the wheel velocity delta vectors as the difference between the input position at a3+8/+12/+16 and the stored wheel position. [source:raw]
    // CALL: Vector3ScalarMultiply: scale the wheel velocity delta by the inverse time step to obtain an acceleration vector. [callee:0x0045EB00, source:raw]
    // GUARD: Gate the full integration on TerrainSurfaceRoughnessHeightSampling succeeding, the sampled height exceeding the wheel threshold dword_7D1158, and the penetration limit flt_7D108C minus dword_7D1158 being positive. [callee:0x0045CA20, global:0x007D1158, global:0x007D108C, source:raw]
    // CALL: TerrainSurfaceRoughnessHeightSampling: sample the terrain height/roughness at the wheel's current contact point, producing the height value tested by the gate. [callee:0x0045CA20, source:raw]
    // CALCULATION: Clamp the normalized penetration ratio to the 0.0-1.0 range and compute a new suspension stiffness value interpolated between flt_7D117C and flt_7D11A0; when it differs from the stored wheel value by more than 5.0, store it and set a damping derivative from flt_7D11C4. [global:0x007D117C, global:0x007D11A0, global:0x007D11C4, source:raw]
    // CALCULATION: Integrate the suspension velocity scaled by the time step into displacement, and compute the wheel-space velocity error scaled by the inverse time step. [global:0x0059E43C, global:0x0059E440, global:0x0059E450, source:raw]
    // CALCULATION: Semi-implicit Euler update: when the relative wheel position stays within a squared radius of 256.0, apply the acceleration scaled by the time step to velocity and a half-step of velocity to position; otherwise snap position and velocity directly. The clamp constants (50.0, 2500.0, 1.0 and pi-related double) are drawn from the 0059E43C..0059F110 constant table. [global:0x0059E474, global:0x0059E828, global:0x0059EB08, global:0x0059F10C, global:0x0059F110, source:raw]
    // ASSIGNMENT: Write the integrated velocity back to a3+8/+12/+16 and store the updated wheel position/velocity into the axle state arrays. [source:raw]
    // ASSIGNMENT: Fallback path: when the terrain gate fails, store the current wheel position and velocity values directly without integration. [source:raw]
    // RETURN: Return a pointer into the wheel state (the updated velocity location). [source:raw]

    // Conservative worker pseudocode:
    //   // a1: vehicle/axle state base; a2: time; a3: wheel input (index byte at +0, position at +8/+12/+16)
    //   float* PhysicsIntegrationStep_e620(int a1, int a2, int a3) {
    //     float dt = clamp(dbl_8AFE98, 0.0f, 0.033333335f);
    //     float* w = wheelSlot(a1, *(byte*)a3);
    //     vec3 velDelta = inputPos(a3) - w->pos;
    //     vec3 accel = Vector3ScalarMultiply(velDelta, 1.0f / dt);
    //     if (TerrainSurfaceRoughnessHeightSampling(...) && height > dword_7D1158 && limit > 0) {
    //       integrateSuspension(w, accel, dt, clamps);
    //       semiImplicitEuler(w, velDelta, dt);
    //       writeBackVelocity(a3, w); storeWheelState(w);
    //     } else {
    //       storeCurrent(w, inputPos(a3), accel);
    //     }
    //     return &w->velocity;
    //   }
    // UNRESOLVED: Exact layout of the 56-byte wheel slot and the two axle state arrays (base a1+112544) is not defined by the packet.
    // UNRESOLVED: Individual roles of the 0x59E474/0x59E828/0x59EB08/0x59F10C/0x59F110 constants are DERIVED from surrounding clamps.
}
