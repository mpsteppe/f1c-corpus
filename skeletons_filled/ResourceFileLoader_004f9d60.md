## ResourceFileLoader_004f9d60 — LoadResourceWithTimedLoadingScreen

**Summary:** Loads a resource from either direct path or default directory + override path; if resource not immediately available, displays a timed loading animation with optional input polling that breaks early on user input.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0), sub_496380 (00496380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004537b0 | sub_4537B0 | poll/process input messages with 50ms timeout |
| 00494fb0 | ShortComputation_4fb0 | open/validate resource file, return handle in out param |
| 00494fd0 | ThunkToFUN0053cb90 | release/free loaded resource handle |
| 00495080 | sub_495080 | present/swap display buffers |
| 004950c0 | ShortComputation_50c0 | unknown cleanup after resource load |
| 00495150 | GlobalAccessor_5150 | get screen width or render-target dimension |
| 004b0170 | EmptyStub_0170 | no-op stub, does nothing |
| 00543250 | ClippedRenderRegion | draw a filled clipped rectangle region |
| 00568ba0 | StructZeroInit_8ba0 | zero-initialize a structure |
| 00568be0 | QPCTimerInitialization | initialize high-precision performance counter |
| 00568d90 | PerformanceCounterDiffWithScaling | get elapsed time in seconds since initialization |
| 0058815f | StringFormatWithBufferOverflowCheck | format string with overflow protection |

**Guard conditions:** First ShortComputation_4fb0 returns 0 (fails) → skip path construction, jump to LABEL_6. Second ShortComputation_4fb0 returns non-zero (succeeds) → return 0 immediately, skip loading screen. v12 == 0 at LABEL_6 → skip entire rendering/timing block. a3 == 0 → skip input polling within timing loop (no early break from user). dword_7CB218 > 0 → break out of timing loop (input device active).
