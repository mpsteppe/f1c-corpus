# Safety Car Plugin v3 for F1 Challenge 99-02

Adds safety car deployment to the game via the `oph.dll` plugin slot.

## Status: TESTING REQUIRED

v3 adds speed governor and probe diagnostics but key offsets are GUESS tier.
Run the probe (NUM5 in-game) and check `LOG\safety_car.txt` before trusting
speed control.

## What It Does

- Monitors for DNFs during a race; deploys safety car automatically
- Forces AI to reduced speed via two layers:
  1. Built-in `SafetyCarFollow` flag at `+0x443c` (game's cut feature)
  2. Direct `liveLapRatio` clamp at `+0x453C` (speed governor)
- Injects AI command `0xe` ("safety car") into AI command queues
- Safety car stays out for ~3 laps, then withdraws
- Restores original AI speed ratios on withdrawal
- Optional physical SC vehicle (car #99)

## Hotkeys (during race)

| Key | Action |
|-----|--------|
| NUM8 | Deploy safety car |
| NUM2 | Withdraw safety car / skip cooldown |
| NUM5 | Dump diagnostic probe to log |

## Installation

1. Build `oph.dll` (MinGW or MSVC)
2. Copy `oph.dll` to game directory (next to `F1 Challenge Online.exe`)
3. Optional: copy `zzz_safety_car.veh` into a season directory for a physical SC car

## Phase 1 Verification Checklist

Run the game, start a race, press NUM5, then check `LOG\safety_car.txt`:

- [ ] `live_lap_ratio` shows float values ~0.85-1.0 (confirms offset is correct)
- [ ] `base_speed` shows float values ~0.0-1.0 (confirms offset)
- [ ] `behavior` shows int values 0-7 (confirms offset)
- [ ] `safety_follow` reads 0 before deployment (confirms offset)
- [ ] Deploy with NUM8: AI visibly slows down
- [ ] `safety_follow` reads 1 after deployment
- [ ] `live_lap_ratio` reads ~0.60 after deployment
- [ ] Withdraw with NUM2: AI resumes normal speed
- [ ] `live_lap_ratio` restored to saved values

If `live_lap_ratio` shows garbage (very large/small numbers, NaN), the
byte offset 0x453C is wrong — consult the probe raw bytes dump to find
the actual location.

## Known Limitations

- Speed governor offset (0x453C) is GUESS tier — may need adjustment
- No yellow flag visuals (marshal posts don't change)
- No overtaking enforcement (AI follow mode reduces but doesn't prevent)
- No pit lane closure during SC
- No unlapping procedure
- No proper rolling restart
- SC vehicle uses existing car model (no dedicated safety car 3D model)

## Files

| File | Purpose |
|------|---------|
| `oph.c` | Plugin source (C99) |
| `zzz_safety_car.veh` | SC vehicle definition (car #99) |
| `facts.json` | Preflight verification fact set |
| `Makefile` | Build targets |
