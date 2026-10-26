# Worker P — delta cleanup (34 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_P.md`

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

1. nascar03/42-presentation.md sub_00553cb0 [tier=T2] MISSING=F1C status — "MIDI All-Notes-Off"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553cb0__sub_553CB0.c
2. nascar03/42-presentation.md sub_005540d0 [tier=T2] MISSING=F1C status — "MIDI Reset"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005540d0__sub_5540D0.c
3. nascar03/42-presentation.md sub_00554420 [tier=T2] MISSING=F1C status — "MIDI Master Volume"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00554420__sub_554420.c
4. nascar03/42-presentation.md sub_00554530 [tier=T1] MISSING=F1C status — "MIDI Data Send"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00554530__sub_554530.c
5. nascar03/42-presentation.md sub_00554580 [tier=T2] MISSING=F1C status — "MIDI Short Message"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00554580__sub_554580.c
6. nascar03/42-presentation.md sub_00554640 [tier=T2] MISSING=F1C status — "MIDI Long Message"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00554640__sub_554640.c
7. nascar03/42-presentation.md sub_00554880 [tier=T2] MISSING=F1C status — "MIDI SysEx"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00554880__sub_554880.c
8. nascar03/42-presentation.md sub_005549e0 [tier=T2] MISSING=F1C status — "MIDI Timing"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005549e0__sub_5549E0.c
9. nascar03/43-io.md sub_0044db90 [tier=T2] MISSING=Port — "File: Size Verification"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0044db90__sub_44DB90.c
10. nascar03/43-io.md sub_00451520 [tier=T2] MISSING=Port — "Session: File Existence Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00451520__sub_451520.c
11. nascar03/43-io.md sub_004552b0 [tier=T2] MISSING=Port — "Network: Outbound Command Encoding"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004552b0__sub_4552B0.c
12. nascar03/43-io.md sub_00459400 [tier=T1] MISSING=Port — "Track: Temporary .scn Gen"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00459400__sub_459400.c
13. nascar03/43-io.md sub_0045a2b0 [tier=T2] MISSING=Port — "Session: Find Current Track"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045a2b0__sub_45A2B0.c
14. nascar03/43-io.md sub_0045a8e0 [tier=T2] MISSING=Port — "Session: Season Event List Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045a8e0__sub_45A8E0.c
15. nascar03/43-io.md sub_0045dee0 [tier=T2] MISSING=Port — "Career: Controller Config Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045dee0__sub_45DEE0.c
16. nascar03/43-io.md sub_00461aa0 [tier=T2] MISSING=Port — "Career: Replay List Scan"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00461aa0__sub_461AA0.c
17. nascar03/43-io.md sub_00558641 [tier=T2] MISSING=F1C status — "MSVC CRT Function-Address Adjuster"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00558641_____L@YGXPAXIHP6EX0@Z1@Z.c
18. nascar03/43-io.md sub_005655a5 [tier=T2] MISSING=F1C status — "MSVC iostream Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005655a5____0Init@ios_base@std@@QAE@XZ.c
19. nascar03/43-io.md sub_00566729 [tier=T2] MISSING=F1C status — "MSVC wchar Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00566729____0_Winit@std@@QAE@XZ.c
20. nascar03/43-io.md sub_0056783c [tier=T2] MISSING=F1C status — "MSVC Locale Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0056783c____Init@locale@std@@CAPAV_Locimp@12@XZ.c
21. nascar03/43-io.md sub_00567a02 [tier=T2] MISSING=F1C status — "MSVC Locale Destructor"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00567a02____1_Locimp@locale@std@@UAE@XZ.c
22. nascar03/43-io.md sub_00567fe0 [tier=T2] MISSING=F1C status — "MSVC Locale Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00567fe0__sub_567FE0.c
23. nascar03/43-io.md sub_005689b8 [tier=T2] MISSING=F1C status — "MSVC IosBase Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005689b8__sub_5689B8.c
24. nascar03/43-io.md sub_00568c15 [tier=T2] MISSING=F1C status — "MSVC IosBase Destructor Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00568c15__sub_568C15.c
25. nascar03/43-io.md sub_00568fe6 [tier=T2] MISSING=F1C status — "MSVC Locale Static"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00568fe6__sub_568FE6.c
26. nascar03/43-io.md sub_005690e1 [tier=T2] MISSING=F1C status — "MSVC Facet Refcount"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005690e1__sub_5690E1.c
27. nascar03/43-io.md sub_0057925a [tier=T1] MISSING=F1C status — "MSVC CRT atexit Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0057925a__sub_57925A.c
28. nascar03/43-io.md sub_0057d310 [tier=T2] MISSING=F1C status — "MSVC File I/O Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0057d310__sub_57D310.c
29. nascar03/43-io.md sub_0057d420 [tier=T2] MISSING=F1C status — "MSVC File I/O Helper 2"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0057d420__sub_57D420.c
30. nascar03/43-io.md sub_0057f3cf [tier=T2] MISSING=F1C status — "MSVC fclose Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0057f3cf__sub_57F3CF.c
31. nascar03/43-io.md sub_00580c2c [tier=T2] MISSING=F1C status — "MSVC tmpfile Helper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00580c2c__sub_580C2C.c
32. nascar03/43-io.md sub_00594c5a [tier=T1] MISSING=F1C status — "MSVC fseeki64 Wrapper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00594c5a____fseeki64.c
33. nascar03/43-io.md sub_00451710 [tier=T1] MISSING=F1C status — "NetComm Slot Marking"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00451710__sub_451710.c
34. nascar03/43-io.md sub_00456850 [tier=T2] MISSING=F1C status — "CUSTOM Setup Loader"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00456850__sub_456850.c