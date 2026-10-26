# WORKER A — F1C Source Tree Reconstruction

You are reconstructing the original source tree of F1 Challenge 99-02 from assert
strings and debug paths embedded in the binary.
Worker A of 3.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_A.md

## SOURCE PATHS (19 unique source files)

1. D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp
   functions (3): 0x0052da30, 0x0052e090, 0x0052e1d0
2. D:\dev\F1_1999_2002\Source\O_AppGz.cpp
   functions (1): 0x0046de10
3. D:\dev\F1_1999_2002\Source\Replay.cpp
   functions (1): 0x004ba1f0
4. D:\dev\F1_1999_2002\Source\ai_db.cpp]
   functions (1): 0x004024f0
5. D:\dev\F1_1999_2002\Source\config.cpp
   functions (1): 0x00421cd0
6. D:\dev\F1_1999_2002\Source\game.cpp
   functions (9): 0x0042cf10, 0x0042d260, 0x0042d370, 0x0042d5d0, 0x0042d6b0, 0x0042d7a0, 0x0042d8a0, 0x0042da30, 0x0042db20
7. D:\dev\F1_1999_2002\Source\garage.cpp]
   functions (1): 0x0042fd00
8. D:\dev\F1_1999_2002\Source\htree.cpp
   functions (1): 0x00449a80
9. D:\dev\F1_1999_2002\Source\hwinput.cpp]
   functions (1): 0x00455bf0
10. D:\dev\F1_1999_2002\Source\options.cpp
   functions (1): 0x004a0eb0
11. D:\dev\F1_1999_2002\Source\osman.cpp]
   functions (1): 0x004a18d0
12. D:\dev\F1_1999_2002\Source\plrfile.cpp
   functions (5): 0x004b0770, 0x004b1820, 0x004b1870, 0x004b18d0, 0x004b1900
13. D:\dev\F1_1999_2002\Source\render.cpp]
   functions (1): 0x004b4030
14. D:\dev\F1_1999_2002\Source\setup.cpp
   functions (4): 0x004c3200, 0x004c3d80, 0x004c40d0, 0x004c52c0
15. D:\dev\F1_1999_2002\Source\specialfx.cpp
   functions (10): 0x004ca480, 0x004cada0, 0x004cb120, 0x004cdc70, 0x004cee90, 0x004ceec0, 0x004cf070, 0x004cfc90, 0x004cfed0, 0x004cfff0
16. D:\dev\F1_1999_2002\Source\tire_manager.cpp]
   functions (1): 0x004d5ee0
17. D:\dev\F1_1999_2002\Source\vehgfx.cpp
   functions (2): 0x004ddf90, 0x004dfce0
18. D:\dev\F1_1999_2002\Source\vidman.cpp
   functions (7): 0x004f9310, 0x004fa000, 0x004fa2f0, 0x004fa320, 0x004fa640, 0x004fac00, 0x004fad00
19. D:\dev\F1_1999_2002\Source\weather.cpp]
   functions (1): 0x004fe820

## TASK
1. Parse all D:\dev\ paths into a directory tree
2. For each source file: list referencing functions, note address range, estimate total count
3. Identify gaps: address ranges with functions but no source path (inlined or path-less)

## OUTPUT FORMAT

```
# F1 Challenge 99-02 — Reconstructed Source Tree

## Directory Structure
```
D:\dev\F1_1999_2002\Source\
  ├── Physics\
  │   ├── tire_model.cpp    (N functions, 0x004A0000-0x004A8000)
```

## Source File Details

### Physics/tire_model.cpp
Functions: FUN_XXXXXXXX, FUN_YYYYYYYY, ...
Address range: 0x... — 0x...
Estimated total functions: N (~M inlined)

## Inlined / Path-less Gaps
[Address ranges with documented functions but no matching source path]

## Statistics
- .cpp files: N | Functions attributed: N | Estimated inlined: N
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_A.md.
1. Every D:\dev path must appear in the tree.
2. Use address clustering to group functions by source file.
3. Note the project directory structure — reveals team organization.
