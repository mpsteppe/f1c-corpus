# Worker H — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_H.md`

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

### GAME `nascar03` — target prefix `nascar03/` (e.g. `<!-- target: nascar03/40-gameplay.md -->`), 130 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b6720__sub_4B6720.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b68f0__sub_4B68F0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b8160__sub_4B8160.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b82a0__sub_4B82A0.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b87a0__sub_4B87A0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b88a0__sub_4B88A0.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b8b80__sub_4B8B80.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b8ce0__sub_4B8CE0.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b8e70__sub_4B8E70.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b8f60__sub_4B8F60.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b94c0__sub_4B94C0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b97a0__sub_4B97A0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b9a70__sub_4B9A70.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ba4c0__sub_4BA4C0.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ba5a0__sub_4BA5A0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bac10__sub_4BAC10.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bafe0__sub_4BAFE0.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bb4b0__sub_4BB4B0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bb560__sub_4BB560.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bbe00__sub_4BBE00.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bc120__sub_4BC120.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bc200__sub_4BC200.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bc7c0__sub_4BC7C0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bcc20__sub_4BCC20.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bd620__sub_4BD620.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bd8a0__sub_4BD8A0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bdf30__sub_4BDF30.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004be230__sub_4BE230.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004be7f0__sub_4BE7F0.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bf070__sub_4BF070.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bfa50__sub_4BFA50.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004bfe60__sub_4BFE60.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0030__sub_4C0030.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0220__sub_4C0220.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0280__sub_4C0280.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c04d0__sub_4C04D0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0970__sub_4C0970.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0be0__sub_4C0BE0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0e30__sub_4C0E30.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c0ed0__sub_4C0ED0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c1030__sub_4C1030.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c1ca0__sub_4C1CA0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c3230__sub_4C3230.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c43c0__sub_4C43C0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c4630__sub_4C4630.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c47e0__sub_4C47E0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c49e0__sub_4C49E0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c4b20__sub_4C4B20.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c5510__sub_4C5510.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c57d0__sub_4C57D0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c5a00__sub_4C5A00.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c5a90__sub_4C5A90.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c5c30__sub_4C5C30.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c6c80__sub_4C6C80.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c7dd0__sub_4C7DD0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c8330__sub_4C8330.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c84c0__sub_4C84C0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c88a0__sub_4C88A0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c8c90__sub_4C8C90.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c8d60__sub_4C8D60.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c8ed0__sub_4C8ED0.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c9410__sub_4C9410.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c95c0__sub_4C95C0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c9cd0__sub_4C9CD0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004c9e90__sub_4C9E90.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ca100__sub_4CA100.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ca3f0__sub_4CA3F0.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cab70__sub_4CAB70.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cad30__sub_4CAD30.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cb6a0__sub_4CB6A0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cc6c0__sub_4CC6C0.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cdf70__sub_4CDF70.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ce4a0__sub_4CE4A0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cfd10__sub_4CFD10.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004cff90__sub_4CFF90.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d0210__sub_4D0210.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d02d0__sub_4D02D0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d0460__sub_4D0460.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d0550__sub_4D0550.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d07a0__sub_4D07A0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d0c40__sub_4D0C40.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d0f00__sub_4D0F00.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d10d0__sub_4D10D0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d1160__sub_4D1160.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d1470__sub_4D1470.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d1640__sub_4D1640.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d1760__sub_4D1760.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d1e60__sub_4D1E60.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d22b0__sub_4D22B0.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d2580__sub_4D2580.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d2670__sub_4D2670.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d2970__sub_4D2970.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d3020__sub_4D3020.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d34a0__sub_4D34A0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d3660__sub_4D3660.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d4290__sub_4D4290.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d4650__sub_4D4650.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d48a0__sub_4D48A0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d4bd0__sub_4D4BD0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d51d0__sub_4D51D0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d5940__sub_4D5940.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d5c80__sub_4D5C80.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d6ba0__sub_4D6BA0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d6d40__sub_4D6D40.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d6f80__sub_4D6F80.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d7080__sub_4D7080.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d7f00__sub_4D7F00.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d8c30__sub_4D8C30.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d97f0__sub_4D97F0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d9c90__sub_4D9C90.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004d9d70__sub_4D9D70.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004da600__sub_4DA600.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004dadc0__sub_4DADC0.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004daf30__sub_4DAF30.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004db1b0__sub_4DB1B0.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004db340__sub_4DB340.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004dd3c0__sub_4DD3C0.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004dd5a0__sub_4DD5A0.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004dd7d0__sub_4DD7D0.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ddc80__sub_4DDC80.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ddd60__sub_4DDD60.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ddf00__sub_4DDF00.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004de000__sub_4DE000.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004de270__sub_4DE270.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004de7b0__sub_4DE7B0.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004de9c0__sub_4DE9C0.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004dee40__sub_4DEE40.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e0d50__sub_4E0D50.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e0fe0__sub_4E0FE0.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e10b0__sub_4E10B0.c
