## PhysicsTreeMassPropagation_00448de0 — Physics mass property propagation across collision tree

**Summary:** Propagates mass properties through a collision tree by blending a physics value (offset 0x10) toward a target value (offset 0x4) by half each step, then recursing into children and following the sibling chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactResponse (00449700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Source/target mass property value for blending |
| this | 0x10 | RW | — | Current mass property value being lerped toward target |
| this | 0x4C | R | — | Pointer to first child node (child[0]) |
| this | 0x5C | R | — | Pointer to sibling/next node in tree chain |

**Written-by note (persistence):**
- this 0x10: Written each call with lerp result; survives as long as pointer remains valid

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) — 0.5 blend factor for mass lerp |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448de0 | PhysicsTreeMassPropagation | Recursive self-call to process each non-null child node |

**Guard conditions:** Child pointers at this+0x4C (4 slots) — null child skipped. Sibling link at this+0x5C — null terminates loop.
