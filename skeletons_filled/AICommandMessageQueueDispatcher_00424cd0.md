## AICommandMessageQueueDispatcher_00424cd0 — AICommandMessageQueueDispatcher

**Summary:** Dispatches AI commands via a switch-based message handler then manages a deduplicated command queue. Handles AI state transitions (cases 4, 5), timer setup (case 1), and race-phase-dependent cleanup (case 15). Deduplicates pending commands before enqueueing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStructInit (00424790), CameraViewportFrustumInitialization (00424b20), sub_426430 (00426430), PitStopProgress (004a68b0), TimerFrameRateThrottle (004d3740), TrackTemperatureDisplay (004d37b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4064 | R | — | FinishState of object referenced by this[0] (indirect access) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — pointer to inner struct |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x413C | RW | — | timer field — set to sessionTime + 2.0 for delayed action |
| this | 0x4410 | R | — | RetiredFlag [FACT] |
| this | 0x44A8 | R | — | pointer to command queue buffer (array of 8-byte {cmd, param} pairs) |
| this | 0x44AC | R | — | maximum capacity of command queue |
| this | 0x44B0 | RW | 18446744073709551615 | current queue index (-1 = empty/processed; init value is max uint32) |
| this | 0x4544 | RW | 0 | reset flag — cleared in case 15 handler |
| this | 0x4548 | RW | 1 | active byte flag — 0 in case 5/1 in case 15 |
| this | 0x4550 | RW | 1 | state marker — set to 1 in case 15 |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00429ee0 | CommandQueueResponseHandler | processes enqueued command after it's added to queue |
| 0042acd0 | ParameterValueSetter | writes parameter value 18 (part of case 15 cleanup) |
| 0042adb0 | SessionCleanupFlagClear | clears cleanup flags when race is still active |
| 004a46f0 | sub_4A46F0 | transitions AI to/from a state (triggered by commands 4 and 5) |
| 004a5c80 | StateChangeNotify | notifies of state change when race is effectively over |
| 004c6d90 | SceneRenderUpdate | triggers scene render update for end-of-race display |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x4064 | == | 0 | FinishState of inner object == 0 (not finished / still racing) |
| this | 0x4064 | == | 2 | FinishState [FACT] == DNF (did not finish) |

**Guard interpretation:** For case 15: when session type is 7 AND referenced FinishState != 0, OR session type is not 7 AND race phase == 8, the condition fails (v4=false), triggering end-of-race screen (SceneRenderUpdate + StateChangeNotify). Otherwise (v4=true and race still active), clears cleanup flag via SessionCleanupFlagClear.
