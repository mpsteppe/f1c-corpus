## PitStopOperationTimer_004a6340 — Pit Stop Operation Timer & Sequence Coordinator

**Summary:** Manages pit stop operation timing per frame — computes max duration of all pending operations (tire change, jack, wheel gun, refueling), tracks progress, dispatches audio/visual effects, and handles crew condition checks. Pit stop system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xCD4 | R | — | pit stop blocking condition flag (from PitStopBlockingCondition) |
| obj | 0x1054 | R | — | pit stop blocked input (audio effect dispatch gate) |
| obj | 0x105C | RW | 0 | pit stop audio effect dispatched flag (cleared after playing sound) |
| obj | 0x32C8 | R | — | pit stop active state (1 = currently in pit stop) |
| obj | 0x403C | R | — | current lap number |
| obj | 0x4040 | R | — | pit stop type (2 = regular stop, adjusts part indexing) |
| this | 0x0 | R | — | vehicle object pointer (cast from float) |
| this | 0x4 | R | — | audio/sound effect object pointer |
| this | 0x8 | R | — | physics channel / crew member reference |
| this | 0x2C | R | — | pit stop active flag (non-zero = pit stop in progress) |
| this | 0x58 | R | — | part array sub-struct for NthValidPartLookup |
| this | 0x60 | R | — | previous tire change state (compared for change detection) |
| this | 0x6C | R | — | timing offset value (used in base time computation) |
| this | 0xAC | R | — | wheel gun crew sub-struct pointer (for gun operation timing) |
| this | 0xD8 | R | — | time step factor (double, for delta-time scaling) |
| this | 0xE0 | R | — | time accumulator base (double) |
| this | 0xEC | R | — | previous tire change state (read for comparison) |
| this | 0xF0 | RW | — | current tire change state (updated when change detected) |
| this | 0x12C | R | — | jack operation active flag (non-zero = jack in use) |
| this | 0x158 | R | — | part list pointer (for NthValidPartLookup) |
| this | 0x160 | R | — | part count |
| this | 0x164 | R | — | part slot entry value (signed, -1 sentinel = invalid) |
| this | 0x168 | R | — | valid part count (number of parts with non-negative IDs) |
| this | 0x18C | R | — | pit entry session time (used for base timer calc) |
| this | 0x1A0 | R | — | per-frame time delta (dt) |
| this | 0x1B0 | RW | — | computed operation timing value (from vehicle ref offset 0x3984) |
| this | 0x1B4 | RW | — | computed jack operation start time |
| this | 0x1B8 | RW | — | computed base time (from timing offset + accumulator) |
| this | 0x1BC | RW | 1 | operation flag: progress bar active |
| this | 0x1C0 | RW | 0 | operation flag: physics channel processing pending |
| this | 0x1C4 | RW | 0 | operation flag: wheel gun sequence active |
| this | 0x1C8 | RW | 0 | operation flag: tire change sequence active |
| this | 0x1CC | RW | 0 | operation flag: jack sequence active |
| this | 0x1D0 | RW | — | stored reference (copied from this+0x1A0) |
| this | 0x1D4 | RW | — | computed total operation duration offset |

**Written-by note (persistence):**
- obj 0x105C: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0x1B0: recalc every frame — external poke does NOT persist
- this 0x1B4: recalc every frame — external poke does NOT persist
- this 0x1B8: recalc every frame — external poke does NOT persist
- this 0x1BC: recalc every frame — external poke does NOT persist
- this 0x1C0: recalc every frame — external poke does NOT persist
- this 0x1C4: recalc every frame — external poke does NOT persist
- this 0x1C8: recalc every frame — external poke does NOT persist
- this 0x1CC: recalc every frame — external poke does NOT persist
- this 0x1D0: recalc every frame — external poke does NOT persist
- this 0x1D4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e918 | flt_59E918 | R | ProximityDistThreshold [DERIVED] |
| 0059e960 | flt_59E960 | R | BrakeBiasThreshold [DERIVED] |
| 0059e994 | flt_59E994 | R | AIPerfThreshold [DERIVED] |
| 005acb54 | flt_5ACB54 | R | ScoringTimeTolerance [DERIVED] |
| 005acb58 | flt_5ACB58 | R | FloatConstantPair [DERIVED] |
| 005acb5c | flt_5ACB5C | R | ToleranceOffset [DERIVED] (also: ` — float, tolerance offset) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aee0 | PitStopBlockingCondition | check if pit stop is blocked (returns true if blocked) |
| 004a34a0 | PerElementConditionalActionDispatcher | dispatch per-element conditional actions on crew channel |
| 004a3560 | FlagSetterWithOR | set flags via bitwise OR on target memory |
| 004a35f0 | sub_4A35F0 | process operation timing data on physics channel |
| 004a3820 | PhysicsChannelProcessingWithLocals | forward physics channel data with local float array |
| 004a5820 | NthValidPartLookup | find the Nth valid (non-sentinel) part in part list |
| 004b33b0 | ProgressBarEventEncode | encode progress bar event into ring buffer |
| 004bbf20 | ProgressBarIncrement | increment pit stop progress bar value |
| 004d7570 | CompoundIndexLookup | lookup compound index for part type |
| 004e0ed0 | AudioSoundEffectController | trigger pit stop audio sound effect |
| 004f1860 | ConditionalMathDispatch | dispatch math computation with conditional check |
| 004f1890 | SpeedValueSetterWithGlobalMirror | set speed value and mirror to global (non-race session) |
| 004f1a60 | LoopWithConditionalSubCall | iterate with conditional sub-call for part processing |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 1 | pit stop is currently active |
| obj | 0x4040 | == | 2 | pit stop type is regular stop (affects part indexing) |
| this | 0x164 | >= | 0 | part slot ID is valid (non-negative, not sentinel) |
| this | 0x168 | > | 0 | at least one valid part exists in the list |

**Guard interpretation:** `obj+0x32C8 == 1` → pit stop active. PASSES: enters progress-bar-increment branch (short path, no timing computation). BLOCKED: pit stop not active → enters full timing computation branch. `obj+0x4040 == 2` → regular pit stop type. PASSES: increments lap index by 1 for part lookup. `this+0x164 >= 0` → valid part slot. PASSES: processes the slot, invalidates subsequent slots. BLOCKED (< 0): sentinel/invalid slot, skips. `this+0x168 > 0` → has parts. PASSES: enters part processing loop. BLOCKED: no parts, skips part-related logic.
