# WORKER P — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker P of 20, items 4966–5296.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_P.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

4966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004038e0__FUN_004038e0.c
4967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404ac0__sub_404AC0.c
4968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004053e0__FUN_004053e0.c
4969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405e60__FUN_00405e60.c
4970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406b30__sub_406B30.c
4971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407e10__FUN_00407e10.c
4972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408450__FUN_00408450.c
4973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a910__FUN_0040a910.c
4974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b710__FUN_0040b710.c
4975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c910__FUN_0040c910.c
4976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d980__FUN_0040d980.c
4977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e710__FUN_0040e710.c
4978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f4b0__FUN_0040f4b0.c
4979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411330__FUN_00411330.c
4980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00412c30__FUN_00412c30.c
4981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144a0__FUN_004144a0.c
4982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415700__FUN_00415700.c
4983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418b70__FUN_00418b70.c
4984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a200__FUN_0041a200.c
4985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041c0f0__FUN_0041c0f0.c
4986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f190__FUN_0041f190.c
4987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004218f0__FUN_004218f0.c
4988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423250__FUN_00423250.c
4989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424c80__FUN_00424c80.c
4990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a110__FUN_0042a110.c
4991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042aeb0__FUN_0042aeb0.c
4992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ce20__sub_42CE20.c
4993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e4a0__FUN_0042e4a0.c
4994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431930__FUN_00431930.c
4995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004328e0__FUN_004328e0.c
4996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433b60__FUN_00433b60.c
4997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435240__FUN_00435240.c
4998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00436870__FUN_00436870.c
4999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bc20__FUN_0043bc20.c
5000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043fffb__FUN_0043fffb.c
5001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004441f0__FUN_004441f0.c
5002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448300__FUN_00448300.c
5003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448fc0__FUN_00448fc0.c
5004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a450__FUN_0044a450.c
5005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c4c0__FUN_0044c4c0.c
5006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c920__FUN_0044c920.c
5007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbf0__FUN_0044cbf0.c
5008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce74__sub_44CE74.c
5009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d130__FUN_0044d130.c
5010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d4c0__FUN_0044d4c0.c
5011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d880__FUN_0044d880.c
5012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc40__FUN_0044dc40.c
5013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e000__FUN_0044e000.c
5014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3c0__FUN_0044e3c0.c
5015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e780__FUN_0044e780.c
5016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c
5017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f150__FUN_0044f150.c
5018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
5019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454c20__FUN_00454c20.c
5020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456150__FUN_00456150.c
5021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582a0__FUN_004582a0.c
5022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b050__sub_45B050.c
5023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb90__FUN_0045bb90.c
5024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0c0__FUN_0045c0c0.c
5025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cf50__sub_45CF50.c
5026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f030__FUN_0045f030.c
5027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461560__FUN_00461560.c
5028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462370__FUN_00462370.c
5029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462ff0__FUN_00462ff0.c
5030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463ef0__FUN_00463ef0.c
5031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464b40__FUN_00464b40.c
5032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465d70__FUN_00465d70.c
5033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466980__FUN_00466980.c
5034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00468610__FUN_00468610.c
5035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a980__FUN_0046a980.c
5036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb10__FUN_0046cb10.c
5037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e590__FUN_0046e590.c
5038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fe20__FUN_0046fe20.c
5039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004711a0__FUN_004711a0.c
5040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472630__FUN_00472630.c
5041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473dd0__FUN_00473dd0.c
5042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475120__FUN_00475120.c
5043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476250__sub_476250.c
5044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477720__FUN_00477720.c
5045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478280__FUN_00478280.c
5046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479790__FUN_00479790.c
5047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479cd0__FUN_00479cd0.c
5048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a620__FUN_0047a620.c
5049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bcf0__FUN_0047bcf0.c
5050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047dbe0__sub_47DBE0.c
5051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f3d0__FUN_0047f3d0.c
5052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485900__FUN_00485900.c
5053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486320__FUN_00486320.c
5054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004869e0__FUN_004869e0.c
5055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487400__FUN_00487400.c
5056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487e70__FUN_00487e70.c
5057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488be0__FUN_00488be0.c
5058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489a50__FUN_00489a50.c
5059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b024__sub_48B024.c
5060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c940__FUN_0048c940.c
5061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3e0__FUN_0048d3e0.c
5062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e360__FUN_0048e360.c
5063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f300__FUN_0048f300.c
5064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe90__FUN_0048fe90.c
5065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490920__FUN_00490920.c
5066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491740__FUN_00491740.c
5067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491ee0__FUN_00491ee0.c
5068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494f10__FUN_00494f10.c
5069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495790__FUN_00495790.c
5070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496560__FUN_00496560.c
5071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497650__FUN_00497650.c
5072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004980d0__FUN_004980d0.c
5073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d20__FUN_00498d20.c
5074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499280__FUN_00499280.c
5075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004999e0__FUN_004999e0.c
5076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e00__FUN_00499e00.c
5077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a210__FUN_0049a210.c
5078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aa10__FUN_0049aa10.c
5079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b030__sub_49B030.c
5080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049bb20__FUN_0049bb20.c
5081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e170__FUN_0049e170.c
5082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049eca0__FUN_0049eca0.c
5083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0010__FUN_004a0010.c
5084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0dc0__FUN_004a0dc0.c
5085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b70__FUN_004a1b70.c
5086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2980__FUN_004a2980.c
5087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40f0__FUN_004a40f0.c
5088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5c10__FUN_004a5c10.c
5089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a7040__sub_4A7040.c
5090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b04e0__FUN_004b04e0.c
5091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b19b0__FUN_004b19b0.c
5092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b20d0__FUN_004b20d0.c
5093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2980__FUN_004b2980.c
5094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2dd0__FUN_004b2dd0.c
5095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b41b0__FUN_004b41b0.c
5096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4a30__FUN_004b4a30.c
5097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5c50__FUN_004b5c50.c
5098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b72a0__FUN_004b72a0.c
5099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8ae0__FUN_004b8ae0.c
5100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9c80__FUN_004b9c80.c
5101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba6c0__FUN_004ba6c0.c
5102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bae20__FUN_004bae20.c
5103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb950__FUN_004bb950.c
5104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7d0__FUN_004bd7d0.c
5105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be6f0__FUN_004be6f0.c
5106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0370__FUN_004c0370.c
5107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1660__thunk_FUN_004c0f60.c
5108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2be0__FUN_004c2be0.c
5109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3890__FUN_004c3890.c
5110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5130__FUN_004c5130.c
5111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c69e0__FUN_004c69e0.c
5112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c50__sub_4C7C50.c
5113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85c0__FUN_004c85c0.c
5114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9060__FUN_004c9060.c
5115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9ba0__sub_4C9BA0.c
5116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb860__sub_4CB860.c
5117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce110__FUN_004ce110.c
5118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0c20__FUN_004d0c20.c
5119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1cf0__FUN_004d1cf0.c
5120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47c0__FUN_004d47c0.c
5121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c50__FUN_004d5c50.c
5122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7c10__FUN_004d7c10.c
5123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8720__FUN_004d8720.c
5124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d99e0__FUN_004d99e0.c
5125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db100__sub_4DB100.c
5126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc0b0__FUN_004dc0b0.c
5127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd10__FUN_004dcd10.c
5128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4d0__FUN_004dd4d0.c
5129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfb60__FUN_004dfb60.c
5130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e19d0__FUN_004e19d0.c
5131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3090__FUN_004e3090.c
5132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4fb0__FUN_004e4fb0.c
5133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9600__FUN_004e9600.c
5134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed1f0__FUN_004ed1f0.c
5135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef7c0__FUN_004ef7c0.c
5136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f15da__FUN_004f15da.c
5137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f2430__FUN_004f2430.c
5138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b80__FUN_004f6b80.c
5139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f88a0__FUN_004f88a0.c
5140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9160__FUN_004f9160.c
5141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004faf60__FUN_004faf60.c
5142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd7e0__FUN_004fd7e0.c
5143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fffb0__FUN_004fffb0.c
5144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500b42__FUN_00500b42.c
5145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c1f__sub_502C1F.c
5146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050427d__FUN_0050427d.c
5147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506971__FUN_00506971.c
5148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005081ae__FUN_005081ae.c
5149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005094e8__FUN_005094e8.c
5150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a172__FUN_0050a172.c
5151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae3e__FUN_0050ae3e.c
5152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b3ed__FUN_0050b3ed.c
5153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b891__FUN_0050b891.c
5154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c525__sub_50C525.c
5155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdff__sub_50CDFF.c
5156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d93f__FUN_0050d93f.c
5157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e0d3__FUN_0050e0d3.c
5158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e84b__FUN_0050e84b.c
5159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fc58__FUN_0050fc58.c
5160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005115c4__FUN_005115c4.c
5161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051215a__FUN_0051215a.c
5162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513022__FUN_00513022.c
5163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513e5d__FUN_00513e5d.c
5164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159f5__FUN_005159f5.c
5165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516772__FUN_00516772.c
5166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005177b6__FUN_005177b6.c
5167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519351__FUN_00519351.c
5168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a4f2__FUN_0051a4f2.c
5169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051be7d__sub_51BE7D.c
5170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cd3e__sub_51CD3E.c
5171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e0dc__FUN_0051e0dc.c
5172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ef5e__sub_51EF5E.c
5173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051fd90__sub_51FD90.c
5174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005214aa__sub_5214AA.c
5175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522b5b__sub_522B5B.c
5176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052704a__sub_52704A.c
5177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528f00__FUN_00528f00.c
5178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d9d0__FUN_0052d9d0.c
5179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e520__FUN_0052e520.c
5180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ae0__AVIFileExit.c
5181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005357c0__FUN_005357c0.c
5182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537eb0__FUN_00537eb0.c
5183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539f60__FUN_00539f60.c
5184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b1d0__FUN_0053b1d0.c
5185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c200__FUN_0053c200.c
5186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cb20__FUN_0053cb20.c
5187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d4c0__FUN_0053d4c0.c
5188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005404d0__FUN_005404d0.c
5189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005414f0__FUN_005414f0.c
5190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542420__FUN_00542420.c
5191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005435c0__FUN_005435c0.c
5192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544f50__FUN_00544f50.c
5193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005458d0__FUN_005458d0.c
5194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546fe0__FUN_00546fe0.c
5195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547860__FUN_00547860.c
5196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548e80__FUN_00548e80.c
5197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a200__FUN_0054a200.c
5198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4a0__FUN_0054b4a0.c
5199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c110__FUN_0054c110.c
5200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d7a0__FUN_0054d7a0.c
5201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eed0__FUN_0054eed0.c
5202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fcc0__FUN_0054fcc0.c
5203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005507d0__FUN_005507d0.c
5204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551800__FUN_00551800.c
5205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552d70__FUN_00552d70.c
5206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553d70__FUN_00553d70.c
5207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554cc0__FUN_00554cc0.c
5208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556700__FUN_00556700.c
5209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556e70__FUN_00556e70.c
5210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558cb0__FUN_00558cb0.c
5211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a40__FUN_00559a40.c
5212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055be60__FUN_0055be60.c
5213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9b0__FUN_0055c9b0.c
5214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d530__FUN_0055d530.c
5215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
5216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560fd0__FUN_00560fd0.c
5217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561f40__FUN_00561f40.c
5218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562fe0__FUN_00562fe0.c
5219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563ec0__FUN_00563ec0.c
5220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564660__FUN_00564660.c
5221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564b10__FUN_00564b10.c
5222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ef0__FUN_00565ef0.c
5223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566c00__FUN_00566c00.c
5224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005676c0__FUN_005676c0.c
5225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567bb0__FUN_00567bb0.c
5226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568ba0__FUN_00568ba0.c
5227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569860__FUN_00569860.c
5228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c2d0__FUN_0056c2d0.c
5229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056eb90__FUN_0056eb90.c
5230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579ff0__FUN_00579ff0.c
5231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a4f0__FUN_0057a4f0.c
5232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a8b0__FUN_0057a8b0.c
5233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057adb0__FUN_0057adb0.c
5234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b5c0__FUN_0057b5c0.c
5235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bc80__sub_57BC80.c
5236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e280__FUN_0057e280.c
5237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057fb90__FUN_0057fb90.c
5238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581940__FUN_00581940.c
5239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582650__FUN_00582650.c
5240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005833e0__FUN_005833e0.c
5241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583f50__FUN_00583f50.c
5242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005853b0__FUN_005853b0.c
5243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e50__FUN_00585e50.c
5244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005865c0__FUN_005865c0.c
5245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f20__FUN_00586f20.c
5246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587370__FUN_00587370.c
5247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587730__FUN_00587730.c
5248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587d02__FUN_00587d02.c
5249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884ed___rand.c
5250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588f66__FUN_00588f66.c
5251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589a35__FUN_00589a35.c
5252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a02c__FUN_0058a02c.c
5253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a65f__FUN_0058a65f.c
5254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac7a__FUN_0058ac7a.c
5255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b9ff__FUN_0058b9ff.c
5256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c203__FUN_0058c203.c
5257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d7f4__FUN_0058d7f4.c
5258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd89__FUN_0058dd89.c
5259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ef83__sub_58EF83.c
5260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590246__FUN_00590246.c
5261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005912bc__FUN_005912bc.c
5262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591fa1__FUN_00591fa1.c
5263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005934e1__FUN_005934e1.c
5264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594478__FUN_00594478.c
5265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595304__FUN_00595304.c
5266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595af9__FUN_00595af9.c
5267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596d81__FUN_00596d81.c
5268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597621__FUN_00597621.c
5269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598648__socket.c
5270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986ec__FUN_005986ec.c
5271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598994__FUN_00598994.c
5272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e9e__FUN_00598e9e.c
5273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005994bc__FUN_005994bc.c
5274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059980e__sub_59980E.c
5275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059994e__sub_59994E.c
5276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a2d0__FUN_0059a2d0.c
5277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a69a__FUN_0059a69a.c
5278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aab9__FUN_0059aab9.c
5279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b07a__FUN_0059b07a.c
5280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bae8__FUN_0059bae8.c
5281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c40a__Unwind_0059c40a.c
5282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c52c__Unwind_0059c52c.c
5283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c62a__Unwind_0059c62a.c
5284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6f2__Unwind_0059c6f2.c
5285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c846__Unwind_0059c846.c
5286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c956__Unwind_0059c956.c
5287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cae0__Unwind_0059cae0.c
5288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc40__Unwind_0059cc40.c
5289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd88__Unwind_0059cd88.c
5290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf03__Unwind_0059cf03.c
5291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d020__Unwind_0059d020.c
5292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d130__Unwind_0059d130.c
5293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2dc__Unwind_0059d2dc.c
5294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d484__Unwind_0059d484.c
5295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d738__FUN_0059d738.c
5296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059dba9__FUN_0059dba9.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_P.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
