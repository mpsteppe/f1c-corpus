## CollisionMaterialCoefficientsSet4_0044ec60 — CollisionInitBlockR

**Summary:** Initializes eighteenth collision block (dword_7CA4A0–7CA4B4). Sets tag to 100, zeros material/render fields, sets collision world range to 18000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca4a0 | dword_7CA4A0 | W | CollisionMaterialID [DERIVED] |
| 007ca4a4 | dword_7CA4A4 | W | Zeroed material field |
| 007ca4a8 | dword_7CA4A8 | W | Zeroed material field |
| 007ca4ac | dword_7CA4AC | W | Zeroed material field |
| 007ca4b0 | dword_7CA4B0 | W | RenderStateDwordPair [DERIVED] |
| 007ca4b4 | dword_7CA4B4 | W | CollisionWorldRange [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
