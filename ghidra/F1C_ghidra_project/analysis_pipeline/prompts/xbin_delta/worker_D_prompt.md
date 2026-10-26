# Worker D — sibling-delta documentation (129 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_D.md`

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

### GAME `f1_2002` — target prefix `f1_2002/` (e.g. `<!-- target: f1_2002/40-gameplay.md -->`), 129 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cebf0__sub_4CEBF0.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cf200__sub_4CF200.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cf3a0__sub_4CF3A0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cf500__sub_4CF500.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cfa00__sub_4CFA00.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cfc80__sub_4CFC80.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cfec0__sub_4CFEC0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cffc0__sub_4CFFC0.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d0fe0__sub_4D0FE0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d1320__sub_4D1320.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d1ad0__sub_4D1AD0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d2280__sub_4D2280.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d2500__sub_4D2500.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d3b90__sub_4D3B90.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d3d40__sub_4D3D40.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d3e60__sub_4D3E60.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d4090__sub_4D4090.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d44b0__sub_4D44B0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d4630__sub_4D4630.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d48b0__sub_4D48B0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d4d30__sub_4D4D30.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d4f40__sub_4D4F40.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d53b0__sub_4D53B0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d6820__sub_4D6820.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d6ab0__sub_4D6AB0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d6b80__sub_4D6B80.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d7150__sub_4D7150.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d7440__sub_4D7440.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d7700__sub_4D7700.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d78e0__sub_4D78E0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d7c80__sub_4D7C80.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d85b0__sub_4D85B0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d8f90__sub_4D8F90.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d9440__sub_4D9440.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d9900__sub_4D9900.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004d9a20__sub_4D9A20.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004da3c0__sub_4DA3C0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004da8a0__sub_4DA8A0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004daf20__sub_4DAF20.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004db080__sub_4DB080.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004db120__sub_4DB120.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dbbf0__sub_4DBBF0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dbde0__sub_4DBDE0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dc000__sub_4DC000.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dc350__sub_4DC350.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dc680__sub_4DC680.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dcb10__sub_4DCB10.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dd1e0__sub_4DD1E0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dd400__sub_4DD400.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dd660__sub_4DD660.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dd780__sub_4DD780.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004dd9d0__sub_4DD9D0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ddc20__sub_4DDC20.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004de110__sub_4DE110.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004de500__sub_4DE500.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004df000__sub_4DF000.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e3140__sub_4E3140.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e4200__sub_4E4200.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e54f0__sub_4E54F0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e5620__sub_4E5620.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e6140__sub_4E6140.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e6d20__sub_4E6D20.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e7460__sub_4E7460.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e7510__sub_4E7510.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e7730__sub_4E7730.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e7840__sub_4E7840.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e7910__sub_4E7910.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e8670__sub_4E8670.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e8710__sub_4E8710.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e89d0__sub_4E89D0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004e8c30__sub_4E8C30.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00501d62__sub_501D62.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00501fbf__sub_501FBF.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00502390__sub_502390.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0050248b__sub_50248B.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00504095__sub_504095.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00507450__sub_507450.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0050cb90__sub_50CB90.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0050cca0__sub_50CCA0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0050d5c0__sub_50D5C0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0052dad0__sub_52DAD0.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0052dc00__sub_52DC00.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0052dda0__sub_52DDA0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0052e5f0__sub_52E5F0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00531340__sub_531340.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00531490__sub_531490.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005345f0__sub_5345F0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00534b80__sub_534B80.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005357b0__sub_5357B0.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00537090__sub_537090.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00537c40__sub_537C40.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00539060__sub_539060.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0053b980__sub_53B980.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0053fcd0__sub_53FCD0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005444f0__sub_5444F0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0054ac80__sub_54AC80.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0054e0f0__sub_54E0F0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0054e2a0__sub_54E2A0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0054e8c0__sub_54E8C0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0054eba0__sub_54EBA0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00551370__sub_551370.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005514a0__sub_5514A0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005524b0__sub_5524B0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005528b0__sub_5528B0.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00552ba0__sub_552BA0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00554070__sub_554070.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00554420__sub_554420.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00555640__sub_555640.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00555ca0__sub_555CA0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00555f80__sub_555F80.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005565e0__sub_5565E0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005589a0__sub_5589A0.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0055b670__sub_55B670.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0055d0f0__sub_55D0F0.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0055d830__sub_55D830.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00563590__sub_563590.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00563890__sub_563890.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x005641c0__sub_5641C0.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00569bd7__sub_569BD7.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0056a1b9____0Init@ios_base@std@@QAE@XZ.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0056b238____0_Winit@std@@QAE@XZ.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0056c468____Init@locale@std@@CAPAV_Locimp@12@XZ.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0056c62e____1_Locimp@locale@std@@UAE@XZ.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0056d5d8___setlocale.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00579fbd____fseeki64.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0057dd50__sub_57DD50.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x006ea497__sub_6EA497.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x006eb349__sub_6EB349.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x006ed56e__sub_6ED56E.c
