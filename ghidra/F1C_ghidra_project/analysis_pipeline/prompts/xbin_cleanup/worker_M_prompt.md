# Worker M — delta cleanup (39 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_M.md`

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

1. nascar03/41-engine.md sub_0049a930 [tier=T2] MISSING=Port+F1C status — "Global Cache Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049a930__sub_49A930.c
2. nascar03/41-engine.md sub_0049b4e0 [tier=T2] MISSING=Port+F1C status — "Session Object Initializer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049b4e0__sub_49B4E0.c
3. nascar03/41-engine.md sub_0049cb80 [tier=T2] MISSING=Port+F1C status — "Camera Euler Angle Calculator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049cb80__sub_49CB80.c
4. nascar03/41-engine.md sub_0049cc70 [tier=T2] MISSING=Port+F1C status — "Object Proximity Manager"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049cc70__sub_49CC70.c
5. nascar03/41-engine.md sub_0049cdb0 [tier=T2] MISSING=Port+F1C status — "Object Audio Proximity Manager (3 Modes)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049cdb0__sub_49CDB0.c
6. nascar03/41-engine.md sub_0049d360 [tier=T2] MISSING=Port+F1C status — "AI Rubber-Banding Adjuster"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049d360__sub_49D360.c
7. nascar03/41-engine.md sub_0049d9a0 [tier=T1] MISSING=Port+F1C status — "Pit Setup File Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049d9a0__sub_49D9A0.c
8. nascar03/41-engine.md sub_0049dfe0 [tier=T1] MISSING=Port+F1C status — "Pit Stop Option Labels"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049dfe0__sub_49DFE0.c
9. nascar03/41-engine.md sub_0049e240 [tier=T2] MISSING=Port+F1C status — "Pit Stop Setup Data Initializer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049e240__sub_49E240.c
10. nascar03/41-engine.md sub_0049e610 [tier=T2] MISSING=Port+F1C status — "Pit Fuel Selector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049e610__sub_49E610.c
11. nascar03/41-engine.md sub_0049f900 [tier=T2] MISSING=Port+F1C status — "Pit Entry Detector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049f900__sub_49F900.c
12. nascar03/41-engine.md sub_0049fba0 [tier=T2] MISSING=Port+F1C status — "Pit Stop Execution Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049fba0__sub_49FBA0.c
13. nascar03/41-engine.md sub_0049fd40 [tier=T1] MISSING=Port+F1C status — "Pit Stop Time Calculator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0049fd40__sub_49FD40.c
14. nascar03/41-engine.md sub_004a06d0 [tier=T1] MISSING=Port+F1C status — "Pit Request Input Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a06d0__sub_4A06D0.c
15. nascar03/41-engine.md sub_004a08a0 [tier=T2] MISSING=Port+F1C status — "Pit Stop State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a08a0__sub_4A08A0.c
16. nascar03/41-engine.md sub_004a0c30 [tier=T2] MISSING=Port+F1C status — "Vehicle Session Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a0c30__sub_4A0C30.c
17. nascar03/41-engine.md sub_004a2160 [tier=T2] MISSING=Port+F1C status — "Vehicle Session Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a2160__sub_4A2160.c
18. nascar03/41-engine.md sub_004a64a0 [tier=T2] MISSING=Port+F1C status — "Transmission/Drivetrain Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a64a0__sub_4A64A0.c
19. nascar03/41-engine.md sub_004a6a20 [tier=T2] MISSING=Port+F1C status — "Suspension/Steering Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a6a20__sub_4A6A20.c
20. nascar03/41-engine.md sub_004adcd0 [tier=T2] MISSING=Port+F1C status — "Shadow Projection Processor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004adcd0__sub_4ADCD0.c
21. nascar03/41-engine.md sub_004ae3f0 [tier=T2] MISSING=Port+F1C status — "Render Node Transfer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004ae3f0__sub_4AE3F0.c
22. nascar03/41-engine.md sub_004aebd0 [tier=T2] MISSING=Port+F1C status — "Angular Threshold Test (Variant 1)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004aebd0__sub_4AEBD0.c
23. nascar03/41-engine.md sub_004aeca0 [tier=T2] MISSING=Port+F1C status — "Angular Threshold Test (Variant 2)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004aeca0__sub_4AECA0.c
24. nascar03/41-engine.md sub_004afed0 [tier=T2] MISSING=Port+F1C status — "Sorted List Head/Tail Query"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004afed0__sub_4AFED0.c
25. nascar03/41-engine.md sub_004b0100 [tier=T2] MISSING=Port+F1C status — "Range-Constrained Buffer Copy"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b0100__sub_4B0100.c
26. nascar03/41-engine.md sub_004b1070 [tier=T2] MISSING=Port+F1C status — "Depth-Sorted Object Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b1070__sub_4B1070.c
27. nascar03/41-engine.md sub_004b1560 [tier=T2] MISSING=Port+F1C status — "Range-Based Object Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b1560__sub_4B1560.c
28. nascar03/41-engine.md sub_004b18f0 [tier=T2] MISSING=Port+F1C status — "Normalized Time Calculation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b18f0__sub_4B18F0.c
29. nascar03/41-engine.md sub_004b19a0 [tier=T2] MISSING=Port+F1C status — "Physics Query by Channel"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b19a0__sub_4B19A0.c
30. nascar03/41-engine.md sub_004b1a80 [tier=T2] MISSING=Port+F1C status — "Dual-Range Render Dispatch"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b1a80__sub_4B1A80.c
31. nascar03/41-engine.md sub_004b1dc0 [tier=T2] MISSING=Port+F1C status — "Camera FOV/Zoom Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b1dc0__sub_4B1DC0.c
32. nascar03/41-engine.md sub_004b2250 [tier=T2] MISSING=Port+F1C status — "Session State/Flag Manager"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b2250__sub_4B2250.c
33. nascar03/41-engine.md sub_004b3350 [tier=T2] MISSING=Port+F1C status — "304-Byte Stride Object List Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b3350__sub_4B3350.c
34. nascar03/41-engine.md sub_004b3400 [tier=T2] MISSING=Port+F1C status — "436-Byte Stride Object List Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b3400__sub_4B3400.c
35. nascar03/41-engine.md sub_004b3e60 [tier=T2] MISSING=Port+F1C status — "Penalty/Flag Time Accumulator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b3e60__sub_4B3E60.c
36. nascar03/41-engine.md sub_004b4180 [tier=T2] MISSING=Port+F1C status — "Caution Flag Trigger"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b4180__sub_4B4180.c
37. nascar03/41-engine.md sub_004b4410 [tier=T1] MISSING=Port+F1C status — "Pace Car Instruction Message"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b4410__sub_4B4410.c
38. nascar03/41-engine.md sub_004b4ab0 [tier=T2] MISSING=Port+F1C status — "Lap Completion Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b4ab0__sub_4B4AB0.c
39. nascar03/41-engine.md sub_004b5df0 [tier=T2] MISSING=Port+F1C status — "AI Speed Limiter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b5df0__sub_4B5DF0.c