# Safety Car Assets — Porting the Real FIA Mercedes from F1 2002

## Finding

F1 2002 (same isiMotor1 engine as F1C) shipped a **complete, real FIA safety
car and medical car** that F1C's retail data does NOT include. Because the
engine and file formats are identical, these assets drop straight into F1C.

Source folder: `F1 2002\Game\Season02\Vehicles\FIA\`

| File | What | Use for SC |
|------|------|-----------|
| `Safgpxa.veh` | Safety car definition — `Driver="Bernd Maylander"`, `Manufacturer="Mercedes-Benz"`, `Classes="Safety, ...NotAI"`, `Number=29` | reference (our `zzz_safety_car.veh` replaces it) |
| `safety.gen` | Safety car 3D model instance file | **yes** |
| `safety.hdv` | Mercedes-Benz physics — `Mass=1800.0`, `GearFile=saf_ratios.ini` | **yes** |
| `saf_ratios.ini` | Gearbox ratios (7 gears + reverse) | **yes** (hdv needs it) |
| `team.mas` | Mercedes-Benz textures (packed, 1.5 MB) | **yes** |
| `Mercedes-Benz_*.bmp/.jpg` | Showroom / garage backdrops | optional (menus) |
| `FIAIcon.bmp`, `safgIcon.bmp` | Icons | optional |
| `Medgpxa.veh`, `medical.hdv`, `MedgIcon.bmp` | **Medical car** (bonus — same deal) | future |

`safety.gen` also pulls `Cdb.mas`, `Cmaps.mas`, `Drivers.mas` from `<VEHDIR>`
and `Team.mas` from `<TEAMDIR>`. `Cdb/Cmaps/Drivers.mas` already exist in F1C's
common vehicle data; `Team.mas` is the FIA folder's Mercedes textures.

## Why F1C doesn't use them

1. **Data stripped:** F1C's retail season directories omit the FIA folder — the
   safety car was cut from shipping content.
2. **No spawn code:** F1C has no full-course-yellow / safety-car system, so no
   engine path loads a `Safety`/`NotAI`-class vehicle. The class filter
   (`FUN_004bf790`, assert `"%s NOT: NotAI"`) still exists and works, but it
   only *excludes* cars from AI selection — it doesn't add a loader.
3. **Result:** the assets are orphaned. The engine can render and simulate them
   fine; nothing references them.

## Install steps

1. Create `<F1C>\GameData\<Season>\SC_Team\` (e.g. `...\F1_2002\SC_Team\`).
2. Copy the FIA folder contents into `SC_Team\`:
   `safety.gen safety.hdv saf_ratios.ini team.mas f1car.mts`
   (plus icons/backdrops if you want menu art).
3. Copy this mod's `zzz_safety_car.veh` into the same `SC_Team\`.
4. Ensure `zzz_safety_car.veh` `Classes=` matches the session's class filter so
   the car spawns (see the .veh header — it must be the RACE class, not NotAI).
5. Build + install `oph.dll` (see README.md). It finds the car by `Number=99`.

## Open test items

- **GenString / texture mapping:** `safety.gen` uses `<123>`/`<ID>` token
  substitution. F1 2002's `Safgpxa.veh` has no `GenString=` line, so the engine
  derives mesh/texture names by default. Verify the model renders in F1C; if it
  shows untextured/missing, add an explicit `GenString=` matching `team.mas`.
- **Class-filter spawn:** confirm the car actually appears in the vehicle array
  (oph.dll `NUM5` probe will show `number=99` in the dump if it spawned).
- **Collision mesh:** `f1car.mts` referenced by both — F1C ships one; verify the
  path resolves.

## Better long-term option

If a future version adds a real caution state machine (ported from NASCAR —
see `plans/investigate-*.md`), wire a dedicated safety-car loader that spawns
the `Safety`/`NotAI` car OUTSIDE the grid, so it doesn't consume a race-entry
slot. That is how F1 2002 intended it. For now, the grid-slot + park approach
is the only one that works without new engine code.
