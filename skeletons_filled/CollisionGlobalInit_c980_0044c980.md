## CollisionGlobalInit_c980_0044c980 — CollisionContactCountInit

**Summary:** Initializes four collision globals: maximum contact count to 10, -1.0f contact sentinel, and two float fields to 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf80 | dword_7CCF80 | W | MaxContactCount [DERIVED] (also: ` — collision global, int = 10) |
| 007ccf84 | flt_7CCF84 | W | VehicleSetupFloat_7CCF84 [DERIVED] |
| 007ccf88 | dword_7CCF88 | W | CollisionContactSentinel [DERIVED] (also: ` — collision global, float = -1.0f) |
| 007ccf8c | flt_7CCF8C | W | Flt_CopilotThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
