// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A0A0
// Canonical corpus name: TestFrustumPlanes
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TestFrustumPlanes_0054a0a0.c

void UnknownObject::TestFrustumPlanes()
{
    // __thiscall that tests an AABB's 8 corner vertices (starting at this+0x24, 3 floats per corner) against 6 frustum planes read from a2+0x104 onward (4 floats each). Clears the lower 4 bits of the visibility flag word this+0x4, then evaluates each plane: for each of the 8 corners it checks the signed plane distance and accumulates a per-plane bitmask v5. If all 8 corners are outside one plane (v5 == 255) the object is fully culled and bit 1 is set; if any corner is outside any plane (v5 != 0) bit 2 is set (partial); if all corners of all 6 planes pass, bit 0 is set (fully visible). Always returns 0. Called by sub_556E70 (0x00556E70), a scene-culling path.
    // ASSIGNMENT: Clear the lower 4 bits of the flag word at this+0x4 (v3 = this[1] & 0xFFFFFFF0) and store v3 back to this+0x4. [field:this:0x00000004, source:raw]
    // LOOP: Outer loop over the 6 frustum planes, starting at a2+260 and advancing 4 floats per plane; also tracks plane count v10, breaking the search once all 6 planes have passed. [field:this:0x00000004, source:raw]
    // LOOP: Inner loop over the 8 AABB corners starting at this+9 (this+0x24), advancing 3 floats per corner. [field:this:0x00000024, source:raw]
    // CALCULATION: Per corner, evaluate the signed plane distance -dot(plane_n, corner) - plane_d against i[1]; if it exceeds i[1] (outside the plane), set the corner's bit in v5 (v5 |= 1 << v6). [field:this:0x00000024, source:raw]
    // GUARD: If v5 != 0 for the current plane (at least one corner outside), break out of the plane loop. [field:this:0x00000004, source:raw]
    // STATE_TRANSITION: If all 6 planes passed with every corner inside (v5 == 0 each time), write this+0x4 = v3 | 1 (fully visible) and return 0. [field:this:0x00000004, source:raw]
    // GUARD: On the plane where the loop broke: if v5 == 255 (all 8 corners outside that plane) the object is fully culled; otherwise it is partially intersecting. [field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Write this+0x4 = v3 | 2 (fully culled) when v5 == 255, or this+0x4 = v3 | 4 (partial/intersecting) otherwise. [field:this:0x00000004, source:raw]
    // RETURN: Return 0 on both the visible and culled/partial paths. [source:raw]
    // CALL: This function is called by sub_556E70 (0x00556E70) as part of a scene-culling traversal. [caller:0x00556E70, function:0x0054A0A0, source:raw]

    // Conservative worker pseudocode:
    //   int TestFrustumPlanes(float *this, int a2) {
    //     v3 = ((unsigned int)this[1]) & 0xFFFFFFF0;
    //     ((unsigned int*)this)[1] = v3;
    //     v10 = 0;
    //     for (i = (float*)(a2 + 260); ; i += 4) {
    //       v5 = 0; v6 = 0; v7 = this + 9;
    //       do {
    //         if (-(*(i-2) * *(v7-2)) - *(i-1) * *(v7-1) - *i * *v7 > i[1]) v5 |= 1 << v6;
    //         ++v6; v7 += 3;
    //       } while (v6 < 8);
    //       if (v5) break;
    //       if (++v10 >= 6) { ((unsigned int*)this)[1] = v3 | 1; return 0; }
    //     }
    //     ((unsigned int*)this)[1] = (v5 == 255) ? (v3 | 2) : (v3 | 4);
    //     return 0;
    //   }
    // UNRESOLVED: The frustum plane layout at a2+260 (4 floats: nx, ny, nz, d) is inferred from the pointer arithmetic; no explicit field evidence for a2 offsets exists in the packet.
    // UNRESOLVED: The meaning of the bit flags at this+0x4 (bits 0/1/2) is proposed from the existing analysis and not independently confirmed by the packet.
    // UNRESOLVED: The object type owning this+0x24 corners and this+0x4 flag word is unknown.
}
