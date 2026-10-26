// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2CA0
// Canonical corpus name: ScalePropagate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScalePropagate_004e2ca0.c

void UnknownObject::ScalePropagate()
{
    // Propagates a new scale value to scene-graph children when it changes (thiscall). Computes the scale ratio old->new and applies velocity scaling on the primary child node, and on a secondary child node when present. Per-frame tick on the vehicle transform/scale path.
    // GUARD: Guard on scale change: a2 != *(float *)(this + 0x970); when the new scale equals the current stored scale the whole update is skipped. [field:this:0x00000970, source:raw]
    // CALCULATION: Compute the scale ratio v4 = a2 / *(float *)(this + 0x970) from the pre-update scale value, staged through local float v6. [field:this:0x00000970, source:raw]
    // ASSIGNMENT: Store the new scale: *(float *)(this + 0x970) = a2. [field:this:0x00000970, source:raw]
    // CALL: SceneGraphChildVelocityScaling(*(_DWORD *)(this + 4), v6, 0) applies the ratio to the primary scene-graph child node. [field:this:0x00000004, callee:0x004E2A00, source:raw]
    // CALL: Load secondary child pointer v5 = *(_DWORD *)(*(_DWORD *)(this + 4) + 0x44); when non-zero, SceneGraphChildVelocityScaling(v5, v6, 1) applies the ratio to it as a second child. [field:*(this+0x4):0x00000044, callee:0x004E2A00, source:raw]
    // CALL: Called by VehicleRespawnReset (0x004E0800) and sub_4F0D20 (0x004F0D20) to re-propagate a vehicle scale change. [caller:0x004E0800, caller:0x004F0D20, source:raw]

    // Conservative worker pseudocode:
    //   void ScalePropagate(int this, float newScale) {
    //     if (newScale != *(float *)(this + 0x970)) {
    //       float ratio = newScale / *(float *)(this + 0x970);
    //       *(float *)(this + 0x970) = newScale;
    //       SceneGraphChildVelocityScaling(*(int *)(this + 4), ratio, 0);
    //       int child2 = *(int *)(*(int *)(this + 4) + 0x44);
    //       if (child2) SceneGraphChildVelocityScaling(child2, ratio, 1);
    //     }
    //   }
    // UNRESOLVED: Semantic units of the scale value at this+0x970 (visual scale factor) and the meaning of the two child-node velocity scalings.
    // UNRESOLVED: The object owning `this` and the two scene-graph child nodes is unknown (UnknownObject).
}
