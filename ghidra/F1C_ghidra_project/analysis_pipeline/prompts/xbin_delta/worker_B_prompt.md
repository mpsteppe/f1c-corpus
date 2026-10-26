# Worker B — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_B.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00439550__sub_439550.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043aff0__sub_43AFF0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043c4c0__sub_43C4C0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043c880__sub_43C880.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043e080__sub_43E080.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043e190__sub_43E190.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043e3e0__sub_43E3E0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043e510__sub_43E510.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0043ec60__sub_43EC60.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00440020__sub_440020.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00440470__sub_440470.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00440750__sub_440750.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004410f0__sub_4410F0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00441570__sub_441570.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00441d20__sub_441D20.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00442210__sub_442210.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445580__sub_445580.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445860__sub_445860.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445900__sub_445900.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445c30__sub_445C30.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445e50__sub_445E50.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00445ee0__sub_445EE0.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00446100__sub_446100.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00446300__sub_446300.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004468b0__sub_4468B0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004470d0__sub_4470D0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00447210__sub_447210.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00447960__sub_447960.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00447ac0__sub_447AC0.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004487a0__sub_4487A0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00448b00__sub_448B00.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00448ff0__sub_448FF0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0044bb00__sub_44BB00.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0044c480__sub_44C480.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0044c9b0__sub_44C9B0.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0044fdf0__sub_44FDF0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0044ffd0__sub_44FFD0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00451920__sub_451920.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00453350__sub_453350.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004533e0__sub_4533E0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00457be0___WinMain@16.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00458470__sub_458470.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004588a0__sub_4588A0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00458c60__sub_458C60.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00459130__sub_459130.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004595b0__sub_4595B0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00459740__sub_459740.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045add0__sub_45ADD0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045b030__sub_45B030.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045b400__sub_45B400.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045b600__sub_45B600.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045b7a0__sub_45B7A0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045be60__sub_45BE60.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045c410__sub_45C410.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045c9e0__sub_45C9E0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045cde0__sub_45CDE0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045d360__sub_45D360.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045d4d0__sub_45D4D0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045e590__sub_45E590.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0045ea10__sub_45EA10.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00460370__sub_460370.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004605b0__sub_4605B0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00460670__sub_460670.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004616d0__sub_4616D0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004617c0__sub_4617C0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004619f0__sub_4619F0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00461d90__sub_461D90.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00462a40__sub_462A40.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00463120__sub_463120.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00463580__sub_463580.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00463b90__sub_463B90.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00463c20__sub_463C20.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00463d10__sub_463D10.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00464b90__sub_464B90.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00465d20__sub_465D20.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00465dc0__sub_465DC0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00466270__sub_466270.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00466310__sub_466310.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00466d00__sub_466D00.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004678b0__sub_4678B0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00468ae0__sub_468AE0.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00468d70__sub_468D70.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004694c0__sub_4694C0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00469970__sub_469970.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00469ba0__sub_469BA0.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0046bd85__sub_46BD85.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0046c1c0__sub_46C1C0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0046c730__sub_46C730.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0046fb00__sub_46FB00.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00471480__sub_471480.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00471900__sub_471900.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00471a30__sub_471A30.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00471b10__sub_471B10.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00471d70__sub_471D70.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004732e0__sub_4732E0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00474be0__sub_474BE0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00474da0__sub_474DA0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00475bf0__sub_475BF0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004763c0__sub_4763C0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00477720__sub_477720.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004777b0__sub_4777B0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004780a0__sub_4780A0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00478ba0__sub_478BA0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00479050__sub_479050.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00479940__sub_479940.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0047a300__sub_47A300.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0047fa40__sub_47FA40.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004801b0__sub_4801B0.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00481950__sub_481950.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00483e10__sub_483E10.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00484050__sub_484050.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00484340__sub_484340.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00485d10__sub_485D10.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00486130__sub_486130.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00488190__sub_488190.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00488c30__sub_488C30.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00489ec0__sub_489EC0.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048a9d0__sub_48A9D0.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048ad90__sub_48AD90.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048b400__sub_48B400.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048bbb0__sub_48BBB0.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048f0f0__sub_48F0F0.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0048f1a0__sub_48F1A0.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00491a50__sub_491A50.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00494030__sub_494030.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00494e80__sub_494E80.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00495470__sub_495470.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00495dc0__sub_495DC0.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00496ca0__sub_496CA0.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00496df0__sub_496DF0.c
