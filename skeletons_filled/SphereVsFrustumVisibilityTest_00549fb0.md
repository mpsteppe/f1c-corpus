## SphereVsFrustumVisibilityTest_00549fb0 — Test sphere visibility against view frustum

**Summary:** Tests whether a bounding sphere (center at this+0x7C, radius at this+0x18) is visible within a 6-plane view frustum. First checks a "force hidden" flag at this+0x4 bits 4 or 6; if clear, performs sphere-sphere distance check against frustum bounding volume, then tests against all 6 frustum planes. Writes visibility result into flag bits at this+0x4. Part of scene culling system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_556E70 (00556e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Visibility flag word: bit0=visible, bit1=culled, bit2=partial, bit3=sphere-culled, bits4/6=force-hidden override |
| this | 0x18 | R | — | Bounding sphere radius for plane distance tests |
| this | 0x7C | R | — | Bounding sphere center X coordinate |
| this | 0x80 | R | — | Bounding sphere center Y coordinate |
| this | 0x84 | R | — | Bounding sphere center Z coordinate |

**Written-by note (persistence):**
- this 0x4: written every call with visibility result (bits 0-3 updated); force-hidden bits (4,6) survive if already set but function early-returns

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this+0x4 & 0x50` (bits 4 or 6 set) → sets bit 1 (culled) and returns immediately — object is force-hidden regardless of position. Sphere-sphere test: if distance from (this+0x7C + frustum offset) exceeds frustum radius + sphere radius, sets bit 3 (sphere-culled). Per-plane loop (6 frustum planes): for each plane, if sphere is entirely outside (`plane_dist(this.center) > radius`) → sets bit 1 (plane-culled); if sphere intersects plane (`plane_dist > -radius`) → breaks loop and sets bit 2 (partial visibility). Sphere fully inside all 6 planes → bit 0 set (fully visible).
