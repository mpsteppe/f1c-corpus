# Worker P — sibling-delta documentation (112 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_P.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00504220__sub_504220.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00504ba0__sub_504BA0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00504d60__sub_504D60.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00505210__sub_505210.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005053e0__sub_5053E0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00505f10__sub_505F10.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005062d0__sub_5062D0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00506520__sub_506520.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00506660__sub_506660.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00506880__sub_506880.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00506e80__sub_506E80.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00507320__sub_507320.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00507690__sub_507690.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00507810__sub_507810.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00507a30__sub_507A30.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00507b60__sub_507B60.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00508210__sub_508210.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00508ba0__sub_508BA0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00508ce0__sub_508CE0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050b010__sub_50B010.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050b230__sub_50B230.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050b380__sub_50B380.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050c360__sub_50C360.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050c4f0__sub_50C4F0.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050c7e0__sub_50C7E0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050cd30__sub_50CD30.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050ce10__sub_50CE10.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050cef0__sub_50CEF0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050d700__sub_50D700.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050d980__sub_50D980.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050e7c0__sub_50E7C0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050f3a0__sub_50F3A0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050f7d0__sub_50F7D0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050fad0__sub_50FAD0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0050fd10__sub_50FD10.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00512550__sub_512550.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00512790__sub_512790.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00512cc0__sub_512CC0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00512e00__sub_512E00.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00513190__sub_513190.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005135f0__sub_5135F0.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00513880__sub_513880.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00513d00__sub_513D00.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00513ee0__sub_513EE0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00516200__sub_516200.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005169d0__sub_5169D0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00516aa0__sub_516AA0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00516e10__sub_516E10.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00516f60__sub_516F60.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00517380__sub_517380.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00517580__sub_517580.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005178b0__sub_5178B0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00517fa0__sub_517FA0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00518170__sub_518170.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00518240__sub_518240.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005185f0__sub_5185F0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051ae20__sub_51AE20.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051af40__sub_51AF40.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051bf00__sub_51BF00.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051bfc0__sub_51BFC0.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051c030__sub_51C030.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051c160__sub_51C160.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051c5a0__sub_51C5A0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051c6f0__sub_51C6F0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051d130__sub_51D130.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051d1d0__sub_51D1D0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051e270__sub_51E270.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051e540__sub_51E540.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051e8f0__sub_51E8F0.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051f200__sub_51F200.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051f330__sub_51F330.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051f5b0__sub_51F5B0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0051f6c0__sub_51F6C0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00520610__sub_520610.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005207d0__sub_5207D0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00520a00__sub_520A00.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00520de0__sub_520DE0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005210d0__sub_5210D0.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00521150__sub_521150.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00521510__sub_521510.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00521ab0__sub_521AB0.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00521f60__sub_521F60.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00526a00__sub_526A00.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00526b90__sub_526B90.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00529740__sub_529740.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052a3b0__sub_52A3B0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052b3b0__sub_52B3B0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052b530__sub_52B530.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052b9a0__sub_52B9A0.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052c160__sub_52C160.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052c550__sub_52C550.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052c650__sub_52C650.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052e190__sub_52E190.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052ea70__sub_52EA70.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052eb20__sub_52EB20.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052ed40__sub_52ED40.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052ee50__sub_52EE50.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052ef20__sub_52EF20.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052fc90__sub_52FC90.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0052fd30__sub_52FD30.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00531220__sub_531220.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005317b0__sub_5317B0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054a64d__sub_54A64D.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054a8aa__sub_54A8AA.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054abf0__sub_54ABF0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054aceb__sub_54ACEB.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054bbac__sub_54BBAC.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054c3ff__sub_54C3FF.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054c8f5__sub_54C8F5.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0054fee5__sub_54FEE5.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00555630__sub_555630.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00555740__sub_555740.c
