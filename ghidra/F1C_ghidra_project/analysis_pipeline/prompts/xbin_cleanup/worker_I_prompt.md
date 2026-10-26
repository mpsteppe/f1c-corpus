# Worker I — delta cleanup (36 entries need fields)

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_cleanup\worker_I.md`

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

1. f1_2002/42-presentation.md sub_00537c40 [tier=T2] MISSING=F1C status — "Audio Mixer Channel Process"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00537c40__sub_537C40.c
2. f1_2002/42-presentation.md sub_00539060 [tier=T2] MISSING=F1C status — "File Load / Audio Stream Read"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00539060__sub_539060.c
3. f1_2002/42-presentation.md sub_0053b980 [tier=T2] MISSING=F1C status — "Sound Channel State Machine"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0053b980__sub_53B980.c
4. f1_2002/42-presentation.md sub_0053fcd0 [tier=T2] MISSING=F1C status — "Sound Object Destroy/Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0053fcd0__sub_53FCD0.c
5. f1_2002/42-presentation.md sub_005444f0 [tier=T2] MISSING=F1C status — "Network Protocol Size Lookup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005444f0__sub_5444F0.c
6. f1_2002/42-presentation.md sub_0054ac80 [tier=T2] MISSING=F1C status — "Winsock TCP Connect"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0054ac80__sub_54AC80.c
7. f1_2002/42-presentation.md sub_0054e0f0 [tier=T2] MISSING=F1C status — "Network Linked List Remove"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0054e0f0__sub_54E0F0.c
8. f1_2002/42-presentation.md sub_0054e2a0 [tier=T2] MISSING=F1C status — "Network Packet Builder"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0054e2a0__sub_54E2A0.c
9. f1_2002/42-presentation.md sub_0054e8c0 [tier=T2] MISSING=F1C status — "Network Game State Sync"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0054e8c0__sub_54E8C0.c
10. f1_2002/42-presentation.md sub_0054eba0 [tier=T2] MISSING=F1C status — "Network Lobby/Packet Dispatch"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0054eba0__sub_54EBA0.c
11. f1_2002/42-presentation.md sub_00551370 [tier=T2] MISSING=F1C status — "Network Player List Manage"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00551370__sub_551370.c
12. f1_2002/42-presentation.md sub_005514a0 [tier=T2] MISSING=F1C status — "Network Chat Message Send"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005514a0__sub_5514A0.c
13. f1_2002/42-presentation.md sub_005524b0 [tier=T2] MISSING=F1C status — "Network UDP Socket Recv"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005524b0__sub_5524B0.c
14. f1_2002/42-presentation.md sub_005528b0 [tier=T2] MISSING=F1C status — "Miles Sound System Channel Stop"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005528b0__sub_5528B0.c
15. f1_2002/42-presentation.md sub_00552ba0 [tier=T2] MISSING=F1C status — "Miles Sound System Stream Play"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00552ba0__sub_552BA0.c
16. f1_2002/42-presentation.md sub_00554070 [tier=T2] MISSING=F1C status — "Sound Volume Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00554070__sub_554070.c
17. f1_2002/42-presentation.md sub_00554420 [tier=T2] MISSING=F1C status — "Network Session Create"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00554420__sub_554420.c
18. f1_2002/42-presentation.md sub_00555640 [tier=T2] MISSING=F1C status — "Network Session Join"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00555640__sub_555640.c
19. f1_2002/42-presentation.md sub_00555ca0 [tier=T2] MISSING=F1C status — "Network Session Leave"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00555ca0__sub_555CA0.c
20. f1_2002/42-presentation.md sub_00555f80 [tier=T2] MISSING=F1C status — "Network Session Enumerate"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00555f80__sub_555F80.c
21. f1_2002/42-presentation.md sub_005565e0 [tier=T2] MISSING=F1C status — "Network Session Data Send"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005565e0__sub_5565E0.c
22. f1_2002/42-presentation.md sub_005589a0 [tier=T2] MISSING=F1C status — "Network Host Migrate"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005589a0__sub_5589A0.c
23. f1_2002/42-presentation.md sub_0055b670 [tier=T2] MISSING=F1C status — "Miles Sound System Stream Stop"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0055b670__sub_55B670.c
24. f1_2002/42-presentation.md sub_0055d0f0 [tier=T2] MISSING=F1C status — "File System Read Wrapper"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0055d0f0__sub_55D0F0.c
25. f1_2002/42-presentation.md sub_0055d830 [tier=T2] MISSING=F1C status — "Directory Enumeration"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0055d830__sub_55D830.c
26. f1_2002/42-presentation.md sub_00563590 [tier=T2] MISSING=F1C status — "3D Object Destroy/Cleanup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00563590__sub_563590.c
27. f1_2002/42-presentation.md sub_00563890 [tier=T2] MISSING=F1C status — "LDLT Dynamics Solver Matrix Batch"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00563890__sub_563890.c
28. f1_2002/42-presentation.md sub_005641c0 [tier=T2] MISSING=F1C status — "Frequency Table / Audio Setup"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x005641c0__sub_5641C0.c
29. f1_2002/42-presentation.md sub_00569bd7 [tier=T2] MISSING=F1C status — "Dynamics Solver State Zero-Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00569bd7__sub_569BD7.c
30. f1_2002/42-presentation.md sub_0050cb90 [tier=T2] MISSING=F1C status — "Winsock VTable Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0050cb90__sub_50CB90.c
31. f1_2002/42-presentation.md sub_0050d5c0 [tier=T2] MISSING=F1C status — "Winsock Socket Create"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0050d5c0__sub_50D5C0.c
32. f1_2002/42-presentation.md sub_00504095 [tier=T2] MISSING=F1C status — "Network Address Cache Init"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00504095__sub_504095.c
33. f1_2002/42-presentation.md sub_0050248b [tier=T2] MISSING=F1C status — "Network MTU Cache Set"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x0050248b__sub_50248B.c
34. f1_2002/42-presentation.md sub_00501fbf [tier=T2] MISSING=F1C status — "Network Rate Limit"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00501fbf__sub_501FBF.c
35. f1_2002/42-presentation.md sub_00501d62 [tier=T2] MISSING=F1C status — "Network Latency Get"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00501d62__sub_501D62.c
36. f1_2002/42-presentation.md sub_00502390 [tier=T2] MISSING=F1C status — "Network Congestion Control"
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\decompiled\0x00502390__sub_502390.c