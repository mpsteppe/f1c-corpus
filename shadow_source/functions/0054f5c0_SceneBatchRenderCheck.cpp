// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054F5C0
// Canonical corpus name: SceneBatchRenderCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneBatchRenderCheck_0054f5c0.c

void UnknownObject::SceneBatchRenderCheck()
{
    // Per-entity scene check returning 1 when the entity has no render/visibility flags to process, 0 after a detected collision contact increments the global counter, and 0 when the entity is blocked or too far. When the entity flags at a2+60 do not set bit 1, it verifies the global counter is below the threshold at *(this+0x1E0)+4, optionally prepares the render batch (bit 4), then if the node visibility flag at v6+20 has bit 0x40 it computes squared distance from the camera position (this+0x204 float array) to the node and, when inside the squared radius and proximity is enabled (a3 & 1), runs collision contact detection and increments the counter by the hit count.
    // ASSIGNMENT: Read the entity flags at a2+60 into v3 and initialize the default result v4 to 0. [source:raw]
    // GUARD: If v3 has bit 1 (value 2) set, skip the whole block and return the default result 0 (blocked entity). [source:raw]
    // GUARD: Counter saturation guard: if the global counter dword_8C5F40 is >= the threshold at *(this+0x1E0)+4, return 1 (nothing more to process). [global:0x008C5F40, field:*(this+0x1E0):0x00000004, field:this:0x000001E0, source:raw]
    // ASSIGNMENT: Load the entity node pointer at a2+516 into v6. [source:raw]
    // GUARD: Batch-prepare branch when v3 has bit 4 (value 0x10) set. [source:raw]
    // CALL: Call sub_54B570(a2, 0, *(a2+516)) to prepare the render batch. [callee:0x0054B570, source:raw]
    // GUARD: If the dword flag at v6+20 has bit 0x20000000 clear, set it on the node. [source:raw]
    // CALL: Indirect vtable call through the dword_8B8F24 device wrapper (+4 slot) passing (dword_8B8F24, v6+220, v6+232, a2+276). [global:0x008B8F24, source:raw]
    // GUARD: Visibility guard: proceed only when the byte flag at v6+20 has bit 0x40 set. [source:raw]
    // ASSIGNMENT: Load the camera position float array pointer from this+0x204 into v8. [field:this:0x00000204, source:raw]
    // CALCULATION: Compute the camera-to-node delta vector: when v3 has bit 4, subtract the node positions at v6+240/236/232 from the camera components at v8[60]/v8[59]/v8[58]; otherwise subtract v6+228/224/220. [field:*(this+0x204):0x000000F0, field:*(this+0x204):0x000000EC, field:*(this+0x204):0x000000E8, source:raw]
    // CALCULATION: Squared distance v13 = sum of squares of the delta components. [source:raw]
    // CALCULATION: Build the squared collision radius v14 = node radius (float at v6+24) + base radius float **(this+0x1E0); compare against v13. [field:*(this+0x1E0):0x00000000, field:this:0x000001E0, source:raw]
    // GUARD: Distance/proximity guard: run contact detection only when v13 < v14*v14 and the proximity flag (a3 & 1) is set. [source:raw]
    // CALL: Call the collision contact detector: sub_54EED0 when v3 has bit 4, otherwise CollisionContactDetection; both receive (this, a2, node, a3) and return the hit count v15. [callee:0x0054EED0, callee:0x0054F2F0, source:raw]
    // GUARD: When the hit count v15 is greater than zero, a collision contact is recorded. [source:raw]
    // STATE_TRANSITION: Increment the global counter dword_8C5F40 by the hit count v15. [global:0x008C5F40, source:raw]
    // RETURN: Return 0 after recording the contact, and return 0 in every other fall-through path. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneBatchRenderCheck(int this, int a2, int a3) {
    //     int flags = *(int*)(a2 + 60);
    //     int result = 0;
    //     if ((flags & 2) == 0) {
    //       if (dword_8C5F40 >= *(int*)(*(int*)(this + 480) + 4)) return 1;
    //       int node = *(int*)(a2 + 516);
    //       if ((flags & 0x10) != 0) {
    //         sub_54B570(a2, 0, *(int*)(a2 + 516));
    //         if ((*(int*)(node + 20) & 0x20000000) == 0) {
    //           *(int*)(node + 20) |= 0x20000000;
    //           (*(void(__cdecl**)(int,int,int,int))(*(int*)dword_8B8F24 + 4))(dword_8B8F24, node + 220, node + 232, a2 + 276);
    //         }
    //       }
    //       if ((*(byte*)(node + 20) & 0x40) != 0) {
    //         float* cam = *(float**)(this + 516);
    //         float dx, dy, dz;
    //         if ((flags & 0x10) != 0) { dx = cam[60] - *(float*)(node + 240); dy = cam[59] - *(float*)(node + 236); dz = cam[58] - *(float*)(node + 232); }
    //         else { dx = cam[60] - *(float*)(node + 228); dy = cam[59] - *(float*)(node + 224); dz = cam[58] - *(float*)(node + 220); }
    //         double dist2 = dx*dx + dy*dy + dz*dz;
    //         double radius = *(float*)(node + 24) + **(float**)(this + 480);
    //         if (dist2 < radius*radius && (a3 & 1) != 0) {
    //           int hits = ((flags & 0x10) != 0) ? sub_54EED0(this, a2, node, a3) : CollisionContactDetection(this, a2, node, a3);
    //           if (hits > 0) { dword_8C5F40 += hits; return 0; }
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The entity struct offsets (a2+60, a2+516) and node struct offsets (v6+20, v6+24, v6+220..240) are not covered by the packet field table; their meanings are DERIVED from usage.
    // UNRESOLVED: Identity of the indirect vtable slot (+4) on the dword_8B8F24 wrapper is unknown.
    // UNRESOLVED: Whether dword_8C5F40 is truly an audio-collision counter (fill claim) is not independently confirmed.
    // UNRESOLVED: The base radius float **(this+0x1E0) and the threshold at *(this+0x1E0)+4 are read through an untyped descriptor pointer.
}
