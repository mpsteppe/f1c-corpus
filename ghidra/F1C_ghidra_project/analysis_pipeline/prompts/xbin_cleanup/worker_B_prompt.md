# Worker B — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_B.md`

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

1. f1_2002/40-gameplay.md sub_004158b0 [tier=T2] MISSING=F1C status — "Standings Entry Destructor (With Free Fl"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004158b0__sub_4158B0.c
2. f1_2002/40-gameplay.md sub_00415960 [tier=T2] MISSING=F1C status — "Standings Builder (Driver List Construct"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00415960__sub_415960.c
3. f1_2002/40-gameplay.md sub_00417c50 [tier=T2] MISSING=F1C status — "Sorted List Insertion"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00417c50__sub_417C50.c
4. f1_2002/40-gameplay.md sub_00417dd0 [tier=T2] MISSING=F1C status — "Event Timer/Countdown Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00417dd0__sub_417DD0.c
5. f1_2002/40-gameplay.md sub_004181b0 [tier=T2] MISSING=F1C status — "Event List Defrag/Compaction"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004181b0__sub_4181B0.c
6. f1_2002/40-gameplay.md sub_00418300 [tier=T2] MISSING=F1C status — "Standings Entry Destructor (Variant 2)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00418300__sub_418300.c
7. f1_2002/40-gameplay.md sub_00418a00 [tier=T2] MISSING=F1C status — "Commentary: Player Lap Time Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00418a00__sub_418A00.c
8. f1_2002/40-gameplay.md sub_00418e00 [tier=T2] MISSING=F1C status — "Commentary: Fastest/Slowest Lap Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00418e00__sub_418E00.c
9. f1_2002/40-gameplay.md sub_00419a50 [tier=T2] MISSING=F1C status — "Commentary: DNF Retirement Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00419a50__sub_419A50.c
10. f1_2002/40-gameplay.md sub_00419ae0 [tier=T2] MISSING=F1C status — "Commentary: Pit Exit Timing Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00419ae0__sub_419AE0.c
11. f1_2002/40-gameplay.md sub_00419bd0 [tier=T2] MISSING=F1C status — "Commentary: Overtaking Position Change E"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00419bd0__sub_419BD0.c
12. f1_2002/40-gameplay.md sub_00419f50 [tier=T2] MISSING=F1C status — "Commentary: Penalty Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00419f50__sub_419F50.c
13. f1_2002/40-gameplay.md sub_0041aa40 [tier=T2] MISSING=F1C status — "Commentary: Retirement/DNF Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041aa40__sub_41AA40.c
14. f1_2002/40-gameplay.md sub_0041b180 [tier=T2] MISSING=F1C status — "Commentary: Championship Standings Displ"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041b180__sub_41B180.c
15. f1_2002/40-gameplay.md sub_0041b240 [tier=T2] MISSING=F1C status — "Commentary: Track Intro Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041b240__sub_41B240.c
16. f1_2002/40-gameplay.md sub_0041b450 [tier=T2] MISSING=F1C status — "Commentary: Session Phase Intro"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041b450__sub_41B450.c
17. f1_2002/40-gameplay.md sub_0041b640 [tier=T2] MISSING=F1C status — "Commentary: Gap Time Threshold Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041b640__sub_41B640.c
18. f1_2002/40-gameplay.md sub_0041b720 [tier=T2] MISSING=F1C status — "Commentary: Team Intro Event"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041b720__sub_41B720.c
19. f1_2002/40-gameplay.md sub_0041bf80 [tier=T2] MISSING=F1C status — "MAIN COMMENTARY DISPATCH"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041bf80__sub_41BF80.c
20. f1_2002/40-gameplay.md sub_0041dd70 [tier=T2] MISSING=F1C status — "Driver Selection for Commentary"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041dd70__sub_41DD70.c
21. f1_2002/40-gameplay.md sub_0041e1f0 [tier=T2] MISSING=F1C status — "Driver Championship Lead Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041e1f0__sub_41E1F0.c
22. f1_2002/40-gameplay.md sub_0041e670 [tier=T2] MISSING=F1C status — "Constructor Points Accumulator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041e670__sub_41E670.c
23. f1_2002/40-gameplay.md sub_0041e790 [tier=T2] MISSING=F1C status — "Best Constructor Finder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041e790__sub_41E790.c
24. f1_2002/40-gameplay.md sub_0041e9f0 [tier=T2] MISSING=F1C status — "Best Constructor Finder (Multi-Round Var"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041e9f0__sub_41E9F0.c
25. f1_2002/40-gameplay.md sub_0041ec90 [tier=T2] MISSING=F1C status — "Constructor Championship Lead Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041ec90__sub_41EC90.c
26. f1_2002/40-gameplay.md sub_0041eed0 [tier=T2] MISSING=F1C status — "Driver Finishing Position Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041eed0__sub_41EED0.c
27. f1_2002/40-gameplay.md sub_0041efb0 [tier=T2] MISSING=F1C status — "Driver Championship Status (Dual Top-10 "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041efb0__sub_41EFB0.c
28. f1_2002/40-gameplay.md sub_0041f100 [tier=T2] MISSING=F1C status — "Driver Top-10 Finish Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041f100__sub_41F100.c
29. f1_2002/40-gameplay.md sub_0041f2a0 [tier=T2] MISSING=F1C status — "Driver Consecutive Top-10 Streak"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041f2a0__sub_41F2A0.c
30. f1_2002/40-gameplay.md sub_0041f520 [tier=T2] MISSING=F1C status — "Driver Points Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041f520__sub_41F520.c
31. f1_2002/40-gameplay.md sub_0041f610 [tier=T2] MISSING=F1C status — "Driver Consecutive Points Finish"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0041f610__sub_41F610.c
32. f1_2002/40-gameplay.md sub_00420910 [tier=T2] MISSING=F1C status — "Driver Championship Points Accumulator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00420910__sub_420910.c
33. f1_2002/40-gameplay.md sub_004209b0 [tier=T2] MISSING=F1C status — "Driver Top-10 Finish Counter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004209b0__sub_4209B0.c
34. f1_2002/40-gameplay.md sub_0042a360 [tier=T2] MISSING=F1C status — "Driver Data List Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042a360__sub_42A360.c
35. f1_2002/40-gameplay.md sub_0042a480 [tier=T2] MISSING=F1C status — "Driver Data Comparator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042a480__sub_42A480.c
36. f1_2002/40-gameplay.md sub_0042abd0 [tier=T1] MISSING=F1C status — "Test Result Serializer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0042abd0__sub_42ABD0.c