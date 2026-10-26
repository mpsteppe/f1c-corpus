# Worker F — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_F.md`

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

1. f1_2002/41-engine.md sub_004d1320 [tier=T2] MISSING=F1C status — "Vehicle State Machine (3 Modes)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d1320__sub_4D1320.c
2. f1_2002/41-engine.md sub_004d1ad0 [tier=T2] MISSING=F1C status — "Car Physics/Controls Update Loop"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d1ad0__sub_4D1AD0.c
3. f1_2002/41-engine.md sub_004d2280 [tier=T2] MISSING=F1C status — "Suspension Spring/Damper Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d2280__sub_4D2280.c
4. f1_2002/41-engine.md sub_004d2500 [tier=T2] MISSING=F1C status — "Wheel Position Packed UID Encoder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d2500__sub_4D2500.c
5. f1_2002/41-engine.md sub_004d3e60 [tier=T2] MISSING=F1C status — "Physics State Zero-Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d3e60__sub_4D3E60.c
6. f1_2002/41-engine.md sub_004d4090 [tier=T2] MISSING=F1C status — "Car Physics State Init (Rotation + Suspe"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d4090__sub_4D4090.c
7. f1_2002/41-engine.md sub_004d44b0 [tier=T2] MISSING=F1C status — "Suspension Spring Rate Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d44b0__sub_4D44B0.c
8. f1_2002/41-engine.md sub_004d4630 [tier=T2] MISSING=F1C status — "Tire Force / Damper Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d4630__sub_4D4630.c
9. f1_2002/41-engine.md sub_004d48b0 [tier=T2] MISSING=F1C status — "Wheel Force + Moment Integration"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d48b0__sub_4D48B0.c
10. f1_2002/41-engine.md sub_004d4d30 [tier=T2] MISSING=F1C status — "Tire Contact Force Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d4d30__sub_4D4D30.c
11. f1_2002/41-engine.md sub_004d4f40 [tier=T2] MISSING=F1C status — "Wheel Force Application + Brake"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d4f40__sub_4D4F40.c
12. f1_2002/41-engine.md sub_004d6820 [tier=T2] MISSING=F1C status — "Brake Torque / Brake Balance Computation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d6820__sub_4D6820.c
13. f1_2002/41-engine.md sub_004d6ab0 [tier=T2] MISSING=F1C status — "Spring Deflection to Force Converter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d6ab0__sub_4D6AB0.c
14. f1_2002/41-engine.md sub_004d6b80 [tier=T2] MISSING=F1C status — "Per-Wheel Brake Torque Limit Comparison"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d6b80__sub_4D6B80.c
15. f1_2002/41-engine.md sub_004d7150 [tier=T2] MISSING=F1C status — "Wheel Contact Force (Brush Model)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d7150__sub_4D7150.c
16. f1_2002/41-engine.md sub_004d7700 [tier=T2] MISSING=F1C status — "Wheel Position Integration + Error Corre"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d7700__sub_4D7700.c
17. f1_2002/41-engine.md sub_004d78e0 [tier=T2] MISSING=F1C status — "Collision Response / Contact Resolution"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d78e0__sub_4D78E0.c
18. f1_2002/41-engine.md sub_004d7c80 [tier=T2] MISSING=F1C status — "Collision Manifold Generation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d7c80__sub_4D7C80.c
19. f1_2002/41-engine.md sub_004d85b0 [tier=T2] MISSING=F1C status — "Collision Detection Sweep/Query"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d85b0__sub_4D85B0.c
20. f1_2002/41-engine.md sub_004d8f90 [tier=T2] MISSING=F1C status — "Impact/Force Response Aggregation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d8f90__sub_4D8F90.c
21. f1_2002/41-engine.md sub_004d9440 [tier=T2] MISSING=F1C status — "Wheel Impulse Force Application"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d9440__sub_4D9440.c
22. f1_2002/41-engine.md sub_004d9900 [tier=T2] MISSING=F1C status — "Force Delta Integration Into Position"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d9900__sub_4D9900.c
23. f1_2002/41-engine.md sub_004d9a20 [tier=T2] MISSING=F1C status — "Wheel-to-Wheel Collision / Debris Spark"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004d9a20__sub_4D9A20.c
24. f1_2002/41-engine.md sub_004da3c0 [tier=T2] MISSING=F1C status — "Collision Plane Projection / Distance Ca"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004da3c0__sub_4DA3C0.c
25. f1_2002/41-engine.md sub_004da8a0 [tier=T2] MISSING=F1C status — "Tire Wear / Damage Timer Decrement"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004da8a0__sub_4DA8A0.c
26. f1_2002/41-engine.md sub_004daf20 [tier=T2] MISSING=F1C status — "Wheel Angular Velocity / Spin Computatio"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004daf20__sub_4DAF20.c
27. f1_2002/41-engine.md sub_004db080 [tier=T2] MISSING=F1C status — "Brake Bias Copy Per Wheel"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004db080__sub_4DB080.c
28. f1_2002/41-engine.md sub_004db120 [tier=T2] MISSING=F1C status — "Suspension Raycast / Wheel-Ground Contac"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004db120__sub_4DB120.c
29. f1_2002/41-engine.md sub_004dbbf0 [tier=T2] MISSING=F1C status — "Replay State Pack / Recording"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dbbf0__sub_4DBBF0.c
30. f1_2002/41-engine.md sub_004dbde0 [tier=T2] MISSING=F1C status — "Contact State Change Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dbde0__sub_4DBDE0.c
31. f1_2002/41-engine.md sub_004dc000 [tier=T2] MISSING=F1C status — "Position Correction / Teleport Snap"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dc000__sub_4DC000.c
32. f1_2002/41-engine.md sub_004dc350 [tier=T2] MISSING=F1C status — "Wheel-Ground Penetration Depth"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dc350__sub_4DC350.c
33. f1_2002/41-engine.md sub_004dc680 [tier=T2] MISSING=F1C status — "Velocity-to-Force Directional Converter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dc680__sub_4DC680.c
34. f1_2002/41-engine.md sub_004dcb10 [tier=T2] MISSING=F1C status — "Full Vehicle State Step Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dcb10__sub_4DCB10.c
35. f1_2002/41-engine.md sub_004dd1e0 [tier=T2] MISSING=F1C status — "Steering Wheel Force Feedback"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dd1e0__sub_4DD1E0.c
36. f1_2002/41-engine.md sub_004dd400 [tier=T2] MISSING=F1C status — "Suspension Force Feedback / Vibration"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x004dd400__sub_4DD400.c