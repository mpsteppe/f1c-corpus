## AudioStateInit_0044e960 — CollisionInitBlockJ

**Summary:** Initializes tenth collision block (dword_7CCA14–7CCA28). Sets tag to 92, zeros audio/UI state fields, sets UI element state to 18000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cca14 | dword_7CCA14 | W | AudioStatePtr [DERIVED] |
| 007cca18 | dword_7CCA18 | W | Zeroed collision state field |
| 007cca1c | dword_7CCA1C | W | Zeroed collision state field |
| 007cca20 | dword_7CCA20 | W | Zeroed collision state field |
| 007cca24 | dword_7CCA24 | W | CollisionMiscFloat [DERIVED] |
| 007cca28 | dword_7CCA28 | W | UIElementState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
