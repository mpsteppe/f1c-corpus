// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549FB0
// Canonical corpus name: SphereVsFrustumVisibilityTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SphereVsFrustumVisibilityTest_00549fb0.c

void UnknownObject::SphereVsFrustumVisibilityTest()
{
    // Scene-culling test of a bounding sphere (center at this+0x7C/0x80/0x84, radius at this+0x18) against the caller-supplied view frustum a2. A force-hidden flag mask (this+0x4 bits 4/6) short-circuits to culled; otherwise a bounding-sphere distance test prunes the object, then all six frustum planes are tested. The visibility result is written into the low status bits of this+0x4. Part of the scene culling system.
    // GUARD: Load flags at this+0x4; when (flags & 0x50) is non-zero the object is force-hidden, so set bit 1 (culled) via flags | 2 and return 0. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the sphere center relative to the frustum bounding volume: cx = a2[9] + *(this+0x7C), cy = a2[10] + *(this+0x80), cz = a2[11] + *(this+0x84). [field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, source:raw]
    // ASSIGNMENT: Clear the four low status bits of this+0x4: flags & 0xFFFFFFF0. [field:this:0x00000004, source:raw]
    // GUARD: Bounding-sphere distance test: when sqrt(cx*cx + cy*cy + cz*cz) - radius(this+0x18) exceeds a2[2], set bit 3 (sphere-culled) via flags | 8 and return 0. [field:this:0x00000018, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Mark bit 0 (visible): this+0x4 = flags & 0xFFFFFFF0 | 1. [field:this:0x00000004, source:raw]
    // LOOP: Iterate the six frustum plane equation blocks starting at a2 + 65, advancing 4 floats per plane. [source:raw]
    // CALCULATION: For each plane compute the signed distance v11 = -(nx * cx) - (ny * cy) - (nz * cz) - d from the plane coefficients. [source:raw]
    // GUARD: When v11 > radius(this+0x18) the sphere is fully outside this plane: set bit 1 (culled) via flags & 0xFFFFFFFC | 2 and return 0. [field:this:0x00000018, field:this:0x00000004, source:raw]
    // GUARD: When v11 > -radius(this+0x18) the sphere straddles this plane, so break out of the plane loop. [field:this:0x00000018, source:raw]
    // LOOP: If the plane counter reaches 6 without a straddle or outside case, the sphere was inside every plane: return 0 as fully visible. [source:raw]
    // ASSIGNMENT: After the plane loop, set bit 2 (partial visibility): this+0x4 = flags & 0xFFFFFFFA | 4, then return 0. [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   int TestSphereAgainstFrustum(void* this, float* frustum) {
    //     flags = *(this+4);
    //     if (flags & 0x50) { *(this+4) = flags | 2; return 0; }
    //     cx = frustum[9] + *(this+0x7C);
    //     cy = frustum[10] + *(this+0x80);
    //     cz = frustum[11] + *(this+0x84);
    //     *(this+4) = flags & 0xFFFFFFF0;
    //     if (sqrt(cx*cx + cy*cy + cz*cz) - *(this+0x18) <= frustum[2]) {
    //       flags = flags & 0xFFFFFFF0 | 1;
    //       *(this+4) = flags;
    //       for (plane = 0; plane < 6; ++plane) {
    //         p = frustum + 65 + plane*4;
    //         dist = -(p[-2]*cx) - (p[-1]*cy) - (p[0]*cz) - p[1];
    //         if (dist > *(this+0x18)) { *(this+4) = flags & 0xFFFFFFFC | 2; return 0; }
    //         if (dist > -*(this+0x18)) break;
    //       }
    //       if (plane == 6) return 0;
    //       *(this+4) = flags & 0xFFFFFFFA | 4;
    //     } else {
    //       *(this+4) = flags & 0xFFFFFFF0 | 8;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The frustum argument a2 layout (bounding radius at a2[2], sphere offset at a2[9..11], plane block at a2+65) is caller-defined; only the used indices are evidenced here.
    // UNRESOLVED: The bit semantics of the visibility flags at this+0x4 beyond the force-hidden 0x50 mask are inferred from the branch structure, not independently confirmed.
}
