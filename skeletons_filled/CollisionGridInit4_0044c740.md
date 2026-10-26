## CollisionGridInit4_0044c740 — CollisionGridSize4Init

**Summary:** Initializes four collision grid globals: grid size to 4, -1.0f sentinel, and two float fields to 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca470 | dword_7CA470 | W | CollisionGridSize (4) [DERIVED] |
| 007ca474 | flt_7CA474 | W | ZeroFloat [DERIVED] (also: ` — zero) |
| 007ca478 | dword_7CA478 | W | MinusOneSentinel [DERIVED] (also: ` — -1.0f sentinel) |
| 007ca47c | flt_7CA47C | W | VecInitZero [DERIVED] (also: ` — zero) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
