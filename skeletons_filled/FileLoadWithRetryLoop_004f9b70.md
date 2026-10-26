## FileLoadWithRetryLoop_004f9b70 — FileLoadWithRetryLoop

**Summary:** Loads a file via ObjectCreationWithRollbackOnFailure with path fallback retry. Displays Bink video loading sequence with retry loop until input device detected or video completes. Cleans up resources on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0), sub_4A00A0 (004a00a0), sub_4A0760 (004a0760), sub_4A08E0 (004a08e0), sub_4A09F0 (004a09f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | Returns singleton/global initialization context |
| 00422fd0 | StringFormatReplaceOperation | Replaces path prefix in filename string |
| 004537b0 | sub_4537B0 | Processes module output array with time step |
| 00495020 | MultiStepInitSequence | Runs multi-step initialization sequence |
| 00495060 | GuardedSubsystemRelease | Releases guarded subsystem |
| 00495140 | GlobalAccessor | Returns global context pointer |
| 004a1830 | sub_4A1830 | Unknown (called in retry loop) |
| 004c8580 | VTableMethodGuard | Checks/validates vtable method availability |
| 004c85a0 | VTableDispatchViaGlobal | Dispatches vtable call via global pointer |
| 004c85c0 | NullCheckedVTableCall | Null-checked vtable call |
| 005434a0 | sub_5434A0 | Sets up viewport/scissor rectangle |
| 00551cf0 | BinkVideoFrameRender | Renders Bink video frame |
| 00551eb0 | sub_551EB0 | Configures DSP/audio transform parameter |
| 00551f10 | ObjectCreationWithRollbackOnFailure | Loads file/object with rollback on failure |
| 00551f80 | ConditionalFreeWithBinkClose | Frees loaded object and closes Bink |

**Guard conditions:** First load attempt with original filename; if fails, retries with path-replaced filename. If both fail, returns 1. If `a2` is set, retry loop waits for `dword_7CB218 > 0` (input device connected). Loop exits when BinkVideoFrameRender succeeds.
