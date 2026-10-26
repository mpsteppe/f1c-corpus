# BF-04: Deep String Forensics

**Status:** DONE (2026-07-16)

## Source File References

31 unique source files found in binary strings (assert macros + trace strings):

### ISI Game Source (`D:\dev\F1_1999_2002\Source\`)
| File | Maps to subsystem |
|------|------------------|
| ai_db.cpp | AI database/waypoints |
| camera.cpp | Camera manager |
| config.cpp | Config file parsing |
| dynman.cpp | Dynamics manager |
| game.cpp | Game lifecycle |
| garage.cpp | Garage/setup UI |
| hdvehicle.cpp | HD vehicle physics model |
| htree.cpp | H-tree/Gaussian elimination |
| hwinput.cpp | Hardware input (DirectInput) |
| NetComm.cpp | Network communication |
| O_AppGz.cpp | App gizmo (UI framework) |
| O_BaseGz.cpp | Base gizmo (UI base class) |
| onscreen.cpp | On-screen display/HUD |
| options.cpp | Options/settings |
| osman.cpp | OS manager |
| pitcrew.cpp | Pit crew logic |
| plrfile.cpp | Player file (profiles) |
| Replay.cpp | Replay system |
| render.cpp | Renderer |
| searchgrid.cpp | Search grid (spatial partitioning) |
| setup.cpp | Car setup |
| sound.cpp | Sound system |
| specialfx.cpp | Special effects (particles, weather) |
| steward.cpp | Race steward |
| tire_manager.cpp | Tire brand/compound manager |
| util.cpp | Utilities |
| vehgfx.cpp | Vehicle graphics |
| vehload.cpp | Vehicle loader |
| vidman.cpp | Video manager (D3D) |
| weather.cpp | Weather system |

### External Library
| File | Source |
|------|--------|
| LbMpeg.cpp | `\Dev\AudioDev\Shared\Engine\Dev\` — Lee Briggs MPEG decoder, separate dev tree |

## Missing vs Rich Header

- Rich header: **69 compilation units**
- Strings: **31 source files** (30 ISI + 1 LbMpeg)
- **~38 source files** have no string references in the binary

Missing files likely include: main.cpp, the D3D renderer backend, networking protocol,
AI behavior, physics solver core, math library, file I/O framework, and any ISI
shared-engine modules without assert/trace strings.

## Assert Patterns

Only 2 hits:
- `"Received server verify, setting self as ready..."` (NetComm, not a real assert)
- `"AUDIO ASSERT !!! ..."` (sound system error)

ISI used trace strings (`"Entered Class::Method()"`) rather than standard C assert macros.
This is why the binary has class/method names but no file:line assert data.

## Physics Format Strings (selection)

```
EngineBrakeMapSetting=%d
EngineMapSetting=%d
TireCompoundSetting=%d
Could not find suspension bar %s
*.hdv file references unknown tire compound "%s"
Could not find one of tire slip curves %s/%s/%s
GAMEOPT_tire_mult=%d
Tire Mult=%d
DRIVEAIDS_extra_tire_sampling=%d
First data point must be zero in tire slip curve "%s"
Wheel%dCollParams
Wheel%dMassInertia
```

These are Config.ini keys and .hdv parser error messages — already captured in
`tools/trace_caller_strings.csv` (1,044 strings from trace callers).
