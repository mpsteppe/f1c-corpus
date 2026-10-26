# WORKER STUBS — F1C Remaining Stub Upgrade (25 functions)

Upgrade 25 table-row stubs to lightweight ### FUN_ entries.

## STEP 1 — LOAD REFERENCES

1. %USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md
2. %USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_STUBS.md

Structure:
```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
### FUN_00XXXXXX -- Short Name
...
```

Leave TRIAGE LINES empty. Write target comment before EVERY entry. Write to file after every 5 entries.

## YOUR FUNCTIONS (25)

1. FUN_0042C170
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c170__FUN_0042c170.c
   target: docs/01-engine-architecture.md
2. FUN_0042C1A0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c1a0__FUN_0042c1a0.c
   target: docs/01-engine-architecture.md
3. FUN_0042C9F0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c9f0__FUN_0042c9f0.c
   target: docs/01-engine-architecture.md
4. FUN_004C8D00
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8d00__FUN_004c8d00.c
   target: docs/01-engine-architecture.md
5. FUN_0049EF40
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049ef40__FUN_0049ef40.c
   target: docs/01-engine-architecture.md
6. FUN_0049EFA0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049efa0__FUN_0049efa0.c
   target: docs/01-engine-architecture.md
7. FUN_00455DA0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455da0__FUN_00455da0.c
   target: docs/01-engine-architecture.md
8. FUN_00455E70
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455e70__FUN_00455e70.c
   target: docs/01-engine-architecture.md
9. FUN_004FA000
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fa000__FUN_004fa000.c
   target: docs/01-engine-architecture.md
10. FUN_004B4060
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b4060__FUN_004b4060.c
   target: docs/01-engine-architecture.md
11. FUN_004B40A0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b40a0__FUN_004b40a0.c
   target: docs/01-engine-architecture.md
12. FUN_0040C920
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0040c920__FUN_0040c920.c
   target: docs/01-engine-architecture.md
13. FUN_004B1870
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b1870__FUN_004b1870.c
   target: docs/08-file-formats.md
14. FUN_004B18D0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b18d0__FUN_004b18d0.c
   target: docs/08-file-formats.md
15. FUN_004C6980
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6980__FUN_004c6980.c
   target: docs/08-file-formats.md
16. FUN_00463160
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00463160__FUN_00463160.c
   target: docs/09-track-system.md
17. FUN_004CEE90
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cee90__FUN_004cee90.c
   target: docs/09-track-system.md
18. FUN_004CF070
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cf070__FUN_004cf070.c
   target: docs/09-track-system.md
19. FUN_00410F60
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410f60__FUN_00410f60.c
   target: docs/10-vehicle-physics.md
20. FUN_0052835F
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052835f__FUN_0052835f.c
   target: docs/10-vehicle-physics.md
21. FUN_004AF220
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004af220__FUN_004af220.c
   target: docs/10-vehicle-physics.md
22. FUN_004C6810
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6810__FUN_004c6810.c
   target: docs/10-vehicle-physics.md
23. FUN_004C2E20
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2e20__FUN_004c2e20.c
   target: docs/10-vehicle-physics.md
24. FUN_005418E0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005418e0__FUN_005418e0.c
   target: docs/10-vehicle-physics.md
25. FUN_0054F5C0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f5c0__FUN_0054f5c0.c
   target: docs/10-vehicle-physics.md

## ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
### FUN_00XXXXXX -- Short Name

One-line summary.

**Key logic:**
- 2-4 bullets: main behavior, constants, branches

**Calls:** FUN_AAAAAA (purpose)
```

## RULES
1. Use ### FUN_ format (h3), NOT ## FUN_.
2. Write <!-- target: --> before every entry using the target doc given.
3. Write entry for ALL 25 functions.
4. Empty/bare-return: write ### FUN_X -- Empty Stub, one bullet.
5. Thunk: write ### FUN_X -- Thunk to FUN_Y, one bullet.
6. NEVER modify existing files. Only write to the output file above.
