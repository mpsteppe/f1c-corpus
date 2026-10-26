# Worker C — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_C.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00497030__sub_497030.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00497120__sub_497120.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004973e0__sub_4973E0.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00497590__sub_497590.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00497630__sub_497630.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00497800__sub_497800.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004989a0__sub_4989A0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00499000__sub_499000.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00499730__sub_499730.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x00499b80__sub_499B80.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049a1e0__sub_49A1E0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049c2f0__sub_49C2F0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049c4c0__sub_49C4C0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049c860__sub_49C860.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049cc30__sub_49CC30.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049d260__sub_49D260.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049d4e0__sub_49D4E0.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049de10__sub_49DE10.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049e2e0__sub_49E2E0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049e7d0__sub_49E7D0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049ecf0__sub_49ECF0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049f4f0__sub_49F4F0.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049f720__sub_49F720.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x0049fb10__sub_49FB10.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a0ee0__sub_4A0EE0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a50c0__sub_4A50C0.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a5380__sub_4A5380.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a5610__sub_4A5610.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a5e40__sub_4A5E40.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a5ee0__sub_4A5EE0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a7450__sub_4A7450.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a7710__sub_4A7710.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a8dc0__sub_4A8DC0.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004a9cb0__sub_4A9CB0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004aa700__sub_4AA700.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004aaa10__sub_4AAA10.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004aacc0__sub_4AACC0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ab520__sub_4AB520.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ab5b0__sub_4AB5B0.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ab9c0__sub_4AB9C0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004abb20__sub_4ABB20.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ac410__sub_4AC410.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ac4e0__sub_4AC4E0.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004acfb0__sub_4ACFB0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ad0d0__sub_4AD0D0.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ad840__sub_4AD840.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ae390__sub_4AE390.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ae470__sub_4AE470.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ae5e0__sub_4AE5E0.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ae780__sub_4AE780.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004aea40__sub_4AEA40.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004af150__sub_4AF150.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004af750__sub_4AF750.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004af9c0__sub_4AF9C0.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004aff40__sub_4AFF40.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b0c80__sub_4B0C80.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b1080__sub_4B1080.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b1130__sub_4B1130.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b20c0__sub_4B20C0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b2590__sub_4B2590.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b3360__sub_4B3360.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b36a0__sub_4B36A0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b3d10__sub_4B3D10.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b3ff0__sub_4B3FF0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b4220__sub_4B4220.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b4410__sub_4B4410.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b5b00__sub_4B5B00.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b5db0__sub_4B5DB0.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b63f0__sub_4B63F0.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b66e0__sub_4B66E0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b6840__sub_4B6840.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b69f0__sub_4B69F0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b6d50__sub_4B6D50.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b72c0__sub_4B72C0.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b8190__sub_4B8190.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b82e0__sub_4B82E0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b83d0__sub_4B83D0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b8730__sub_4B8730.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b87c0__sub_4B87C0.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b8910__sub_4B8910.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b9090__sub_4B9090.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b93b0__sub_4B93B0.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b9960__sub_4B9960.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004b99f0__sub_4B99F0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ba060__sub_4BA060.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004ba980__sub_4BA980.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bb300__sub_4BB300.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bb820__sub_4BB820.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bbe20__sub_4BBE20.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bc060__sub_4BC060.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bcb40__sub_4BCB40.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bcbd0__sub_4BCBD0.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bcd10__sub_4BCD10.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bcea0__sub_4BCEA0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bd050__sub_4BD050.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bd370__sub_4BD370.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bd7a0__sub_4BD7A0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bd840__sub_4BD840.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004bd8f0__sub_4BD8F0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004be4b0__sub_4BE4B0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004befc0__sub_4BEFC0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c0b10__sub_4C0B10.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c0c50__sub_4C0C50.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c0d70__sub_4C0D70.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c0ed0__sub_4C0ED0.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c1080__sub_4C1080.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c1280__sub_4C1280.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c13c0__sub_4C13C0.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c1cd0__sub_4C1CD0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c1f40__sub_4C1F40.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c2140__sub_4C2140.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c21f0__sub_4C21F0.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c3170__sub_4C3170.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c4140__sub_4C4140.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c4fa0__sub_4C4FA0.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c5070__sub_4C5070.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c5490__sub_4C5490.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c5990__sub_4C5990.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c5ad0__sub_4C5AD0.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c6240__sub_4C6240.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c8720__sub_4C8720.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004c9330__sub_4C9330.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004caba0__sub_4CABA0.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cb300__sub_4CB300.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cb480__sub_4CB480.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cb510__sub_4CB510.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cbc00__sub_4CBC00.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cccf0__sub_4CCCF0.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cd550__sub_4CD550.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\F1 2002\pipeline\not_analyzed\0x004cda90__sub_4CDA90.c
