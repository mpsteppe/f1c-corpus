# Worker T — delta cleanup (30 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_T.md`

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

1. scgt/42-presentation.md sub_00430fe0 [tier=T2] MISSING=F1C status — "String Trimmer (Whitespace + Tabs)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00430fe0__sub_430FE0.c
2. scgt/42-presentation.md sub_00431150 [tier=T2] MISSING=F1C status — "Localized String Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00431150__sub_431150.c
3. scgt/43-io.md sub_004979f0 [tier=T2] MISSING=F1C status — "Glide Thunk: ConvertAndDownloadRle"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004979f0___ConvertAndDownloadRle@64.c
4. scgt/43-io.md sub_00498ce0 [tier=T2] MISSING=F1C status — "Glide Thunk: guTexAllocateMemory"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00498ce0___guTexAllocateMemory@60.c
5. scgt/43-io.md sub_00498da0 [tier=T2] MISSING=F1C status — "Glide Thunk: guTexChangeAttributes"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00498da0___guTexChangeAttributes@48.c
6. scgt/43-io.md sub_00498f90 [tier=T2] MISSING=F1C status — "Glide LFB Lock/Unlock (Pixel Buffer Acce"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00498f90__sub_498F90.c
7. scgt/43-io.md sub_00499230 [tier=T2] MISSING=F1C status — "Glide Texture Download Dispatch"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x00499230__sub_499230.c
8. scgt/43-io.md sub_0049c6f0 [tier=T2] MISSING=F1C status — "Glide LFB Blit (Lock + Buffer Copy + Unl"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049c6f0__sub_49C6F0.c
9. scgt/43-io.md sub_0049cfd0 [tier=T2] MISSING=F1C status — "Renderer Function Pointer Table Init (Gl"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049cfd0__sub_49CFD0.c
10. scgt/43-io.md sub_0049d110 [tier=T2] MISSING=F1C status — "Renderer Shutdown (Null All Callbacks)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049d110__sub_49D110.c
11. scgt/43-io.md sub_0049fbf0 [tier=T2] MISSING=F1C status — "Pixel Format Detection + Hardware Dispat"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049fbf0__sub_49FBF0.c
12. scgt/43-io.md sub_0049fe4b [tier=T2] MISSING=F1C status — "16-bit→32-bit Pixel Format Expand"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049fe4b__sub_49FE4B.c
13. scgt/43-io.md sub_0049ffaf [tier=T2] MISSING=F1C status — "RLE-Compressed Pixel Blit with Transpare"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x0049ffaf__sub_49FFAF.c
14. scgt/43-io.md sub_004a15de [tier=T2] MISSING=F1C status — "Tile-Based Pixel Blit with Color Key"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a15de__sub_4A15DE.c
15. scgt/43-io.md sub_004a1ad0 [tier=T2] MISSING=F1C status — "8/16-bit Blit Function Pointer Table Ini"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a1ad0__sub_4A1AD0.c
16. scgt/43-io.md sub_004a1d40 [tier=T2] MISSING=F1C status — "Scene Render Draw Dispatch (Material → B"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a1d40__sub_4A1D40.c
17. scgt/43-io.md sub_004a31b0 [tier=T2] MISSING=F1C status — "Alpha Blend/Multiply Lookup Table Genera"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a31b0__sub_4A31B0.c
18. scgt/43-io.md sub_004a35b0 [tier=T2] MISSING=F1C status — "Span Node Alloc + Init (Position Slope)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a35b0__sub_4A35B0.c
19. scgt/43-io.md sub_004a3650 [tier=T2] MISSING=F1C status — "Span Node Alloc + Init (Position + U Slo"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a3650__sub_4A3650.c
20. scgt/43-io.md sub_004a3700 [tier=T2] MISSING=F1C status — "Span Node Alloc + Init (Position + UV Sl"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a3700__sub_4A3700.c
21. scgt/43-io.md sub_004a37c0 [tier=T2] MISSING=F1C status — "Span Node Alloc + Init (Position + UV + "
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a37c0__sub_4A37C0.c
22. scgt/43-io.md sub_004a4240 [tier=T2] MISSING=F1C status — "Span/Sort Merging for Trapezoid Rasteriz"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a4240__sub_4A4240.c
23. scgt/43-io.md sub_004a4770 [tier=T2] MISSING=F1C status — "Sorted Edge/Span Pair Iterator"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a4770__sub_4A4770.c
24. scgt/43-io.md sub_004a4830 [tier=T2] MISSING=F1C status — "Span/Edge State Reset (New Frame)"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a4830__sub_4A4830.c
25. scgt/43-io.md sub_004a48d0 [tier=T2] MISSING=F1C status — "Rasterizer Workspace Buffer Allocation +"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a48d0__sub_4A48D0.c
26. scgt/43-io.md sub_004a49f0 [tier=T2] MISSING=F1C status — "Rasterizer Workspace Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a49f0__sub_4A49F0.c
27. scgt/43-io.md sub_004a8470 [tier=T2] MISSING=F1C status — "JPEG Decoder: Huffman + IDCT Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004a8470__sub_4A8470.c
28. scgt/43-io.md sub_004ad360 [tier=T2] MISSING=F1C status — "JPEG Decoder: Write MCU Row with Byte St"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004ad360__sub_4AD360.c
29. scgt/43-io.md sub_004adfe0 [tier=T2] MISSING=F1C status — "JPEG Decoder: Ring Buffer Output"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004adfe0__sub_4ADFE0.c
30. scgt/43-io.md sub_004ba330 [tier=T2] MISSING=F1C status — "Timezone / DST Detection"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\decompiled\0x004ba330__sub_4BA330.c