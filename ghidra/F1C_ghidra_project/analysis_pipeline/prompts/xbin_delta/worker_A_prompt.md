# Worker A — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_A.md`

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

### GAME `f1_2002` — target prefix `f1_2002/` (e.g. `<!-- target: f1_2002/40-gameplay.md -->`), 130 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00401100__sub_401100.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00404b80__sub_404B80.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004058a0__sub_4058A0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00405ff0__sub_405FF0.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00406160__sub_406160.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00406860__sub_406860.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004069e0__sub_4069E0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00406b20__sub_406B20.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00406ea0__sub_406EA0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00406f80__sub_406F80.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004071a0__sub_4071A0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004074b0__sub_4074B0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00407680__sub_407680.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00407a80__sub_407A80.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00408560__sub_408560.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004090e0__sub_4090E0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040c4d0__sub_40C4D0.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040c5b0__sub_40C5B0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040c660__sub_40C660.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040cfc0__sub_40CFC0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040ec70__sub_40EC70.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040f070__sub_40F070.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0040f370__sub_40F370.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00410e80__sub_410E80.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00411050__sub_411050.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00411530__sub_411530.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004115f0__sub_4115F0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004131d0__sub_4131D0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00413430__sub_413430.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00413520__sub_413520.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004137b0__sub_4137B0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00414280__sub_414280.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004143f0__sub_4143F0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00414560__sub_414560.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00414db0__sub_414DB0.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004150d0__sub_4150D0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004158b0__sub_4158B0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00415960__sub_415960.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00417c50__sub_417C50.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00417dd0__sub_417DD0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004181b0__sub_4181B0.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00418300__sub_418300.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00418a00__sub_418A00.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00418e00__sub_418E00.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00419a50__sub_419A50.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00419ae0__sub_419AE0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00419bd0__sub_419BD0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00419f50__sub_419F50.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041aa40__sub_41AA40.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041b180__sub_41B180.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041b240__sub_41B240.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041b450__sub_41B450.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041b640__sub_41B640.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041b720__sub_41B720.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041bf80__sub_41BF80.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041dd70__sub_41DD70.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041e1f0__sub_41E1F0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041e670__sub_41E670.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041e790__sub_41E790.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041e9f0__sub_41E9F0.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041ec90__sub_41EC90.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041eed0__sub_41EED0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041efb0__sub_41EFB0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041f100__sub_41F100.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041f2a0__sub_41F2A0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041f520__sub_41F520.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0041f610__sub_41F610.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00420910__sub_420910.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004209b0__sub_4209B0.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00422af0__sub_422AF0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00422e30__sub_422E30.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00423780__sub_423780.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00423d00__sub_423D00.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00423ed0__sub_423ED0.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00424070__sub_424070.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00424760__sub_424760.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00424a20__sub_424A20.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00425290__sub_425290.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004254c0__sub_4254C0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00425640__sub_425640.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00425ef0__sub_425EF0.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00426210__sub_426210.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004285e0__sub_4285E0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00429270__sub_429270.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00429470__sub_429470.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00429840__sub_429840.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00429f70__sub_429F70.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042a360__sub_42A360.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042a480__sub_42A480.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042abd0__sub_42ABD0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042acc0__sub_42ACC0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042b160__sub_42B160.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042b360__sub_42B360.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042b710__sub_42B710.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042bad0__sub_42BAD0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042bbc0__sub_42BBC0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042bef0__sub_42BEF0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042c0b0__sub_42C0B0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042c9e0__sub_42C9E0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042cc10__sub_42CC10.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042ce30__sub_42CE30.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042cf60__sub_42CF60.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042d2c0__sub_42D2C0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042d890__sub_42D890.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042dbc0__sub_42DBC0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042e110__sub_42E110.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042e340__sub_42E340.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042e750__sub_42E750.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042e8a0__sub_42E8A0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042ef30__sub_42EF30.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0042f4d0__sub_42F4D0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004310a0__sub_4310A0.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004315e0__sub_4315E0.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004328c0__sub_4328C0.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004333b0__sub_4333B0.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00434150__sub_434150.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004343e0__sub_4343E0.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00434d90__sub_434D90.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004356c0__sub_4356C0.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00435c00__sub_435C00.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00435c90__sub_435C90.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004363e0__sub_4363E0.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00437000__sub_437000.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004377d0__sub_4377D0.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00437b30__sub_437B30.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00437e80__sub_437E80.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00438740__sub_438740.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004390e0__sub_4390E0.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00439350__sub_439350.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004393e0__sub_4393E0.c
