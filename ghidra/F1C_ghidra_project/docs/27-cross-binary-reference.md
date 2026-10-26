# Cross-Binary Function Reference

Function matches between F1 Challenge 99-02 and NASCAR Thunder 2003/2004.
Matched via string anchors, exact byte hashes, and normalized byte signatures.

## Summary

- **3018 functions matched** out of 5,797 F1C functions (52.1%)
- NASCAR 2003 Demo: 7,653 functions, 1.9MB
- NASCAR 2004 Demo: 8,640 functions, 2.3MB
- Game code matches: 1122
- Library code matches: 1896
- Functions with ISI class names: 94

## Shared Source Files

29 source files shared between F1C (`D:\dev\F1_1999_2002\Source\`) and NASCAR (`D:\Dev\NASCAR_2003\Source\`):

- NetComm.cpp
- O_AppGz.cpp
- O_BaseGz.cpp
- Replay.cpp
- ai_db.cpp
- camera.cpp
- dynman.cpp
- game.cpp
- garage.cpp
- hdvehicle.cpp
- htree.cpp
- hwinput.cpp
- onscreen.cpp
- options.cpp
- osman.cpp
- pitcrew.cpp
- plrfile.cpp
- render.cpp
- searchgrid.cpp
- setup.cpp
- sound.cpp
- specialfx.cpp
- steward.cpp
- tire_manager.cpp
- util.cpp
- vehgfx.cpp
- vehload.cpp
- vidman.cpp
- weather.cpp

CUBE42 library files (NASCAR 2004 3DConfig): Cube.cpp, DX8Main.cpp, DX8Pipe.cpp, DX8Util.cpp, Particle.cpp, Shadow.cpp

## ISI Class Mapping

Classes identified via "Entered Class::Method()" trace strings:

| Class | Source File | Methods Found |
|-------|-----------|---------------|
| AIDatabase | ai_db.cpp | Init |
| CamMan | camera.cpp | Init, Post, Restart |
| DynMan | dynman.cpp | Enter, Exit, Init, Post, Restart, Setup |
| Game | game.cpp | Enter, Init, Post, Restart, Setup |
| HDVehicle | hdvehicle.cpp | parse |
| HWInput | hwinput.cpp | Enter, Exit, Init, Post, Restart, Setup |
| OSMan | osman.cpp | Enter, Exit |
| OnScreen | onscreen.cpp | Enter, Exit, Init, Post, Restart, Setup |
| Options | options.cpp | Setup |
| PlayerFile | plrfile.cpp | Enter, Post, Restart, Setup |
| Render | render.cpp | Init, Post, Restart |
| Setup | setup.cpp | parse |
| Sound | sound.cpp | Enter, Exit, Init, Post, Restart, Setup |
| SpecialFX | specialfx.cpp | Enter, Exit, Init, Post, Restart, Setup |
| Steward | steward.cpp | Init, Post, Restart, Setup |
| VidMan | vidman.cpp | Enter, Exit, Init, Post, Restart, Setup |

## Engine Lifecycle Pattern

Every major subsystem implements 6 lifecycle methods: Enter, Setup, Init, Restart, Post, Exit.
All confirmed via trace strings in both F1C and NASCAR.

| Class | Enter | Setup | Init | Restart | Post | Exit |
|-------|-------|-------|------|---------|------|------|
| AIDatabase | - | - | 0x004040a0 | - | - | - |
| CamMan | - | - | 0x0040c920 | 0x0040c9e0 | 0x0040cce0 | - |
| DynMan | 0x0042c130 | 0x0042c170 | 0x0042c1a0 | 0x0042c3b0 | 0x0042c9f0 | 0x0042ca70 |
| Game | 0x0042d370 | 0x0042d5d0 | 0x0042d6b0 | 0x0042d7a0 | 0x0042da30 | - |
| HWInput | 0x00455bf0 | 0x00455c60 | 0x00455d50 | 0x00455da0 | 0x00455e70 | 0x00455f00 |
| OnScreen | 0x0049ef40 | 0x0049ef70 | 0x0049efa0 | 0x0049f000 | 0x0049f0d0 | 0x0049f120 |
| Options | - | 0x004a0eb0 | - | - | - | - |
| OSMan | 0x004a18d0 | - | - | - | - | 0x0042db20 |
| PitCrew | - | - | - | - | - | - |
| PlayerFile | 0x004b1820 | 0x004b1870 | - | 0x004b18d0 | 0x004b1900 | - |
| Render | - | - | 0x004b4030 | 0x004b4060 | 0x004b4170 | - |
| Sound | 0x004c8a20 | 0x004c8ab0 | 0x004c8ae0 | 0x004c8b20 | 0x004c8ca0 | 0x004c8d00 |
| SpecialFX | 0x004cee90 | 0x004ceec0 | 0x004cf070 | 0x004cfc90 | 0x004cfed0 | 0x004cfff0 |
| Steward | - | 0x004d36d0 | 0x004d38f0 | 0x004d3cf0 | 0x004d4600 | - |
| VidMan | 0x004fa000 | 0x004fa2f0 | 0x004fa320 | 0x004fa640 | 0x004fac00 | 0x004fad00 |

## Match Statistics

| Method | Count |
|--------|-------|
| normalized | 1461 |
| exact_hash | 988 |
| string | 340 |
| n04_only | 229 |

## Data Files

| File | Records | Description |
|------|---------|-------------|
| `tools/cross_binary_final.csv` | 3,018 | Consolidated F1C - NASCAR function pairs |
| `tools/cross_binary_matches.csv` | 341 | String-anchored matches with class names |
| `tools/f1c_byte_sigs.csv` | 5,797 | F1C function byte signatures |
| `tools/nascar03_byte_sigs.csv` | 7,187 | NASCAR 2003 function byte signatures |
| `tools/nascar04_byte_sigs.csv` | 8,077 | NASCAR 2004 function byte signatures |
| `tools/nascar03_functions.csv` | 7,653 | NASCAR 2003 IDA function list |
| `tools/nascar03_strings.csv` | 5,246 | NASCAR 2003 strings with xrefs |
| `tools/nascar04_functions.csv` | 8,640 | NASCAR 2004 IDA function list |
| `tools/nascar04_strings.csv` | 6,288 | NASCAR 2004 strings with xrefs |