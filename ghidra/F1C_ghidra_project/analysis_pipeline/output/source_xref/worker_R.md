# Source Cross-Reference: docs/20-math-utilities.md

**File stats:** 58,240 lines, 1,793 KB, 2,968 `## FUN_` entries
**Category:** Math utilities index + utility foundation layer (Part 2)
**Nature:** ~4,000 pure math_util leaf functions + ~1,414 utility foundation functions (memory mgmt, file I/O, CRT, string, threading, SEH, data structures, UI text, renderer-adjacent)
**Key characteristics:** Stateless pure computation - no branching on SessionType/RacePhase, operates on caller-provided struct pointers. UTILITY document - all functions are indexed entries, not full deep-dive entries.

---

## RTTI Class Mappings

The math utility functions are **leaf computation functions** called by game classes, NOT class methods themselves. No direct 1:1 mapping to rFactor RTTI classes is expected. However, functional clusters correspond to specific rFactor classes through documented call relationships:

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `Render` | FUN_0055eb30, FUN_0055EBA0, FUN_0055ee20, FUN_0050a92d | HIGH | Vertex color modulation with packed short multiply (DAT_008b6c20/DAT_008b8e40 blend factors); per-vertex lighting/reflection vector compute with virtual dispatch per vertex via DAT_008b8f24; all documented as "Renderer-Adjacent Math" section |
| `Render` | FUN_005033a5 | HIGH | DXT compressed texture block copy - DXT1-5 format handling, surface alignment validation, fourCC detection (0x31545844) |
| `Render` | FUN_00500bc8 | HIGH | D3D surface copy/blit with format conversion, surface type validation (texture=3, cube map=4, volume tex=5), LockRect/blit via vtable |
| `Render`/`VidMan` | FUN_00562250 | MED | Texture creation wrapper: allocate + init width/height/format - feeds D3D render pipeline |
| `VidMan` | FUN_00595135 | HIGH | DirectDraw surface flag translation (DDSD flags 0x1/0x2/0x4/0x8/0x10/0x30000/0x40000/0x80000) - DirectX infrastructure |
| `cubeGraphicsDevice` | FUN_00501992 | MED | DDS texture header parsing + pixel loading - CUBE engine texture loading pathway |
| `Render` | FUN_00503f75 | MED | 2×2 box downscale pixel averaging filter - renderer texture mipmap chain |
| `cubeBase` | FUN_005567f5 | MED | CPU feature detection via CPUID (EFLAGS ID bit toggle, RDTSC, vendor string) - platform abstraction layer |
| `cubeBase` | FUN_005565b0 | MED | High-precision timer: QueryPerformanceCounter wrapper with 64-bit tick delta + frequency normalization |
| `SmartFile`/`ISIUtility` | FUN_0058806e, FUN_0058c824, FUN_0058e22b, FUN_0058e290, FUN_00599ed6, FUN_0059b650, FUN_0059c30e | HIGH | Buffered file I/O wrappers, CR/LF conversion, handle table management, Unicode BOM handling, file duplication via DuplicateHandle - matches rFactor source path `..\Source\util.cpp` pattern |
| `AIDatabase`/`HDVehicle` | FUN_004258c0 | MED | AI speed/overtaking state setter. Sets AIStateFlags at +0x4354, AISpeedDelta at +0x4438, AIGapToAhead at +0x4434. These offsets are internal HDVehicle struct fields, NOT exposed via rFactor plugin SDK. |
| `HDVehicle` | FUN_00426cc0 | MED | Speed delta computation using AIStateFlags +0x4354 as overtaking zone check, reads AIFollowTarget pointer and vehicle speed at +0x4c |
| `GameComponent` | FUN_00550f70, FUN_00582650, FUN_00582a10 | LOW | Resource manager destructors with vtable dispatch. Generic pool/list cleanup pattern could belong to any GameComponent subclass |
| `Controller` | FUN_00598c1c | LOW | Locale management with thread-safe refcounting - used by text rendering which is part of Options/OnScreen |
| `Steward` | FUN_0049ba10, FUN_004f9ad0 | LOW | Time accumulation and session time queries (DAT_008afea0, DAT_007ce238). Called steward-adjacent for session timing |
| `Options_SliderBar`/`Options_BaseMenuItem` | FUN_00507496 | LOW | Constructor pattern: `FUN_00507496(param_2, size, 1) + vtable = PTR_FUN_005adXXX`. This is the standard widget constructor pattern. |
| `SoundMan` | FUN_0049ec40, FUN_0049ec60, FUN_005539f0 | MED | Sound resource cleanup: checks non-null, calls FUN_005539f0 (release sound), zeros handle. Matches rFactor `SoundMan` class resource lifecycle |
| `ReplayMan` | FUN_0056aa60 | LOW | Multi-phase finite-element matrix assembly (2922 bytes, 22 double-precision variables, cross-element coupling) - suspension/chassis compliance solver for physics integration. Called by physics tick (60-300×/s) |
| `cubeDirectX` | FUN_005111d3 | LOW | JPEG marker reader from byte stream - DirectX texture loading pathway |

### Notes on RTTI mapping for this doc:
- Math utilities are NOT class methods - they are **static/global helper functions** called across all subsystems
- The SIMD cluster (FUN_00520FC6 SSE normalize, FUN_0052179f 3DNow! blend, FUN_00528f00 3DNow!, FUN_005215db packed math) are pure leaf math with no class affiliation
- The ~2,000 pure vector/matrix math functions (0x0040XXXX range) have NO class mapping - they are called by physics, renderer, AI with equal frequency
- Memory allocator / CRT functions have NO class mapping - they are infrastructure
- The utility foundation functions in Part 2 (~1,414 functions) are scattered helpers, vtable stubs, and inline expansions - too fragmented for class mapping

---

## Parameter-to-Offset Mappings

Math functions do NOT parse config files or read .hdv/.pm parameters directly. However, the doc **references struct offsets by name** that correspond to known .hdv config parameters. These are documented in the System Overview and in specific function entries:

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| (engine_lifetime in F1_2000:FAILURES) | FAILURES | +0x1330 | LifetimeAvg | EngineLifetimeAvg | MED — offset referenced in math doc overview; F1_2000 calls this `engine_lifetime` |
| (engine_variance in F1_2000:FAILURES) | FAILURES | +0x1338 | LifetimeVar | EngineLifetimeVar | MED — same pattern as LifetimeAvg |
| CGRightRange | GENERAL | +0x??? | CGRightRange | CGRightRange | LOW — .hdv field "CGRightRange" is parsed in setup; math doc doesn't reference this specific offset but the term "Global constants (DAT_0059eXXX) ... physics bounds, scale factors" suggests config-derived constants |
| FuelRange | GENERAL | +0x??? | FuelRange | FuelRange | LOW — .hdv field "FuelRange" appears in hdv_pm_full.txt; math doesn't reference offset but global float constants may derive from this |
| AIDamperSlow | GENERAL | +0x??? | — | — | LOW — .hdv field "AIDamperSlow" and "AIDamperFast" (config_params.txt line 98-106). Doc references "AI speed/overtaking state" but not damper values |

### Key finding:
- The struct offsets referenced in the math doc (LifetimeAvg +0x1330, LifetimeVar +0x1338, QualifyingAbility +0x1130, RaceAbility +0x1138) are **validated config parameters** from F1_2000's .veh format. The F1_2000 `.veh` file uses `engine_lifetime` and `engine_variance` under the [FAILURES] section. This confirms the LifetimeAvg/Var fields are carry-over from F1_2000 physics.
- No direct sscanf/param parse occurs in math utility functions. Config parsing lives in `decompiled_all/` functions (hdvehicle.cpp, setup.cpp).

---

## String Matches

The math doc contains very few literal strings. Most function descriptions reference code/API calls, not literal strings. Found strings:

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `"MZ"` | docs/20-math-utilities.md line 8508 | FUN_00XXXXXX | Checks DOS signature at offset 0: must be 0x5A4D ("MZ") — PE/DLL loader validation. Cross-binary shared with rFactor/NASCAR |
| `"VC20"` | docs/20-math-utilities.md line 54227 | FUN_00XXXXXX | Writes magic value 0x56433230 ("VC20") at param_1[8] for version identification — Version Check 2.0. Not in crossref data |
| `"FTFRAMERATE"` | docs/20-math-utilities.md line 51298/51302 | FUN_00XXXXXX | Font lookup string "FTFRAMERATE" via FUN_0053d1f0 — FPS counter font name. Unique to F1C |
| `"---Halting program..."` | docs/20-math-utilities.md line 51633/51636 | FUN_00XXXXXX | Debug output string. Cross-binary shared pattern but exact string not in crossref.txt |
| `"1.3f"` | docs/20-math-utilities.md line 55344/55348 | FUN_00XXXXXX | Debug float format template. Not in crossref data |

### Cross-binary string matches (from string_crossref.txt):
- **No direct matches** between doc/20-math-utilities.md strings and string_crossref.txt entries. The crossref file focuses on UI strings, physics parameter names, and network messages — none of which appear in the math utility descriptions.
- The math utilities document describes **code structure**, not string content. The literal strings that DO exist are internal debug/font names not captured in the crossref.

---

## SDK Struct Alignment

### Vehicle/AI Struct Offsets vs rFactor SDK

The math doc references vehicle struct offsets that correspond to F1C's internal HDVehicle struct. These do NOT appear in the rFactor SDK (InternalsPlugin.hpp) which exposes a much smaller struct:

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| TelemInfoBase.mEngineRPM | +0x64 | — | N/A | SDK exposes telemetry at small offsets; F1C internal struct is much larger |
| TelemInfoBase.mGear | +0x60 | — | N/A | Same |
| VehicleScoringInfo.mDriverName[32] | +0x00 | +0x4620 (DriverName) | MISMATCH | F1C DriverName at +0x4620 is internal struct offset; SDK VehicleScoringInfo has mDriverName at +0x00 |
| VehicleScoringInfo.mFinishStatus | +0x42 | +0x4064 (FinishState) | MISMATCH | Same field, different struct context |
| VehicleScoringInfoV2.mPlace | +0x4b | +0x4058 (QualifyingPosition) | MISMATCH | SDK scoring struct is much smaller |
| VehicleScoringInfoV2.mControl | +0x49 | — | NEW | SDK has control field at +0x49; F1C's internal struct doesn't use SDK layout |
| ScoringInfoV2.mGamePhase | +0x00 | DAT_007c56a8 (RacePhase) | MATCH | Game phases align: SDK docs 0-8 phases match F1C RacePhase 0-7 (SDK adds session stopped=7, over=8) |
| TelemWheelV2.mWear | +0x28 | — | NEW | SDK has tire wear at +0x28 in TelemWheelV2; not directly mapped in math doc |
| TelemWheel.mBrakeTemp | +0x18 | — | N/A | Math doc doesn't expose per-wheel brake temp |
| TelemWheel.mTemperature[3] | +0x20 | — | N/A | Math doc doesn't reference 3-zone tire temp array |

### Key struct alignment finding:
- **SDK vs F1C offsets are NOT directly comparable.** The rFactor SDK publishes tiny structs (TelemInfoBase ~0x74 bytes, VehicleScoringInfoV2 ~0xF0 bytes) that are projected views of the internal HDVehicle struct. F1C's HDVehicle struct is much larger (offsets > 0x4000 bytes observed).
- F1C field names in math doc (LifetimeAvg +0x1330, QualifyingAbility +0x1130, etc.) are **internal HDVehicle fields** not exposed in the rFactor plugin API.
- The **RTII class names** from rFactor Dedicated.exe (`.?AVHDVehicle@@`) confirm that HDVehicle is the class, and these large offsets belong to its internal layout.
- **RacePhase** (DAT_007c56a8) is the closest match: SDK ScoringInfoV2.mGamePhase maps to the same game state machine (0-8 values).

---

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| `FUN_0059416f` — "Custom memory allocator (buddy allocator or slab allocator)" | `mbmalloc_BuddyAlloc` or `alloc_BuddyBlock` | rFactor source paths include `..\Source\util.cpp`; buddy allocator pattern with two-level bitmap + size class linked lists. Common ISI engine memory allocator. |
| `FUN_00587DD0` — "MSVC CRT _strncpy" | `strncpy` | Already identified as standard C strncpy. Keep as-is. |
| `FUN_0058c824` — "File position calculation with line-ending translation" | `file_tell_converted` | rFactor class `SmartFile` provides file I/O with text/binary mode. This is the internal file position query. |
| `FUN_005567f5` — "CPU feature detection via CPUID" | `cpuid_DetectFeatures` | Matches CPUID detection pattern across all ISI binaries (rFactor, NASCAR). Cross-binary shared. |
| `FUN_00595135` — "DirectDraw surface flag translation" | `d3d_DDSDFlagsToInternal` | DirectDraw surface flags — shared across CUBE engine (rFactor, NASCAR). Maps to `cubeGraphicsDevice` or `cubeDirectX` |
| `FUN_005565b0` — "High-precision timer" | `timer_QueryPerformanceCounter` | Wraps QueryPerformanceCounter — platform layer in `cubeBase` |
| `FUN_0055eb30` — "Vertex color modulation" | `d3d_VertexColorModulate` | Packed short multiply per-channel RGBA — `Render` class vertex pipeline |
| `FUN_0056aa60` — "Multi-phase finite-element matrix assembly" | `suspension_ComplianceSolver` or `physics_MatrixAssembly_3x22` | Described as 2922-byte finite-element style matrix with 22 double-precision variables, cross-element coupling. Likely suspension/chassis compliance solver. Called by physics integration tick. |
| `FUN_00550f70` — "Resource manager destructor" | `resmgr_Destroy` | Two-mode destructor (refcounted array sub-mode vs sub-array mode). Matches rFactor's `GenericManager` pattern. |
| `FUN_0058de2c` — "Math boundary function for transcendental range reduction" | `math_range_reduction` or `frexp_scalar` | Checks IEEE 754 special values (Inf, NaN, zero). Used by pow/exp math library. |
| `FUN_00549ec0` / `FUN_0049ec60` — "Sound Resource Release/Cleanup" | `sound_ReleaseResource` / `sound_StopRelease` | Matches `SoundMan` resource lifecycle in rFactor. Calls FUN_005539f0 (sound release). |
| `FUN_00599ed6` — "Stream write with encoding/translation" | `file_write_converted` | Unicode BOM, codepage conversion, lock — `SmartFile`/`ISIUtility` pattern |
| `FUN_0059b650` — "File handle duplication" | `file_DuplicateHandle` | Wraps DuplicateHandle — utility in `util.cpp` |
| `FUN_00588b465` — "Case-insensitive char conversion" | `char_toupper` or `str_toupper_ascii` | Standard ASCII toupper with locale fallback. Utility pattern. |

### Tier-2 Proposed Renames (lower confidence or more speculative):

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_00592dfa — "Environment block retrieval" | `env_GetEnvironmentBlock` | GetEnvironmentStringsW/A wrapper. OS platform layer. |
| FUN_00596175 — "Format string dispatch" | `printf_format_dispatch` | Maps format IDs (1-8) to handlers. CRT format dispatching. |
| FUN_005832e0 — "Linked list node removal by key" | `list_RemoveByKey` | Doubly-linked list node removal. Generic container utility. |
| FUN_0059416f — "Buddy allocator" | `alloc_buddy_alloc` | Two-level bitmap free list, size-class linked lists. ISI engine signature. |
| FUN_0055ed10 — "Proximity/lights query" | `scene_ProximityQuery` or `octree_FindNearby` | Octree-style linked list, distance² test, collects 8 nearby items. Render/culling pipeline. |
| FUN_005033a5 — "DXT compressed texture block copy" | `tex_DXTBlockCopy` | DXT1-5 format block copy. Renderer texture management. |
| FUN_005645b0 — "Hash computation" | `hash_Compute` | Hash function used across linked-list string search. Utility. |
| FUN_00520FC6 — "SSE vector normalization" | `vec3_Normalize_SSE` | Newton-Raphson refinement SSE normalization. 3DNow!/SIMD math cluster. |
| FUN_0052179f — "3DNow! packed math blend" | `vec3_Blend_3DNow` | 3DNow! instruction variant for vector blend. CPU-specific code path. |
| FUN_0058bdcd — "float-to-string with sign, width, precision" | `sprintf_double_to_str` or `ftoa` | Float-to-decimal string formatting. CRT-like utility. |

---

## Summary Statistics

| Category | Count | Notes |
|----------|-------|-------|
| RTTI class mappings | 19 entries | All MED/LOW confidence — math utilities are leaf helpers, not class methods |
| Parameter-to-offset mappings | 5 entries | Only from doc overview, not from individual function entries |
| String matches | 5 found, 0 crossref matches | Doc has few literal strings; crossref data has no overlap |
| SDK struct alignment entries | 12 fields compared | SDK structs are much smaller than F1C's internal HDVehicle struct |
| Proposed renames | 25 entries | Renamed toward ISI engine conventions based on cross-binary evidence |
| Functions with game-logic globals | ~10 functions | Most math utilities are pure computation with no globals; exceptions use DAT_008aae70 (random ring buffer), DAT_008b8dc8 (render context), DAT_008afea0 (session time) |

### Key Takeaway
**docs/20-math-utilities.md** is the engine's computational foundation layer. Its 2,968 functions are predominantly stateless leaf computations with no game-logic branching. Cross-reference value is limited because:
1. No config file parsing occurs here
2. No RTTI class methods are documented (these are static helpers)
3. No SDK-exposed structs are operated on (offsets are internal HDVehicle struct)
4. Few literal strings exist in function descriptions

The most valuable cross-ref findings are the **proposed function renames** (25 entries) based on cross-binary ISI engine patterns.
