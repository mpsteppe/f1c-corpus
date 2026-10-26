## MultiStepInitSequence_00495020 — Render frame with state flag computation

**Summary:** Performs a render frame operation: initializes timing, draws via render device (sub_553700), computes state flags (StateFlagComputation), and resets timing. Used in file loading retry loop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileLoadWithRetryLoop (004f9b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde24 | dword_7CDE24 | R | TexSurfaceRef3 [DERIVED] (also: � surface 3 refs) |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9b30 | StateFlagComputation | Computes internal state flags after render |
| 004f9f00 | ConditionalInit | Initializes timing/conditional state before render |
| 00553700 | sub_553700 | Performs render/draw operation via render device |

**Guard conditions:** No guard conditions; always executes all steps unconditionally.
