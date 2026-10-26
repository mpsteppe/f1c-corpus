## MatrixClear_004bdfe0 — GridMatrixClear

**Summary:** Zeroes an 8x8 grid matrix with stride 9 (clearing 64 elements at offsets 1, 10, 19, ...) and resets the cell count at this[577] to 0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LoopWithConditionalSkipFunction (00410980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | first grid cell entry in strided matrix |
| this | 0x904 | RW | 0 | cell count / total entries counter |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x904: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always clears the entire matrix.
