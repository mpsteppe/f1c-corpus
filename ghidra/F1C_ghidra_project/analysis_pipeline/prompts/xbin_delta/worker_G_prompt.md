# Worker G — sibling-delta documentation (130 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_G.md`

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
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473b30__sub_473B30.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00473df0__sub_473DF0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047a370__sub_47A370.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047a400__sub_47A400.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047a940__sub_47A940.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047b000__sub_47B000.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047b0b0__sub_47B0B0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047b280__sub_47B280.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047b3a0__sub_47B3A0.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047e3c0__sub_47E3C0.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047e9d0__sub_47E9D0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047ef00__sub_47EF00.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047f150__sub_47F150.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0047f380__sub_47F380.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00480aa0__sub_480AA0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00481200__sub_481200.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00481620__sub_481620.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00482cb0__sub_482CB0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00483d70__sub_483D70.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00484060__sub_484060.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004841c0__sub_4841C0.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00484520__sub_484520.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00484eb0__sub_484EB0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00485120__sub_485120.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00485a90__sub_485A90.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00485c50__sub_485C50.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00485ff0__sub_485FF0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004864f0__sub_4864F0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004868b0__sub_4868B0.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00486ab0__sub_486AB0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00486f50__sub_486F50.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00487700__sub_487700.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0048ae20__sub_48AE20.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0048d2b0__sub_48D2B0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0048d3f0__sub_48D3F0.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0048d6f0__sub_48D6F0.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00490970__sub_490970.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004912b0__sub_4912B0.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00491540__sub_491540.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00491690__sub_491690.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00491b20__sub_491B20.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00491f30__sub_491F30.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00492380__sub_492380.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004927b0__sub_4927B0.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00492870__sub_492870.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00492a40__sub_492A40.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00493050__sub_493050.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004932e0__sub_4932E0.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00493b80__sub_493B80.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00493c20__sub_493C20.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00493d80__sub_493D80.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00493ff0__sub_493FF0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004940e0__sub_4940E0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004941f0__sub_4941F0.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004943e0__sub_4943E0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004945c0__sub_4945C0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00494c20__sub_494C20.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00495fe0__sub_495FE0.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004964e0__sub_4964E0.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00496740__sub_496740.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00496c00__sub_496C00.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004972c0__sub_4972C0.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004973a0__sub_4973A0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00497a20__sub_497A20.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498380__sub_498380.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498450__sub_498450.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004989d0__sub_4989D0.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498a60__sub_498A60.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498b10__sub_498B10.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498ba0__sub_498BA0.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00498c40__sub_498C40.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004992d0__sub_4992D0.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004999c0__sub_4999C0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x00499d40__sub_499D40.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049a930__sub_49A930.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049b4e0__sub_49B4E0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049c880__sub_49C880.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049cb80__sub_49CB80.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049cc70__sub_49CC70.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049cdb0__sub_49CDB0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049d360__sub_49D360.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049d9a0__sub_49D9A0.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049dfe0__sub_49DFE0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049e240__sub_49E240.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049e610__sub_49E610.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049f900__sub_49F900.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049fba0__sub_49FBA0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x0049fd40__sub_49FD40.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a06d0__sub_4A06D0.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a08a0__sub_4A08A0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a0c30__sub_4A0C30.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a2160__sub_4A2160.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a64a0__sub_4A64A0.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a6a20__sub_4A6A20.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a6c30__sub_4A6C30.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a6e60__sub_4A6E60.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a77a0__sub_4A77A0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a8ee0__sub_4A8EE0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a91e0__sub_4A91E0.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004a95b0__sub_4A95B0.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004abb80__sub_4ABB80.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004abce0__sub_4ABCE0.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ac3d0__sub_4AC3D0.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004acb60__sub_4ACB60.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004acd90__sub_4ACD90.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ad0a0__sub_4AD0A0.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ad350__sub_4AD350.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004adcd0__sub_4ADCD0.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004ae3f0__sub_4AE3F0.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004aebd0__sub_4AEBD0.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004aeca0__sub_4AECA0.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004afed0__sub_4AFED0.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b0100__sub_4B0100.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b1070__sub_4B1070.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b1560__sub_4B1560.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b18f0__sub_4B18F0.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b19a0__sub_4B19A0.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b1a80__sub_4B1A80.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b1dc0__sub_4B1DC0.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b2250__sub_4B2250.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b3350__sub_4B3350.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b3400__sub_4B3400.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b3e60__sub_4B3E60.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b4180__sub_4B4180.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b4410__sub_4B4410.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b4ab0__sub_4B4AB0.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b5df0__sub_4B5DF0.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b5f60__sub_4B5F60.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b6200__sub_4B6200.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Nascar Thunder 2003\pipeline\not_analyzed\0x004b65e0__sub_4B65E0.c
