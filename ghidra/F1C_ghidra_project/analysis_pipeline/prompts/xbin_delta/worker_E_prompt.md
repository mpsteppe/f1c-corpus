# Worker E — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_E.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00402450__sub_402450.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00403ee0__sub_403EE0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00404400__sub_404400.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00405580__sub_405580.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00405e20__sub_405E20.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00406640__sub_406640.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004068f0__sub_4068F0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00407160__sub_407160.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004074c0__sub_4074C0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00407690__sub_407690.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00407a90__sub_407A90.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004085d0__unknown_libname_5.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00408750__sub_408750.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004092a0__sub_4092A0.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004095d0__sub_4095D0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00409bf0__sub_409BF0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040a020__sub_40A020.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040a190__sub_40A190.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040bdd0__sub_40BDD0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040c610__sub_40C610.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040cde0__sub_40CDE0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040d440__sub_40D440.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040d710__sub_40D710.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040d7c0__sub_40D7C0.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0040f9f0__sub_40F9F0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00410ed0__sub_410ED0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00411620__sub_411620.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00411990__sub_411990.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00411b70__sub_411B70.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00412460__sub_412460.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00412700__sub_412700.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00412ea0__sub_412EA0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00413710__sub_413710.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00413b60__sub_413B60.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00413c90__sub_413C90.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00413e70__sub_413E70.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00414130__sub_414130.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004143b0__sub_4143B0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00416aa0__sub_416AA0.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00416b90__sub_416B90.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00416f10__sub_416F10.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00417630__sub_417630.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00417a30__sub_417A30.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00417db0__sub_417DB0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00418110__sub_418110.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00418240__sub_418240.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00418390__sub_418390.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004185e0__sub_4185E0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004188f0__sub_4188F0.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00419770__sub_419770.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00419930__sub_419930.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00419a10__sub_419A10.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041a8f0__sub_41A8F0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041ad50__sub_41AD50.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041b810__sub_41B810.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041b9b0__sub_41B9B0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041bc90__sub_41BC90.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041c7b0__sub_41C7B0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041c9b0__sub_41C9B0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041caf0__sub_41CAF0.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041cdd0__sub_41CDD0.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041d000__sub_41D000.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041d450__sub_41D450.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041e040__sub_41E040.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041e7d0__sub_41E7D0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041f340__sub_41F340.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041f450__sub_41F450.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041f590__sub_41F590.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041f690__sub_41F690.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041f780__sub_41F780.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041fbb0__sub_41FBB0.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041fdc0__sub_41FDC0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041fef0__sub_41FEF0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0041fff0__sub_41FFF0.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004205a0__sub_4205A0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00420720__sub_420720.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00420a10__sub_420A10.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00421db0__sub_421DB0.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00422300__sub_422300.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00422460__sub_422460.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00422a80__sub_422A80.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00422db0__sub_422DB0.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00423f30__sub_423F30.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00424640__sub_424640.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00427730__sub_427730.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00427c40__sub_427C40.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00427cd0__sub_427CD0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00428470__sub_428470.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004286e0__sub_4286E0.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00428ed0__sub_428ED0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00429350__sub_429350.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00429910__sub_429910.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00429e70__sub_429E70.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0042a260__sub_42A260.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0042aca0__sub_42ACA0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0042ae10__sub_42AE10.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0042c730__sub_42C730.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0042f2f0__sub_42F2F0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004318c0__sub_4318C0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00431d00__sub_431D00.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00431ed0__sub_431ED0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00431ff0__sub_431FF0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004320e0__sub_4320E0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004321d0__sub_4321D0.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00432510__sub_432510.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00432e30__sub_432E30.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00434810__sub_434810.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00434910__sub_434910.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00435010__sub_435010.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00435660__sub_435660.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00435fd0__sub_435FD0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00436620__sub_436620.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00436e20__sub_436E20.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004373e0__sub_4373E0.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00439a50__sub_439A50.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a190__sub_43A190.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a510__sub_43A510.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a5a0__sub_43A5A0.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a670__sub_43A670.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a800__sub_43A800.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043a8e0__sub_43A8E0.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043ab90__sub_43AB90.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043adb0__sub_43ADB0.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043ae40__sub_43AE40.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043b060__sub_43B060.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043b260__sub_43B260.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043b810__sub_43B810.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043c030__sub_43C030.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043c160__sub_43C160.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043c200__sub_43C200.c
