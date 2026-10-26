## F_4ComponentVectorNormalize_0051f160 — Vec4NormalizeNewtonRaphson

**Summary:** Unconditionally normalizes a 4-component float vector using Newton-Raphson refined reciprocal square root. Computes squared length of input (a2), applies inverse sqrt with refinement using global constants dword_5D8A40 and dword_5D8A30, scales all 4 components, and stores result in output (a1). Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output vector X component |
| this | 0x4 | RW | — | Output vector Y component |
| this | 0x8 | RW | — | Output vector Z component |
| this | 0xC | RW | — | Output vector W component |

**Written-by note (persistence):**
- this 0x0: unconditionally written with normalized X; survives as output
- this 0x4: unconditionally written with normalized Y; survives as output
- this 0x8: unconditionally written with normalized Z; survives as output
- this 0xC: unconditionally written with normalized W; survives as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8a30 | dword_5D8A30 | R | Newton-Raphson refinement coefficient |
| 005d8a40 | dword_5D8A40 | R | Normalization subtractive constant for refinement |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always normalizes unconditionally.
