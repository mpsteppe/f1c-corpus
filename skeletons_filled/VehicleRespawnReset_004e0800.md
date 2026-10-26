## VehicleRespawnReset_004e0800 — VehicleRespawnAndStateReset

**Summary:** Resets vehicle state on respawn or race restart: clears collision/contact data, computes random respawn delay from noise table, reinitializes vehicle sub-structs, resets gear-change animation timer, zeroes force accumulators, and dispatches per-contact-zone state reset via ConditionalDispatchByFlag.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | postProcessInput / AI active flag (<=1 = not in active race) |
| obj | 0x4894 | R | — | vehicle unique ID / session index (for progress bar event) |
| this | 0x0 | R | — | vehicle pointer / base object reference |
| this | 0x898 | R | — | contact/collision zone enable flag (0 = no zones active) |
| this | 0x8A4 | R | — | existing collision state flag (non-zero = had prior collision) |
| this | 0x8B4 | R | — | contact zone count (number of active collision contact zones) |
| this | 0x8B8 | R | — | contact zone handle array start (zone 0) |
| this | 0x8C4 | R | — | contact zone parameter array start (zone 0 params) |
| this | 0x934 | RW | 0 | collision force accumulator X (zeroed on reset) |
| this | 0x938 | RW | 0 | collision force accumulator Y |
| this | 0x93C | RW | 0 | collision force accumulator Z |
| this | 0x940 | RW | 0 | collision torque accumulator X |
| this | 0x944 | RW | 0 | collision torque accumulator Y |
| this | 0x948 | RW | 0 | collision torque accumulator Z |
| this | 0x94C | RW | — | random respawn timer delay (computed from noise table) |
| this | 0x964 | R | — | audio sound effect handle / ID |
| this | 0x96C | RW | 1 | vehicle respawn active flag (set to 1 = respawning) |
| this | 0x96D | RW | 1 | vehicle state reset flag (set to 1 = reset in progress) |
| this | 0x974 | RW | 0 | respawn sub-state flag (zeroed) |
| this | 0x979 | RW | 0 | post-respawn completion flag (zeroed) |
| this | 0x980 | RW | 18446744073709551615 | collision handle sentinel (set to -1 = invalid) |
| this | 0x984 | RW | 18446744073701163007 | collision state sentinel (set to -8388609 = cleared marker) |
| this | 0x988 | RW | — | gear change animation speed (32.0 / max(gearDuration, 1.0)) |
| this | 0x98C | RW | 0 | post-reset zone clear flag (read from this[2444]) |
| this | 0x990 | RW | 0 | post-reset zone data start (17 entries × 28 bytes, zeroed) |

**Written-by note (persistence):**
- this 0x934: recalc every frame — external poke does NOT persist
- this 0x938: recalc every frame — external poke does NOT persist
- this 0x93C: recalc every frame — external poke does NOT persist
- this 0x940: recalc every frame — external poke does NOT persist
- this 0x944: recalc every frame — external poke does NOT persist
- this 0x948: recalc every frame — external poke does NOT persist
- this 0x94C: recalc every frame — external poke does NOT persist
- this 0x96C: recalc every frame — external poke does NOT persist
- this 0x96D: recalc every frame — external poke does NOT persist
- this 0x974: recalc every frame — external poke does NOT persist
- this 0x979: recalc every frame — external poke does NOT persist
- this 0x980: recalc every frame — external poke does NOT persist
- this 0x984: recalc every frame — external poke does NOT persist
- this 0x988: recalc every frame — external poke does NOT persist
- this 0x98C: recalc every frame — external poke does NOT persist
- this 0x990: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 005ad150 | flt_5AD150 | R | AITimerRandomScale [DERIVED] |
| 007cf740 | flt_7CF740 | R | GearChangeAnimDuration [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | encode respawn event into HUD progress-bar ring buffer |
| 004e0db0 | MultiSystemStructInitializer | reinitialize multiple vehicle sub-structs on respawn |
| 004e0ed0 | AudioSoundEffectController | trigger respawn sound effect by audio handle |
| 004e2ca0 | ScalePropagate | propagate a scale factor (1.0 = identity) through dependent systems |
| 004e3890 | StateArrayReset | reset vehicle state array entries (full respawn path, a2 != 0) |
| 005506a0 | sub_5506A0 | clear/reset prior collision state system |
| 00551810 | ConditionalDispatchByFlag | conditionally reset per-contact-zone state based on zone handle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | <= | 1 | postProcessInput: <=1 (not in active AI race) PASSES → encode progress bar event; >1 BLOCKS |
| this | 0x8B4 | > | 0 | contact zone count: >0 PASSES → iterate and dispatch zone resets; ==0 BLOCKS (skip loop) |

**Guard interpretation:** obj+0x32C8 <= 1 allows progress bar event encoding only when AI is not actively racing (e.g., practice/qualifying or spectator). this+0x8B4 > 0 gates the per-zone state reset loop — only runs when there are active collision contact zones to clear.
