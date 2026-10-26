# Worker J — delta cleanup (35 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_J.md`

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

1. f1_2002/42-presentation.md sub_0057dd50 [tier=T2] MISSING=F1C status — "Network RX Packet Decode"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0057dd50__sub_57DD50.c
2. f1_2002/42-presentation.md sub_00507450 [tier=T1] MISSING=F1C status — "longjmp Wrapper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00507450__sub_507450.c
3. f1_2002/42-presentation.md sub_006ea497 [tier=T2] MISSING=F1C status — "SEH Unwind Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x006ea497__sub_6EA497.c
4. f1_2002/42-presentation.md sub_006eb349 [tier=T2] MISSING=F1C status — "SEH Exception Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x006eb349__sub_6EB349.c
5. f1_2002/42-presentation.md sub_006ed56e [tier=T2] MISSING=F1C status — "SEH Unwinder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x006ed56e__sub_6ED56E.c
6. f1_2002/42-presentation.md sub_0056a1b9 [tier=T2] MISSING=F1C status — "std::ios_base::Init Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0056a1b9____0Init@ios_base@std@@QAE@XZ.c
7. f1_2002/42-presentation.md sub_0056b238 [tier=T2] MISSING=F1C status — "std::_Winit Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0056b238____0_Winit@std@@QAE@XZ.c
8. f1_2002/42-presentation.md sub_0056c468 [tier=T2] MISSING=F1C status — "std::locale::_Init (MSVC CRT)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0056c468____Init@locale@std@@CAPAV_Locimp@12@XZ.c
9. f1_2002/42-presentation.md sub_0056c62e [tier=T2] MISSING=F1C status — "std::locale::_Locimp Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0056c62e____1_Locimp@locale@std@@UAE@XZ.c
10. f1_2002/42-presentation.md sub_0056d5d8 [tier=T2] MISSING=F1C status — "setlocale (MSVC CRT)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0056d5d8___setlocale.c
11. f1_2002/42-presentation.md sub_00579fbd [tier=T1] MISSING=F1C status — "_fseeki64 (MSVC CRT)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00579fbd____fseeki64.c
12. f1_2002/42-presentation.md sub_004d3b90 [tier=T2] MISSING=F1C status — "� Rotation Integration with Clamping"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d3b90__sub_4D3B90.c
13. f1_2002/42-presentation.md sub_004d7440 [tier=T2] MISSING=F1C status — "� Collision Detection / Proximity Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d7440__sub_4D7440.c
14. f1_2002/42-presentation.md sub_0050cca0 [tier=T2] MISSING=F1C status — "� Winsock VTable Init (variant 2)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0050cca0__sub_50CCA0.c
15. f1_2002/43-io.md sub_004af750 [tier=T2] MISSING=Port+F1C status — "Network: Command Buffer Flush"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004af750__sub_4AF750.c
16. f1_2002/43-io.md sub_004af9c0 [tier=T2] MISSING=Port+F1C status — "Race Session: Camera Scroll State Machin"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004af9c0__sub_4AF9C0.c
17. f1_2002/43-io.md sub_004aff40 [tier=T2] MISSING=Port+F1C status — "Race Session: UI State Setter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004aff40__sub_4AFF40.c
18. f1_2002/43-io.md sub_004b0c80 [tier=T2] MISSING=Port+F1C status — "Network: Linked-List Node Pop"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b0c80__sub_4B0C80.c
19. f1_2002/43-io.md sub_004b1080 [tier=T2] MISSING=Port+F1C status — "Network: Linked-list Destructor (532B st"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b1080__sub_4B1080.c
20. f1_2002/43-io.md sub_004b1130 [tier=T2] MISSING=Port+F1C status — "Network: Linked-list Destructor (608B st"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b1130__sub_4B1130.c
21. f1_2002/43-io.md sub_004b3360 [tier=T2] MISSING=Port+F1C status — "Network: Linked-List Destructor (vtable)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b3360__sub_4B3360.c
22. f1_2002/43-io.md sub_004b3d10 [tier=T2] MISSING=Port+F1C status — "Setup Data Tree Walker"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b3d10__sub_4B3D10.c
23. f1_2002/43-io.md sub_004b3ff0 [tier=T2] MISSING=Port+F1C status — "Setup Section Parser"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b3ff0__sub_4B3FF0.c
24. f1_2002/43-io.md sub_004b4220 [tier=T2] MISSING=Port+F1C status — "Setup Parser Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b4220__sub_4B4220.c
25. f1_2002/43-io.md sub_004b4410 [tier=T2] MISSING=Port+F1C status — "Setup File Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b4410__sub_4B4410.c
26. f1_2002/43-io.md sub_004c8720 [tier=T2] MISSING=Port+F1C status — "Network Weather State Serialize"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c8720__sub_4C8720.c
27. f1_2002/43-io.md sub_004c9330 [tier=T2] MISSING=Port+F1C status — "Cubic Spline Interpolation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c9330__sub_4C9330.c
28. f1_2002/43-io.md sub_004caba0 [tier=T2] MISSING=Port+F1C status — "Animated Texture Frame Advance"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004caba0__sub_4CABA0.c
29. f1_2002/43-io.md sub_004cb300 [tier=T2] MISSING=Port+F1C status — "UI Screen Selection"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cb300__sub_4CB300.c
30. f1_2002/43-io.md sub_004cb480 [tier=T2] MISSING=Port+F1C status — "UI Widget List Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cb480__sub_4CB480.c
31. f1_2002/43-io.md sub_004cb510 [tier=T2] MISSING=Port+F1C status — "UI Widget List Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cb510__sub_4CB510.c
32. f1_2002/43-io.md sub_004cbc00 [tier=T2] MISSING=Port+F1C status — "Render Target Release"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cbc00__sub_4CBC00.c
33. f1_2002/43-io.md sub_004cccf0 [tier=T2] MISSING=Port+F1C status — "Subsurface Scattering Render"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cccf0__sub_4CCCF0.c
34. f1_2002/43-io.md sub_004cd550 [tier=T2] MISSING=Port+F1C status — "Pit Lane Speed Limiter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cd550__sub_4CD550.c
35. f1_2002/43-io.md sub_004cda90 [tier=T2] MISSING=Port+F1C status — "Pit Speed Limiter Finish Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cda90__sub_4CDA90.c