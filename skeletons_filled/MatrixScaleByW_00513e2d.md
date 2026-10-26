## MatrixScaleByW_00513e2d — BatchScaleXYZByW

**Summary:** Batch-process 16 float4 vectors: multiply X, Y, Z by W (homogeneous weight). Output W unchanged. Used for 3D perspective/pre-transform vertex weighting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DelegationWithErrorCheck (005158af), InitProcessWrapper (005158e3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | float X — multiplied by W to produce output X |
| this | 0xC | R | — | float W — weight factor for X,Y,Z scaling, passed through as output W |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes 16 iterations unconditionally.
