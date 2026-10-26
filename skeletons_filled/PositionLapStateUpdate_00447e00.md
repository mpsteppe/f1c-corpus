## PositionLapStateUpdate_00447e00 — PositionLapChangeHandler

**Summary:** Detects position change events (gained/lost positions) during a race, updates position tracking state, triggers appropriate positional change sound effects, and sets UI state machine values for position change display. Part of vehicle/race state system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70), VehicleMainPhysicsUpdate (004441f0), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34 | RW | 6 | Position change UI state (0=none, 2=lost normal, 3=gained normal, 5=lost+lap, 6=gained+lap) |
| this | 0x38 | RW | — | Position change UI param 1 (stored position/lap value) |
| this | 0x3C | RW | — | Position change UI param 2 (stored position/lap value) |
| this | 0x60 | R | — | Current position reference value for UI state |
| this | 0x64 | R | — | Current position reference value for UI state |
| this | 0x1E7C | RW | — | Reference position/lap data for lost-position branch (source A) |
| this | 0x1E80 | RW | — | Reference position/lap data for lost-position branch (source B) |
| this | 0x1E84 | R | — | Reference position/lap data for gained-position branch (source A) |
| this | 0x1E88 | R | — | Reference position/lap data for gained-position branch (source B) |
| this | 0x1E94 | R | — | Lost-position data store A |
| this | 0x1E98 | R | — | Lost-position data store B |
| this | 0x1EF0 | RW | 0 | Position change tracking counter (reset to 0 on change) |
| this | 0x1EF4 | RW | — | Previously stored position (compared against new position) |
| this | 0x1EF8 | RW | 0 | Position change direction (-1 lost, 0 unchanged, 1 gained) |
| this | 0x1F00 | R | — | Sound effect base ID offset for position change sounds |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x1E7C: recalc every frame — external poke does NOT persist
- this 0x1E80: recalc every frame — external poke does NOT persist
- this 0x1EF0: recalc every frame — external poke does NOT persist
- this 0x1EF4: recalc every frame — external poke does NOT persist
- this 0x1EF8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f88a0 | SoundEffectTrigger | Play sound for gained-position event |
| 004f89a0 | SoundEffectTrigger_89a0 | Play sound for lost-position event |

**Guard conditions:** If a2 (new position) equals this[0x1EF4] (stored position), skip entire update (no position change). a2 == -1 triggers retirement/DNF path (delta=1). a2 == 0 triggers no-direction path (delta=0). a2 > 0 sets delta = +1 if gained position, -1 if lost. a3 == 0 sets normal state (2/3), a3 == 4 sets lap-associated state (5/6).
