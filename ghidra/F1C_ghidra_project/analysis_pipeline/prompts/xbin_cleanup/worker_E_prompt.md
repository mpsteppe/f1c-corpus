# Worker E — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_E.md`

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

1. f1_2002/40-gameplay.md sub_004b8910 [tier=T2] MISSING=Port+F1C status — "Career: Season State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b8910__sub_4B8910.c
2. f1_2002/40-gameplay.md sub_004b9090 [tier=T2] MISSING=Port+F1C status — "Career: Season File Parser"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b9090__sub_4B9090.c
3. f1_2002/40-gameplay.md sub_004b93b0 [tier=T2] MISSING=Port+F1C status — "Career: Data Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b93b0__sub_4B93B0.c
4. f1_2002/40-gameplay.md sub_004b9960 [tier=T2] MISSING=Port+F1C status — "Career: Season Per-Frame Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b9960__sub_4B9960.c
5. f1_2002/40-gameplay.md sub_004b99f0 [tier=T1] MISSING=Port+F1C status — "Career: Season Scoring"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004b99f0__sub_4B99F0.c
6. f1_2002/40-gameplay.md sub_004ba060 [tier=T2] MISSING=Port+F1C status — "Career: Data Struct Ctor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ba060__sub_4BA060.c
7. f1_2002/40-gameplay.md sub_004ba980 [tier=T2] MISSING=Port+F1C status — "Career: Driver List Query"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ba980__sub_4BA980.c
8. f1_2002/40-gameplay.md sub_004bb300 [tier=T2] MISSING=Port+F1C status — "Career: Data Deep-Copy"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bb300__sub_4BB300.c
9. f1_2002/40-gameplay.md sub_004bb820 [tier=T2] MISSING=Port+F1C status — "Career: Season Driver Remove"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bb820__sub_4BB820.c
10. f1_2002/40-gameplay.md sub_004bbe20 [tier=T2] MISSING=Port+F1C status — "Track Name String Parser"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bbe20__sub_4BBE20.c
11. f1_2002/40-gameplay.md sub_004bc060 [tier=T2] MISSING=Port+F1C status — "Track List Scanner"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bc060__sub_4BC060.c
12. f1_2002/40-gameplay.md sub_004e6140 [tier=T2] MISSING=F1C status — "Fuel Consumption Calculation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e6140__sub_4E6140.c
13. f1_2002/41-engine.md sub_00422af0 [tier=T2] MISSING=F1C status — "Vector Math: Dot/Cross Product Projectio"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00422af0__sub_422AF0.c
14. f1_2002/41-engine.md sub_00422e30 [tier=T2] MISSING=F1C status — "Vehicle Physics State Init/Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00422e30__sub_422E30.c
15. f1_2002/41-engine.md sub_00423780 [tier=T2] MISSING=F1C status — "AI Vehicle Full Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00423780__sub_423780.c
16. f1_2002/41-engine.md sub_00423d00 [tier=T2] MISSING=F1C status — "AI Physics Sub-Object Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00423d00__sub_423D00.c
17. f1_2002/41-engine.md sub_00423ed0 [tier=T2] MISSING=F1C status — "AI Command Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00423ed0__sub_423ED0.c
18. f1_2002/41-engine.md sub_00424070 [tier=T2] MISSING=F1C status — "AI Main Update Tick"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00424070__sub_424070.c
19. f1_2002/41-engine.md sub_00424760 [tier=T2] MISSING=F1C status — "AI Recovery/Steering Behaviour"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00424760__sub_424760.c
20. f1_2002/41-engine.md sub_00424a20 [tier=T2] MISSING=F1C status — "AI Path Following + Speed Control"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00424a20__sub_424A20.c
21. f1_2002/41-engine.md sub_00425290 [tier=T2] MISSING=F1C status — "AI Steering Angle Calculation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00425290__sub_425290.c
22. f1_2002/41-engine.md sub_004254c0 [tier=T2] MISSING=F1C status — "AI Throttle/Brake Control"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004254c0__sub_4254C0.c
23. f1_2002/41-engine.md sub_00425640 [tier=T2] MISSING=F1C status — "AI Track Position / Path Spline Tracking"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00425640__sub_425640.c
24. f1_2002/41-engine.md sub_00425ef0 [tier=T2] MISSING=F1C status — "AI Speed Limiter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00425ef0__sub_425EF0.c
25. f1_2002/41-engine.md sub_00426210 [tier=T2] MISSING=F1C status — "AI Collision Avoidance + Opponent Manage"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00426210__sub_426210.c
26. f1_2002/41-engine.md sub_004285e0 [tier=T2] MISSING=F1C status — "AI Pit Stop / Session Timing Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004285e0__sub_4285E0.c
27. f1_2002/41-engine.md sub_00429270 [tier=T2] MISSING=F1C status — "AI Pit Exit / Out-Lap Timer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00429270__sub_429270.c
28. f1_2002/41-engine.md sub_00429470 [tier=T2] MISSING=F1C status — "AI Session End / Retirement Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00429470__sub_429470.c
29. f1_2002/41-engine.md sub_00429840 [tier=T2] MISSING=F1C status — "AI Opponent Proximity Radar"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00429840__sub_429840.c
30. f1_2002/41-engine.md sub_00429f70 [tier=T2] MISSING=F1C status — "AI Overtake/Passing Decision Logic"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00429f70__sub_429F70.c
31. f1_2002/41-engine.md sub_004310a0 [tier=T2] MISSING=F1C status — "Vehicle Steering Force Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004310a0__sub_4310A0.c
32. f1_2002/41-engine.md sub_0046bd85 [tier=T2] MISSING=F1C status — "Byte Negation/Complement Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0046bd85__sub_46BD85.c
33. f1_2002/41-engine.md sub_004cfc80 [tier=T2] MISSING=F1C status — "AABB Bounding Box Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cfc80__sub_4CFC80.c
34. f1_2002/41-engine.md sub_004cfec0 [tier=T2] MISSING=F1C status — "Support Point / GJK Support Function"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cfec0__sub_4CFEC0.c
35. f1_2002/41-engine.md sub_004cffc0 [tier=T2] MISSING=F1C status — "Bounding Sphere Squared Radius"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cffc0__sub_4CFFC0.c
36. f1_2002/41-engine.md sub_004d0fe0 [tier=T2] MISSING=F1C status — "Vehicle State Reset / Initialize"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d0fe0__sub_4D0FE0.c