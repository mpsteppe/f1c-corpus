## ArithmeticComparison_a630_0053a630 — LoadFourGlobalPtrs

**Summary:** Loads four global pointer constants (dword_5DA998, dword_5DA99C, unk_5DA9A0, unk_5DB9A0) into output parameters. Returns 0. Part of initialization/tables setup for Huffman table building in inflate decompression.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_537110 (00537110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | first output parameter, receives dword_5DA998 value |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da998 | dword_5DA998 | R | GetterReturnConstant [DERIVED] |
| 005da99c | dword_5DA99C | R | StringTablePtr [DERIVED] |
| 005da9a0 | unk_5DA9A0 | R | D3D_Shader_StateFuncs [DERIVED] |
| 005db9a0 | unk_5DB9A0 | R | RenderLightingTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — function always executes fully with no early returns.
