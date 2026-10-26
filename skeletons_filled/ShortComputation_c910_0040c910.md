## ShortComputation_c910_0040c910 — FetchFieldFromSubObject

**Summary:** Returns dword at offset 4 from a sub-object pointer stored at this+0x8. Trivial field accessor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30), CarSelectionStateMachine (00434460), sub_49F870 (0049f870), ArithmeticComparison_9000 (004c9000), CameraViewportRenderSetup (004fbd70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | pointer to sub-object |
| this | 0xC | R | — | not accessed by this function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional field read
