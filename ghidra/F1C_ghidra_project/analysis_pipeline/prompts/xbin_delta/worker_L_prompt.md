# Worker L — sibling-delta documentation (112 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_L.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00467970__sub_467970.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00468000__sub_468000.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00468410__sub_468410.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00468560__sub_468560.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00468870__sub_468870.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004689f0__sub_4689F0.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004691e0__DialogFunc.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00469510__sub_469510.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00469a30__sub_469A30.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046a4f0__sub_46A4F0.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046a730__sub_46A730.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046ab80__sub_46AB80.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046add0__sub_46ADD0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046ae60__sub_46AE60.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046b1a0__sub_46B1A0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046b6e0__sub_46B6E0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046ba10__sub_46BA10.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046c520__sub_46C520.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046c780__sub_46C780.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046c8b0__sub_46C8B0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046caf0__sub_46CAF0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046d560__sub_46D560.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046d660__sub_46D660.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046d8b0__sub_46D8B0.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046dfc0__sub_46DFC0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046e090__sub_46E090.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046e1b0__sub_46E1B0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046e370__sub_46E370.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046e530__sub_46E530.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046ef60__sub_46EF60.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046f350__sub_46F350.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0046f7c0__sub_46F7C0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004705f0__sub_4705F0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004717c0__sub_4717C0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00471d90__sub_471D90.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004722f0__sub_4722F0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00472900__sub_472900.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00472ac0__sub_472AC0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00472b50__sub_472B50.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00472c10__sub_472C10.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00472ca0__sub_472CA0.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004734a0__sub_4734A0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004739e0__sub_4739E0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004742f0__sub_4742F0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00474990__sub_474990.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00474aa0__sub_474AA0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00474dc0__sub_474DC0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00475220__sub_475220.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004752f0__sub_4752F0.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00475480__sub_475480.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00475560__sub_475560.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004755f0__sub_4755F0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00475ef0__sub_475EF0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00476f30__sub_476F30.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00477ba0__sub_477BA0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00478170__sub_478170.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00478690__sub_478690.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00479060__sub_479060.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00479190__sub_479190.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00479360__sub_479360.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00479de0__sub_479DE0.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047a420__sub_47A420.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047a940__sub_47A940.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047ae90__sub_47AE90.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047b1a0__sub_47B1A0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047b240__sub_47B240.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047b940__sub_47B940.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047bb30__sub_47BB30.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047c130__sub_47C130.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047c230__sub_47C230.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047c940__sub_47C940.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047dc50__sub_47DC50.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047e180__sub_47E180.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047e230__sub_47E230.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047e2f0__sub_47E2F0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047e6a0__sub_47E6A0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047ef10__sub_47EF10.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0047ff60__sub_47FF60.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00480310__sub_480310.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004809f0__sub_4809F0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00480c70__sub_480C70.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00480f70__sub_480F70.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004814c0__sub_4814C0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00481600__sub_481600.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00481a90__sub_481A90.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00481ce0__sub_481CE0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00481f10__sub_481F10.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00482110__sub_482110.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00482320__sub_482320.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00482a00__sub_482A00.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00482c50__sub_482C50.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00482e90__sub_482E90.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004832c0__sub_4832C0.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004836b0__sub_4836B0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004839f0__sub_4839F0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00484ca0__sub_484CA0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00485010__sub_485010.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00485990__sub_485990.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x004879d0__sub_4879D0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00487ae0__sub_487AE0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00488030__sub_488030.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00488230__sub_488230.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x00489d30__sub_489D30.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048a8b0__sub_48A8B0.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048afb0__sub_48AFB0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048b120__sub_48B120.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048b430__sub_48B430.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048c040__sub_48C040.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048c120__sub_48C120.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048c1f0__sub_48C1F0.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048c5b0__sub_48C5B0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2004\pipeline\not_analyzed\0x0048c880__sub_48C880.c
