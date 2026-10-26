# Worker C — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_C.md`

## TASK: add the MISSING fields to existing entries. Do NOT rewrite the whole entry.
For each function below: open its source .c, then output a PATCH block with only the
missing field line(s). The merge appends them to the existing entry.

## HARD RULES
1. WRITE ONLY to the output file above. NEVER touch docs/.
2. One function = one patch block, written immediately. Do ALL listed.
3. NEVER spawn a subagent.
4. **F1C status** value by TIER: `T1` -> `absent — <evidence: unique strings / no F1C match>`;
   `T2`/`R` -> `absent (diverged — F1C likely has a different version)`.
5. **Port** value: `yes` (self-contained, F1C lacks it) | `merge` (F1C has a diverged
   version — needs offset re-map) | `data-driven` | `no` (engine-generic/not portable).
   TIER T2/R almost always -> `merge`. TIER T1 self-contained feature -> `yes`.

## OUTPUT FORMAT (one block per function):
```
=== PATCHES ===
<!-- patch: <game>/<doc> sub_XXXXXXXX -->
**F1C status:** absent — <evidence>
**Port:** merge
```
Only include the field lines that were MISSING (listed per function).

## Functions to fix:

1. f1_2002/40-gameplay.md sub_0042acc0 [tier=T2] MISSING=F1C status — "Test Result Generator/Scorer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042acc0__sub_42ACC0.c
2. f1_2002/40-gameplay.md sub_0042b160 [tier=T2] MISSING=F1C status — "Career Challenge Matching Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042b160__sub_42B160.c
3. f1_2002/40-gameplay.md sub_0042b360 [tier=T2] MISSING=F1C status — "Career Data Full Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042b360__sub_42B360.c
4. f1_2002/40-gameplay.md sub_0042b710 [tier=T2] MISSING=F1C status — "Career Data Destructor (Variant)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042b710__sub_42B710.c
5. f1_2002/40-gameplay.md sub_0042bad0 [tier=T2] MISSING=F1C status — "Career Data Linked List Free"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042bad0__sub_42BAD0.c
6. f1_2002/40-gameplay.md sub_0042bbc0 [tier=T2] MISSING=F1C status — "Career Data Serializer (Text Output)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042bbc0__sub_42BBC0.c
7. f1_2002/40-gameplay.md sub_0042bef0 [tier=T2] MISSING=F1C status — "Career Data String-Keyed Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042bef0__sub_42BEF0.c
8. f1_2002/40-gameplay.md sub_0042c0b0 [tier=T2] MISSING=F1C status — "Career Challenge Evaluator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042c0b0__sub_42C0B0.c
9. f1_2002/40-gameplay.md sub_0042c9e0 [tier=T2] MISSING=F1C status — "Career Data Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042c9e0__sub_42C9E0.c
10. f1_2002/40-gameplay.md sub_0042cc10 [tier=T2] MISSING=F1C status — "Career Data Linked List Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042cc10__sub_42CC10.c
11. f1_2002/40-gameplay.md sub_0042ce30 [tier=T2] MISSING=F1C status — "Session Setup: Start Race Session"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042ce30__sub_42CE30.c
12. f1_2002/40-gameplay.md sub_0042cf60 [tier=T2] MISSING=F1C status — "Session Update/Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042cf60__sub_42CF60.c
13. f1_2002/40-gameplay.md sub_0042d2c0 [tier=T2] MISSING=F1C status — "Session State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042d2c0__sub_42D2C0.c
14. f1_2002/40-gameplay.md sub_0042d890 [tier=T2] MISSING=F1C status — "Session Cleanup/Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042d890__sub_42D890.c
15. f1_2002/40-gameplay.md sub_0042dbc0 [tier=T2] MISSING=F1C status — "Session Phase Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042dbc0__sub_42DBC0.c
16. f1_2002/40-gameplay.md sub_0042e110 [tier=T2] MISSING=F1C status — "Career Menu Data List Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042e110__sub_42E110.c
17. f1_2002/40-gameplay.md sub_0042e340 [tier=T1] MISSING=F1C status — "Career Reaction Challenge Parser"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042e340__sub_42E340.c
18. f1_2002/40-gameplay.md sub_0042e750 [tier=T2] MISSING=F1C status — "Merge Sort (Linked List) for Career Data"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042e750__sub_42E750.c
19. f1_2002/40-gameplay.md sub_0042e8a0 [tier=T2] MISSING=F1C status — "Merge Sort Merge Step"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042e8a0__sub_42E8A0.c
20. f1_2002/40-gameplay.md sub_0042ef30 [tier=T2] MISSING=F1C status — "Career Path String Normalizer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042ef30__sub_42EF30.c
21. f1_2002/40-gameplay.md sub_0042f4d0 [tier=T2] MISSING=F1C status — "Lap Count/Validation Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042f4d0__sub_42F4D0.c
22. f1_2002/40-gameplay.md sub_004315e0 [tier=T1] MISSING=F1C status — "Session/Mode State Transition Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004315e0__sub_4315E0.c
23. f1_2002/40-gameplay.md sub_004328c0 [tier=T2] MISSING=F1C status — "HUD Speedometer/Scale Calculation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004328c0__sub_4328C0.c
24. f1_2002/40-gameplay.md sub_004333b0 [tier=T2] MISSING=F1C status — "HUD Display String Formatter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004333b0__sub_4333B0.c
25. f1_2002/40-gameplay.md sub_00434150 [tier=T2] MISSING=F1C status — "Tire Grip/Load Computation (Pacejka-Base"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00434150__sub_434150.c
26. f1_2002/40-gameplay.md sub_004343e0 [tier=T2] MISSING=F1C status — "Tire Heating/Thermal Model"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004343e0__sub_4343E0.c
27. f1_2002/40-gameplay.md sub_00434d90 [tier=T2] MISSING=F1C status — "Vehicle Dynamics Setup (Suspension Targe"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00434d90__sub_434D90.c
28. f1_2002/40-gameplay.md sub_004356c0 [tier=T2] MISSING=F1C status — "Physics Engine Global Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004356c0__sub_4356C0.c
29. f1_2002/40-gameplay.md sub_00435c00 [tier=T2] MISSING=F1C status — "Driver Setup File Path Initialization"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00435c00__sub_435C00.c
30. f1_2002/40-gameplay.md sub_00435c90 [tier=T2] MISSING=F1C status — "Setup File Deployment"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00435c90__sub_435C90.c
31. f1_2002/40-gameplay.md sub_004363e0 [tier=T2] MISSING=F1C status — "Setup File Path Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004363e0__sub_4363E0.c
32. f1_2002/40-gameplay.md sub_00437000 [tier=T2] MISSING=F1C status — "Setup File Finder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00437000__sub_437000.c
33. f1_2002/40-gameplay.md sub_004377d0 [tier=T2] MISSING=F1C status — "Setup File Version/Track Manager"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004377d0__sub_4377D0.c
34. f1_2002/40-gameplay.md sub_00437b30 [tier=T2] MISSING=F1C status — "Telemetry File Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00437b30__sub_437B30.c
35. f1_2002/40-gameplay.md sub_00437e80 [tier=T2] MISSING=F1C status — "Merge Sort (Generic Linked List)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00437e80__sub_437E80.c
36. f1_2002/40-gameplay.md sub_00438740 [tier=T2] MISSING=F1C status — "Vehicle Setup Grid Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00438740__sub_438740.c