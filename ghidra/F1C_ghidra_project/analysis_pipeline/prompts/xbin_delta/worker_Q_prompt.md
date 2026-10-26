# Worker Q — sibling-delta documentation (111 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_Q.md`

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

### GAME `nascar04` — target prefix `nascar04/` (e.g. `<!-- target: nascar04/40-gameplay.md -->`), 111 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0055605e__sub_55605E.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005578bb__sub_5578BB.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0055e900__sub_55E900.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00567e00__sub_567E00.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00568000__sub_568000.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005683e0__sub_5683E0.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005684e0__sub_5684E0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0056d9b0__sub_56D9B0.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0056e1e0__sub_56E1E0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0056edc0__sub_56EDC0.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0056ef80__sub_56EF80.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0056f2b0__sub_56F2B0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00573a40__sub_573A40.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00573c60__sub_573C60.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00573da0__sub_573DA0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005747f0__sub_5747F0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00574bf0__sub_574BF0.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00575d20__sub_575D20.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00575e80__sub_575E80.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00577190__sub_577190.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057ad20__sub_57AD20.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057bb60__sub_57BB60.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057c9b0__sub_57C9B0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057dd70__sub_57DD70.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057de40__sub_57DE40.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057ef10__sub_57EF10.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0057fd50__sub_57FD50.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005809d0__sub_5809D0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00580e80__sub_580E80.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005827e0__sub_5827E0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005830f0__sub_5830F0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00583610__sub_583610.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00583f30__sub_583F30.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00584110__sub_584110.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00584450__sub_584450.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005857b0__sub_5857B0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00585fa0__sub_585FA0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00587550__sub_587550.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00588d00__sub_588D00.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00588dc0__sub_588DC0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0058e520__sub_58E520.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0058e5d0__sub_58E5D0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005904a0__sub_5904A0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00590730__sub_590730.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00590c80__sub_590C80.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00590e70__sub_590E70.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00591080__sub_591080.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00592020__sub_592020.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00594e10__sub_594E10.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00595d22__sub_595D22.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00595f90__sub_595F90.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00596490__sub_596490.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00596600__sub_596600.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00596710__sub_596710.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00596940__sub_596940.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00597700__sub_597700.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00597ae0__sub_597AE0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00599720__sub_599720.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005a09c6__sub_5A09C6.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005a61c1__sub_5A61C1.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005a6aed__sub_5A6AED.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005aabff__sub_5AABFF.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ab3d0__sub_5AB3D0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005abaf0__sub_5ABAF0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005abcb0__sub_5ABCB0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005abe70__sub_5ABE70.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005abfe0__sub_5ABFE0.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ac1a0__sub_5AC1A0.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ac350__sub_5AC350.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ac450__sub_5AC450.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ac540__sub_5AC540.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ac9c0__sub_5AC9C0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005acb10__sub_5ACB10.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005acc50__sub_5ACC50.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005acd30__sub_5ACD30.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ad130__sub_5AD130.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ad370__sub_5AD370.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ad790__sub_5AD790.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005adae0__sub_5ADAE0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005adbf0__sub_5ADBF0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005adc40__sub_5ADC40.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005add00__sub_5ADD00.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005adf40__sub_5ADF40.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005ae0a0__sub_5AE0A0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005af370__sub_5AF370.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005b1d30__sub_5B1D30.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005b4a40__sub_5B4A40.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005b7650__sub_5B7650.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bac70__sub_5BAC70.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bcc30__sub_5BCC30.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bced0__sub_5BCED0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bd590__sub_5BD590.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bd880__sub_5BD880.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005be770__sub_5BE770.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bf260__sub_5BF260.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bf590__sub_5BF590.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bf620__sub_5BF620.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bf7a0__sub_5BF7A0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bf880__sub_5BF880.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005bfb50__sub_5BFB50.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005c0c30__sub_5C0C30.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005c32cb_____dtoxmode.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005c3383____stat.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005cbaec____mbsicmp.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d22ed____0Init@ios_base@std@@QAE@XZ.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d3397____0_Winit@std@@QAE@XZ.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d4584____Init@locale@std@@CAPAV_Locimp@12@XZ.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d474a____1_Locimp@locale@std@@UAE@XZ.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d4db0__sub_5D4DB0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d4f10__sub_5D4F10.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x005d5c87____fseeki64.c
