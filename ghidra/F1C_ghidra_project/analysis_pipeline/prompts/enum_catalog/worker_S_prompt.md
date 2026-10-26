# WORKER S — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker S of 20, items 5957–6286.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_S.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (330)

5957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403cd0__FUN_00403cd0.c
5958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d10__FUN_00404d10.c
5959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004054a0__FUN_004054a0.c
5960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406060__FUN_00406060.c
5961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406ba0__FUN_00406ba0.c
5962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407f01__sub_407F01.c
5963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004084b0__FUN_004084b0.c
5964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac40__FUN_0040ac40.c
5965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040bde0__FUN_0040bde0.c
5966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cdd0__FUN_0040cdd0.c
5967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040da30__FUN_0040da30.c
5968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e880__FUN_0040e880.c
5969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040fb00__FUN_0040fb00.c
5970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411650__FUN_00411650.c
5971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004134d0__FUN_004134d0.c
5972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144f0__FUN_004144f0.c
5973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415900__FUN_00415900.c
5974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418cf0__FUN_00418cf0.c
5975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a4a0__FUN_0041a4a0.c
5976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041c4c0__FUN_0041c4c0.c
5977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fb10__FUN_0041fb10.c
5978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421950__FUN_00421950.c
5979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004234a0__FUN_004234a0.c
5980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424e70__FUN_00424e70.c
5981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a6f0__FUN_0042a6f0.c
5982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042af70__FUN_0042af70.c
5983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dbe0__FUN_0042dbe0.c
5984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ebc0__FUN_0042ebc0.c
5985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431a50__FUN_00431a50.c
5986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432930__FUN_00432930.c
5987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433eb0__FUN_00433eb0.c
5988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435290__FUN_00435290.c
5989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438130__FUN_00438130.c
5990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e230__FUN_0043e230.c
5991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441450__FUN_00441450.c
5992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447100__FUN_00447100.c
5993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004484c0__FUN_004484c0.c
5994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004492b0__FUN_004492b0.c
5995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a880__FUN_0044a880.c
5996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c5f0__FUN_0044c5f0.c
5997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9b0__FUN_0044c9b0.c
5998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc50__FUN_0044cc50.c
5999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ced4__sub_44CED4.c
6000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d1c0__FUN_0044d1c0.c
6001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d550__FUN_0044d550.c
6002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d910__FUN_0044d910.c
6003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dcd0__FUN_0044dcd0.c
6004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e090__FUN_0044e090.c
6005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e450__FUN_0044e450.c
6006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e810__FUN_0044e810.c
6007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ebd0__FUN_0044ebd0.c
6008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c
6009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452700__FUN_00452700.c
6010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455260__FUN_00455260.c
6011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004562a0__FUN_004562a0.c
6012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004583b0__FUN_004583b0.c
6013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b360__FUN_0045b360.c
6014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bc10__FUN_0045bc10.c
6015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3d0__FUN_0045c3d0.c
6016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d240__FUN_0045d240.c
6017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f390__FUN_0045f390.c
6018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461610__FUN_00461610.c
6019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004623e0__FUN_004623e0.c
6020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463140__FUN_00463140.c
6021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464600__FUN_00464600.c
6022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464c10__FUN_00464c10.c
6023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466030__FUN_00466030.c
6024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466a70__sub_466A70.c
6025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004693e0__FUN_004693e0.c
6026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ae60__FUN_0046ae60.c
6027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d0d0__sub_46D0D0.c
6028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e6f0__FUN_0046e6f0.c
6029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ff40__FUN_0046ff40.c
6030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471440__FUN_00471440.c
6031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472930__FUN_00472930.c
6032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473f50__FUN_00473f50.c
6033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475570__FUN_00475570.c
6034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476660__FUN_00476660.c
6035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477aa0__sub_477AA0.c
6036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478320__FUN_00478320.c
6037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479820__FUN_00479820.c
6038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479e30__FUN_00479e30.c
6039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a8f0__FUN_0047a8f0.c
6040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be70__FUN_0047be70.c
6041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047e3f4__sub_47E3F4.c
6042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047fba0__FUN_0047fba0.c
6043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485a70__FUN_00485a70.c
6044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004863c0__FUN_004863c0.c
6045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486e70__sub_486E70.c
6046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004874e0__FUN_004874e0.c
6047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f30__FUN_00487f30.c
6048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488fb0__FUN_00488fb0.c
6049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489c10__FUN_00489c10.c
6050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b4e0__FUN_0048b4e0.c
6051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9d0__FUN_0048c9d0.c
6052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d590__FUN_0048d590.c
6053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e5c0__FUN_0048e5c0.c
6054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f5d0__FUN_0048f5d0.c
6055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fee0__FUN_0048fee0.c
6056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490aa0__FUN_00490aa0.c
6057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004917c0__FUN_004917c0.c
6058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00492030__FUN_00492030.c
6059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494fd0__FUN_00494fd0.c
6060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495890__FUN_00495890.c
6061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004967d0__FUN_004967d0.c
6062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004977e0__FUN_004977e0.c
6063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004983b0__FUN_004983b0.c
6064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498df0__FUN_00498df0.c
6065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004993d0__FUN_004993d0.c
6066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a30__FUN_00499a30.c
6067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e30__FUN_00499e30.c
6068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2b0__FUN_0049a2b0.c
6069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aa90__sub_49AA90.c
6070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b1c0__FUN_0049b1c0.c
6071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c830__FUN_0049c830.c
6072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e490__FUN_0049e490.c
6073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ed10__FUN_0049ed10.c
6074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0590__FUN_004a0590.c
6075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0df0__FUN_004a0df0.c
6076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1d50__FUN_004a1d50.c
6077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3320__FUN_004a3320.c
6078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a46e4__sub_4A46E4.c
6079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5d10__FUN_004a5d10.c
6080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b10__FUN_004a8b10.c
6081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0930__FUN_004b0930.c
6082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a10__FUN_004b1a10.c
6083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2190__FUN_004b2190.c
6084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a10__FUN_004b2a10.c
6085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b33b0__FUN_004b33b0.c
6086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4250__FUN_004b4250.c
6087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4f50__FUN_004b4f50.c
6088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5e50__FUN_004b5e50.c
6089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7a00__FUN_004b7a00.c
6090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8da0__FUN_004b8da0.c
6091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cd0__FUN_004b9cd0.c
6092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba780__FUN_004ba780.c
6093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bafc0__FUN_004bafc0.c
6094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbf20__FUN_004bbf20.c
6095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd860__FUN_004bd860.c
6096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bea10__FUN_004bea10.c
6097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0690__FUN_004c0690.c
6098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1700__FUN_004c1700.c
6099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c10__FUN_004c2c10.c
6100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3fe0__FUN_004c3fe0.c
6101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5690__FUN_004c5690.c
6102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6e80__FUN_004c6e80.c
6103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7ca0__FUN_004c7ca0.c
6104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8650__FUN_004c8650.c
6105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9280__FUN_004c9280.c
6106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9d10__FUN_004c9d10.c
6107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cbf50__FUN_004cbf50.c
6108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce820__FUN_004ce820.c
6109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0f00__FUN_004d0f00.c
6110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2170__FUN_004d2170.c
6111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4840__FUN_004d4840.c
6112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5ea0__FUN_004d5ea0.c
6113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7d90__FUN_004d7d90.c
6114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8860__FUN_004d8860.c
6115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9fe0__FUN_004d9fe0.c
6116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db130__sub_4DB130.c
6117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc250__sub_4DC250.c
6118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcda0__FUN_004dcda0.c
6119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd6a0__FUN_004dd6a0.c
6120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfca0__FUN_004dfca0.c
6121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2130__FUN_004e2130.c
6122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3940__FUN_004e3940.c
6123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e51a0__FUN_004e51a0.c
6124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9980__FUN_004e9980.c
6125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed380__FUN_004ed380.c
6126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efac0__FUN_004efac0.c
6127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f17a0__FUN_004f17a0.c
6128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f3040__FUN_004f3040.c
6129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6d60__FUN_004f6d60.c
6130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ab0__FUN_004f8ab0.c
6131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9200__FUN_004f9200.c
6132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb5d0__FUN_004fb5d0.c
6133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fde00__FUN_004fde00.c
6134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005000e0__FUN_005000e0.c
6135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500f55__FUN_00500f55.c
6136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502f31__FUN_00502f31.c
6137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504640__FUN_00504640.c
6138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506fd9__FUN_00506fd9.c
6139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005084f5__FUN_005084f5.c
6140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509776__FUN_00509776.c
6141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a34b__FUN_0050a34b.c
6142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae92__FUN_0050ae92.c
6143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b42a__FUN_0050b42a.c
6144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c026__FUN_0050c026.c
6145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c5d0__sub_50C5D0.c
6146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0bc__thunk_FUN_0050d0af.c
6147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d9a5__FUN_0050d9a5.c
6148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e198__thunk_FUN_0050e174.c
6149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e9e6__FUN_0050e9e6.c
6150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fd94__FUN_0050fd94.c
6151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511686__sub_511686.c
6152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005122b2__FUN_005122b2.c
6153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051378b__FUN_0051378b.c
6154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051427f__FUN_0051427f.c
6155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515db8__FUN_00515db8.c
6156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516937__FUN_00516937.c
6157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517963__FUN_00517963.c
6158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519375__FUN_00519375.c
6159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a87e__FUN_0051a87e.c
6160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bfc0__FUN_0051bfc0.c
6161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ce2a__FUN_0051ce2a.c
6162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e3e7__FUN_0051e3e7.c
6163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f200__sub_51F200.c
6164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052004e__sub_52004E.c
6165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521712__FUN_00521712.c
6166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00523e7a__FUN_00523e7a.c
6167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005272b5__sub_5272B5.c
6168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005295e0__FUN_005295e0.c
6169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052dc90__FUN_0052dc90.c
6170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e577__sub_52E577.c
6171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534b00__FUN_00534b00.c
6172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536160__FUN_00536160.c
6173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537fe0__FUN_00537fe0.c
6174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053a660__FUN_0053a660.c
6175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b330__FUN_0053b330.c
6176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2c0__FUN_0053c2c0.c
6177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ce40__FUN_0053ce40.c
6178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d880__FUN_0053d880.c
6179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540ca1__sub_540CA1.c
6180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005416a0__FUN_005416a0.c
6181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424c0__FUN_005424c0.c
6182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543800__FUN_00543800.c
6183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545090__FUN_00545090.c
6184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545a10__FUN_00545a10.c
6185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547100__FUN_00547100.c
6186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547af0__FUN_00547af0.c
6187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005490b0__FUN_005490b0.c
6188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a2d0__FUN_0054a2d0.c
6189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b570__FUN_0054b570.c
6190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c1a0__FUN_0054c1a0.c
6191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e080__FUN_0054e080.c
6192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f710__FUN_0054f710.c
6193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fd50__FUN_0054fd50.c
6194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550810__FUN_00550810.c
6195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005518a0__FUN_005518a0.c
6196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552fd0__FUN_00552fd0.c
6197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553e10__FUN_00553e10.c
6198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554e10__FUN_00554e10.c
6199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556790__FUN_00556790.c
6200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557240__FUN_00557240.c
6201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558d80__FUN_00558d80.c
6202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559d10__FUN_00559d10.c
6203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bfc0__FUN_0055bfc0.c
6204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ca90__FUN_0055ca90.c
6205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d5c0__FUN_0055d5c0.c
6206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560547__FUN_00560547.c
6207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561620__FUN_00561620.c
6208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561ff0__FUN_00561ff0.c
6209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563080__FUN_00563080.c
6210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564220__FUN_00564220.c
6211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005646d0__FUN_005646d0.c
6212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564c70__FUN_00564c70.c
6213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f70__FUN_00565f70.c
6214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566cf0__FUN_00566cf0.c
6215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567780__FUN_00567780.c
6216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567db0__FUN_00567db0.c
6217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568cb0__FUN_00568cb0.c
6218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569a20__FUN_00569a20.c
6219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c640__FUN_0056c640.c
6220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ecf0__FUN_0056ecf0.c
6221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a040__FUN_0057a040.c
6222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a580__FUN_0057a580.c
6223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a900__FUN_0057a900.c
6224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae00__FUN_0057ae00.c
6225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6a0__FUN_0057b6a0.c
6226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bcc0__FUN_0057bcc0.c
6227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e570__FUN_0057e570.c
6228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057fde0__sub_57FDE0.c
6229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581a80__FUN_00581a80.c
6230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005828b0__FUN_005828b0.c
6231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583530__FUN_00583530.c
6232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584110__FUN_00584110.c
6233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585470__FUN_00585470.c
6234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585ea0__FUN_00585ea0.c
6235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586700__FUN_00586700.c
6236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586fa0__FUN_00586fa0.c
6237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587430__FUN_00587430.c
6238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005878a0__FUN_005878a0.c
6239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587db0__FUN_00587db0.c
6240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058858d__FUN_0058858d.c
6241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005890aa__FUN_005890aa.c
6242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589b9e__FUN_00589b9e.c
6243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a0bf__FUN_0058a0bf.c
6244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a6eb__FUN_0058a6eb.c
6245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ad08__FUN_0058ad08.c
6246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058babb__FUN_0058babb.c
6247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c331__FUN_0058c331.c
6248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d849__FUN_0058d849.c
6249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dfc1__FUN_0058dfc1.c
6250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f4f2__sub_58F4F2.c
6251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005903c0__FUN_005903c0.c
6252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059163b__FUN_0059163b.c
6253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059247a__FUN_0059247a.c
6254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059379b__FUN_0059379b.c
6255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059491a__FUN_0059491a.c
6256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005953b8__FUN_005953b8.c
6257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595f82__FUN_00595f82.c
6258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596e40__FUN_00596e40.c
6259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597cc0__FUN_00597cc0.c
6260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059865a__closesocket.c
6261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059871b__FUN_0059871b.c
6262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598aa0__FUN_00598aa0.c
6263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005990ae__FUN_005990ae.c
6264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005995e5__FUN_005995e5.c
6265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059983b__sub_59983B.c
6266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599b1c__FUN_00599b1c.c
6267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a336__FUN_0059a336.c
6268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a728__FUN_0059a728.c
6269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac3f__FUN_0059ac3f.c
6270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b0f5__FUN_0059b0f5.c
6271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bbd9__FUN_0059bbd9.c
6272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c43c__Unwind_0059c43c.c
6273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c566__Unwind_0059c566.c
6274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c648__Unwind_0059c648.c
6275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c710__Unwind_0059c710.c
6276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c86a__Unwind_0059c86a.c
6277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c980__Unwind_0059c980.c
6278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb28__Unwind_0059cb28.c
6279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc80__Unwind_0059cc80.c
6280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cde0__Unwind_0059cde0.c
6281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf21__Unwind_0059cf21.c
6282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d03e__Unwind_0059d03e.c
6283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d170__Unwind_0059d170.c
6284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d318__Unwind_0059d318.c
6285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4c0__Unwind_0059d4c0.c
6286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d7ea__FUN_0059d7ea.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_S.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
