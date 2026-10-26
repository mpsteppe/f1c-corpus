# 32 — F1C ↔ F1 2002 Feature Diff (portability map)

Same engine (isiMotor1), same architecture, different **bricks**. This is the
symmetric feature diff between F1 Challenge 99-02 and F1 2002 — the two bins that
tell you what could be **ported** in each direction.

- **Bin A** — F1C HAS / F1 2002 LACKS → F1C's unique bricks
- **Bin B** — F1 2002 HAS / F1C LACKS → candidates to port INTO F1C

Method (`cross_binary/`): byte + masked-byte + string matching both directions, then
the decisive **string-absence** filter — a function is a *feature* candidate only when
its meaningful string anchors (config keys, filenames, UI labels, asserts) appear in
**neither** the other binary's whole string table. String-less helper functions are
excluded (not features). ALLCAPS roster/season data excluded (same feature, different data).

Addresses are in the named binary. Source: `source_material/<game>/decompiled/` (F1 2002),
`analysis_pipeline/analyzed/` + `cross_binary/_decomp/f1c_hexrays/` (F1C).
CSVs: `cross_binary/_delta/featdiff_A_only_f1c.csv`, `featdiff_B_only_f1_2002.csv`.

## Reading nuance — genuine-exclusive vs diverged

The two builds use different source roots: F1C `D:\dev\F1_1999_2002\Source\`,
F1 2002 `D:\Dev\Common\Source\`. So some modules (`htree.cpp`, `NetComm.cpp`) appear in
**both** bins → both games have the subsystem, but as **diverged versions** (different
bricks of the same wall — porting = merging improvements, not adding a missing feature).
A cluster that appears on **one side only** (Driving School, multi-season) is a genuine
whole-feature exclusive.

---

## Bin A — F1C HAS / F1 2002 LACKS (38 feature functions)

| Addr (F1C) | Size | Feature | Exclusive? |
|-----------|-----:|---------|-----------|
| 0x0041daf0 | 2086 | **Multi-season selector** — `F1_2002.gdb/F1_2001.gdb/F1_2000.gdb/F1_1999.gdb`. F1C's defining feature: 4 seasons in one game. | genuine |
| 0x004d24d0 | 2283 | **Race results + penalties** — `MECHFAIL_rate`, `Total Fines=%.1f`, `RaceTime`. Fines/mechanical-failure reporting. | genuine |
| 0x004d2e50 | 1597 | **Pit-window timing** — "Time until pit closes", "Time Remaining". | genuine |
| 0x004f24f0 | 1555 | **Multi-part collision/damage** — `Part%dCollParams/MassInertia/Pos/Random`. Per-part damage model. | likely |
| 0x0042e530 | 1383 | Track-type/setup — `Road Course`, `Track Type`, `RearSpoilerAngle`. | diverged |
| 0x00417f60 | 1353 | **Track roster** — Indianapolis, Nurburgring, Spa, Hungaroring, Hockenheim… | genuine (data) |
| 0x00449a80 | 1090 | **Extended HAT solver** — "Gaussian elimination for HAT poly failed **twice**" — retry logic F1 2002's HAT lacks. `htree.cpp` | diverged |
| 0x0042cf10 |  557 | Multiplayer grid placement for RACE. `game.cpp` | diverged |
| 0x004c52c0 |  554 | Scene-file validation. `setup.cpp` | genuine |
| 0x004dc770 |  493 | Texture material adjust (tex0..texN). `util.cpp` | diverged |
| 0x00460e90… | 1572 | **NetComm** (5 funcs) — open/close track, server handshake, frame-time, internet update. F1C's `NetComm.cpp` (F1_1999_2002 path). | diverged |
| 0x004cdc70 |  262 | Track-variable lookup. `specialfx.cpp` | genuine |
| 0x0043af50 |  229 | Suspension-not-found guard. `hdvehicle.cpp` | diverged |
| 0x004d5ee0 |  137 | Tire load-factor validation. `tire_manager.cpp` | diverged |

Headline F1C exclusives: **multi-season (1999–2002)**, **fines/mechanical-failure race
reporting**, **pit-close timing**, **per-part collision/damage**, **HAT retry solver**.

---

## Bin B — F1 2002 HAS / F1C LACKS (21 feature functions)

| Addr (F1 2002) | Size | Feature | Exclusive? |
|---------------|-----:|---------|-----------|
| 0x0042a520 | 1161 | **Driving School — lesson/challenge parser** — `prerequisiteTest/prerequisiteScore/vehSetup/goalTime/numRuns/completeLaps`. | genuine |
| 0x0042ea50 |  801 | **Driving School — scripted-event factory** — `CAMERA_CONTROL/VEHICLE_CONTROL/VEHICLE_DAMAGE/CONE_COLLISION/LapTimeEvaluate`. | genuine |
| 0x0042de40 |  682 | Driving School — start/finish markers `DsStartPos/DsIndicatorFinish`. | genuine |
| 0x0042b490 |  631 | Driving School — rewards `DsData.dsa/DsRewardCertificate/DsRewardVehicle`. | genuine |
| 0x0042e540 |  362 | Driving School — `drivingschool.mas` content loader. | genuine |
| 0x0042e340 |  501 | Driving School — event reaction `1_SUCCESS/ALL_SUCCESS/nodeReaction`. | genuine |
| 0x00447fc0 | 1985 | **HAT terrain** — height-tree build, "Not enough HAT points". `htree.cpp` | diverged |
| 0x00447ac0 | 1276 | HAT terrain — variant. `htree.cpp` | diverged |
| 0x004468b0 | 1017 | HAT terrain — Gaussian elim. `htree.cpp` | diverged |
| 0x004487a0 |  825 | HAT terrain — point allocation. `htree.cpp` | diverged |
| 0x0045b030 |  963 | NetComm — sync-attempt escalation. `NetComm.cpp` (Common path) | diverged |
| 0x0049c860 |  933 | Pit-crew scene setup after init. `pitcrew.cpp` | diverged |
| 0x004315e0 |  603 | Multiplayer grid placement by vehicle number. `game.cpp` | diverged |
| 0x004cfa00 |  461 | Texture material adjust (tex1..tex3). `util.cpp` | diverged |
| 0x00439350 |  137 | Tire peak-load validation. `hdvehicle.cpp` | diverged |

Headline F1 2002 exclusive: **Driving School / Test Day mode** (whole subsystem, 6+ funcs).
Everything else is a diverged version of a subsystem F1C also has.

---

## Portability read

- **Genuine cross-ports** (whole feature sits on one side):
  - INTO F1C: **Driving School** mode (self-contained: loader + parser + event factory + rewards + UI).
  - F1C-unique (its identity, not needed elsewhere): **multi-season 1999–2002**, extended results/fines.
- **Diverged subsystems** (`htree.cpp` HAT, `NetComm.cpp`, `game.cpp` grid, `util.cpp` texture,
  `hdvehicle`/`tire_manager` validation): both games have them; a "port" here means merging the
  better implementation, and the struct layouts must be checked (same architecture, but offsets
  may differ between the Common-path and F1_1999_2002-path builds).

---

# Cross-family portability matrix (all siblings → F1C)

Symmetric diffs run for every analyzable sibling. Bins in
`cross_binary/_delta/featdiff_<game>_not_f1c.csv` (game HAS / F1C LACKS = port INTO
F1C) and `featdiff_f1c_not_<game>.csv` (F1C HAS / game LACKS).

Per-bin counts: F1 2002 = 21, NASCAR 03 = 35, NASCAR 04 = 137, SCGT = 102. SCGT is
inflated (1999 compiler gap → byte matching fails, more diverged flagged) and its
exclusives are mostly Glide/3dfx-era rendering — low port value.

## PORT-INTO-F1C candidates (genuine whole-feature exclusives, ranked)

| Feature | From | Key funcs / strings | Port note |
|---------|------|---------------------|-----------|
| **Full-course caution / yellow-flag / pace lap** | NASCAR 03/04 | 0x004c9a50 "Green Flag: May Pass On Outside / Yellow Flag", 0x004c9650 "Full Caution / Quickie Caution", 0x004cb3e0 "Beginning Pace Lap" | F1C has **no** full-course yellow or safety-car procedure. Biggest gameplay gap. Self-contained flag state machine. |
| **Detailed penalty / infraction detection** | NASCAR 04 | 0x004e0e10 "Accelerated Too Early / Illegally Passed / Lapped Field Multiple Times" | Richer than F1C's `Steward`. F1C steward exists (0x004d0110) → extend it, don't add from scratch. |
| **Career / reputation / economy** | NASCAR 04 | 0x00410f10 `Reputation/Level%d/CurrentCar/CurrentCost/Condition` | Car ownership + cost + condition progression. F1C has championship but no economy. Large, UI-heavy. |
| **Driving School / Test Day mode** | F1 2002 | 0x0042a520 + cluster (Bin B above) | Self-contained subsystem. Cleanest port (loader+parser+events+rewards). |
| **Multiplayer voting** | NASCAR 04 | 0x0046bb40 "No vote in progress / vote" | MP session voting. Needs netcode hooks. |
| **Connection-speed netcode + GameSpy matchmaking** | NASCAR 04 | 0x0046caf0 (Cable/DSL/56K profiles), 0x00465d40 `MatcherAddServer` | Better matchmaking than F1C's NetComm. Diverged netcomm — merge, not drop-in. |
| **Replay helper data** | NASCAR 04 | 0x004d4bd0 `replay.cpp` | Extra replay stream. |
| **Lap-timing HUD** | NASCAR 03 | 0x00495c60 "Best/Last/Current Lap Time" | Live timing display. |

## Diverged subsystems (both have — port = merge better impl + re-map struct offsets)

Appear in BOTH bins with different source roots (F1C `D:\dev\F1_1999_2002\Source\`,
NASCAR `D:\Dev\NASCAR_200x\Source\`, F1 2002 `D:\Dev\Common\Source\`):

- `htree.cpp` — HAT terrain height-tree. F1C has a **retry** solver ("failed twice");
  NASCAR / F1 2002 versions differ. All three diverge.
- `NetComm.cpp` — networking. Every game has its own; NASCAR 04's is most advanced
  (GameSpy, dedicated-server buffer mgmt).
- `tire_manager.cpp` / `hdvehicle.cpp` — tire model + `.hdv` validation. NASCAR 04's
  `hdvehicle` is 6.2KB — more elaborate tire-brand/compound logic than F1C's.
- `util.cpp` (mesh anim / texture), `steward.cpp` (glow/light), `pitman.cpp`
  (pit textures), `random.cpp`, `specialfx.cpp` — minor divergences.

**Port rule:** genuine-exclusive → hook/DLL drop-in feasible (self-contained). Diverged →
verify struct offsets match F1C's layout before reusing code; the source-root difference
means fields may have moved between builds.

## SCGT (low priority)

102 flagged, but SCGT is isiMotor1's 1999 ancestor: exclusives are **Glide/3dfx
rendering** (`grAADrawLine`, `ConvertAndDownloadRle`), old scene/instance format
(`INSTANCE=/INSSTART=`), video-config (`video.c`, `readme.h`). None port usefully into
F1C's D3D8 engine. Kept for completeness only.

## Not analyzed

F1 2000 / F1 2001 (SafeDisc-packed, need runtime dump; older gen anyway) and the full
NASCAR games (used demos). rFactor excluded (isiMotor2).
