# Worker K — sibling-delta documentation (112 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_K.md`

## HARD RULES (violating any breaks the merge)
1. WRITE ONLY to the output file above. NEVER touch any file under docs/.
2. One function = one write, immediately. Never batch at the end. Do ALL listed.
3. NEVER spawn a subagent/task. Do the work yourself.
4. Header exactly `## sub_XXXXXXXX` (lowercase, 8 hex from filename). Not FUN_/Unwind_/thunk_.
5. Source is IDA Hex-Rays. See role spec for patterns + the worked example.

## OUTPUT STRUCTURE
Start with `=== TRIAGE LINES ===` (one `| 0x.. | lines | category | purpose | port? | <game>/40-gameplay.md |` per function),
then `=== FULL ENTRIES ===` with `## sub_` blocks grouped under game-qualified target comments.

## TARGET ROUTING — target comment MUST be game-qualified:
   `<!-- target: <GAME>/<doc>.md -->`  doc = 40-gameplay | 41-engine | 42-presentation | 43-io
   gameplay/race-control/career/penalty->40-gameplay ; physics/collision/math->41-engine ;
   renderer/audio/ui/hud->42-presentation ; network/replay/file->43-io

### GAME `nascar04` — target prefix `nascar04/` (e.g. `<!-- target: nascar04/40-gameplay.md -->`), 112 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042a1b0__sub_42A1B0.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042a270__sub_42A270.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042b110__sub_42B110.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042b3a0__sub_42B3A0.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042b4b0__sub_42B4B0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042b640__sub_42B640.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042b700__sub_42B700.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042be10__sub_42BE10.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042c080__sub_42C080.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042c1d0__sub_42C1D0.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042c4b0__sub_42C4B0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042cba0__sub_42CBA0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042cd00__sub_42CD00.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042d030__sub_42D030.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042d640__sub_42D640.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042e7a0__sub_42E7A0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042ed10__sub_42ED10.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042ee60__sub_42EE60.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042f3d0__sub_42F3D0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042f6c0__sub_42F6C0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0042f9d0__sub_42F9D0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00434a80__sub_434A80.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00434f90__sub_434F90.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00435020__sub_435020.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00435780__sub_435780.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00435bf0__sub_435BF0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00435fd0__sub_435FD0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00436210__sub_436210.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00436940__sub_436940.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00436c80__sub_436C80.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00437500__sub_437500.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004375f0__sub_4375F0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00438f00__sub_438F00.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00438fc0__sub_438FC0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00439250__sub_439250.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043ae30__sub_43AE30.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043b340__sub_43B340.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043e7b0__sub_43E7B0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043e8c0__sub_43E8C0.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043e9d0__sub_43E9D0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043eac0__sub_43EAC0.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0043f190__sub_43F190.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441280__sub_441280.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441370__sub_441370.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004415f0__sub_4415F0.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441a10__sub_441A10.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441bd0__sub_441BD0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441d20__sub_441D20.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441e40__sub_441E40.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00441fe0__sub_441FE0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00442100__sub_442100.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004426b0__sub_4426B0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00443040__sub_443040.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00444c90__sub_444C90.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00444e10__sub_444E10.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00445560__sub_445560.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00445c40__sub_445C40.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00446520__sub_446520.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00446b60__sub_446B60.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00447510__sub_447510.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00447b80__sub_447B80.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00449c80__sub_449C80.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00449e10__sub_449E10.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00449ea0__sub_449EA0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00449f80__sub_449F80.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044a530__sub_44A530.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044a8c0__sub_44A8C0.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044a960__sub_44A960.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044aa20__sub_44AA20.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044abc0__sub_44ABC0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044acc0__sub_44ACC0.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0044e510__sub_44E510.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004529e0__sub_4529E0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004534b0__sub_4534B0.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00453a80__sub_453A80.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00456670__sub_456670.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00456ab0__sub_456AB0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00457320__sub_457320.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004573d0__sub_4573D0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004575e0__sub_4575E0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00457850__sub_457850.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00458960__sub_458960.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00458a20__sub_458A20.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00459980__sub_459980.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045ae50__sub_45AE50.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045b2d0__sub_45B2D0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045c3b0__sub_45C3B0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045c580__sub_45C580.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045c810__sub_45C810.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045ea80___WinMain@16.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045edc0__sub_45EDC0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045ee90__sub_45EE90.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045fa60__sub_45FA60.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0045ff50__sub_45FF50.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004601b0__sub_4601B0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00460950__sub_460950.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00460fa0__sub_460FA0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004624a0__sub_4624A0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00462ce0__sub_462CE0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00463020__sub_463020.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00463110__sub_463110.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00463380__sub_463380.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004644d0__sub_4644D0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00464810__sub_464810.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00464ae0__sub_464AE0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00465d40__sub_465D40.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00466120__sub_466120.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00466550__sub_466550.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00466890__sub_466890.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00466970__sub_466970.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00466af0__sub_466AF0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004670e0__sub_4670E0.c
