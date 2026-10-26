# Worker T — sibling-delta documentation (116 functions)

ROLE SPEC (read FIRST — has the gold-standard example): `%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\WORKER_DELTA.md`

WRITE OUTPUT ONLY TO: `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\xbin_delta\worker_T.md`

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

### GAME `scgt` — target prefix `scgt/` (e.g. `<!-- target: scgt/40-gameplay.md -->`), 116 functions:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047a410__sub_47A410.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047a810__sub_47A810.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047b280__sub_47B280.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047bd10__sub_47BD10.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047bea0__sub_47BEA0.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047c0b0__sub_47C0B0.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047c4e0__sub_47C4E0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047d0d0__sub_47D0D0.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047d620__sub_47D620.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047e020__sub_47E020.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047edf0__sub_47EDF0.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0047f2f0__sub_47F2F0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00481340__sub_481340.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00482710__sub_482710.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00482f80__sub_482F80.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00483fa0__sub_483FA0.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00485410__sub_485410.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004858a0__sub_4858A0.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00487630__sub_487630.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00487760__sub_487760.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00487e80__sub_487E80.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004886a0__sub_4886A0.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00488bb0__sub_488BB0.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00488c40__sub_488C40.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00488ce0__sub_488CE0.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00488e50__sub_488E50.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00488ee0__sub_488EE0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048a3c0__sub_48A3C0.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048a530__sub_48A530.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048b860__sub_48B860.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048c250__sub_48C250.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048d590__sub_48D590.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048d660__sub_48D660.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048d7c0__sub_48D7C0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048e250__sub_48E250.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048e510__sub_48E510.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0048e6b0__sub_48E6B0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00490d50__sub_490D50.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00490f40__sub_490F40.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00491a30__sub_491A30.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00491c00__sub_491C00.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00491cf0__sub_491CF0.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00494480__sub_494480.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00494510__sub_494510.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00494610__sub_494610.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004947d0__sub_4947D0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004948a0__sub_4948A0.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00494a40__sub_494A40.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004957b0__sub_4957B0.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00495ab0__sub_495AB0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00495ee0__sub_495EE0.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00495fd0__sub_495FD0.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004960a0__sub_4960A0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00496170__sub_496170.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004968d0__sub_4968D0.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004979f0___ConvertAndDownloadRle@64.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00498ce0___guTexAllocateMemory@60.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00498da0___guTexChangeAttributes@48.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00498f90__sub_498F90.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00499230__sub_499230.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x00499a80__sub_499A80.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049c310__sub_49C310.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049c6f0__sub_49C6F0.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049cfd0__sub_49CFD0.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049d110__sub_49D110.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049d1c0__sub_49D1C0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049d610__sub_49D610.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049d780__sub_49D780.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049e450__sub_49E450.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049e570__sub_49E570.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049e62d__sub_49E62D.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049e6e4__sub_49E6E4.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049e900__sub_49E900.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049eb20__sub_49EB20.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049ebd0__sub_49EBD0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049f4e0__sub_49F4E0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049fbf0__sub_49FBF0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049fe4b__sub_49FE4B.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x0049ffaf__sub_49FFAF.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a15de__sub_4A15DE.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a1ad0__sub_4A1AD0.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a1d40__sub_4A1D40.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a31b0__sub_4A31B0.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a35b0__sub_4A35B0.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a3650__sub_4A3650.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a3700__sub_4A3700.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a37c0__sub_4A37C0.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a4240__sub_4A4240.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a4770__sub_4A4770.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a4830__sub_4A4830.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a48d0__sub_4A48D0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a49f0__sub_4A49F0.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a6ee0__sub_4A6EE0.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a73e0__sub_4A73E0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a7540__sub_4A7540.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a7930__sub_4A7930.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a79d0__sub_4A79D0.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a7ba0__sub_4A7BA0.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004a8470__sub_4A8470.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004ad360__sub_4AD360.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004adfe0__sub_4ADFE0.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004af490____fsopen.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004af8d0___atol.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004aff50___qsort.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b0410___fseek.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b0890___ftell.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b1100___fflush.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b1580___fputc.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b4bb0_____sbh_alloc_block_from_page.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b5ba0___parse_cmdline.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b6bc0____ftelli64.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b6de0____fseeki64.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b7a50____free_lc_time.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b8ac0____ShrMan.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004b9fe0_____tzset.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\source_material\Sports Car GT\pipeline\not_analyzed\0x004ba330__sub_4BA330.c
