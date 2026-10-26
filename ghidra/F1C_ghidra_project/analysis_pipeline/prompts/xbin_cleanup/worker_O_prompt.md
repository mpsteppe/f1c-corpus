# Worker O — delta cleanup (39 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_O.md`

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

1. nascar03/42-presentation.md sub_0045c860 [tier=T2] MISSING=Port — "Career: Standings Table Build + Render"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045c860__sub_45C860.c
2. nascar03/42-presentation.md sub_0045d730 [tier=T2] MISSING=Port — "Career: Race Schedule Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045d730__sub_45D730.c
3. nascar03/42-presentation.md sub_0045e740 [tier=T2] MISSING=Port — "Career: Lap Score Line Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045e740__sub_45E740.c
4. nascar03/42-presentation.md sub_0045eb70 [tier=T2] MISSING=Port — "Career: Standings List Tick"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045eb70__sub_45EB70.c
5. nascar03/42-presentation.md sub_0045f260 [tier=T2] MISSING=Port — "Career: Season Summary Build"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0045f260__sub_45F260.c
6. nascar03/42-presentation.md sub_004617d0 [tier=T2] MISSING=Port — "UI: Advanced List/Dropdown Draw"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004617d0__sub_4617D0.c
7. nascar03/42-presentation.md sub_00461e70 [tier=T2] MISSING=Port — "Replay: File Format Check"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00461e70__sub_461E70.c
8. nascar03/42-presentation.md sub_004626f0 [tier=T2] MISSING=Port — "Replay: Save/Overwrite Confirmation"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004626f0__sub_4626F0.c
9. nascar03/42-presentation.md sub_00462a20 [tier=T2] MISSING=Port — "Replay: Play from Game State"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00462a20__sub_462A20.c
10. nascar03/42-presentation.md sub_00462f60 [tier=T2] MISSING=Port — "UI: Text Field Clear"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00462f60__sub_462F60.c
11. nascar03/42-presentation.md sub_00463350 [tier=T2] MISSING=Port — "UI: Text Field Init from State"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00463350__sub_463350.c
12. nascar03/42-presentation.md sub_00463570 [tier=T2] MISSING=Port — "UI: Text Value Change Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00463570__sub_463570.c
13. nascar03/42-presentation.md sub_00463b90 [tier=T2] MISSING=Port — "UI: Drag/Scroll Handler"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00463b90__sub_463B90.c
14. nascar03/42-presentation.md sub_00468170 [tier=T2] MISSING=Port — "File Scan: .svm List Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00468170__sub_468170.c
15. nascar03/42-presentation.md sub_0046a0a0 [tier=T2] MISSING=Port — "UI: Volume Slider"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046a0a0__sub_46A0A0.c
16. nascar03/42-presentation.md sub_0046a3c0 [tier=T2] MISSING=Port — "UI: Control ID to Bitmask"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046a3c0__sub_46A3C0.c
17. nascar03/42-presentation.md sub_0046b1d0 [tier=T2] MISSING=Port — "UI: Main Menu Items"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046b1d0__sub_46B1D0.c
18. nascar03/42-presentation.md sub_0046b740 [tier=T2] MISSING=Port — "UI: Menu String Match"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046b740__sub_46B740.c
19. nascar03/42-presentation.md sub_0046b8a0 [tier=T2] MISSING=Port — "UI: Profile Icon List Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046b8a0__sub_46B8A0.c
20. nascar03/42-presentation.md sub_0046e1a0 [tier=T1] MISSING=Port — "/ sub_0046e2f0 — UI: Weather Icon"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046e1a0__sub_46E1A0.c
21. nascar03/42-presentation.md sub_0046ff60 [tier=T2] MISSING=Port — "UI: Main View Render Pass"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x0046ff60__sub_46FF60.c
22. nascar03/42-presentation.md sub_00471200 [tier=T2] MISSING=Port — "UI: Session Type Label"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00471200__sub_471200.c
23. nascar03/42-presentation.md sub_004717d0 [tier=T2] MISSING=Port — "UI: Error Screen Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004717d0__sub_4717D0.c
24. nascar03/42-presentation.md sub_00471900 [tier=T2] MISSING=Port — "UI: Debug/Telemetry Display"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00471900__sub_471900.c
25. nascar03/42-presentation.md sub_004722c0 [tier=T1] MISSING=Port — "UI: Track Info Screen Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x004722c0__sub_4722C0.c
26. nascar03/42-presentation.md sub_00472710 [tier=T2] MISSING=Port — "UI: Options Display Formatter"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00472710__sub_472710.c
27. nascar03/42-presentation.md sub_00472e30 [tier=T2] MISSING=Port — "UI: Weather Screen Labels"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00472e30__sub_472E30.c
28. nascar03/42-presentation.md sub_005525f0 [tier=T2] MISSING=F1C status — "MIDI Voice Release"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005525f0__sub_5525F0.c
29. nascar03/42-presentation.md sub_005527b0 [tier=T2] MISSING=F1C status — "MIDI Note-On"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x005527b0__sub_5527B0.c
30. nascar03/42-presentation.md sub_00552920 [tier=T2] MISSING=F1C status — "MIDI Note-Off"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00552920__sub_552920.c
31. nascar03/42-presentation.md sub_00552ae0 [tier=T2] MISSING=F1C status — "MIDI Controller"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00552ae0__sub_552AE0.c
32. nascar03/42-presentation.md sub_00552c90 [tier=T2] MISSING=F1C status — "MIDI Program Change"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00552c90__sub_552C90.c
33. nascar03/42-presentation.md sub_00552d90 [tier=T2] MISSING=F1C status — "MIDI Pitch Bend"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00552d90__sub_552D90.c
34. nascar03/42-presentation.md sub_00552e80 [tier=T2] MISSING=F1C status — "MIDI Volume"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00552e80__sub_552E80.c
35. nascar03/42-presentation.md sub_00553300 [tier=T2] MISSING=F1C status — "MIDI Pan"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553300__sub_553300.c
36. nascar03/42-presentation.md sub_00553450 [tier=T2] MISSING=F1C status — "MIDI Expression"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553450__sub_553450.c
37. nascar03/42-presentation.md sub_00553590 [tier=T2] MISSING=F1C status — "MIDI Reverb"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553590__sub_553590.c
38. nascar03/42-presentation.md sub_00553670 [tier=T2] MISSING=F1C status — "MIDI Chorus"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553670__sub_553670.c
39. nascar03/42-presentation.md sub_00553a70 [tier=T2] MISSING=F1C status — "MIDI Sustain"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\decompiled\0x00553a70__sub_553A70.c