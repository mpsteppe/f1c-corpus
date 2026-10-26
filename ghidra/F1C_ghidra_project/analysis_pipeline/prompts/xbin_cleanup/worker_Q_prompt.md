# Worker Q — delta cleanup (41 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_Q.md`

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

1. nascar04/40-gameplay.md sub_00468410 [tier=T2] MISSING=F1C status — "Session State: Countdown Start"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00468410__sub_468410.c
2. nascar04/40-gameplay.md sub_00468560 [tier=T2] MISSING=F1C status — "Session Init: Connect, Track, Grid"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00468560__sub_468560.c
3. nascar04/40-gameplay.md sub_00468870 [tier=T1] MISSING=F1C status — "Session Sync/Handshake"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00468870__sub_468870.c
4. nascar04/40-gameplay.md sub_004689f0 [tier=T2] MISSING=F1C status — "Session Update: Scoreboard + Connection "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004689f0__sub_4689F0.c
5. nascar04/40-gameplay.md sub_0046ba10 [tier=T2] MISSING=F1C status — "Vote Timer / Session Transition"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046ba10__sub_46BA10.c
6. nascar04/40-gameplay.md sub_0046c520 [tier=T2] MISSING=F1C status — "Server Lobby UI Refresh"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046c520__sub_46C520.c
7. nascar04/40-gameplay.md sub_0046c780 [tier=T2] MISSING=F1C status — "Server Lobby: Start Game"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046c780__sub_46C780.c
8. nascar04/40-gameplay.md sub_0046c8b0 [tier=T1] MISSING=F1C status — "Server Lobby State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046c8b0__sub_46C8B0.c
9. nascar04/40-gameplay.md sub_0046d8b0 [tier=T2] MISSING=F1C status — "Server Settings Commit"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046d8b0__sub_46D8B0.c
10. nascar04/40-gameplay.md sub_0046ef60 [tier=T2] MISSING=F1C status — "Race Session Constructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046ef60__sub_46EF60.c
11. nascar04/40-gameplay.md sub_0046f350 [tier=T2] MISSING=F1C status — "Race Session Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046f350__sub_46F350.c
12. nascar04/40-gameplay.md sub_004705f0 [tier=T2] MISSING=F1C status — "Career Event Name Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004705f0__sub_4705F0.c
13. nascar04/40-gameplay.md sub_004717c0 [tier=T1] MISSING=F1C status — "Career Replay Camera Placement Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004717c0__sub_4717C0.c
14. nascar04/40-gameplay.md sub_00471d90 [tier=T2] MISSING=F1C status — "Career Screen Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00471d90__sub_471D90.c
15. nascar04/40-gameplay.md sub_004722f0 [tier=T2] MISSING=F1C status — "Career Mechanic/Crew Skill Upgrade"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004722f0__sub_4722F0.c
16. nascar04/40-gameplay.md sub_00478170 [tier=T2] MISSING=F1C status — "Race Results Table Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00478170__sub_478170.c
17. nascar04/40-gameplay.md sub_00478690 [tier=T2] MISSING=F1C status — "Season Schedule Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00478690__sub_478690.c
18. nascar04/40-gameplay.md sub_00479360 [tier=T2] MISSING=F1C status — "Championship Standings Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00479360__sub_479360.c
19. nascar04/40-gameplay.md sub_00479de0 [tier=T2] MISSING=F1C status — "List Cleanup + Display Rebuild"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00479de0__sub_479DE0.c
20. nascar04/40-gameplay.md sub_0047a420 [tier=T2] MISSING=F1C status — "Driver Results Row Formatter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047a420__sub_47A420.c
21. nascar04/40-gameplay.md sub_0047a940 [tier=T2] MISSING=F1C status — "Results Change Detection"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047a940__sub_47A940.c
22. nascar04/40-gameplay.md sub_0047ae90 [tier=T1] MISSING=F1C status — "Simulation Wait Loop"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047ae90__sub_47AE90.c
23. nascar04/40-gameplay.md sub_0047bb30 [tier=T2] MISSING=F1C status — "Session Results Detail Table"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047bb30__sub_47BB30.c
24. nascar04/40-gameplay.md sub_0047c130 [tier=T2] MISSING=F1C status — "Driver Insertion Sort"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047c130__sub_47C130.c
25. nascar04/40-gameplay.md sub_0047c230 [tier=T2] MISSING=F1C status — "Timing Results Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047c230__sub_47C230.c
26. nascar04/40-gameplay.md sub_0047c940 [tier=T1] MISSING=F1C status — "Season Awards Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047c940__sub_47C940.c
27. nascar04/40-gameplay.md sub_0047e230 [tier=T1] MISSING=F1C status — "MP Vehicle Selection + Lobby"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047e230__sub_47E230.c
28. nascar04/40-gameplay.md sub_0047e6a0 [tier=T2] MISSING=F1C status — "Simulation Run Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047e6a0__sub_47E6A0.c
29. nascar04/40-gameplay.md sub_0047ef10 [tier=T2] MISSING=F1C status — "Session Start Flow"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047ef10__sub_47EF10.c
30. nascar04/40-gameplay.md sub_00480f70 [tier=R] MISSING=F1C status — "Screen Router (Champ/MP/Career)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00480f70__sub_480F70.c
31. nascar04/40-gameplay.md sub_004814c0 [tier=T1] MISSING=F1C status — "Career Engineering Cost Check v1"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004814c0__sub_4814C0.c
32. nascar04/40-gameplay.md sub_00481600 [tier=T1] MISSING=F1C status — "Career Engineering Cost Check v2"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00481600__sub_481600.c
33. nascar04/40-gameplay.md sub_00481a90 [tier=T1] MISSING=F1C status — "Career Sponsor Negotiation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00481a90__sub_481A90.c
34. nascar04/40-gameplay.md sub_00481ce0 [tier=T1] MISSING=F1C status — "Career R&D Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00481ce0__sub_481CE0.c
35. nascar04/40-gameplay.md sub_00481f10 [tier=T1] MISSING=F1C status — "Career Building Purchase"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00481f10__sub_481F10.c
36. nascar04/40-gameplay.md sub_00482110 [tier=T1] MISSING=F1C status — "Career Parts Selling"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00482110__sub_482110.c
37. nascar04/40-gameplay.md sub_00482320 [tier=T1] MISSING=F1C status — "Career Parts Repair"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00482320__sub_482320.c
38. nascar04/40-gameplay.md sub_00482a00 [tier=T2] MISSING=F1C status — "Career Text Input Fields Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00482a00__sub_482A00.c
39. nascar04/40-gameplay.md sub_00482c50 [tier=T2] MISSING=F1C status — "Career Option Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00482c50__sub_482C50.c
40. nascar04/40-gameplay.md sub_00482e90 [tier=T2] MISSING=F1C status — "Career Option Get"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00482e90__sub_482E90.c
41. nascar04/40-gameplay.md sub_004832c0 [tier=T2] MISSING=F1C status — "Career Field Display Update"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004832c0__sub_4832C0.c