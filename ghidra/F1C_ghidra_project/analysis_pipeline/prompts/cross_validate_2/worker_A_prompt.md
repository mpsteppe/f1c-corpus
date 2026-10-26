# WORKER A — F1C Cross-Validation Round 2

You are auditing ALL documented function entries across all docs/ files.
Round 2 uses updated docs/12 (2,356 globals) and docs/13 (6,910 lines) as ground truth.
Worker A of 20, items 1–351.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — global names
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct fields
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json` — call edges

## OUTPUT FILE
**APPEND** to (do NOT overwrite): %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_A.md

The file already contains completed verdicts. Before processing each function, check if `## FUN_XXXXXXXX` already appears in the output file — if so, skip it entirely.

## YOUR REMAINING FUNCTIONS (283)

26. FUN_00589D74
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d74__FUN_00589d74.c

27. FUN_00586170
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586170__FUN_00586170.c

28. FUN_00554D70
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554d70__FUN_00554d70.c

29. FUN_0055BAF0
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055baf0__FUN_0055baf0.c

47. FUN_004DCD06
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd06__sub_4DCD06.c

68. FUN_0041E920
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e920__FUN_0041e920.c

69. FUN_004C5070
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5070__FUN_004c5070.c

72. FUN_0059A103
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a103__FUN_0059a103.c

73. FUN_00559D80
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559d80__FUN_00559d80.c

75. FUN_0050A488
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a488__FUN_0050a488.c

76. FUN_0051BFC0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bfc0__FUN_0051bfc0.c

77. FUN_0041FC60
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fc60__FUN_0041fc60.c

81. FUN_0054B2C0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b2c0__FUN_0054b2c0.c

82. FUN_004A5E10
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5e10__FUN_004a5e10.c

83. FUN_005385E0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005385e0__FUN_005385e0.c

84. FUN_0042AD00
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ad00__FUN_0042ad00.c

85. FUN_004BE700
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be700__FUN_004be700.c

86. FUN_004D1AD0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1ad0__FUN_004d1ad0.c

87. FUN_004C69E0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c69e0__FUN_004c69e0.c

88. FUN_00545930
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545930__FUN_00545930.c

89. FUN_00507AC4
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507ac4__FUN_00507ac4.c

90. FUN_004F6950
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6950__FUN_004f6950.c

91. FUN_00500560
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500560__FUN_00500560.c

92. FUN_005082D1
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005082d1__FUN_005082d1.c

93. FUN_00512366
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512366__FUN_00512366.c

94. FUN_004C6960
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6960__FUN_004c6960.c

95. FUN_004B8140
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8140__FUN_004b8140.c

96. FUN_004B7A00
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7a00__FUN_004b7a00.c

97. FUN_00544C50
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544c50__FUN_00544c50.c

98. FUN_0042B8B0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042b8b0__FUN_0042b8b0.c

99. FUN_0042AE20
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ae20__FUN_0042ae20.c

100. FUN_004D1140
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1140__FUN_004d1140.c

101. FUN_00486660
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486660__FUN_00486660.c

102. FUN_004C9790
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9790__FUN_004c9790.c

103. FUN_0046C750
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c750__FUN_0046c750.c

104. FUN_004A4900
   doc: docs/07-pit-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a4900__FUN_004a4900.c

105. FUN_004B7A90
   doc: docs/07-pit-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7a90__FUN_004b7a90.c

106. FUN_004C3200
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c3200__FUN_004c3200.c

107. FUN_004326A0
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004326a0__FUN_004326a0.c

108. FUN_0046CB50
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0046cb50__FUN_0046cb50.c

109. FUN_00404D50
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d50__FUN_00404d50.c

110. FUN_004328C0
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004328c0__FUN_004328c0.c

111. FUN_004B0390
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0390__FUN_004b0390.c

112. FUN_004C6780
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6780__FUN_004c6780.c

113. FUN_0059A69A
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a69a__FUN_0059a69a.c

114. FUN_00559E20
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559e20__FUN_00559e20.c

115. FUN_005654A0
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005654a0__FUN_005654a0.c

116. FUN_004B6360
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6360__FUN_004b6360.c

117. FUN_00565F70
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f70__FUN_00565f70.c

118. FUN_005984AA
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005984aa__FUN_005984aa.c

119. FUN_0046EE60
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ee60__FUN_0046ee60.c

120. FUN_0059C63E
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c63e__Unwind_0059c63e.c

121. FUN_00538CE0
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00538ce0__sub_538CE0.c

122. FUN_0058A6D5
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a6d5__sub_58A6D5.c

123. FUN_0055B200
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0055b200__FUN_0055b200.c

124. FUN_00462010
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00462010__FUN_00462010.c

125. FUN_004109D0
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004109d0__FUN_004109d0.c

126. FUN_004C0A80
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0a80__FUN_004c0a80.c

127. FUN_004F2C60
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004f2c60__FUN_004f2c60.c

128. FUN_0042F470
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042f470__FUN_0042f470.c

129. FUN_004EE150
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee150__FUN_004ee150.c

130. FUN_0049D280
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d280__FUN_0049d280.c

131. FUN_0046A9C0
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a9c0__FUN_0046a9c0.c

132. FUN_004C2E20
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2e20__FUN_004c2e20.c

133. FUN_004C71C0
   doc: docs/13-audit-report.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c71c0__FUN_004c71c0.c

134. FUN_00490D00
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490d00__FUN_00490d00.c

135. FUN_0044CC80
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc80__FUN_0044cc80.c

136. FUN_00454250
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454250__FUN_00454250.c

137. FUN_00494600
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494600__FUN_00494600.c

138. FUN_0049B6D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b6d0__FUN_0049b6d0.c

139. FUN_0044BA40
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ba40__FUN_0044ba40.c

140. FUN_0044E270
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e270__FUN_0044e270.c

141. FUN_0044D5E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d5e0__FUN_0044d5e0.c

142. FUN_0044D040
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d040__FUN_0044d040.c

143. FUN_0044E3F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3f0__FUN_0044e3f0.c

144. FUN_0044D760
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d760__FUN_0044d760.c

145. FUN_0044CE30
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce30__FUN_0044ce30.c

146. FUN_004039C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004039c0__FUN_004039c0.c

147. FUN_00460DD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460dd0__FUN_00460dd0.c

148. FUN_0044E120
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e120__FUN_0044e120.c

149. FUN_00455F90
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455f90__FUN_00455f90.c

150. FUN_004FB6D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb6d0__FUN_004fb6d0.c

151. FUN_00401910
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401910__FUN_00401910.c

152. FUN_0056D430
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d430__FUN_0056d430.c

153. FUN_00441F00
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441f00__FUN_00441f00.c

154. FUN_004E5AE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5ae0__FUN_004e5ae0.c

155. FUN_00430750
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430750__FUN_00430750.c

156. FUN_00448330
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448330__FUN_00448330.c

157. FUN_00448EC0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448ec0__FUN_00448ec0.c

158. FUN_00449A00
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449a00__FUN_00449a00.c

159. FUN_004532D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004532d0__FUN_004532d0.c

160. FUN_004336D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004336d0__FUN_004336d0.c

161. FUN_00448E20
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448e20__FUN_00448e20.c

162. FUN_0059D9B5
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d9b5__FUN_0059d9b5.c

163. FUN_00526550
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526550__FUN_00526550.c

164. FUN_004ED7B0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed7b0__FUN_004ed7b0.c

165. FUN_0056FA96
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056fa96__FUN_0056fa96.c

166. FUN_0050F258
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f258__sub_50F258.c

167. FUN_0051EDAE
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051edae__sub_51EDAE.c

168. FUN_004C8F10
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8f10__FUN_004c8f10.c

169. FUN_0044ACB0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044acb0__FUN_0044acb0.c

170. FUN_00489600
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489600__FUN_00489600.c

171. FUN_0048E600
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e600__FUN_0048e600.c

172. FUN_004982C0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004982c0__FUN_004982c0.c

173. FUN_0047BC90
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bc90__FUN_0047bc90.c

174. FUN_0059B2F0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b2f0__FUN_0059b2f0.c

175. FUN_0050AFE2
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050afe2__FUN_0050afe2.c

176. FUN_0049ED30
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ed30__FUN_0049ed30.c

177. FUN_00543FA0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543fa0__FUN_00543fa0.c

178. FUN_00528CC0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c

179. FUN_0051DCAA
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dcaa__FUN_0051dcaa.c

180. FUN_00486730
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486730__FUN_00486730.c

181. FUN_0050FD94
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fd94__FUN_0050fd94.c

182. FUN_00558D80
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558d80__FUN_00558d80.c

183. FUN_00542950
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542950__FUN_00542950.c

184. FUN_00543250
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543250__FUN_00543250.c

185. FUN_004184F0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184f0__FUN_004184f0.c

186. FUN_004C9310
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9310__FUN_004c9310.c

187. FUN_004796C0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004796c0__FUN_004796c0.c

188. FUN_004F9F70
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f70__FUN_004f9f70.c

189. FUN_00560340
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c

190. FUN_004CD980
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cd980__sub_4CD980.c

191. FUN_004681B0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004681b0__sub_4681B0.c

192. FUN_0058C824
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c824__FUN_0058c824.c

193. FUN_00596175
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596175__FUN_00596175.c

194. FUN_0056AA60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056aa60__FUN_0056aa60.c

195. FUN_00584130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584130__FUN_00584130.c

196. FUN_00595F11
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595f11__FUN_00595f11.c

197. FUN_00552910
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552910__FUN_00552910.c

198. FUN_0059070A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059070a__FUN_0059070a.c

199. FUN_0058F7C9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f7c9__FUN_0058f7c9.c

200. FUN_004B6C90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6c90__FUN_004b6c90.c

201. FUN_00598CDC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cdc__uflow.c

202. FUN_0049A5A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a5a0__FUN_0049a5a0.c

203. FUN_00540DA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540da0__FUN_00540da0.c

204. FUN_005930E8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005930e8__FUN_005930e8.c

205. FUN_004630D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004630d0__FUN_004630d0.c

206. FUN_0059C428
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c428__Unwind_0059c428.c

207. FUN_00499F00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499f00__FUN_00499f00.c

208. FUN_004C7DD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7dd0__FUN_004c7dd0.c

209. FUN_0050D84A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d84a__FUN_0050d84a.c

210. FUN_00548A30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548a30__FUN_00548a30.c

211. FUN_0059D2BF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2bf__Unwind_0059d2bf.c

212. FUN_0040B630
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b630__FUN_0040b630.c

213. FUN_0046D5F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d5f0__FUN_0046d5f0.c

214. FUN_00494F00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494f00__FUN_00494f00.c

215. FUN_004B9FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9fb0__FUN_004b9fb0.c

216. FUN_004F9150
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9150__FUN_004f9150.c

217. FUN_0053A020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053a020__FUN_0053a020.c

218. FUN_00591D2E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591d2e__FUN_00591d2e.c

219. FUN_0041F1E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f1e0__FUN_0041f1e0.c

220. FUN_0049C8A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c8a0__FUN_0049c8a0.c

221. FUN_0053A630
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053a630__FUN_0053a630.c

222. FUN_00564990
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564990__FUN_00564990.c

223. FUN_00415090
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415090__FUN_00415090.c

224. FUN_00473430
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473430__FUN_00473430.c

225. FUN_00494FD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494fd0__FUN_00494fd0.c

226. FUN_004B97D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b97d0__FUN_004b97d0.c

227. FUN_004E4590
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4590__FUN_004e4590.c

228. FUN_0053C800
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c800__FUN_0053c800.c

229. FUN_005975C6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005975c6__FUN_005975c6.c

230. FUN_00479E50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479e50__FUN_00479e50.c

231. FUN_004579C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004579c0__FUN_004579c0.c

232. FUN_00491D10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491d10__FUN_00491d10.c

233. FUN_004B4840
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4840__FUN_004b4840.c

234. FUN_004DFA50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfa50__FUN_004dfa50.c

235. FUN_0051954E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051954e__FUN_0051954e.c

236. FUN_00562830
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562830__FUN_00562830.c

237. FUN_0059CC13
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc13__Unwind_0059cc13.c

238. FUN_0045B480
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b480__FUN_0045b480.c

239. FUN_0047D060
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047d060__FUN_0047d060.c

240. FUN_0049A1C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a1c0__FUN_0049a1c0.c

241. FUN_004C8DC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8dc0__FUN_004c8dc0.c

242. FUN_00517899
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517899__FUN_00517899.c

243. FUN_00593D53
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593d53__FUN_00593d53.c

244. FUN_0059D0C8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0c8__Unwind_0059d0c8.c

245. FUN_00424E30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424e30__FUN_00424e30.c

246. FUN_004798B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004798b0__FUN_004798b0.c

247. FUN_00499050
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499050__FUN_00499050.c

248. FUN_004BDB10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdb10__FUN_004bdb10.c

249. FUN_004FC280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc280__FUN_004fc280.c

250. FUN_00536130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536130__FUN_00536130.c

251. FUN_00587100
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587100__FUN_00587100.c

252. FUN_005989D7
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005989d7__FUN_005989d7.c

253. FUN_004B2AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2ad0__FUN_004b2ad0.c

254. FUN_005626B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005626b0__FUN_005626b0.c

255. FUN_0040DA00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040da00__FUN_0040da00.c

256. FUN_0046B310
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b310__FUN_0046b310.c

257. FUN_0048FB30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fb30__FUN_0048fb30.c

258. FUN_004B2310
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2310__FUN_004b2310.c

259. FUN_004DB7F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db7f0__FUN_004db7f0.c

260. FUN_00513E80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513e80__FUN_00513e80.c

261. FUN_0054FE50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe50__FUN_0054fe50.c

262. FUN_00401030
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401030__FUN_00401030.c

263. FUN_0058A88F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a88f__FUN_0058a88f.c

264. FUN_005477F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005477f0__FUN_005477f0.c

265. FUN_004EA010
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea010__FUN_004ea010.c

266. FUN_004C9000
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9000__FUN_004c9000.c

267. FUN_00495B30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b30__FUN_00495b30.c

268. FUN_00475120
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475120__FUN_00475120.c

269. FUN_0041A160
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a160__FUN_0041a160.c

270. FUN_004D4780
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4780__FUN_004d4780.c

271. FUN_0051177C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051177c__FUN_0051177c.c

272. FUN_00550810
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550810__FUN_00550810.c

273. FUN_0050DD3A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd3a__thunk_FUN_0050dd0c.c

274. FUN_0059C8D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d0__Unwind_0059c8d0.c

275. FUN_00426CC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426cc0__FUN_00426cc0.c

276. FUN_004799A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799a0__FUN_004799a0.c

277. FUN_00499260
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499260__FUN_00499260.c

278. FUN_004BE180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be180__FUN_004be180.c

279. FUN_004FC9A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9a0__FUN_004fc9a0.c

280. FUN_00536FD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536fd0__FUN_00536fd0.c

281. FUN_005883E5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005883e5__FUN_005883e5.c

282. FUN_0059C504
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c504__Unwind_0059c504.c

283. FUN_004582C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582c0__FUN_004582c0.c

284. FUN_0047BE70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be70__FUN_0047be70.c

285. FUN_00499E50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e50__FUN_00499e50.c

286. FUN_004C2FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fb0__FUN_004c2fb0.c

287. FUN_00502C28
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c28__FUN_00502c28.c

288. FUN_0053C210
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c210__FUN_0053c210.c

289. FUN_0058A9DA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a9da__FUN_0058a9da.c

290. FUN_00597568
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597568_____add_12.c

291. FUN_0045E5D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5d0__FUN_0045e5d0.c

292. FUN_004864C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004864c0__FUN_004864c0.c

293. FUN_0049E3E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e3e0__FUN_0049e3e0.c

294. FUN_004CAED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004caed0__FUN_004caed0.c

295. FUN_0050C23C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c23c__FUN_0050c23c.c

296. FUN_00547100
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547100__FUN_00547100.c

297. FUN_0059BFA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfa0___exception.c

298. FUN_00414380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414380__FUN_00414380.c

299. FUN_00485900
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485900__FUN_00485900.c

300. FUN_0049AFA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afa0__FUN_0049afa0.c

301. FUN_004C92B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c92b0__FUN_004c92b0.c

302. FUN_0050C2A6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2a6__FUN_0050c2a6.c

303. FUN_00544F50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544f50__FUN_00544f50.c

304. FUN_0055BB50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb50__FUN_0055bb50.c

305. FUN_0045C780
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c780__FUN_0045c780.c

306. FUN_004BD760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd760__FUN_004bd760.c

307. FUN_005471C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005471c0__FUN_005471c0.c

308. FUN_0058C411
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c411____freebuf.c

309. FUN_004C7C30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c30__FUN_004c7c30.c

310. FUN_005864E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005864e0__FUN_005864e0.c

311. FUN_0045C850
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c850__FUN_0045c850.c

312. FUN_004875F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004875f0__FUN_004875f0.c

313. FUN_0049FFC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffc0__FUN_0049ffc0.c

314. FUN_004D0080
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0080__FUN_004d0080.c

315. FUN_0050D6AC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d6ac__FUN_0050d6ac.c

316. FUN_00547240
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547240__FUN_00547240.c

317. FUN_0059C4AA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4aa__Unwind_0059c4aa.c

318. FUN_0040E2B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e2b0__FUN_0040e2b0.c

319. FUN_0046CB10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb10__FUN_0046cb10.c

320. FUN_0048FE60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe60__FUN_0048fe60.c

321. FUN_004B2930
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2930__FUN_004b2930.c

322. FUN_004DC290
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc290__FUN_004dc290.c

323. FUN_005159A8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159a8__FUN_005159a8.c

324. FUN_005545E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005545e0__FUN_005545e0.c

325. FUN_0040EBD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ebd0__FUN_0040ebd0.c

326. FUN_00479970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479970__FUN_00479970.c

327. FUN_00499E30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e30__FUN_00499e30.c

328. FUN_0059C7D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d0__Unwind_0059c7d0.c

329. FUN_00534AE6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ae6__AVIFileRelease.c

330. FUN_0059C518
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c518__Unwind_0059c518.c

331. FUN_0058DD4B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd4b____math_exit.c

332. FUN_0059D170
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d170__Unwind_0059d170.c

333. FUN_0045BB50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb50__thunk_FUN_0045b400.c

334. FUN_0051F650
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f650__sub_51F650.c

335. FUN_00522A13
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522a13__sub_522A13.c

336. FUN_00520C0E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520c0e__sub_520C0E.c

337. FUN_0052193C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052193c__sub_52193C.c

338. FUN_0058DA01
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da01__sub_58DA01.c

339. FUN_0052AB4E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052ab4e__FUN_0052ab4e.c

340. FUN_0059491A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059491a__FUN_0059491a.c

341. FUN_00596030
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596030__FUN_00596030.c

342. FUN_0057DD40
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dd40__FUN_0057dd40.c

343. FUN_00580190
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00580190__FUN_00580190.c

344. FUN_004B9510
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9510__FUN_004b9510.c

345. FUN_00564660
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564660__FUN_00564660.c

346. FUN_00598672
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598672__sendto.c

347. FUN_0057A420
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a420__FUN_0057a420.c

348. FUN_00552760
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552760__FUN_00552760.c

349. FUN_00535390
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535390__FUN_00535390.c

350. FUN_00476730
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476730__sub_476730.c

351. FUN_00462848
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462848__sub_462848.c

## FOR EACH FUNCTION
1. Find `## FUN_XXXXXXXX` in the doc file
2. Read the actual .c source
3. Compare EVERY claim:
   - **Globals:** correct DAT_ address? correct name from docs/12?
   - **Direction:** reads vs writes?
   - **Types:** claimed double vs `*(int *)(ptr + 0xXXX)` in .c?
   - **Calls:** does .c actually call each claimed FUN_?
   - **Constants:** thresholds accurate?
   - **Moddability:** "configurable" requires config string literal in .c

If CORRECT: `## FUN_XXXXXXXX — PASS`

If ERRORS:
```
## FUN_XXXXXXXX — FAIL
Source: docs/XX-name.md

**Errors:**
- [WRONG_GLOBAL] / [WRONG_NAME] / [WRONG_TYPE] / [WRONG_DIRECTION]
- [MISSING_GLOBAL] / [WRONG_CALL] / [WRONG_CONST] / [WRONG_MODDABILITY]

**Corrected entry:**
<!-- target: docs/XX-name.md -->
## FUN_XXXXXXXX — Corrected Name
[full corrected entry]
```

Write to disk after EVERY function.

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_A.md.
1. Check EVERY function — no skipping.
2. Only flag REAL errors, not style differences.
3. FAIL entries must include all error tags AND a full corrected entry.
