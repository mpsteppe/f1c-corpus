# WORKER A — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker A of 20, items 1–331.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_A.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

1. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401000__FUN_00401000.c
2. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403fc0__FUN_00403fc0.c
3. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d30__FUN_00404d30.c
4. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405630__FUN_00405630.c
5. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406100__FUN_00406100.c
6. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406e50__FUN_00406e50.c
7. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407fb0__FUN_00407fb0.c
8. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408520__FUN_00408520.c
9. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040acc6__sub_40ACC6.c
10. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040be70__FUN_0040be70.c
11. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d090__FUN_0040d090.c
12. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dbe0__FUN_0040dbe0.c
13. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e8f0__FUN_0040e8f0.c
14. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040fd70__FUN_0040fd70.c
15. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004116b0__FUN_004116b0.c
16. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00413710__FUN_00413710.c
17. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414900__FUN_00414900.c
18. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415c30__FUN_00415c30.c
19. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418db0__FUN_00418db0.c
20. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a6b0__FUN_0041a6b0.c
21. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e840__FUN_0041e840.c
22. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fdb0__FUN_0041fdb0.c
23. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421990__FUN_00421990.c
24. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423530__FUN_00423530.c
25. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00425670__FUN_00425670.c
26. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a780__FUN_0042a780.c
27. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042b8a0__FUN_0042b8a0.c
28. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dc60__FUN_0042dc60.c
29. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ec60__FUN_0042ec60.c
30. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431bc0__FUN_00431bc0.c
31. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432a03__sub_432A03.c
32. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433fc0__FUN_00433fc0.c
33. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435390__FUN_00435390.c
34. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004388d0__FUN_004388d0.c
35. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e4b0__FUN_0043e4b0.c
36. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441600__FUN_00441600.c
37. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004471f0__FUN_004471f0.c
38. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448510__FUN_00448510.c
39. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449340__FUN_00449340.c
40. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044aae0__FUN_0044aae0.c
41. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c650__FUN_0044c650.c
42. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9f4__sub_44C9F4.c
43. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc94__sub_44CC94.c
44. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf20__FUN_0044cf20.c
45. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d220__FUN_0044d220.c
46. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d5b0__FUN_0044d5b0.c
47. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d970__FUN_0044d970.c
48. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd30__FUN_0044dd30.c
49. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0f0__FUN_0044e0f0.c
50. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e4b0__FUN_0044e4b0.c
51. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e870__FUN_0044e870.c
52. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec30__FUN_0044ec30.c
53. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f5f0__FUN_0044f5f0.c
54. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452780__FUN_00452780.c
55. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455580__FUN_00455580.c
56. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004569b0__sub_4569B0.c
57. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004584c0__FUN_004584c0.c
58. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b400__FUN_0045b400.c
59. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bd10__FUN_0045bd10.c
60. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c650__FUN_0045c650.c
61. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d490__FUN_0045d490.c
62. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f710__FUN_0045f710.c
63. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461900__FUN_00461900.c
64. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462460__FUN_00462460.c
65. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636e0__FUN_004636e0.c
66. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004646c0__FUN_004646c0.c
67. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464e90__FUN_00464e90.c
68. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466080__FUN_00466080.c
69. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466d60__FUN_00466d60.c
70. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469630__FUN_00469630.c
71. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b070__sub_46B070.c
72. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d360__FUN_0046d360.c
73. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e7f0__FUN_0046e7f0.c
74. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470170__FUN_00470170.c
75. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004715d0__FUN_004715d0.c
76. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472bc0__FUN_00472bc0.c
77. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004742a0__FUN_004742a0.c
78. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475a90__FUN_00475a90.c
79. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476730__sub_476730.c
80. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477cb0__FUN_00477cb0.c
81. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478390__FUN_00478390.c
82. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479880__FUN_00479880.c
83. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479e80__FUN_00479e80.c
84. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047aa60__FUN_0047aa60.c
85. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047beb0__FUN_0047beb0.c
86. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047e940__FUN_0047e940.c
87. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485510__FUN_00485510.c
88. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485ae0__FUN_00485ae0.c
89. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486460__FUN_00486460.c
90. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486ed0__sub_486ED0.c
91. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004875f0__FUN_004875f0.c
92. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488180__FUN_00488180.c
93. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489440__FUN_00489440.c
94. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489cb0__FUN_00489cb0.c
95. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b560__FUN_0048b560.c
96. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9f0__FUN_0048c9f0.c
97. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d680__FUN_0048d680.c
98. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e650__FUN_0048e650.c
99. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f870__FUN_0048f870.c
100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490160__FUN_00490160.c
101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490b90__FUN_00490b90.c
102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491960__FUN_00491960.c
103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494470__FUN_00494470.c
104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495010__FUN_00495010.c
105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495920__FUN_00495920.c
106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496930__FUN_00496930.c
107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497940__FUN_00497940.c
108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498560__FUN_00498560.c
109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e40__FUN_00498e40.c
110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499540__FUN_00499540.c
111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a70__FUN_00499a70.c
112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e50__FUN_00499e50.c
113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2d0__FUN_0049a2d0.c
114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ab40__sub_49AB40.c
115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b370__FUN_0049b370.c
116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c8a0__FUN_0049c8a0.c
117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e520__FUN_0049e520.c
118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ed30__FUN_0049ed30.c
119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0690__FUN_004a0690.c
120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0e70__FUN_004a0e70.c
121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1dc0__FUN_004a1dc0.c
122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3440__FUN_004a3440.c
123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4710__FUN_004a4710.c
124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5e40__FUN_004a5e40.c
125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b80__FUN_004a8b80.c
126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0b10__FUN_004b0b10.c
127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a50__FUN_004b1a50.c
128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b21c0__FUN_004b21c0.c
129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a40__FUN_004b2a40.c
130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3a90__FUN_004b3a90.c
131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4360__FUN_004b4360.c
132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4fb0__FUN_004b4fb0.c
133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6130__FUN_004b6130.c
134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7c80__FUN_004b7c80.c
135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9510__FUN_004b9510.c
136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cf0__FUN_004b9cf0.c
137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba7a0__FUN_004ba7a0.c
138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb150__FUN_004bb150.c
139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbfc0__FUN_004bbfc0.c
140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd900__FUN_004bd900.c
141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bec55__sub_4BEC55.c
142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0850__FUN_004c0850.c
143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1e20__FUN_004c1e20.c
144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c30__FUN_004c2c30.c
145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c40b0__FUN_004c40b0.c
146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c58a0__FUN_004c58a0.c
147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c71c0__FUN_004c71c0.c
148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7de0__FUN_004c7de0.c
149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c88a0__FUN_004c88a0.c
150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9310__FUN_004c9310.c
151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9d50__FUN_004c9d50.c
152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc500__FUN_004cc500.c
153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce8d0__FUN_004ce8d0.c
154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1027__sub_4D1027.c
155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2210__FUN_004d2210.c
156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4870__FUN_004d4870.c
157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6830__FUN_004d6830.c
158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7dd0__FUN_004d7dd0.c
159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d88b0__FUN_004d88b0.c
160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da820__sub_4DA820.c
161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db4e0__FUN_004db4e0.c
162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc2d0__FUN_004dc2d0.c
163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcee0__FUN_004dcee0.c
164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd8f0__FUN_004dd8f0.c
165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e09e0__FUN_004e09e0.c
166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2230__FUN_004e2230.c
167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3a10__FUN_004e3a10.c
168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e58d0__FUN_004e58d0.c
169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9bd0__FUN_004e9bd0.c
170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed710__FUN_004ed710.c
171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efb20__FUN_004efb20.c
172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1860__FUN_004f1860.c
173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f31f0__FUN_004f31f0.c
174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6f00__FUN_004f6f00.c
175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8b00__FUN_004f8b00.c
176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9240__FUN_004f9240.c
177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb8e0__FUN_004fb8e0.c
178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fe060__FUN_004fe060.c
179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500170__FUN_00500170.c
180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500fca__FUN_00500fca.c
181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503533__FUN_00503533.c
182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504933__FUN_00504933.c
183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507473__FUN_00507473.c
184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005086dd__FUN_005086dd.c
185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005098b7__FUN_005098b7.c
186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a488__FUN_0050a488.c
187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050af3b__FUN_0050af3b.c
188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b462__FUN_0050b462.c
189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c07c__FUN_0050c07c.c
190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c647__FUN_0050c647.c
191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d44f__FUN_0050d44f.c
192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050db5c__sub_50DB5C.c
193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e281__FUN_0050e281.c
194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ed19__FUN_0050ed19.c
195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ff84__FUN_0050ff84.c
196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005116d4__sub_5116D4.c
197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512322__FUN_00512322.c
198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b12__FUN_00513b12.c
199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00514fee__FUN_00514fee.c
200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515e85__FUN_00515e85.c
201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516974__FUN_00516974.c
202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179e0__FUN_005179e0.c
203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051954e__FUN_0051954e.c
204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a9c6__FUN_0051a9c6.c
205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c091__sub_51C091.c
206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d166__FUN_0051d166.c
207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e5d7__FUN_0051e5d7.c
208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f350__sub_51F350.c
209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052020e__sub_52020E.c
210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521831__sub_521831.c
211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00524553__FUN_00524553.c
212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005275dc__sub_5275DC.c
213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529af8__FUN_00529af8.c
214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052ddc0__FUN_0052ddc0.c
215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e5b0__FUN_0052e5b0.c
216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534e70__FUN_00534e70.c
217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536260__FUN_00536260.c
218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005383d0__FUN_005383d0.c
219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ab70__FUN_0053ab70.c
220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b3b0__FUN_0053b3b0.c
221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c4d0__FUN_0053c4d0.c
222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cfe0__FUN_0053cfe0.c
223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d8b0__FUN_0053d8b0.c
224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540d40__FUN_00540d40.c
225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005418b0__FUN_005418b0.c
226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542520__FUN_00542520.c
227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005438b0__FUN_005438b0.c
228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545150__FUN_00545150.c
229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545bb0__FUN_00545bb0.c
230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005471c0__FUN_005471c0.c
231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548190__FUN_00548190.c
232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549166__sub_549166.c
233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a580__FUN_0054a580.c
234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b950__FUN_0054b950.c
235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c210__FUN_0054c210.c
236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e0f0__FUN_0054e0f0.c
237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f830__FUN_0054f830.c
238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fdf0__FUN_0054fdf0.c
239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550870__FUN_00550870.c
240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551a30__FUN_00551a30.c
241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553050__FUN_00553050.c
242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553fc0__FUN_00553fc0.c
243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554f80__FUN_00554f80.c
244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567d3__FUN_005567d3.c
245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005572b0__FUN_005572b0.c
246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558e10__FUN_00558e10.c
247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559e20__FUN_00559e20.c
248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bff0__FUN_0055bff0.c
249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055cdf0__FUN_0055cdf0.c
250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d900__FUN_0055d900.c
251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005607c1__FUN_005607c1.c
252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561940__FUN_00561940.c
253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562150__FUN_00562150.c
254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631a0__FUN_005631a0.c
255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564271__FUN_00564271.c
256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564780__FUN_00564780.c
257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564f10__FUN_00564f10.c
258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566380__FUN_00566380.c
259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566d70__FUN_00566d70.c
260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005678f0__FUN_005678f0.c
261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567f10__FUN_00567f10.c
262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568d90__FUN_00568d90.c
263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569b70__FUN_00569b70.c
264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c830__FUN_0056c830.c
265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f020__FUN_0056f020.c
266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a0c0__FUN_0057a0c0.c
267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a5a0__FUN_0057a5a0.c
268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a910__FUN_0057a910.c
269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae40__FUN_0057ae40.c
270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6c0__FUN_0057b6c0.c
271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bee0__FUN_0057bee0.c
272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e760__FUN_0057e760.c
273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005804a0__FUN_005804a0.c
274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581b30__FUN_00581b30.c
275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582b10__FUN_00582b10.c
276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005835f0__FUN_005835f0.c
277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584c70__FUN_00584c70.c
278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005855e0__FUN_005855e0.c
279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585f60__FUN_00585f60.c
280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586800__FUN_00586800.c
281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587070__FUN_00587070.c
282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587460__FUN_00587460.c
283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005879f0__FUN_005879f0.c
284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587ece__FUN_00587ece.c
285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588678__FUN_00588678.c
286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058924c__FUN_0058924c.c
287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589bf3__FUN_00589bf3.c
288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a19e__FUN_0058a19e.c
289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a770___longjmp.c
290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058af5c__FUN_0058af5c.c
291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bb68__FUN_0058bb68.c
292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c411____freebuf.c
293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da01__sub_58DA01.c
294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e04b__FUN_0058e04b.c
295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f6fe__sub_58F6FE.c
296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590440__FUN_00590440.c
297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591727__FUN_00591727.c
298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592647__FUN_00592647.c
299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005938b4__FUN_005938b4.c
300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594ab4__FUN_00594ab4.c
301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059553a__FUN_0059553a.c
302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596030__FUN_00596030.c
303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597037__FUN_00597037.c
304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597e4f__FUN_00597e4f.c
305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598666__inet_addr.c
306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598731__FUN_00598731.c
307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598af5__FUN_00598af5.c
308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599232__FUN_00599232.c
309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059964a__FUN_0059964a.c
310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059985c__FUN_0059985c.c
311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599be5__FUN_00599be5.c
312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a371__FUN_0059a371.c
313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a781__FUN_0059a781.c
314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac63__FUN_0059ac63.c
315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b24a__RtlUnwind.c
316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bcfc__FUN_0059bcfc.c
317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c45a__Unwind_0059c45a.c
318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c582__Unwind_0059c582.c
319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c65c__Unwind_0059c65c.c
320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c750__Unwind_0059c750.c
321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c880__Unwind_0059c880.c
322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9a0__Unwind_0059c9a0.c
323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb40__Unwind_0059cb40.c
324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc93__Unwind_0059cc93.c
325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce20__Unwind_0059ce20.c
326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf3d__Unwind_0059cf3d.c
327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d058__Unwind_0059d058.c
328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d190__Unwind_0059d190.c
329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d338__Unwind_0059d338.c
330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4e0__Unwind_0059d4e0.c
331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d928__FUN_0059d928.c

## TASK
For each .c file:
1. Find switch statements — extract case values and purposes
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals/struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT

```
=== ENUM DISCOVERIES ===

### EnumName (new or extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence | Confidence |
|-------|---------|----------|------------|

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Likely Meaning |
|-------|-----|------|---------|---------------|
| 0.017453 | — | float | FUN_X | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_A.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
