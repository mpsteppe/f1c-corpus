# Worker N — delta cleanup (39 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_N.md`

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

1. nascar03/41-engine.md sub_004b5f60 [tier=T1] MISSING=Port+F1C status — "Pit State Message Dispatcher"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b5f60__sub_4B5F60.c
2. nascar03/41-engine.md sub_004b6200 [tier=T2] MISSING=Port+F1C status — "Lead Vehicle Query for Pace/Caution"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b6200__sub_4B6200.c
3. nascar03/41-engine.md sub_004b65e0 [tier=T1] MISSING=Port+F1C status — "Lapped Vehicle Under Caution Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004b65e0__sub_4B65E0.c
4. nascar03/41-engine.md sub_004a95b0 [tier=R] MISSING=Port+F1C status — "Player Profile Save/Load"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a95b0__sub_4A95B0.c
5. nascar03/41-engine.md sub_004abb80 [tier=T1] MISSING=Port+F1C status — "Unique Random Integer Generator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004abb80__sub_4ABB80.c
6. nascar03/41-engine.md sub_004abce0 [tier=T2] MISSING=Port+F1C status — "Sky/Cloud Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004abce0__sub_4ABCE0.c
7. nascar03/41-engine.md sub_004ac3d0 [tier=T2] MISSING=Port+F1C status — "View Frustum Culling"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004ac3d0__sub_4AC3D0.c
8. nascar03/41-engine.md sub_004acb60 [tier=T2] MISSING=Port+F1C status — "Global Cache Destructor (Renderer)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004acb60__sub_4ACB60.c
9. nascar03/41-engine.md sub_004acd90 [tier=T2] MISSING=Port+F1C status — "Packed Bitfield/Array Search"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004acd90__sub_4ACD90.c
10. nascar03/41-engine.md sub_004ad0a0 [tier=T2] MISSING=Port+F1C status — "Proximity-Merge Spatial Sort"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004ad0a0__sub_4AD0A0.c
11. nascar03/41-engine.md sub_004ad350 [tier=T2] MISSING=Port+F1C status — "Frame Buffer Reset"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004ad350__sub_4AD350.c
12. nascar03/41-engine.md sub_0047ef00 [tier=T2] MISSING=Port+F1C status — "List Item Selector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0047ef00__sub_47EF00.c
13. nascar03/41-engine.md sub_0047f150 [tier=T2] MISSING=Port+F1C status — "Scroll Bar Geometry Recalculation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0047f150__sub_47F150.c
14. nascar03/41-engine.md sub_0047f380 [tier=T2] MISSING=Port+F1C status — "List Hit-Test"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0047f380__sub_47F380.c
15. nascar03/41-engine.md sub_004a6c30 [tier=T2] MISSING=Port+F1C status — "Drivetrain Mode Selector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a6c30__sub_4A6C30.c
16. nascar03/41-engine.md sub_004a6e60 [tier=T2] MISSING=Port+F1C status — "Suspension Geometry Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a6e60__sub_4A6E60.c
17. nascar03/41-engine.md sub_004a77a0 [tier=T2] MISSING=Port+F1C status — "Damping/Aero Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a77a0__sub_4A77A0.c
18. nascar03/41-engine.md sub_004a8ee0 [tier=T2] MISSING=Port+F1C status — "Vehicle Setup Profile Copier"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a8ee0__sub_4A8EE0.c
19. nascar03/41-engine.md sub_004a91e0 [tier=T2] MISSING=Port+F1C status — "Session Config Reader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004a91e0__sub_4A91E0.c
20. nascar03/41-engine.md sub_004e18e0 [tier=T2] MISSING=Port+F1C status — "Coord Transform (duplicate pattern, see "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004e18e0__sub_4E18E0.c
21. nascar03/41-engine.md sub_004e1970 [tier=T2] MISSING=Port+F1C status — "Coord Transform (duplicate pattern, see "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004e1970__sub_4E1970.c
22. nascar03/41-engine.md sub_004e6ea0 [tier=T2] MISSING=Port+F1C status — "Lap Checkpoint Notify (see above)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004e6ea0__sub_4E6EA0.c
23. nascar03/41-engine.md sub_0043cbc0 [tier=T1] MISSING=F1C status — "HAT Terrain Tree Build"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0043cbc0__sub_43CBC0.c
24. nascar03/41-engine.md sub_0043d180 [tier=T1] MISSING=F1C status — "HAT Terrain Tree Build (variant)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0043d180__sub_43D180.c
25. nascar03/42-presentation.md sub_00440b40 [tier=T2] MISSING=Port — "Controller: Message Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00440b40__sub_440B40.c
26. nascar03/42-presentation.md sub_004414d0 [tier=T2] MISSING=Port — "Controller: Position Clamp + Derivative"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004414d0__sub_4414D0.c
27. nascar03/42-presentation.md sub_00441a20 [tier=T2] MISSING=Port — "Controller: Axis Set with Clamp"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00441a20__sub_441A20.c
28. nascar03/42-presentation.md sub_00446a20 [tier=T2] MISSING=Port — "Controller: Pedal Smoothing"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00446a20__sub_446A20.c
29. nascar03/42-presentation.md sub_00448380 [tier=T2] MISSING=Port — "Animation: Rotation Update (Wheel 1)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00448380__sub_448380.c
30. nascar03/42-presentation.md sub_00448410 [tier=T2] MISSING=Port — "Animation: Rotation Update (Wheel 2)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00448410__sub_448410.c
31. nascar03/42-presentation.md sub_0044e080 [tier=T2] MISSING=Port — "Audio: RMS Analysis"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0044e080__sub_44E080.c
32. nascar03/42-presentation.md sub_0044fc20 [tier=T2] MISSING=Port — "Network: Packet Send Wrapper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0044fc20__sub_44FC20.c
33. nascar03/42-presentation.md sub_0044fe80 [tier=T2] MISSING=Port — "Network: Synchronization Handshake"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0044fe80__sub_44FE80.c
34. nascar03/42-presentation.md sub_00450700 [tier=T2] MISSING=Port — "Network: Time Synchronization"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00450700__sub_450700.c
35. nascar03/42-presentation.md sub_00450100 [tier=T2] MISSING=Port — "Input: Steering Wheel Events"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00450100__sub_450100.c
36. nascar03/42-presentation.md sub_004504d0 [tier=T2] MISSING=Port — "Input: Controller Event Processing"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004504d0__sub_4504D0.c
37. nascar03/42-presentation.md sub_00452140 [tier=T2] MISSING=Port — "Controls: Read Calibrations to Globals"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00452140__sub_452140.c
38. nascar03/42-presentation.md sub_00457220 [tier=T2] MISSING=Port — "UI: Viewport Blit with Clipping"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00457220__sub_457220.c
39. nascar03/42-presentation.md sub_00458d70 [tier=T2] MISSING=Port — "Track: .scn Export with Conditional Sect"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00458d70__sub_458D70.c