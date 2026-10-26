## InitMouseAxis_0044e720 — CollisionInitBlockD

**Summary:** Initializes fourth collision block (dword_7CCFC4–7CCFD8). Sets tag to 86, zeros object pointer, material pair, and UI color value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccfc4 | dword_7CCFC4 | W | CollisionObjectPtr [DERIVED] |
| 007ccfc8 | dword_7CCFC8 | W | Zeroed collision state field |
| 007ccfcc | dword_7CCFCC | W | Zeroed collision state field |
| 007ccfd0 | dword_7CCFD0 | W | Zeroed collision state field |
| 007ccfd4 | dword_7CCFD4 | W | CollisionMaterialPairB [DERIVED] |
| 007ccfd8 | dword_7CCFD8 | W | UIColorValue_CCFD8 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
