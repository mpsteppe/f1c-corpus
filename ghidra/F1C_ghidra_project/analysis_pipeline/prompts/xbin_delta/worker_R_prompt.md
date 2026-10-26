# Worker R — sibling-delta documentation (118 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_R.md`

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

### GAME `scgt` — target prefix `scgt/` (e.g. `<!-- target: scgt/40-gameplay.md -->`), 118 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00401c20__sub_401C20.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00401d10__sub_401D10.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004051f0__sub_4051F0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405300__sub_405300.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405390__sub_405390.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405640__sub_405640.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405770__sub_405770.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405810__sub_405810.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00405a00__sub_405A00.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00408060__sub_408060.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00409010__sub_409010.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00409dc0__sub_409DC0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040a620__sub_40A620.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040a6f0__sub_40A6F0.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040a790__sub_40A790.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040a830__sub_40A830.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040abe0__sub_40ABE0.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040ad00__sub_40AD00.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040ae20__sub_40AE20.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040bbd0__sub_40BBD0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040c0e0__sub_40C0E0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040c280__sub_40C280.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040cf80__sub_40CF80.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0040e7d0__sub_40E7D0.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004101d0__sub_4101D0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00410ae0__sub_410AE0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00411150__sub_411150.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00411b70__sub_411B70.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00412760__sub_412760.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004128b0__sub_4128B0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004129c0__sub_4129C0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00412be0__sub_412BE0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00412cc0__sub_412CC0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00412d50__sub_412D50.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00413260__sub_413260.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00413ef0__sub_413EF0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00414050__sub_414050.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004140e0__sub_4140E0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00414490__sub_414490.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00415200__sub_415200.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00416e70__sub_416E70.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00416f50__sub_416F50.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00418dc0__sub_418DC0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00419890__sub_419890.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00419dc0__sub_419DC0.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041b450__sub_41B450.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041b560__sub_41B560.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041bdd0__sub_41BDD0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041c890__sub_41C890.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041cdb0__sub_41CDB0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041d040__sub_41D040.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041d4f0__sub_41D4F0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041d930__sub_41D930.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041db50__sub_41DB50.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041e140__sub_41E140.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041f0d0__sub_41F0D0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041f470__sub_41F470.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0041faf0__sub_41FAF0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00420040__sub_420040.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00420490__sub_420490.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00420570__sub_420570.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004209c0__sub_4209C0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00422990__sub_422990.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00422d10__sub_422D10.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004231e0__sub_4231E0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00423270__sub_423270.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004233f0__sub_4233F0.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00423630__sub_423630.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00423760__sub_423760.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00423c60__sub_423C60.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00424920__sub_424920.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004257d0__sub_4257D0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00425b20__sub_425B20.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00425bf0__sub_425BF0.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004265b0__sub_4265B0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00427750__sub_427750.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00427820__sub_427820.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042acc0__sub_42ACC0.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042b130__sub_42B130.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042bb20__sub_42BB20.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042e750__sub_42E750.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042eb60__sub_42EB60.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0042f290__sub_42F290.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00430ea0__sub_430EA0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00430fe0__sub_430FE0.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00431150__sub_431150.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00431430__sub_431430.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00431c10__sub_431C10.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00432000__sub_432000.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004320d0__sub_4320D0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00432340__sub_432340.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00432b20__sub_432B20.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00432e70__sub_432E70.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00434640__sub_434640.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00435000__sub_435000.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00435790__sub_435790.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00435b40__sub_435B40.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00436160__sub_436160.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00436480__sub_436480.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004369a0__sub_4369A0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00436ac0__sub_436AC0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004374a0__sub_4374A0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00437590__sub_437590.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00438410__sub_438410.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00439410__sub_439410.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004395a0__sub_4395A0.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00439880__sub_439880.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043aa10__sub_43AA10.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043c420__sub_43C420.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043d070__sub_43D070.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043d300__sub_43D300.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043d520__sub_43D520.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043ebe0__sub_43EBE0.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043f950__sub_43F950.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043fda0__sub_43FDA0.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0043fea0__sub_43FEA0.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00440740__sub_440740.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00440dd0__sub_440DD0.c
