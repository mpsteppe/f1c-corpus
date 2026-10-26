# Worker D — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_D.md`

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

1. f1_2002/40-gameplay.md sub_004390e0 [tier=T2] MISSING=F1C status — "Ray-Plane Intersection Test"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004390e0__sub_4390E0.c
2. f1_2002/40-gameplay.md sub_00439350 [tier=T1] MISSING=F1C status — "Tire Peak Load Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00439350__sub_439350.c
3. f1_2002/40-gameplay.md sub_004393e0 [tier=T2] MISSING=F1C status — "Tire Lateral/Longitudinal Force Computat"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004393e0__sub_4393E0.c
4. f1_2002/40-gameplay.md sub_004973e0 [tier=T2] MISSING=Port+F1C status — "Tutorial: 4-Panel Instruction Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004973e0__sub_4973E0.c
5. f1_2002/40-gameplay.md sub_00497590 [tier=T2] MISSING=Port+F1C status — "Tutorial: 2-Panel Instruction Renderer ("
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00497590__sub_497590.c
6. f1_2002/40-gameplay.md sub_00497630 [tier=T2] MISSING=Port+F1C status — "Tutorial: Special-Character Instruction "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00497630__sub_497630.c
7. f1_2002/40-gameplay.md sub_00497800 [tier=T2] MISSING=Port+F1C status — "Driving School: Replay/Analysis Telemetr"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00497800__sub_497800.c
8. f1_2002/40-gameplay.md sub_004989a0 [tier=T2] MISSING=Port+F1C status — "Driving School: Menu Navigation Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004989a0__sub_4989A0.c
9. f1_2002/40-gameplay.md sub_00499000 [tier=T2] MISSING=Port+F1C status — "Driving School: Main Menu Init/Transitio"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00499000__sub_499000.c
10. f1_2002/40-gameplay.md sub_00499730 [tier=T2] MISSING=Port+F1C status — "Driving School: Per-Frame Tick / Timer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00499730__sub_499730.c
11. f1_2002/40-gameplay.md sub_00499b80 [tier=T2] MISSING=Port+F1C status — "Driving School: State Machine Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00499b80__sub_499B80.c
12. f1_2002/40-gameplay.md sub_0049c4c0 [tier=T2] MISSING=Port+F1C status — "Screen Element Collection: Animation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049c4c0__sub_49C4C0.c
13. f1_2002/40-gameplay.md sub_0049cc30 [tier=T2] MISSING=Port+F1C status — "Pit Director: Scene Position Setup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049cc30__sub_49CC30.c
14. f1_2002/40-gameplay.md sub_0049d260 [tier=T1] MISSING=Port+F1C status — "Pit Director: SCR File Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049d260__sub_49D260.c
15. f1_2002/40-gameplay.md sub_0049d4e0 [tier=T2] MISSING=Port+F1C status — "Pit Director: Crew Activation Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049d4e0__sub_49D4E0.c
16. f1_2002/40-gameplay.md sub_0049de10 [tier=T2] MISSING=Port+F1C status — "Pit Director: Crew State Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049de10__sub_49DE10.c
17. f1_2002/40-gameplay.md sub_0049e2e0 [tier=T2] MISSING=Port+F1C status — "Pit Director: Driver Slot Iterator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049e2e0__sub_49E2E0.c
18. f1_2002/40-gameplay.md sub_0049e7d0 [tier=T2] MISSING=Port+F1C status — "Pit Director: Animation State Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049e7d0__sub_49E7D0.c
19. f1_2002/40-gameplay.md sub_0049ecf0 [tier=T2] MISSING=Port+F1C status — "Pit Director: Crew Movement Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049ecf0__sub_49ECF0.c
20. f1_2002/40-gameplay.md sub_0049f4f0 [tier=T2] MISSING=Port+F1C status — "Driving School: Ghost Catch Detection"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049f4f0__sub_49F4F0.c
21. f1_2002/40-gameplay.md sub_0049f720 [tier=T2] MISSING=Port+F1C status — "Driving School: Completion Condition Che"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049f720__sub_49F720.c
22. f1_2002/40-gameplay.md sub_0049fb10 [tier=T2] MISSING=Port+F1C status — "UI Object Tree Constructor (~16KB)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0049fb10__sub_49FB10.c
23. f1_2002/40-gameplay.md sub_004a0ee0 [tier=T2] MISSING=Port+F1C status — "UI Object Tree Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004a0ee0__sub_4A0EE0.c
24. f1_2002/40-gameplay.md sub_004b5b00 [tier=T2] MISSING=Port+F1C status — "Fuel Consumption Rate Calculator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b5b00__sub_4B5B00.c
25. f1_2002/40-gameplay.md sub_004b5db0 [tier=T2] MISSING=Port+F1C status — "Fuel Consumption Stochastic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b5db0__sub_4B5DB0.c
26. f1_2002/40-gameplay.md sub_004b63f0 [tier=T2] MISSING=Port+F1C status — "Fuel/Tyre Strategy Per-Vehicle"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b63f0__sub_4B63F0.c
27. f1_2002/40-gameplay.md sub_004b66e0 [tier=T2] MISSING=Port+F1C status — "Track Position Sorting"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b66e0__sub_4B66E0.c
28. f1_2002/40-gameplay.md sub_004b6840 [tier=T2] MISSING=Port+F1C status — "Tyre Fuel Depletion Flush"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b6840__sub_4B6840.c
29. f1_2002/40-gameplay.md sub_004b69f0 [tier=T2] MISSING=Port+F1C status — "Fuel Calc from INI"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b69f0__sub_4B69F0.c
30. f1_2002/40-gameplay.md sub_004b6d50 [tier=T2] MISSING=Port+F1C status — "Career: Track Selector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b6d50__sub_4B6D50.c
31. f1_2002/40-gameplay.md sub_004b72c0 [tier=T2] MISSING=Port+F1C status — "Career: Grid Position Assignment"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b72c0__sub_4B72C0.c
32. f1_2002/40-gameplay.md sub_004b8190 [tier=T2] MISSING=Port+F1C status — "Career: Season Setup Screen Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b8190__sub_4B8190.c
33. f1_2002/40-gameplay.md sub_004b82e0 [tier=T2] MISSING=Port+F1C status — "Career: Season Standings Sort"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b82e0__sub_4B82E0.c
34. f1_2002/40-gameplay.md sub_004b83d0 [tier=T2] MISSING=Port+F1C status — "Career: Season Entry Setup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b83d0__sub_4B83D0.c
35. f1_2002/40-gameplay.md sub_004b8730 [tier=T2] MISSING=Port+F1C status — "Career: Driver Points Tally"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b8730__sub_4B8730.c
36. f1_2002/40-gameplay.md sub_004b87c0 [tier=T2] MISSING=Port+F1C status — "Career: Championship Rank Order"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b87c0__sub_4B87C0.c