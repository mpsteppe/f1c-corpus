# WORKER D — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker D of 20, items 994–1324.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_D.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401090__FUN_00401090.c
995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404460__FUN_00404460.c
996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404e60__FUN_00404e60.c
997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004057e4__sub_4057E4.c
998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406250__FUN_00406250.c
999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004070e0__FUN_004070e0.c
1000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004080b0__FUN_004080b0.c
1001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408740__FUN_00408740.c
1002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ad90__FUN_0040ad90.c
1003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c3b0__FUN_0040c3b0.c
1004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d1b0__FUN_0040d1b0.c
1005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dd30__FUN_0040dd30.c
1006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040eb30__FUN_0040eb30.c
1007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410890__FUN_00410890.c
1008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004117b0__FUN_004117b0.c
1009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414010__FUN_00414010.c
1010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414e54__sub_414E54.c
1011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184f0__FUN_004184f0.c
1012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418e50__FUN_00418e50.c
1013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ab30__FUN_0041ab30.c
1014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041eb30__FUN_0041eb30.c
1015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ff10__FUN_0041ff10.c
1016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004219f0__FUN_004219f0.c
1017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423ad0__FUN_00423ad0.c
1018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426100__FUN_00426100.c
1019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ac90__FUN_0042ac90.c
1020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bb50__FUN_0042bb50.c
1021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dcc0__FUN_0042dcc0.c
1022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ed30__FUN_0042ed30.c
1023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c60__FUN_00431c60.c
1024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432cc0__FUN_00432cc0.c
1025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434090__FUN_00434090.c
1026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004358f0__FUN_004358f0.c
1027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438c10__FUN_00438c10.c
1028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e770__FUN_0043e770.c
1029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441bb0__FUN_00441bb0.c
1030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004472a8__sub_4472A8.c
1031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004485d0__FUN_004485d0.c
1032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449700__FUN_00449700.c
1033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044af60__FUN_0044af60.c
1034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c6e0__FUN_0044c6e0.c
1035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ca70__FUN_0044ca70.c
1036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ccf4__sub_44CCF4.c
1037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf80__FUN_0044cf80.c
1038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2b0__FUN_0044d2b0.c
1039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d640__FUN_0044d640.c
1040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da00__FUN_0044da00.c
1041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ddc0__FUN_0044ddc0.c
1042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e180__FUN_0044e180.c
1043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e540__FUN_0044e540.c
1044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e900__FUN_0044e900.c
1045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ecc0__FUN_0044ecc0.c
1046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f6f0__FUN_0044f6f0.c
1047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452810__FUN_00452810.c
1048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455e50__FUN_00455e50.c
1049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457000__FUN_00457000.c
1050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459070__FUN_00459070.c
1051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b500__FUN_0045b500.c
1052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045be00__FUN_0045be00.c
1053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c7a0__FUN_0045c7a0.c
1054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d500__FUN_0045d500.c
1055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004607a0__FUN_004607a0.c
1056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461db0__FUN_00461db0.c
1057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462550__FUN_00462550.c
1058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463710__FUN_00463710.c
1059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464740__FUN_00464740.c
1060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464f50__FUN_00464f50.c
1061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466160__FUN_00466160.c
1062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004672c0__FUN_004672c0.c
1063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469880__FUN_00469880.c
1064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b5c0__FUN_0046b5c0.c
1065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d630__FUN_0046d630.c
1066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046eec0__FUN_0046eec0.c
1067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004702a0__FUN_004702a0.c
1068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471750__FUN_00471750.c
1069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004732d0__FUN_004732d0.c
1070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474900__FUN_00474900.c
1071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475d30__FUN_00475d30.c
1072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476ec0__FUN_00476ec0.c
1073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477f30__sub_477F30.c
1074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478e10__FUN_00478e10.c
1075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479910__FUN_00479910.c
1076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a000__FUN_0047a000.c
1077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047ab35__sub_47AB35.c
1078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c6c0__FUN_0047c6c0.c
1079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047ef3c__sub_47EF3C.c
1080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004855a0__FUN_004855a0.c
1081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485e30__FUN_00485e30.c
1082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486500__FUN_00486500.c
1083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487010__FUN_00487010.c
1084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487690__FUN_00487690.c
1085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004883a0__FUN_004883a0.c
1086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004894d0__FUN_004894d0.c
1087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489f40__FUN_00489f40.c
1088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b810__FUN_0048b810.c
1089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ca50__FUN_0048ca50.c
1090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d6f0__FUN_0048d6f0.c
1091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e6b0__sub_48E6B0.c
1092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fb30__FUN_0048fb30.c
1093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490250__FUN_00490250.c
1094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004910d0__FUN_004910d0.c
1095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491ad0__FUN_00491ad0.c
1096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494630__sub_494630.c
1097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495080__FUN_00495080.c
1098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495980__FUN_00495980.c
1099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004970e0__FUN_004970e0.c
1100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979c0__FUN_004979c0.c
1101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004986a0__FUN_004986a0.c
1102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f40__FUN_00498f40.c
1103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004995e0__FUN_004995e0.c
1104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499af0__FUN_00499af0.c
1105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e80__FUN_00499e80.c
1106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a330__FUN_0049a330.c
1107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049acc0__FUN_0049acc0.c
1108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b6d0__FUN_0049b6d0.c
1109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d150__FUN_0049d150.c
1110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e663__sub_49E663.c
1111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f170__FUN_0049f170.c
1112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0a80__FUN_004a0a80.c
1113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11b0__FUN_004a11b0.c
1114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1ec0__FUN_004a1ec0.c
1115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3570__FUN_004a3570.c
1116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5330__FUN_004a5330.c
1117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5fa0__FUN_004a5fa0.c
1118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ade20__FUN_004ade20.c
1119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0e30__FUN_004b0e30.c
1120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1ab0__FUN_004b1ab0.c
1121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b21f0__FUN_004b21f0.c
1122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2ad0__FUN_004b2ad0.c
1123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3b30__FUN_004b3b30.c
1124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4460__FUN_004b4460.c
1125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5120__FUN_004b5120.c
1126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b66e0__FUN_004b66e0.c
1127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8140__FUN_004b8140.c
1128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b97e0__FUN_004b97e0.c
1129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d80__FUN_004b9d80.c
1130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba8c0__FUN_004ba8c0.c
1131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb3d0__FUN_004bb3d0.c
1132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc270__FUN_004bc270.c
1133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bda20__FUN_004bda20.c
1134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf390__FUN_004bf390.c
1135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0ab0__FUN_004c0ab0.c
1136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2300__FUN_004c2300.c
1137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2d30__FUN_004c2d30.c
1138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4900__FUN_004c4900.c
1139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5d30__FUN_004c5d30.c
1140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c77d0__FUN_004c77d0.c
1141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7f30__FUN_004c7f30.c
1142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8b70__FUN_004c8b70.c
1143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9600__FUN_004c9600.c
1144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca280__FUN_004ca280.c
1145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
1146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cef30__FUN_004cef30.c
1147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1100__FUN_004d1100.c
1148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2300__FUN_004d2300.c
1149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4a30__FUN_004d4a30.c
1150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7020__FUN_004d7020.c
1151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e30__FUN_004d7e30.c
1152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d89d0__FUN_004d89d0.c
1153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da9c0__FUN_004da9c0.c
1154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db550__FUN_004db550.c
1155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc320__FUN_004dc320.c
1156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf50__FUN_004dcf50.c
1157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de5d0__FUN_004de5d0.c
1158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0d68__sub_4E0D68.c
1159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e23d0__FUN_004e23d0.c
1160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c
1161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e6d93__FUN_004e6d93.c
1162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea040__FUN_004ea040.c
1163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed810__FUN_004ed810.c
1164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004eff00__FUN_004eff00.c
1165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1a60__FUN_004f1a60.c
1166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f62e6__FUN_004f62e6.c
1167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f7010__FUN_004f7010.c
1168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c70__FUN_004f8c70.c
1169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b20__FUN_004f9b20.c
1170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc170__FUN_004fc170.c
1171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fefc0__FUN_004fefc0.c
1172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001d0__FUN_005001d0.c
1173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00501722__FUN_00501722.c
1174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503772__FUN_00503772.c
1175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005053ec__FUN_005053ec.c
1176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005076fe__FUN_005076fe.c
1177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050895d__FUN_0050895d.c
1178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509ab8__FUN_00509ab8.c
1179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a659__FUN_0050a659.c
1180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050afe2__FUN_0050afe2.c
1181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b743__FUN_0050b743.c
1182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c15e__FUN_0050c15e.c
1183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c78c__FUN_0050c78c.c
1184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d507__sub_50D507.c
1185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd0c__FUN_0050dd0c.c
1186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e313__FUN_0050e313.c
1187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f0bf__FUN_0050f0bf.c
1188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005105bf__FUN_005105bf.c
1189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051184f__FUN_0051184f.c
1190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512366__FUN_00512366.c
1191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b8a__FUN_00513b8a.c
1192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005152eb__sub_5152EB.c
1193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515f0e__FUN_00515f0e.c
1194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516a1d__FUN_00516a1d.c
1195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517e85__FUN_00517e85.c
1196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519720__FUN_00519720.c
1197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051aefc__FUN_0051aefc.c
1198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c1cd__FUN_0051c1cd.c
1199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d57f__FUN_0051d57f.c
1200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e7d7__FUN_0051e7d7.c
1201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f560__sub_51F560.c
1202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052050e__sub_52050E.c
1203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005219e1__FUN_005219e1.c
1204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00525aa2__sub_525AA2.c
1205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527eed__FUN_00527eed.c
1206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052a5a8__FUN_0052a5a8.c
1207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052de60__FUN_0052de60.c
1208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e6e7__sub_52E6E7.c
1209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005351d0__FUN_005351d0.c
1210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536560__sub_536560.c
1211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005388d0__FUN_005388d0.c
1212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ac70__FUN_0053ac70.c
1213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b4c0__FUN_0053b4c0.c
1214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c5d0__FUN_0053c5d0.c
1215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d1f0__FUN_0053d1f0.c
1216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ead0__FUN_0053ead0.c
1217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540f00__FUN_00540f00.c
1218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541a70__FUN_00541a70.c
1219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005425a0__FUN_005425a0.c
1220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005439f0__FUN_005439f0.c
1221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005452f0__FUN_005452f0.c
1222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545f50__FUN_00545f50.c
1223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547280__FUN_00547280.c
1224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548810__FUN_00548810.c
1225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549250__FUN_00549250.c
1226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a600__FUN_0054a600.c
1227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054baa0__FUN_0054baa0.c
1228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c290__FUN_0054c290.c
1229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e190__FUN_0054e190.c
1230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fa90__FUN_0054fa90.c
1231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe50__FUN_0054fe50.c
1232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550f70__FUN_00550f70.c
1233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551dd0__FUN_00551dd0.c
1234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005532a0__FUN_005532a0.c
1235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005544c0__FUN_005544c0.c
1236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005550e0__FUN_005550e0.c
1237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055685a__FUN_0055685a.c
1238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005573f0__FUN_005573f0.c
1239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005592b0__FUN_005592b0.c
1240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055baf0__FUN_0055baf0.c
1241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c070__FUN_0055c070.c
1242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055cee0__FUN_0055cee0.c
1243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eb30__FUN_0055eb30.c
1244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560a82__FUN_00560a82.c
1245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005619f1__FUN_005619f1.c
1246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562530__FUN_00562530.c
1247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563230__FUN_00563230.c
1248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564390__FUN_00564390.c
1249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564860__FUN_00564860.c
1250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005651b0__FUN_005651b0.c
1251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566650__FUN_00566650.c
1252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566e20__FUN_00566e20.c
1253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567970__FUN_00567970.c
1254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005681f0__FUN_005681f0.c
1255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568e70__FUN_00568e70.c
1256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a150__FUN_0056a150.c
1257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056cf70__FUN_0056cf70.c
1258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f100__FUN_0056f100.c
1259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a160__FUN_0057a160.c
1260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a680__FUN_0057a680.c
1261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a950__FUN_0057a950.c
1262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aea0__sub_57AEA0.c
1263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7d0__FUN_0057b7d0.c
1264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057c8e0__FUN_0057c8e0.c
1265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e8d0__FUN_0057e8d0.c
1266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00580de0__FUN_00580de0.c
1267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581e80__FUN_00581e80.c
1268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582dc0__FUN_00582dc0.c
1269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583680__FUN_00583680.c
1270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584e30__FUN_00584e30.c
1271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005857c0__FUN_005857c0.c
1272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586000__FUN_00586000.c
1273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586a80__FUN_00586a80.c
1274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005870e0__FUN_005870e0.c
1275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587500__FUN_00587500.c
1276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587a90__FUN_00587a90.c
1277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f90__FUN_00587f90.c
1278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005887ed__FUN_005887ed.c
1279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005894a0__FUN_005894a0.c
1280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589c77__FUN_00589c77.c
1281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2ef__FUN_0058a2ef.c
1282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a88f__FUN_0058a88f.c
1283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058afe1__FUN_0058afe1.c
1284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc56__FUN_0058bc56.c
1285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c674__FUN_0058c674.c
1286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dad7____trandisp2.c
1287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e0c7__FUN_0058e0c7.c
1288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f939__FUN_0058f939.c
1289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005905dd__FUN_005905dd.c
1290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591c79__FUN_00591c79.c
1291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592924__FUN_00592924.c
1292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005939f9__FUN_005939f9.c
1293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594c12__FUN_00594c12.c
1294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005955aa__FUN_005955aa.c
1295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596175__FUN_00596175.c
1296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597218__FUN_00597218.c
1297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059801a__FUN_0059801a.c
1298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598678__connect.c
1299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059876b__sub_59876B.c
1300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c1c__FUN_00598c1c.c
1301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599298__sub_599298.c
1302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599707__FUN_00599707.c
1303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059988b__FUN_0059988b.c
1304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599cb7__FUN_00599cb7.c
1305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a3f3__FUN_0059a3f3.c
1306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a854__FUN_0059a854.c
1307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ad3d__FUN_0059ad3d.c
1308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b390__FUN_0059b390.c
1309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059befd__FUN_0059befd.c
1310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c482__Unwind_0059c482.c
1311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5b2__Unwind_0059c5b2.c
1312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c67a__Unwind_0059c67a.c
1313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7b0__Unwind_0059c7b0.c
1314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8a4__Unwind_0059c8a4.c
1315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9f0__Unwind_0059c9f0.c
1316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb68__Unwind_0059cb68.c
1317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ccc8__Unwind_0059ccc8.c
1318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce76__Unwind_0059ce76.c
1319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf70__Unwind_0059cf70.c
1320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d086__Unwind_0059d086.c
1321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1c8__Unwind_0059d1c8.c
1322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d368__Unwind_0059d368.c
1323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d51c__Unwind_0059d51c.c
1324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d984__FUN_0059d984.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_D.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
