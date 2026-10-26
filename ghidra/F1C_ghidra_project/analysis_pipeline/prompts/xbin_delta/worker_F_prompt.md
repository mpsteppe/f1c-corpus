# Worker F — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_F.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043c950__sub_43C950.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043cad0__sub_43CAD0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043cbc0__sub_43CBC0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043d180__sub_43D180.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043d920__sub_43D920.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043dc80__sub_43DC80.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0043e160__sub_43E160.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00440b40__sub_440B40.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004414d0__sub_4414D0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00441a20__sub_441A20.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00443410__sub_443410.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00444f00__sub_444F00.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004450e0__sub_4450E0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00446a20__sub_446A20.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00448380__sub_448380.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00448410__sub_448410.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00449670__sub_449670.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00449850__sub_449850.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044cbd0___WinMain@16.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044db90__sub_44DB90.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044e080__sub_44E080.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044e710__sub_44E710.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044e8c0__sub_44E8C0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044fc20__sub_44FC20.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0044fe80__sub_44FE80.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00450100__sub_450100.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004504d0__sub_4504D0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00450700__sub_450700.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00450f70__sub_450F70.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00451520__sub_451520.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00451710__sub_451710.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00452140__sub_452140.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004525d0__sub_4525D0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00452c90__sub_452C90.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00452f80__sub_452F80.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00453340__sub_453340.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004540f0__sub_4540F0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00454240__sub_454240.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00454550__sub_454550.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00454680__sub_454680.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00455030__sub_455030.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004552b0__sub_4552B0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00456850__sub_456850.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00457220__sub_457220.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00457470__sub_457470.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00457540__sub_457540.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00457600__sub_457600.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00457e40__sub_457E40.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00458840__sub_458840.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00458d70__sub_458D70.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00459400__sub_459400.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004596c0__sub_4596C0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00459af0__sub_459AF0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00459bc0__sub_459BC0.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00459d50__sub_459D50.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045a2b0__sub_45A2B0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045a8e0__sub_45A8E0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045ae70__sub_45AE70.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045af80__sub_45AF80.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045b6b0__sub_45B6B0.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045bb60__sub_45BB60.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045bd60__sub_45BD60.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045be10__sub_45BE10.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045c040__sub_45C040.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045c570__sub_45C570.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045c6a0__sub_45C6A0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045c790__sub_45C790.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045c860__sub_45C860.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045d4e0__sub_45D4E0.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045d730__sub_45D730.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045dbe0__sub_45DBE0.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045dee0__sub_45DEE0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045e740__sub_45E740.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045eb70__sub_45EB70.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045f120__sub_45F120.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045f1c0__sub_45F1C0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0045f260__sub_45F260.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00460320__sub_460320.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00460710__sub_460710.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004607d0__sub_4607D0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00460a00__sub_460A00.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00460e50__sub_460E50.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004617d0__sub_4617D0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00461aa0__sub_461AA0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00461e70__sub_461E70.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004620b0__sub_4620B0.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00462540__sub_462540.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004626f0__sub_4626F0.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00462a20__sub_462A20.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00462ab0__sub_462AB0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00462e60__sub_462E60.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00462f60__sub_462F60.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00463350__sub_463350.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00463570__sub_463570.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00463910__sub_463910.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00463b90__sub_463B90.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00464910__sub_464910.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00464a50__sub_464A50.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00467b30__sub_467B30.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00468170__sub_468170.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00469970__sub_469970.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046a0a0__sub_46A0A0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046a3c0__sub_46A3C0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046b1d0__sub_46B1D0.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046b310__sub_46B310.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046b740__sub_46B740.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046b8a0__sub_46B8A0.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046bc40__sub_46BC40.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046bf50__sub_46BF50.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046c7b0__sub_46C7B0.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046cf50__sub_46CF50.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046e1a0__sub_46E1A0.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046e2f0__sub_46E2F0.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046e820__sub_46E820.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0046ff60__sub_46FF60.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00470af0__sub_470AF0.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00471200__sub_471200.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004717d0__sub_4717D0.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00471900__sub_471900.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004722c0__sub_4722C0.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00472710__sub_472710.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00472e30__sub_472E30.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004732e0__sub_4732E0.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473420__sub_473420.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473520__sub_473520.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473620__sub_473620.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473740__sub_473740.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473840__sub_473840.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473940__sub_473940.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473a80__sub_473A80.c
