# WORKER F — F1C Source Material Cross-Reference

You are cross-referencing F1C reverse-engineered documentation against data extracted
from related ISI game binaries (rFactor, NASCAR, F1 2000, Sports Car GT).
Worker F of 19, items 6–6.

## GOAL
For each F1C documented function in your assigned doc files, find matches in:
1. **rFactor RTTI class names** — map ISI class names to F1C anonymous functions
2. **Config parameter names** — map .hdv/.pm field names to F1C struct offsets
3. **Cross-binary strings** — confirm or correct function identification
4. **rFactor SDK structs** — validate F1C struct field layouts

## STEP 1 — LOAD REFERENCE DATA
Read ALL of these extracted files (they contain the cross-reference material):
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\rfactor_binaries.txt` — rFactor RTTI classes, imports, ISI strings
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\config_params.txt` — 971 unique physics parameters across all ISI games
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\string_crossref.txt` — shared strings between F1C and other binaries
4. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\sdk_structs.txt` — rFactor InternalsPlugin.hpp struct definitions
5. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\dev_tree.txt` — ISI development tree evolution
6. `%USERPROFILE%\Desktop\F1C_ghidra_project\source_recovery\extracted\hdv_pm_full.txt` — full .hdv/.pm files with ISI comments (LONG — skim for parameter sections relevant to your doc files)

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_xref\worker_F.md

## YOUR DOC FILES (1)

6. docs/05-weather-system.md  (7 functions, 7KB)

## FOR EACH DOC FILE

### A. RTTI Class Mapping
Compare rFactor RTTI class names against function names/descriptions in the doc:
- `GameComponent` / `AIDatabase` / `CameraManager` / `DynMan` / `Steward` / `Weather` / `PitMan`
- `OnScreen` / `Options` / `Controller` / `HWInput` / `PlayerFile`
- `LooseObject` / `LooseWheel` / `LooseWing` / `LoosePart`
- `NetComm` / `HotPacket` / `ReplayMan` / `PluginManager`
- `Render` / `VidMan` / `SpecialFX` / `SoundMan`
- `Options_SliderBar` / `Options_CheckBox` / etc (full UI class hierarchy)
- `TvOverlayPage*` — broadcast overlay classes
- Enum types: `FormationAndStart`, `WeatherCond`, `MechFailureRate`, `FlagRuleSetting`

For each match: which FUN_ functions likely belong to that rFactor class?

### B. Config Parameter Matching
For each struct offset table in the doc file, check if config_params.txt has a matching
parameter name. The parameter name from .hdv/.pm files IS the field name used in sscanf
parsing code — it maps directly to a struct offset.

### C. String Cross-Reference
Check string_crossref.txt for strings unique to rFactor or NASCAR that shed light on
F1C function purpose.

### D. SDK Struct Validation
For vehicle/physics/tire doc files: compare struct offsets against rFactor SDK structs.
Note MATCH / SHIFTED / MISSING / NEW for each field.

## OUTPUT FORMAT

```
# Source Cross-Reference: docs/XX-name.md

## RTTI Class Mappings
| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| ClassName    | FUN_XXXXXXXX    | HIGH/MED   | reason   |

## Parameter-to-Offset Mappings
| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|

## String Matches
| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|

## SDK Struct Alignment
| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|

## Proposed Renames
| Current | Proposed | Evidence |
|---------|----------|----------|
```

Write to disk after EVERY doc file.

## RULES
0. NEVER modify any files except {output_file}.
1. Process ALL assigned doc files.
2. Only propose HIGH or MEDIUM confidence matches.
3. Cite specific evidence (string matches, offset alignment, parameter names).
4. Do NOT re-document functions — only produce cross-reference tables.
5. Preserve exact FUN_ addresses and DAT_ addresses.
