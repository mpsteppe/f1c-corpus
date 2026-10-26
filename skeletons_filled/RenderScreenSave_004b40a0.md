## RenderScreenSave_004b40a0 — RenderScreenSave

**Summary:** Captures screenshot when 'X' key is pressed: saves screen to season or default directory path, displays "Screen Saved" message. Always runs CameraViewportRenderSetup, VehicleVisibilityCulling, and final render call. Called each frame from GamePostMainLoop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d240c | aScreenSaved | R | "Screen Saved" text string |
| 005ea438 | byte_5EA438 | R | Default application directory (fallback screenshot path) |
| 005ec478 | dword_5EC478 | R | Season-specific directory (primary screenshot path) |
| 005ec4c0 | byte_5EC4C0 | R | Empty string buffer (string table search input) |
| 005ec4cc | byte_5EC4CC | RW | Message display buffer — "Screen Saved" text copied here |
| 007cb218 | dword_7CB218 | R | Input device count (number of devices to scan) |
| 007cb21c | word_7CB21C | R | Input action keycodes array (scanned for key 'X' = 88) |
| 007cd204 | dword_7CD204 | R | Resource dispatch handle for text rendering |
| 008afe88 | dword_8AFE88 | R | Collision geometry handle (passed to final render call) |
| 008affc8 | unk_8AFFC8 | R | Network replay packet data (viewport setup input) |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr (D3D device/renderer interface) |
| 008b8dd4 | dword_8B8DD4 | R | Screen width for screenshot |
| 008b8dd8 | dword_8B8DD8 | R | Screen height for screenshot |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Look up "Screen Saved" in string table for localization |
| 0045bd10 | TextLineWrappingAndRendering | Render "Screen Saved" message overlay |
| 004b3dc0 | VehicleVisibilityCulling | Cull non-visible vehicles before render |
| 004fbd70 | CameraViewportRenderSetup | Set up camera viewport for frame render |
| 00551fd0 | sub_551FD0 | Save screen capture to file (screenshot) |

**Guard conditions:** 
1. Scans all input devices for keycode 'X' (88). Only fires screenshot when X is pressed.
2. If dword_5EC478 (season path) is zero, falls back to byte_5EA438 (default app directory).
3. Screenshot save (sub_551FD0) must succeed before "Screen Saved" message is displayed.
4. CameraViewportRenderSetup, VehicleVisibilityCulling, and final render call always execute regardless of screenshot key state.
