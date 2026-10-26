## ShortComputation_3ca0_00423ca0 — ComputeRelativeVelocityComponents

**Summary:** Decomposes target vehicle velocity into longitudinal and lateral components relative to a given direction (a2, a4). Computes signed projection magnitude (minus offset a5) into this[6] and signed perpendicular magnitude into this[4]. Used by AI steering for passing/overtaking decisions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x34F8 | R | — | target vehicle velocity X from this[0] dereference |
| obj | 0x3500 | R | — | target vehicle velocity Y |
| this | 0x0 | R | — | indirection pointer to target vehicle object |
| this | 0x10 | RW | — | lateral relative velocity component (perpendicular to direction) |
| this | 0x18 | RW | — | longitudinal relative velocity component minus a5 (parallel to direction) |

**Written-by note (persistence):**
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — both computations always execute. No early return path.
