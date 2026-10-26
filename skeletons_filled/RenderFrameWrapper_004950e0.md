## RenderFrameWrapper_004950e0 — Simple render frame wrapper

**Summary:** Performs a minimal render frame operation: initializes timing, draws via render device (sub_553700), and resets timing. Lacks StateFlagComputation call compared to similar frame functions (00495020, 00495080).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneEntityCleanup (00497100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde18 | dword_7CDE18 | R | SurfaceRef2 [DERIVED] (also: � surface 2 refs) |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9f00 | ConditionalInit | Initializes timing/conditional state before render |
| 00553700 | sub_553700 | Performs render/draw operation via render device |

**Guard conditions:** No guard conditions; always executes all steps unconditionally.
