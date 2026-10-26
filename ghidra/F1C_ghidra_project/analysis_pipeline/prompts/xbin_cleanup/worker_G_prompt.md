# Worker G — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_G.md`

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

1. f1_2002/41-engine.md sub_004dd660 [tier=T2] MISSING=F1C status — "Brake Pressure Scaling"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dd660__sub_4DD660.c
2. f1_2002/41-engine.md sub_004e5620 [tier=T2] MISSING=F1C status — "BSP/Tree Node AABB Delta"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e5620__sub_4E5620.c
3. f1_2002/41-engine.md sub_004e6d20 [tier=T2] MISSING=F1C status — "Interpolated Table Generation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e6d20__sub_4E6D20.c
4. f1_2002/41-engine.md sub_004de500 [tier=T2] MISSING=F1C status — "Brake Torque Initialization"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004de500__sub_4DE500.c
5. f1_2002/41-engine.md sub_004dd780 [tier=T2] MISSING=F1C status — "Physics State Copy (Full Vehicle)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dd780__sub_4DD780.c
6. f1_2002/41-engine.md sub_004dd9d0 [tier=T2] MISSING=F1C status — "Brake Setup from Car Setup Data"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dd9d0__sub_4DD9D0.c
7. f1_2002/41-engine.md sub_004ddc20 [tier=T2] MISSING=F1C status — "Vehicle Recovery / Reset on Track"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ddc20__sub_4DDC20.c
8. f1_2002/41-engine.md sub_004de110 [tier=T2] MISSING=F1C status — "Spin-out / Off-track Detection"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004de110__sub_4DE110.c
9. f1_2002/41-engine.md sub_004df000 [tier=T2] MISSING=F1C status — "Render State / Tint Parameter Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004df000__sub_4DF000.c
10. f1_2002/41-engine.md sub_004e3140 [tier=T2] MISSING=F1C status — "RPM-to-Sound Pitch Mapping"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e3140__sub_4E3140.c
11. f1_2002/41-engine.md sub_004e4200 [tier=T2] MISSING=F1C status — "Loading Screen + File Mount"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e4200__sub_4E4200.c
12. f1_2002/41-engine.md sub_004e54f0 [tier=T2] MISSING=F1C status — "Vertex/Polygon Group Zero-Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e54f0__sub_4E54F0.c
13. f1_2002/42-presentation.md sub_004ac410 [tier=T2] MISSING=Port+F1C status — "Network: Dead-Reckoning Error (Angular)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ac410__sub_4AC410.c
14. f1_2002/42-presentation.md sub_004ac4e0 [tier=T2] MISSING=Port+F1C status — "Network: Dead-Reckoning Error (Accelerat"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ac4e0__sub_4AC4E0.c
15. f1_2002/42-presentation.md sub_004ae390 [tier=T2] MISSING=Port+F1C status — "Race Session: Position Scroll/Clamp"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ae390__sub_4AE390.c
16. f1_2002/42-presentation.md sub_004ae780 [tier=T2] MISSING=Port+F1C status — "Race Session: Per-Frame Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004ae780__sub_4AE780.c
17. f1_2002/42-presentation.md sub_004aea40 [tier=T2] MISSING=Port+F1C status — "Race Session: Driver Matching"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004aea40__sub_4AEA40.c
18. f1_2002/42-presentation.md sub_004bcb40 [tier=T2] MISSING=Port+F1C status — "Renderable Reset"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bcb40__sub_4BCB40.c
19. f1_2002/42-presentation.md sub_004bcbd0 [tier=T2] MISSING=Port+F1C status — "Rendered Vehicle Position Refresh"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bcbd0__sub_4BCBD0.c
20. f1_2002/42-presentation.md sub_004bcea0 [tier=T2] MISSING=Port+F1C status — "Rendered Vehicle State Push"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bcea0__sub_4BCEA0.c
21. f1_2002/42-presentation.md sub_004bd050 [tier=T2] MISSING=Port+F1C status — "Rendered Vehicle D3D Transform"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bd050__sub_4BD050.c
22. f1_2002/42-presentation.md sub_004bd370 [tier=T2] MISSING=Port+F1C status — "Career: Track Config Copy"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bd370__sub_4BD370.c
23. f1_2002/42-presentation.md sub_004bd7a0 [tier=T2] MISSING=Port+F1C status — "UI Animation Timer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bd7a0__sub_4BD7A0.c
24. f1_2002/42-presentation.md sub_004bd840 [tier=T2] MISSING=Port+F1C status — "UI Animation Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bd840__sub_4BD840.c
25. f1_2002/42-presentation.md sub_004bd8f0 [tier=T2] MISSING=Port+F1C status — "Race Start Countdown Lights"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004bd8f0__sub_4BD8F0.c
26. f1_2002/42-presentation.md sub_004be4b0 [tier=T2] MISSING=Port+F1C status — "Per-Frame Rendering Kickoff"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004be4b0__sub_4BE4B0.c
27. f1_2002/42-presentation.md sub_004befc0 [tier=T2] MISSING=Port+F1C status — "Announcer Audio Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004befc0__sub_4BEFC0.c
28. f1_2002/42-presentation.md sub_004c0b10 [tier=T2] MISSING=Port+F1C status — "Smoke Particle Spawn"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c0b10__sub_4C0B10.c
29. f1_2002/42-presentation.md sub_004c0c50 [tier=T2] MISSING=Port+F1C status — "Smoke Particle Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c0c50__sub_4C0C50.c
30. f1_2002/42-presentation.md sub_004c0d70 [tier=T2] MISSING=Port+F1C status — "Smoke Particle Vertex Setup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c0d70__sub_4C0D70.c
31. f1_2002/42-presentation.md sub_004c0ed0 [tier=T2] MISSING=Port+F1C status — "Smoke Particle Physics Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c0ed0__sub_4C0ED0.c
32. f1_2002/42-presentation.md sub_004c1080 [tier=T2] MISSING=Port+F1C status — "Smoke Quad Vertex Calc"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c1080__sub_4C1080.c
33. f1_2002/42-presentation.md sub_004c1280 [tier=T2] MISSING=Port+F1C status — "Smoke Billboard Transform"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c1280__sub_4C1280.c
34. f1_2002/42-presentation.md sub_004c13c0 [tier=T2] MISSING=Port+F1C status — "Smoke Velocity/Rotation Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c13c0__sub_4C13C0.c
35. f1_2002/42-presentation.md sub_004c1cd0 [tier=T2] MISSING=Port+F1C status — "Smoke Trail Physics + D3D"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c1cd0__sub_4C1CD0.c
36. f1_2002/42-presentation.md sub_004c1f40 [tier=T2] MISSING=Port+F1C status — "Tire Smoke Vertex Create"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c1f40__sub_4C1F40.c