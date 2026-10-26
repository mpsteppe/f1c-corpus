## ShortComputation_3db0_00423db0 — ComputeRelativePositionComponents

**Summary:** Decomposes position difference between target vehicle and a reference point (a5, a7) into longitudinal and lateral components relative to direction (a2, a4). Stores signed longitudinal distance in this[3] and signed lateral distance in this[1]. Used by AI steering for spatial awareness.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x34E0 | R | — | target vehicle X position from this[0] dereference |
| obj | 0x34E8 | R | — | target vehicle Y position |
| this | 0x0 | R | — | indirection pointer to target vehicle object |
| this | 0x4 | RW | — | signed lateral distance (perpendicular to direction) |
| this | 0xC | RW | — | signed longitudinal distance (parallel to direction) |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — both computations always execute.
