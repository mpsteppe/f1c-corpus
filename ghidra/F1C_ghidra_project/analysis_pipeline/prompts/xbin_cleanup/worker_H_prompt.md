# Worker H — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_H.md`

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

1. f1_2002/42-presentation.md sub_004c2140 [tier=T2] MISSING=Port+F1C status — "Smoke Alpha Fade"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c2140__sub_4C2140.c
2. f1_2002/42-presentation.md sub_004c21f0 [tier=T2] MISSING=Port+F1C status — "Smoke Dual-Layer Fade"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c21f0__sub_4C21F0.c
3. f1_2002/42-presentation.md sub_004c3170 [tier=T2] MISSING=Port+F1C status — "Tire Smoke/Dust Manager"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c3170__sub_4C3170.c
4. f1_2002/42-presentation.md sub_004c4140 [tier=T2] MISSING=Port+F1C status — "Particle System Per-Frame"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c4140__sub_4C4140.c
5. f1_2002/42-presentation.md sub_004c4fa0 [tier=T2] MISSING=Port+F1C status — "Race Position QSort Comparator (Race)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c4fa0__sub_4C4FA0.c
6. f1_2002/42-presentation.md sub_004c5070 [tier=T2] MISSING=Port+F1C status — "Race Position QSort Comparator (Quali)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c5070__sub_4C5070.c
7. f1_2002/42-presentation.md sub_004c5490 [tier=T2] MISSING=Port+F1C status — "Race Position LED Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c5490__sub_4C5490.c
8. f1_2002/42-presentation.md sub_004c5990 [tier=T2] MISSING=Port+F1C status — "Position Slot Assignment"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c5990__sub_4C5990.c
9. f1_2002/42-presentation.md sub_004c5ad0 [tier=T2] MISSING=Port+F1C status — "Race Position Computation + Ordering"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c5ad0__sub_4C5AD0.c
10. f1_2002/42-presentation.md sub_004c6240 [tier=T2] MISSING=Port+F1C status — "Race Session State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004c6240__sub_4C6240.c
11. f1_2002/42-presentation.md sub_004cebf0 [tier=T2] MISSING=F1C status — "HUD Button Prompt Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cebf0__sub_4CEBF0.c
12. f1_2002/42-presentation.md sub_004cf200 [tier=T2] MISSING=F1C status — "HUD Setup Screen Text Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cf200__sub_4CF200.c
13. f1_2002/42-presentation.md sub_004cf3a0 [tier=T2] MISSING=F1C status — "HUD Settings Screen Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cf3a0__sub_4CF3A0.c
14. f1_2002/42-presentation.md sub_004cf500 [tier=T2] MISSING=F1C status — "HUD Multi-Line Display Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cf500__sub_4CF500.c
15. f1_2002/42-presentation.md sub_004cfa00 [tier=T1] MISSING=F1C status — "Texture Material Adjustment"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004cfa00__sub_4CFA00.c
16. f1_2002/42-presentation.md sub_004d3d40 [tier=T2] MISSING=F1C status — "Car Render Setup / Scene Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d3d40__sub_4D3D40.c
17. f1_2002/42-presentation.md sub_004d53b0 [tier=T2] MISSING=F1C status — "Car Render State Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d53b0__sub_4D53B0.c
18. f1_2002/42-presentation.md sub_004e7460 [tier=T2] MISSING=F1C status — "Scissor Rect / Viewport Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e7460__sub_4E7460.c
19. f1_2002/42-presentation.md sub_004e7510 [tier=T2] MISSING=F1C status — "Render State Apply"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e7510__sub_4E7510.c
20. f1_2002/42-presentation.md sub_004e7730 [tier=T2] MISSING=F1C status — "Texture Stage / Sampler Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e7730__sub_4E7730.c
21. f1_2002/42-presentation.md sub_004e7840 [tier=T2] MISSING=F1C status — "Texture Coordinate Gen"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e7840__sub_4E7840.c
22. f1_2002/42-presentation.md sub_004e7910 [tier=T2] MISSING=F1C status — "Alpha Blend State Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e7910__sub_4E7910.c
23. f1_2002/42-presentation.md sub_004e8670 [tier=T2] MISSING=F1C status — "Vertex Shader Constants Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e8670__sub_4E8670.c
24. f1_2002/42-presentation.md sub_004e8710 [tier=T2] MISSING=F1C status — "Scene Vertex Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e8710__sub_4E8710.c
25. f1_2002/42-presentation.md sub_004e89d0 [tier=T2] MISSING=F1C status — "VBO Create / Upload"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e89d0__sub_4E89D0.c
26. f1_2002/42-presentation.md sub_004e8c30 [tier=T2] MISSING=F1C status — "Draw Indexed Primitives"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004e8c30__sub_4E8C30.c
27. f1_2002/42-presentation.md sub_0052dad0 [tier=T2] MISSING=F1C status — "Render Node Tree Traversal"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0052dad0__sub_52DAD0.c
28. f1_2002/42-presentation.md sub_0052dc00 [tier=T2] MISSING=F1C status — "Render Node Tree Insertion"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0052dc00__sub_52DC00.c
29. f1_2002/42-presentation.md sub_0052dda0 [tier=T2] MISSING=F1C status — "Named Render Node Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0052dda0__sub_52DDA0.c
30. f1_2002/42-presentation.md sub_0052e5f0 [tier=T2] MISSING=F1C status — "Audio Volume Ramp/Fade"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0052e5f0__sub_52E5F0.c
31. f1_2002/42-presentation.md sub_00531340 [tier=T2] MISSING=F1C status — "Render Node Insert Ordered"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00531340__sub_531340.c
32. f1_2002/42-presentation.md sub_00531490 [tier=T2] MISSING=F1C status — "Render Tree Node Cleanup/Destroy"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00531490__sub_531490.c
33. f1_2002/42-presentation.md sub_005345f0 [tier=T2] MISSING=F1C status — "Render Node Animation Transform"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005345f0__sub_5345F0.c
34. f1_2002/42-presentation.md sub_00534b80 [tier=T2] MISSING=F1C status — "Render Tree Destroy/Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00534b80__sub_534B80.c
35. f1_2002/42-presentation.md sub_005357b0 [tier=T2] MISSING=F1C status — "Collision Mesh Bounding Box"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005357b0__sub_5357B0.c
36. f1_2002/42-presentation.md sub_00537090 [tier=T2] MISSING=F1C status — "Triangle Intersection Test"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00537090__sub_537090.c