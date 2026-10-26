# WORKER C — F1C Source Tree Reconstruction

You are reconstructing the original source tree of F1 Challenge 99-02 from assert
strings and debug paths embedded in the binary.
Worker C of 3.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_C.md

## SOURCE PATHS (18 unique source files)

38. D:\dev\F1_1999_2002\Source\NetComm.cpp]
   functions (1): 0x00463160
39. D:\dev\F1_1999_2002\Source\O_BaseGz.cpp]
   functions (1): 0x0048e8d0
40. D:\dev\F1_1999_2002\Source\ai_db.cpp
   functions (2): 0x004024f0, 0x004040a0
41. D:\dev\F1_1999_2002\Source\camera.cpp]
   functions (1): 0x0040c920
42. D:\dev\F1_1999_2002\Source\dynman.cpp]
   functions (1): 0x0042c130
43. D:\dev\F1_1999_2002\Source\garage.cpp
   functions (1): 0x0042fd00
44. D:\dev\F1_1999_2002\Source\hdvehicle.cpp]
   functions (1): 0x00439210
45. D:\dev\F1_1999_2002\Source\hwinput.cpp
   functions (6): 0x00455bf0, 0x00455c60, 0x00455d50, 0x00455da0, 0x00455e70, 0x00455f00
46. D:\dev\F1_1999_2002\Source\onscreen.cpp]
   functions (1): 0x0049ef40
47. D:\dev\F1_1999_2002\Source\osman.cpp
   functions (3): 0x0042db20, 0x004a18d0, 0x004a1930
48. D:\dev\F1_1999_2002\Source\pitcrew.cpp]
   functions (1): 0x004a2010
49. D:\dev\F1_1999_2002\Source\render.cpp
   functions (3): 0x004b4030, 0x004b4060, 0x004b4170
50. D:\dev\F1_1999_2002\Source\searchgrid.cpp]
   functions (1): 0x004bdc10
51. D:\dev\F1_1999_2002\Source\sound.cpp]
   functions (1): 0x004c8a20
52. D:\dev\F1_1999_2002\Source\tire_manager.cpp
   functions (7): 0x004d5ee0, 0x004d5f70, 0x004d7150, 0x004d7570, 0x004d75d0, 0x004d7660, 0x004d7880
53. D:\dev\F1_1999_2002\Source\util.cpp]
   functions (1): 0x004dc770
54. D:\dev\F1_1999_2002\Source\vehload.cpp]
   functions (1): 0x004f3240
55. D:\dev\F1_1999_2002\Source\weather.cpp
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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\source_tree\worker_C.md.
1. Every D:\dev path must appear in the tree.
2. Use address clustering to group functions by source file.
3. Note the project directory structure — reveals team organization.
