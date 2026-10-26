# WORKER B — F1C Source Tree Reconstruction

You are reconstructing the original source tree of F1 Challenge 99-02 from assert
strings and debug paths embedded in the binary.
Worker B of 3.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_B.md

## SOURCE PATHS (18 unique source files)

20. D:\dev\F1_1999_2002\Source\NetComm.cpp
   functions (16): 0x0045d890, 0x0045eb50, 0x0045fc50, 0x00460470, 0x00460520, 0x00460cb0, 0x00460e90, 0x00461020, 0x00461190, 0x004612e0 +6 more
21. D:\dev\F1_1999_2002\Source\O_BaseGz.cpp
   functions (1): 0x0048e8d0
22. D:\dev\F1_1999_2002\Source\Replay.cpp]
   functions (1): 0x004ba1f0
23. D:\dev\F1_1999_2002\Source\camera.cpp
   functions (3): 0x0040c920, 0x0040c9e0, 0x0040cce0
24. D:\dev\F1_1999_2002\Source\dynman.cpp
   functions (6): 0x0042c130, 0x0042c170, 0x0042c1a0, 0x0042c3b0, 0x0042c9f0, 0x0042ca70
25. D:\dev\F1_1999_2002\Source\game.cpp]
   functions (1): 0x0042cf10
26. D:\dev\F1_1999_2002\Source\hdvehicle.cpp
   functions (5): 0x00439210, 0x0043af50, 0x0043b040, 0x0043c250, 0x0043da10
27. D:\dev\F1_1999_2002\Source\htree.cpp]
   functions (1): 0x00449a80
28. D:\dev\F1_1999_2002\Source\onscreen.cpp
   functions (6): 0x0049ef40, 0x0049ef70, 0x0049efa0, 0x0049f000, 0x0049f0d0, 0x0049f120
29. D:\dev\F1_1999_2002\Source\options.cpp]
   functions (1): 0x004a0eb0
30. D:\dev\F1_1999_2002\Source\pitcrew.cpp
   functions (3): 0x004a2010, 0x004a22d0, 0x004a2a90
31. D:\dev\F1_1999_2002\Source\plrfile.cpp]
   functions (1): 0x004b0770
32. D:\dev\F1_1999_2002\Source\searchgrid.cpp
   functions (1): 0x004bdc10
33. D:\dev\F1_1999_2002\Source\sound.cpp
   functions (6): 0x004c8a20, 0x004c8ab0, 0x004c8ae0, 0x004c8b20, 0x004c8ca0, 0x004c8d00
34. D:\dev\F1_1999_2002\Source\steward.cpp
   functions (6): 0x004d0110, 0x004d0e20, 0x004d36d0, 0x004d38f0, 0x004d3cf0, 0x004d4600
35. D:\dev\F1_1999_2002\Source\util.cpp
   functions (1): 0x004dc770
36. D:\dev\F1_1999_2002\Source\vehload.cpp
   functions (3): 0x004f3240, 0x004f3c80, 0x004f4270
37. D:\dev\F1_1999_2002\Source\vidman.cpp]
   functions (1): 0x004f9310

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_B.md.
1. Every D:\dev path must appear in the tree.
2. Use address clustering to group functions by source file.
3. Note the project directory structure — reveals team organization.
