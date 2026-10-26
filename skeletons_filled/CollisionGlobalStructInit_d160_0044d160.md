## CollisionGlobalStructInit_d160_0044d160 — CollisionConfigBlockInit

**Summary:** Initializes four collision configuration globals: config block type to 108, two float thresholds to 0.0, and config variable to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf70 | dword_7CCF70 | W | CollisionConfigBlock [DERIVED] (also: ` through `_DAT_007ccf7c` — collision configuration variables) |
| 007ccf74 | flt_7CCF74 | W | RenderState_7CCF74 [DERIVED] |
| 007ccf78 | flt_7CCF78 | W | AudioEngine_MinVol_Type10 [DERIVED] |
| 007ccf7c | dword_7CCF7C | W | CollisionConfigVars [DERIVED] (also: ` — collision configuration variables) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
