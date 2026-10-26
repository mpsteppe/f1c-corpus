## AABBFrustumVisibilityClassification_0054d910 — AABB frustum visibility classification

**Summary:** Classifies an axis-aligned bounding box against frustum planes by testing all 8 corners. Determines whether the AABB is fully visible, fully culled, or intersecting the view frustum. Part of the visibility/culling system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_556B10 (00556b10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Visibility state word; low 3 bits encode result (1=visible, 2=culled, 4=intersecting) |
| this | 0xFC | R | — | Frustum plane count (guard > 0 for culling test loop) |

**Written-by note (persistence):**
- this 0x14: rewritten each call; low 3 bits set to visibility classification result

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[63] (frustum plane count at +0xFC) <= 0, BLOCKED: no culling test performed, defaults to state 1 (visible). If > 0, PASSES: iterates all planes, testing each of 8 AABB corners per plane. If any plane has all 8 corners on the outside (bitmask == 255), state = 2 (culled). If any corner is outside any plane (bitmask != 0 but != 255), state = 4 (intersecting). If no corner is outside any plane, state = 1 (visible).
