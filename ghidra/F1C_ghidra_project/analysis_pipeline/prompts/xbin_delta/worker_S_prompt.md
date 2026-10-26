# Worker S — sibling-delta documentation (118 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_S.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004415c0__sub_4415C0.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00441700__sub_441700.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00441a30__sub_441A30.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00441c70__sub_441C70.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004424d0__sub_4424D0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004425f0__sub_4425F0.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00442800__sub_442800.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00442a20__sub_442A20.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00442ba0__sub_442BA0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00442df0__sub_442DF0.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004437e0__sub_4437E0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00444010__sub_444010.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00444490__sub_444490.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00444700__sub_444700.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004447b0__sub_4447B0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004448e0__sub_4448E0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00444c70__sub_444C70.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004452f0__sub_4452F0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004471b0__sub_4471B0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00447ef0__sub_447EF0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00448820__sub_448820.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00448b00__sub_448B00.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00448dd0__sub_448DD0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00448ec0__sub_448EC0.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00449b20__sub_449B20.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00449f90__sub_449F90.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044a2e0__sub_44A2E0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044acb0__sub_44ACB0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044b5d0__sub_44B5D0.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044b6d0__sub_44B6D0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044b830__sub_44B830.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044bcd0__sub_44BCD0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044bf00__sub_44BF00.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044bff0__sub_44BFF0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044c170__sub_44C170.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044c9f0__sub_44C9F0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044f750__sub_44F750.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044ff10__sub_44FF10.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0044ffd0__sub_44FFD0.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00457080__sub_457080.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00457300__sub_457300.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004577d0__sub_4577D0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00457a10__sub_457A10.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00457ae0__sub_457AE0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00457fe0__sub_457FE0.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00458530__sub_458530.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004585c0__sub_4585C0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00458ad0__sub_458AD0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00458e20__sub_458E20.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00459120__sub_459120.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00459ff0__DialogFunc.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045b1a0__sub_45B1A0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045b440__sub_45B440.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045b810__sub_45B810.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045c620__sub_45C620.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045cf90__sub_45CF90.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045d0c0__sub_45D0C0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045d710__sub_45D710.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045e570__sub_45E570.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0045fdf0__sub_45FDF0.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00460e00__sub_460E00.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00460fe0__sub_460FE0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00462b30__sub_462B30.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00463df0__sub_463DF0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00464070__sub_464070.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004649f0__sub_4649F0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00464c10__sub_464C10.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00464e90__sub_464E90.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00465090__sub_465090.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00465f60__sub_465F60.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00467320__sub_467320.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004675d0__sub_4675D0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00467ec0__sub_467EC0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00468160__sub_468160.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00468630__sub_468630.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00468a10__sub_468A10.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004697c0__sub_4697C0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00469940__sub_469940.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00469af0__sub_469AF0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00469e60__sub_469E60.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046a120__sub_46A120.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046aa30__sub_46AA30.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046b0f0__sub_46B0F0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046b710__sub_46B710.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046c3e0__sub_46C3E0.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046c4b0__sub_46C4B0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046c540__sub_46C540.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046c830__sub_46C830.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046d460__sub_46D460.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046d7a0__sub_46D7A0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0046e300__sub_46E300.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00470110__sub_470110.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004701c0__sub_4701C0.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00470e10__sub_470E10.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00471890__sub_471890.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004724b0__sub_4724B0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004726b0__sub_4726B0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00472a90__sub_472A90.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00472c10__sub_472C10.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00472e30__sub_472E30.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00473890__sub_473890.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00473ae0___WinMain@16.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00475b30__sub_475B30.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00475ca0__sub_475CA0.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00476010__sub_476010.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004760d0__sub_4760D0.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00476fe0__sub_476FE0.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00477070__sub_477070.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00477b90__sub_477B90.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00478210__sub_478210.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004782c0__sub_4782C0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00478430__sub_478430.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00478530__sub_478530.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00478e50__sub_478E50.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004794e0__sub_4794E0.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00479580__sub_479580.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00479610__sub_479610.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00479bd0__sub_479BD0.c
