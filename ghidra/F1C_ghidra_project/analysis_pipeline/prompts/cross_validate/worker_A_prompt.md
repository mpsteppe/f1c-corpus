# WORKER A — F1C Cross-Validation Audit

You are auditing documented function entries against their actual Ghidra decompilation.
Worker A of 20, items 1–207.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_A.md

## YOUR FUNCTIONS (207)

1. FUN_004A6B80
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6b80__FUN_004a6b80.c
2. FUN_004E96C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e96c0__FUN_004e96c0.c
3. FUN_0044E180
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e180__FUN_0044e180.c
4. FUN_0044DA60
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da60__FUN_0044da60.c
5. FUN_004542D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004542d0__FUN_004542d0.c
6. FUN_0044C680
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c680__FUN_0044c680.c
7. FUN_0044DA30
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da30__FUN_0044da30.c
8. FUN_004636A0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636a0__FUN_004636a0.c
9. FUN_0044C800
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c800__FUN_0044c800.c
10. FUN_0044DBB0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbb0__FUN_0044dbb0.c
11. FUN_0044EFC0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044efc0__FUN_0044efc0.c
12. FUN_0044C980
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c980__FUN_0044c980.c
13. FUN_0044DD30
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd30__FUN_0044dd30.c
14. FUN_00455B30
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455b30__FUN_00455b30.c
15. FUN_0044CB00
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb00__FUN_0044cb00.c
16. FUN_0044E840
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
17. FUN_0044C890
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c890__FUN_0044c890.c
18. FUN_0049B630
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b630__FUN_0049b630.c
19. FUN_004B5630
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5630__FUN_004b5630.c
20. FUN_0059A8FA
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a8fa__FUN_0059a8fa.c
21. FUN_0043E360
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e360__FUN_0043e360.c
22. FUN_004E4790
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4790__FUN_004e4790.c
23. FUN_00441BB0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441bb0__FUN_00441bb0.c
24. FUN_00448120
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448120__FUN_00448120.c
25. FUN_00448EE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448ee0__FUN_00448ee0.c
26. FUN_0043EAE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043eae0__FUN_0043eae0.c
27. FUN_00431850
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431850__FUN_00431850.c
28. FUN_004330D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004330d0__FUN_004330d0.c
29. FUN_004388D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004388d0__FUN_004388d0.c
30. FUN_00441D60
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441d60__FUN_00441d60.c
31. FUN_004FEFC0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fefc0__FUN_004fefc0.c
32. FUN_004C2CB0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2cb0__FUN_004c2cb0.c
33. FUN_004A2800
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2800__FUN_004a2800.c
34. FUN_004CB620
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb620__FUN_004cb620.c
35. FUN_0044ACB0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044acb0__FUN_0044acb0.c
36. FUN_00488BE0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488be0__FUN_00488be0.c
37. FUN_0048E110
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e110__FUN_0048e110.c
38. FUN_004980D0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004980d0__FUN_004980d0.c
39. FUN_0047B730
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b730__FUN_0047b730.c
40. FUN_00557120
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557120__FUN_00557120.c
41. FUN_0053FD40
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fd40__FUN_0053fd40.c
42. FUN_00550080
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550080__FUN_00550080.c
43. FUN_0044A880
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a880__FUN_0044a880.c
44. FUN_004B7860
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7860__FUN_004b7860.c
45. FUN_005172A5
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005172a5__FUN_005172a5.c
46. FUN_00518248
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00518248__FUN_00518248.c
47. FUN_00553CD0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553cd0__FUN_00553cd0.c
48. FUN_00558D10
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558d10__FUN_00558d10.c
49. FUN_0050B244
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b244__FUN_0050b244.c
50. FUN_00500010
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500010__FUN_00500010.c
51. FUN_005029E5
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005029e5__FUN_005029e5.c
52. FUN_0048E860
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e860__FUN_0048e860.c
53. FUN_00408290
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408290__FUN_00408290.c
54. FUN_004A1367
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1367__FUN_004a1367.c
55. FUN_00558C60
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558c60__FUN_00558c60.c
56. FUN_0058DE2C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058de2c__FUN_0058de2c.c
57. FUN_0055ED10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ed10__FUN_0055ed10.c
58. FUN_0059BBD9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bbd9__FUN_0059bbd9.c
59. FUN_0058E41B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e41b__FUN_0058e41b.c
60. FUN_0058F939
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f939__FUN_0058f939.c
61. FUN_00582BA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582ba0__FUN_00582ba0.c
62. FUN_0055EE20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ee20__FUN_0055ee20.c
63. FUN_00591EDF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591edf__FUN_00591edf.c
64. FUN_0051D897
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d897__FUN_0051d897.c
65. FUN_00406060
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406060__FUN_00406060.c
66. FUN_004C0370
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0370__FUN_004c0370.c
67. FUN_0055BB20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb20__FUN_0055bb20.c
68. FUN_00404FE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404fe0__FUN_00404fe0.c
69. FUN_0046A4E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a4e0__FUN_0046a4e0.c
70. FUN_00487690
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487690__FUN_00487690.c
71. FUN_004A1AC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1ac0__FUN_004a1ac0.c
72. FUN_004D7AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ad0__FUN_004d7ad0.c
73. FUN_00515D26
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515d26__FUN_00515d26.c
74. FUN_0055BDC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bdc0__FUN_0055bdc0.c
75. FUN_00566CF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566cf0__FUN_00566cf0.c
76. FUN_004119D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004119d0__FUN_004119d0.c
77. FUN_00473330
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473330__FUN_00473330.c
78. FUN_00498550
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498550__FUN_00498550.c
79. FUN_004BD8C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd8c0__FUN_004bd8c0.c
80. FUN_00507473
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507473__FUN_00507473.c
81. FUN_0053D430
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d430__FUN_0053d430.c
82. FUN_0059AAA2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aaa2__FUN_0059aaa2.c
83. FUN_0045BDF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bdf0__FUN_0045bdf0.c
84. FUN_004B3AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3ad0__FUN_004b3ad0.c
85. FUN_00546230
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546230__FUN_00546230.c
86. FUN_005867B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005867b0__FUN_005867b0.c
87. FUN_004219D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004219d0__FUN_004219d0.c
88. FUN_00478220
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478220__FUN_00478220.c
89. FUN_004985D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004985d0__FUN_004985d0.c
90. FUN_004BB800
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb800__FUN_004bb800.c
91. FUN_004F9190
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9190__FUN_004f9190.c
92. FUN_00546250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546250__FUN_00546250.c
93. FUN_0050B82B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b82b__thunk_FUN_00506fd9.c
94. FUN_004855D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004855d0__FUN_004855d0.c
95. FUN_0045D490
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d490__FUN_0045d490.c
96. FUN_004974A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004974a0__FUN_004974a0.c
97. FUN_004BACF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bacf0__FUN_004bacf0.c
98. FUN_004F8850
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8850__FUN_004f8850.c
99. FUN_0052D8D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8d0__FUN_0052d8d0.c
100. FUN_0057A900
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a900__FUN_0057a900.c
101. FUN_0059D498
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d498__Unwind_0059d498.c
102. FUN_004614C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004614c0__FUN_004614c0.c
103. FUN_00486AA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486aa0__FUN_00486aa0.c
104. FUN_0049ECC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ecc0__FUN_0049ecc0.c
105. FUN_004D1CD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1cd0__FUN_004d1cd0.c
106. FUN_0052692F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052692f__FUN_0052692f.c
107. FUN_0059C6B6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6b6__Unwind_0059c6b6.c
108. FUN_00404830
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404830__FUN_00404830.c
109. FUN_0045B500
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b500__FUN_0045b500.c
110. FUN_0047E680
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047e680__FUN_0047e680.c
111. FUN_0049A210
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a210__FUN_0049a210.c
112. FUN_004C5130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5130__FUN_004c5130.c
113. FUN_00503F75
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503f75__FUN_00503f75.c
114. FUN_0053CA00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ca00__FUN_0053ca00.c
115. FUN_0058DA70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da70____trandisp1.c
116. FUN_00404970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404970__FUN_00404970.c
117. FUN_004BDDE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdde0__FUN_004bdde0.c
118. FUN_0057AEF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aef0__FUN_0057aef0.c
119. FUN_00414180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414180__FUN_00414180.c
120. FUN_004718E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004718e0__FUN_004718e0.c
121. FUN_00491E40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e40__FUN_00491e40.c
122. FUN_004B4FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4fb0__FUN_004b4fb0.c
123. FUN_004DFB90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfb90__FUN_004dfb90.c
124. FUN_0051A5EA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a5ea__FUN_0051a5ea.c
125. FUN_00563E70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563e70__FUN_00563e70.c
126. FUN_0058DCE5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dce5____fload_withFB.c
127. FUN_005986BF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986bf__FUN_005986bf.c
128. FUN_0051A794
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a794__FUN_0051a794.c
129. FUN_004F9AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9ad0__FUN_004f9ad0.c
130. FUN_004B9A10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9a10__FUN_004b9a10.c
131. FUN_00499180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499180__FUN_00499180.c
132. FUN_00479940
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479940__FUN_00479940.c
133. FUN_00455BD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455bd0__FUN_00455bd0.c
134. FUN_004D7DE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7de0__FUN_004d7de0.c
135. FUN_0051177C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051177c__FUN_0051177c.c
136. FUN_0054B4D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4d0__FUN_0054b4d0.c
137. FUN_00593CFD
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593cfd__FUN_00593cfd.c
138. FUN_0059ABCD
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059abcd__FUN_0059abcd.c
139. FUN_00414200
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414200__FUN_00414200.c
140. FUN_00473DD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473dd0__FUN_00473dd0.c
141. FUN_00495110
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495110__FUN_00495110.c
142. FUN_004B9C80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9c80__FUN_004b9c80.c
143. FUN_004EC020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec020__FUN_004ec020.c
144. FUN_0052156F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052156f__FUN_0052156f.c
145. FUN_0057A000
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a000__FUN_0057a000.c
146. FUN_0058C1B1
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c1b1__FUN_0058c1b1.c
147. FUN_004214A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004214a0__FUN_004214a0.c
148. FUN_00477EE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ee0__FUN_00477ee0.c
149. FUN_004979B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979b0__thunk_FUN_00495b30.c
150. FUN_004BB200
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb200__FUN_004bb200.c
151. FUN_004F8C90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c90__FUN_004f8c90.c
152. FUN_0052DF90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df90__FUN_0052df90.c
153. FUN_0057B2E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b2e0__FUN_0057b2e0.c
154. FUN_0058AA39
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aa39__FUN_0058aa39.c
155. FUN_0042E1F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e1f0__FUN_0042e1f0.c
156. FUN_00479A10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a10__FUN_00479a10.c
157. FUN_004992E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004992e0__FUN_004992e0.c
158. FUN_004C2780
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2780__FUN_004c2780.c
159. FUN_005006A4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006a4__FUN_005006a4.c
160. FUN_0053C2A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2a0__FUN_0053c2a0.c
161. FUN_0058AC7A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac7a__FUN_0058ac7a.c
162. FUN_00406F90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406f90__FUN_00406f90.c
163. FUN_004795E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004795e0__FUN_004795e0.c
164. FUN_00498D90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d90__FUN_00498d90.c
165. FUN_004BC390
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc390__FUN_004bc390.c
166. FUN_004FD6F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd6f0__FUN_004fd6f0.c
167. FUN_00537CE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537ce0__FUN_00537ce0.c
168. FUN_005904C1
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005904c1__FUN_005904c1.c
169. FUN_0040CDD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cdd0__FUN_0040cdd0.c
170. FUN_004AA1B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004aa1b0__FUN_004aa1b0.c
171. FUN_00517F04
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f04__FUN_00517f04.c
172. FUN_0059567D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059567d__FUN_0059567d.c
173. FUN_00499E90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e90__FUN_00499e90.c
174. FUN_005957BD
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005957bd__FUN_005957bd.c
175. FUN_00421910
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421910__FUN_00421910.c
176. FUN_00479C30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c30__FUN_00479c30.c
177. FUN_00499540
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499540__FUN_00499540.c
178. FUN_004C2990
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2990__FUN_004c2990.c
179. FUN_005008E4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005008e4__FUN_005008e4.c
180. FUN_0053B330
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b330__FUN_0053b330.c
181. FUN_005891FE
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005891fe__FUN_005891fe.c
182. FUN_00404F10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f10__FUN_00404f10.c
183. FUN_00461F70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461f70__FUN_00461f70.c
184. FUN_00487640
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487640__FUN_00487640.c
185. FUN_0049FFD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffd0__FUN_0049ffd0.c
186. FUN_004CBDD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cbdd0__FUN_004cbdd0.c
187. FUN_0050C48C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c48c__FUN_0050c48c.c
188. FUN_005458D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005458d0__FUN_005458d0.c
189. FUN_0059A3F3
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a3f3__FUN_0059a3f3.c
190. FUN_00463D50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463d50__FUN_00463d50.c
191. FUN_0048E360
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e360__FUN_0048e360.c
192. FUN_004B2B10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b10__FUN_004b2b10.c
193. FUN_0059CFA2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfa2__Unwind_0059cfa2.c
194. FUN_0059CEF5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cef5__Unwind_0059cef5.c
195. FUN_0059CEED
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ceed__Unwind_0059ceed.c
196. FUN_0059C9AB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9ab__Unwind_0059c9ab.c
197. FUN_0059C652
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c652__Unwind_0059c652.c
198. FUN_00568910
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568910__FUN_00568910.c
199. FUN_00568320
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568320__FUN_00568320.c
200. FUN_00585470
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585470__FUN_00585470.c
201. FUN_00411E90
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411e90__FUN_00411e90.c
202. FUN_004B54E0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b54e0__FUN_004b54e0.c
203. FUN_0057BEE0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bee0__FUN_0057bee0.c
204. FUN_00598690
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598690____WSAFDIsSet.c
205. FUN_0057F2B0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057f2b0__FUN_0057f2b0.c
206. FUN_00552760
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552760__FUN_00552760.c
207. FUN_00535390
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535390__FUN_00535390.c

## FOR EACH FUNCTION

1. Find the `## FUN_XXXXXXXX` entry in the doc file (path given in your list)
2. Read the actual .c source file (path given in your list)
3. Compare EVERY claim in the doc entry against the .c source:

   **Check globals:** Does .c actually reference each claimed DAT_ address?
   **Check direction:** Entry says "reads DAT_X" — does .c read or write it?
   **Check struct offsets:** Claimed type (float/int/double) must match .c dereference pattern.
     `*(double *)(ptr + 0xXXX)` = double. `*(int *)(ptr + 0xXXX)` = int.
   **Check called functions:** Does .c actually call each claimed FUN_ address?
   **Check constants:** Are numeric thresholds and values accurate?
   **Check moddability:** "configurable" requires a config/field-name string literal in .c.

4. Write one block per function:

If CORRECT (all claims verified):
```
## FUN_XXXXXXXX — PASS
```

If ERRORS FOUND:
```
## FUN_XXXXXXXX — FAIL
Source: docs/XX-name.md

**Errors:**
- [WRONG_GLOBAL] Entry claims DAT_007c56a4 but .c does not reference it
- [WRONG_TYPE] Entry claims +0x1330 is double but .c shows *(int *)(ptr + 0x1330)
- [WRONG_DIRECTION] Entry says "reads DAT_X" but .c only writes to it
- [MISSING_GLOBAL] .c references DAT_YYYYYY not mentioned in entry
- [WRONG_CALL] Entry claims calls FUN_AAAAAA but .c does not call it
- [MISSING_CALL] .c calls FUN_BBBBBB not mentioned in entry
- [WRONG_CONST] Entry claims threshold 0.5 but .c shows 0.75
- [WRONG_MODDABILITY] Entry says configurable but no config string in .c

**Corrected entry:**
<!-- target: docs/XX-name.md -->
## FUN_XXXXXXXX — Corrected Name
[full corrected entry in standard format]
```

Write to disk after EVERY function. Do not batch.

## GHIDRA PATTERNS
- `*(double *)(ptr + 0x1330)` → offset +0x1330, type double
- `param_1[0x4a]` → int-indexed: byte offset = 0x4a × 4 = 0x128
- `unaff_EBX/ESI/EBP` → register-allocated `this` pointer
- `DAT_XXXXXXXX` → global variable

## RULES
0. NEVER move, rename, or delete any files.
1. Check EVERY function in your list — no skipping.
2. Only flag REAL errors — not style or wording differences.
3. If entry is correct, write PASS — one line only.
4. FAIL entries must include all error tags AND a full corrected replacement entry.
5. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_A.md after each function — never accumulate.
