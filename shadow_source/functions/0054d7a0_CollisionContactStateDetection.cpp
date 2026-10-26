// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D7A0
// Canonical corpus name: CollisionContactStateDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionContactStateDetection_0054d7a0.c

void UnknownObject::CollisionContactStateDetection()
{
    // Computes the distance between two collision feature offsets, then classifies the contact state stored in the low bits of the state word at this+20 (1 = potential contact, 2 = separated, 4 = contact). Bit 0x10 of the state word selects a plane-based contact path; otherwise a simple inner/outer radius test decides. The plane path evaluates per-plane distance equations against a threshold and rewrites the state accordingly. Always returns 0.
    // CALCULATION: Compute relative distance components v8/v7/v5 by adding a2[9..11] to the a3 vector components. [source:raw]
    // CALCULATION: Compute the distance magnitude v15 = sqrt(v8*v8 + v7*v7 + v5*v5). [source:raw]
    // GUARD: Branch on bit 0x10 of the state word at this+20 to select the plane-based contact mode path. [source:raw, field:this:0x00000014]
    // GUARD: Simple path: if inner radius at this+244 < v15 < outer radius at this+248, classify as contact. [source:raw, field:this:0x000000F4, field:this:0x000000F8]
    // STATE_TRANSITION: Set the state word to (v6 & 0xFFFFFFF8) | 4, encoding the contact state in the low bits. [source:raw, field:this:0x00000014]
    // STATE_TRANSITION: Fall through of the simple path sets the state word to (v6 & 0xFFFFFFF8) | 2, encoding separated. [source:raw, field:this:0x00000014]
    // GUARD: Contact mode: if plane count at this+252 > 4 and v15 - threshold at this+24 > a2[2], or (when a4 is zero) the radius test scaled by a2[34] fails, jump to the separated path. [source:raw, field:this:0x000000FC, field:this:0x00000018]
    // STATE_TRANSITION: Otherwise set the state word to (v6 & 0xFFFFFFF8) | 1, encoding potential contact, and remember it as v10. [source:raw, field:this:0x00000014]
    // GUARD: If the plane count at this+252 <= 0, return 0 without evaluating any plane. [source:raw, field:this:0x000000FC]
    // LOOP: Iterate over collision planes starting at a2[65], stepping 4 floats per plane (a plane holds two normal components, a remaining normal component, and a distance term). [source:raw]
    // CALCULATION: Compute v13 = -(planeNormalX * a3[0]) - (planeNormalY * a3[1]) - (planeNormalZ * a3[2]) - planeDistance. [source:raw]
    // GUARD: If v13 > threshold at this+24, set the state word to (v10 & 0xFFFFFFFC) | 2 and return 0. [source:raw, field:this:0x00000018]
    // GUARD: If v13 > -threshold at this+24, break out of the plane loop to the contact result; otherwise continue iterating. [source:raw, field:this:0x00000018]
    // STATE_TRANSITION: After the plane loop, set the state word to (v10 & 0xFFFFFFFA) | 4 (contact bit set) and return 0. [source:raw, field:this:0x00000014]
    // RETURN: All reachable paths return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionContactStateDetection(int this, float* a2, float* a3, int a4) {
    //     float v8 = a2[9] + a3[0], v7 = a2[10] + a3[1], v5 = a2[11] + a3[2];
    //     float v15 = sqrtf(v8*v8 + v7*v7 + v5*v5);
    //     unsigned state = *(unsigned*)(this+20);
    //     if ((state & 0x10) == 0) {
    //       if (*(float*)(this+244) < v15 && v15 < *(float*)(this+248)) {
    //         *(unsigned*)(this+20) = (state & 0xFFFFFFF8) | 4; return 0;
    //       }
    //       *(unsigned*)(this+20) = (state & 0xFFFFFFF8) | 2; return 0;
    //     }
    //     int planes = *(int*)(this+252);
    //     if (planes > 4 && v15 - *(float*)(this+24) > a2[2]
    //         || !a4 && (*(float*)(this+248)*a2[34] < v15 || *(float*)(this+244)*a2[34] >= v15)) {
    //       *(unsigned*)(this+20) = (state & 0xFFFFFFF8) | 2; return 0;
    //     }
    //     unsigned potential = (state & 0xFFFFFFF8) | 1;
    //     *(unsigned*)(this+20) = potential;
    //     if (planes <= 0) return 0;
    //     for (int n = 0; n < planes; ++n) {
    //       float* p = a2 + 65 + 4*n;
    //       float v13 = -(p[-2]*a3[0]) - p[-1]*a3[1] - p[0]*a3[2] - p[1];
    //       if (v13 > *(float*)(this+24)) { *(unsigned*)(this+20) = (potential & 0xFFFFFFFC) | 2; return 0; }
    //       if (v13 > -*(float*)(this+24)) break;
    //     }
    //     *(unsigned*)(this+20) = (potential & 0xFFFFFFFA) | 4;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic roles of a2[2], a2[34], and the plane block (a2[63..66] per plane) are caller-defined and not resolvable here.
    // UNRESOLVED: Meaning of bit 0x10 of the state word that switches between the two classification algorithms is not documented.
    // UNRESOLVED: Whether the final low-bit pattern (v10 & 0xFFFFFFFA) | 4 encodes a distinct contact sub-state is unknown.
    // UNRESOLVED: Relationship between this+244/this+248 radii and the caller's collision geometry is unverified.
}
