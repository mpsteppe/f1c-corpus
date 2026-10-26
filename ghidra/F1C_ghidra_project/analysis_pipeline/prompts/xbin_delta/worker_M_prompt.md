# Worker M — sibling-delta documentation (112 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_M.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048e6b0__sub_48E6B0.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048e840__sub_48E840.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048ee00__sub_48EE00.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048fcc0__sub_48FCC0.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00490520__sub_490520.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00490a40__sub_490A40.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00490f00__sub_490F00.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00491160__sub_491160.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004914c0__sub_4914C0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00491c30__sub_491C30.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00492000__sub_492000.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004920a0__sub_4920A0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00492210__sub_492210.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004926c0__sub_4926C0.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00492f40__sub_492F40.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00493430__sub_493430.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00494720__sub_494720.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00494b20__sub_494B20.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00494f20__sub_494F20.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004951c0__sub_4951C0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495300__sub_495300.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495400__sub_495400.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495500__sub_495500.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495600__sub_495600.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495700__sub_495700.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495800__sub_495800.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004958b0__sub_4958B0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00495b70__sub_495B70.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00496040__sub_496040.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049e8d0__sub_49E8D0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049e9a0__sub_49E9A0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049eb10__sub_49EB10.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049ec00__sub_49EC00.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049ed20__sub_49ED20.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049eec0__sub_49EEC0.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049f000__sub_49F000.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049f120__sub_49F120.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049f7a0__sub_49F7A0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049fa20__sub_49FA20.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049fe10__sub_49FE10.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0049fee0__sub_49FEE0.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a1180__sub_4A1180.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a1bb0__sub_4A1BB0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a2570__sub_4A2570.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a4310__sub_4A4310.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a4730__sub_4A4730.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a5420__sub_4A5420.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a6410__sub_4A6410.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a6720__sub_4A6720.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a6c10__sub_4A6C10.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a8100__sub_4A8100.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a82c0__sub_4A82C0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a8660__sub_4A8660.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a8d20__sub_4A8D20.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9030__sub_4A9030.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a93c0__sub_4A93C0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a95b0__sub_4A95B0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9800__sub_4A9800.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a98a0__sub_4A98A0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9b40__sub_4A9B40.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9c70__sub_4A9C70.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9d20__sub_4A9D20.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004a9e80__sub_4A9E80.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aa1a0__sub_4AA1A0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aa260__sub_4AA260.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aa560__sub_4AA560.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aa640__sub_4AA640.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aa710__sub_4AA710.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004acef0__sub_4ACEF0.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004ad350__sub_4AD350.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004ad9b0__sub_4AD9B0.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004ae570__sub_4AE570.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004aed80__sub_4AED80.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004af920__sub_4AF920.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004afee0__sub_4AFEE0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b03a0__sub_4B03A0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b0470__sub_4B0470.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b0540__sub_4B0540.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b0620__sub_4B0620.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b07e0__sub_4B07E0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b0930__sub_4B0930.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b0d70__sub_4B0D70.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b13f0__sub_4B13F0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b1790__sub_4B1790.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b19b0__sub_4B19B0.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b1a40__sub_4B1A40.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b21c0__sub_4B21C0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b2250__sub_4B2250.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b2330__sub_4B2330.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b24a0__sub_4B24A0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b25e0__sub_4B25E0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b26d0__sub_4B26D0.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b28e0__sub_4B28E0.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b2970__sub_4B2970.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b2bf0__sub_4B2BF0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b2d70__sub_4B2D70.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b3100__sub_4B3100.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b3c50__sub_4B3C50.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b40f0__sub_4B40F0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b4380__sub_4B4380.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b44d0__sub_4B44D0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b4a60__sub_4B4A60.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b4be0__sub_4B4BE0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b5070__sub_4B5070.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b54b0__sub_4B54B0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b5670__sub_4B5670.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b58e0__sub_4B58E0.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b59a0__sub_4B59A0.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b6170__sub_4B6170.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b6400__sub_4B6400.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b6cf0__sub_4B6CF0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004b6d90__sub_4B6D90.c
