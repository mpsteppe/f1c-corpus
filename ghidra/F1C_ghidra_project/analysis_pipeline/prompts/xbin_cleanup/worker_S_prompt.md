# Worker S — delta cleanup (39 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_S.md`

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

1. nascar04/42-presentation.md sub_00475480 [tier=T2] MISSING=F1C status — "List Cleanup + Rebuild"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00475480__sub_475480.c
2. nascar04/42-presentation.md sub_00475560 [tier=T2] MISSING=F1C status — "Screen Dirty Flag + Render"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00475560__sub_475560.c
3. nascar04/42-presentation.md sub_004755f0 [tier=T2] MISSING=F1C status — "Selection Rectangle + Highlight Bar"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004755f0__sub_4755F0.c
4. nascar04/42-presentation.md sub_00475ef0 [tier=T2] MISSING=F1C status — "String Copy with Mode Fallback"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00475ef0__sub_475EF0.c
5. nascar04/42-presentation.md sub_00476f30 [tier=T2] MISSING=F1C status — "Name Matching in List"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00476f30__sub_476F30.c
6. nascar04/42-presentation.md sub_00477ba0 [tier=T2] MISSING=F1C status — "Wide-Char List Sort Comparator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00477ba0__sub_477BA0.c
7. nascar04/42-presentation.md sub_0047b1a0 [tier=T2] MISSING=F1C status — "Menu Item List Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047b1a0__sub_47B1A0.c
8. nascar04/42-presentation.md sub_0047b240 [tier=T2] MISSING=F1C status — "Screen Header Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047b240__sub_47B240.c
9. nascar04/42-presentation.md sub_0047b940 [tier=T2] MISSING=F1C status — "List Search by Pattern"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047b940__sub_47B940.c
10. nascar04/42-presentation.md sub_0047dc50 [tier=T2] MISSING=F1C status — "Button Visibility/State"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047dc50__sub_47DC50.c
11. nascar04/42-presentation.md sub_0047e180 [tier=T2] MISSING=F1C status — "Screen Router"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047e180__sub_47E180.c
12. nascar04/42-presentation.md sub_004809f0 [tier=T2] MISSING=F1C status — "Replay Editor Commands"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004809f0__sub_4809F0.c
13. nascar04/42-presentation.md sub_004836b0 [tier=T2] MISSING=F1C status — "Slider Value Clamp + Bind"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004836b0__sub_4836B0.c
14. nascar04/42-presentation.md sub_004839f0 [tier=T2] MISSING=F1C status — "Screen State Toggle (Mouse)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004839f0__sub_4839F0.c
15. nascar04/42-presentation.md sub_00484ca0 [tier=T2] MISSING=F1C status — "Slider Tier Value Clamp"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00484ca0__sub_484CA0.c
16. nascar04/42-presentation.md sub_00485010 [tier=T2] MISSING=F1C status — "Spin Control Value Inc/Dec"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00485010__sub_485010.c
17. nascar04/42-presentation.md sub_00485990 [tier=T2] MISSING=F1C status — "Track/Series Selection List Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00485990__sub_485990.c
18. nascar04/42-presentation.md sub_004879d0 [tier=T2] MISSING=F1C status — "Main Menu Screen Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x004879d0__sub_4879D0.c
19. nascar04/42-presentation.md sub_00487ae0 [tier=T2] MISSING=F1C status — "Screen Navigation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00487ae0__sub_487AE0.c
20. nascar04/42-presentation.md sub_00488030 [tier=T2] MISSING=F1C status — "Spin Control Display Format"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00488030__sub_488030.c
21. nascar04/42-presentation.md sub_00488230 [tier=T2] MISSING=F1C status — "Slider Value Clamp + Bind v2"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00488230__sub_488230.c
22. nascar04/42-presentation.md sub_0048a8b0 [tier=T2] MISSING=F1C status — "Screen State Toggle (Keyboard)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048a8b0__sub_48A8B0.c
23. nascar04/42-presentation.md sub_0048afb0 [tier=T2] MISSING=F1C status — "Screen State Sync"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048afb0__sub_48AFB0.c
24. nascar04/42-presentation.md sub_0048b120 [tier=T2] MISSING=F1C status — "Volume Slider Adjust"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048b120__sub_48B120.c
25. nascar04/42-presentation.md sub_0048c040 [tier=T2] MISSING=F1C status — "Audio Track Selector"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048c040__sub_48C040.c
26. nascar04/42-presentation.md sub_0048c120 [tier=T2] MISSING=F1C status — "Audio Track Selector v2"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048c120__sub_48C120.c
27. nascar04/42-presentation.md sub_0048c1f0 [tier=T2] MISSING=F1C status — "Audio Track Selector v3"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0048c1f0__sub_48C1F0.c
28. nascar04/42-presentation.md sub_0049e9a0 [tier=T2] MISSING=Port+F1C status — "Screen Object Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0049e9a0__sub_49E9A0.c
29. nascar04/42-presentation.md sub_00504220 [tier=T2] MISSING=Port+F1C status — "Colored Quad Renderer"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00504220__sub_504220.c
30. nascar04/43-io.md sub_00467970 [tier=T1] MISSING=F1C status — "Call-Vote Message Dispatcher"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00467970__sub_467970.c
31. nascar04/43-io.md sub_00468000 [tier=T1] MISSING=F1C status — "Dedicated Server Launcher"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00468000__sub_468000.c
32. nascar04/43-io.md sub_0046b1a0 [tier=T1] MISSING=F1C status — "Dedicated Server Config (.dsm) File Pars"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046b1a0__sub_46B1A0.c
33. nascar04/43-io.md sub_0046b6e0 [tier=T1] MISSING=F1C status — "Dedicated Server Config (.dsm) File Writ"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046b6e0__sub_46B6E0.c
34. nascar04/43-io.md sub_0046d660 [tier=T1] MISSING=F1C status — "Incoming Vote/Text Command Parser"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0046d660__sub_46D660.c
35. nascar04/43-io.md sub_00479060 [tier=T2] MISSING=F1C status — "Path String Split Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00479060__sub_479060.c
36. nascar04/43-io.md sub_0047e2f0 [tier=T1] MISSING=F1C status — "Replay File Load"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047e2f0__sub_47E2F0.c
37. nascar04/43-io.md sub_0047ff60 [tier=T2] MISSING=F1C status — "File Listing Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x0047ff60__sub_47FF60.c
38. nascar04/43-io.md sub_00480310 [tier=T2] MISSING=F1C status — "File Type Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00480310__sub_480310.c
39. nascar04/43-io.md sub_00480c70 [tier=T2] MISSING=F1C status — "Replay File Save"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\decompiled\0x00480c70__sub_480C70.c