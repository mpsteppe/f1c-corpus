# Worker I — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_I.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e13f0__sub_4E13F0.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e14e0__sub_4E14E0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e15c0__sub_4E15C0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e1680__sub_4E1680.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e18e0__sub_4E18E0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e1970__sub_4E1970.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e1a10__sub_4E1A10.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e1cf0__sub_4E1CF0.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e1ee0__sub_4E1EE0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e2280__sub_4E2280.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e2bb0__sub_4E2BB0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e34a0__sub_4E34A0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e3dd0__sub_4E3DD0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e4210__sub_4E4210.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e4330__sub_4E4330.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e5170__sub_4E5170.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e5220__sub_4E5220.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e5290__sub_4E5290.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e53c0__sub_4E53C0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e55b0__sub_4E55B0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e5850__sub_4E5850.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e59a0__sub_4E59A0.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e6290__sub_4E6290.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e6330__sub_4E6330.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e6d40__sub_4E6D40.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e6ea0__sub_4E6EA0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7090__sub_4E7090.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7280__sub_4E7280.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7480__sub_4E7480.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7520__sub_4E7520.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e76c0__sub_4E76C0.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7a60__sub_4E7A60.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7b30__sub_4E7B30.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7ba0__sub_4E7BA0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7d00__sub_4E7D00.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e7f80__sub_4E7F80.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e88c0__sub_4E88C0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e8dd0__sub_4E8DD0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e8ff0__sub_4E8FF0.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e9130__sub_4E9130.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e9280__sub_4E9280.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e92b0__sub_4E92B0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e93d0__sub_4E93D0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e9690__sub_4E9690.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004e9bb0__sub_4E9BB0.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ea120__sub_4EA120.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ea4d0__sub_4EA4D0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004eeea0__sub_4EEEA0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f0030__sub_4F0030.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f0de0__sub_4F0DE0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f1390__sub_4F1390.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f1820__sub_4F1820.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f2720__sub_4F2720.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f2870__sub_4F2870.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f2cc0__sub_4F2CC0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f3430__sub_4F3430.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f3680__sub_4F3680.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f37d0__sub_4F37D0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f38e0__sub_4F38E0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f4400__sub_4F4400.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f4bb0__sub_4F4BB0.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f4c60__sub_4F4C60.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f4e80__sub_4F4E80.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f4f90__sub_4F4F90.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f5060__sub_4F5060.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f5dc0__sub_4F5DC0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f5e60__sub_4F5E60.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f6070__sub_4F6070.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f6320__sub_4F6320.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004f6940__sub_4F6940.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00510e00__sub_510E00.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00514140__sub_514140.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00514e90__sub_514E90.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0052b3f2__sub_52B3F2.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0052c460__sub_52C460.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00530c20__sub_530C20.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00530de0__sub_530DE0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005356d0__sub_5356D0.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00538150__sub_538150.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00539280__sub_539280.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053b880__sub_53B880.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053d080__sub_53D080.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053d190__sub_53D190.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053d3c0__sub_53D3C0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053e300__sub_53E300.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053edc0__sub_53EDC0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0053fde0__sub_53FDE0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00540470__sub_540470.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00547306__sub_547306.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0054cb01__sub_54CB01.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0054d42d__sub_54D42D.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0055153f__sub_55153F.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00551d10__sub_551D10.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552430__sub_552430.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005525f0__sub_5525F0.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005527b0__sub_5527B0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552920__sub_552920.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552ae0__sub_552AE0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552c90__sub_552C90.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552d90__sub_552D90.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00552e80__sub_552E80.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553300__sub_553300.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553450__sub_553450.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553590__sub_553590.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553670__sub_553670.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553a70__sub_553A70.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00553cb0__sub_553CB0.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005540d0__sub_5540D0.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00554420__sub_554420.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00554530__sub_554530.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00554580__sub_554580.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00554640__sub_554640.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00554880__sub_554880.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005549e0__sub_5549E0.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00558641_____L@YGXPAXIHP6EX0@Z1@Z.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005655a5____0Init@ios_base@std@@QAE@XZ.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00566729____0_Winit@std@@QAE@XZ.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0056783c____Init@locale@std@@CAPAV_Locimp@12@XZ.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00567a02____1_Locimp@locale@std@@UAE@XZ.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00567fe0__sub_567FE0.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005689b8__sub_5689B8.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00568c15__sub_568C15.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00568fe6__sub_568FE6.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x005690e1__sub_5690E1.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0057925a__sub_57925A.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0057d310__sub_57D310.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0057d420__sub_57D420.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0057f3cf__sub_57F3CF.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00580c2c__sub_580C2C.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00594c5a____fseeki64.c
