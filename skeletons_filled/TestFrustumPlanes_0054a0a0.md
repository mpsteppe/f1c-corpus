## TestFrustumPlanes_0054a0a0 — Test AABB corners against 6 frustum planes

**Summary:** Tests 8 corner vertices of an axis-aligned bounding box (starting at this+0x24) against 6 view frustum planes. Checks each plane: if all 8 corners are on the negative side, the box is fully culled. If any corner is outside a plane, the box is partially visible. If all corners of all 6 planes are inside, the box is fully visible. Writes result to flag bits at this+0x4. Part of scene culling system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_556E70 (00556e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Visibility flag word: bit0=visible, bit1=fully-culled, bit2=partial/intersecting |
| this | 0x24 | R | — | Start of 8 AABB corner vertices (3 floats each, stride 12 bytes) |

**Written-by note (persistence):**
- this 0x4: written every call with visibility result; lower 4 bits cleared before testing

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-exit guard on inputs — function always runs the full test. Initial lower 4 bits of this+0x4 are cleared unconditionally. Loop breaks when a plane has any vertex outside (`v5 != 0`). If all 6 planes pass with all vertices inside (`v5 == 0` for all), bit 0 set (visible). If break occurs: `v5 == 255` (all 8 vertices outside one plane) sets bit 1 (fully culled); otherwise sets bit 2 (partial).
