# WORKER M — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker M of 20, items 3973–4303.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_M.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

3973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004034d0__FUN_004034d0.c
3974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404970__FUN_00404970.c
3975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405030__sub_405030.c
3976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b50__FUN_00405b50.c
3977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406a70__FUN_00406a70.c
3978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407c90__FUN_00407c90.c
3979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004082b0__FUN_004082b0.c
3980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a610__FUN_0040a610.c
3981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b630__FUN_0040b630.c
3982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c870__FUN_0040c870.c
3983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d450__FUN_0040d450.c
3984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e480__FUN_0040e480.c
3985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f1c0__FUN_0040f1c0.c
3986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410bc0__FUN_00410bc0.c
3987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411e90__FUN_00411e90.c
3988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414380__FUN_00414380.c
3989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415650__FUN_00415650.c
3990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418a20__FUN_00418a20.c
3991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a0c0__FUN_0041a0c0.c
3992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b970__FUN_0041b970.c
3993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f100__FUN_0041f100.c
3994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421570__FUN_00421570.c
3995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421b10__FUN_00421b10.c
3996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424790__FUN_00424790.c
3997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429ee0__FUN_00429ee0.c
3998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ae20__FUN_0042ae20.c
3999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042caa0__FUN_0042caa0.c
4000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e320__FUN_0042e320.c
4001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004317f0__FUN_004317f0.c
4002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432820__FUN_00432820.c
4003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004336f0__FUN_004336f0.c
4004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004349a0__FUN_004349a0.c
4005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004364a0__FUN_004364a0.c
4006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bb30__FUN_0043bb30.c
4007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ef20__FUN_0043ef20.c
4008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443b70__FUN_00443b70.c
4009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447f30__FUN_00447f30.c
4010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448ec0__FUN_00448ec0.c
4011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a170__FUN_0044a170.c
4012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c0e0__FUN_0044c0e0.c
4013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c890__FUN_0044c890.c
4014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb90__FUN_0044cb90.c
4015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce14__sub_44CE14.c
4016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d0a0__FUN_0044d0a0.c
4017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d430__FUN_0044d430.c
4018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d7f0__FUN_0044d7f0.c
4019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbb0__FUN_0044dbb0.c
4020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df70__FUN_0044df70.c
4021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e330__FUN_0044e330.c
4022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e6f0__FUN_0044e6f0.c
4023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eab0__FUN_0044eab0.c
4024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f070__FUN_0044f070.c
4025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fc20__FUN_0044fc20.c
4026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004537b0__FUN_004537b0.c
4027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560e0__FUN_004560e0.c
4028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457ee0__FUN_00457ee0.c
4029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045a8e0__FUN_0045a8e0.c
4030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb40__FUN_0045bb40.c
4031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bff0__FUN_0045bff0.c
4032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cde0__FUN_0045cde0.c
4033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e620__FUN_0045e620.c
4034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004614f0__FUN_004614f0.c
4035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462300__FUN_00462300.c
4036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462ce0__FUN_00462ce0.c
4037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463d50__FUN_00463d50.c
4038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ad0__FUN_00464ad0.c
4039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465460__FUN_00465460.c
4040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466650__FUN_00466650.c
4041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004681b0__sub_4681B0.c
4042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a900__FUN_0046a900.c
4043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c7b0__FUN_0046c7b0.c
4044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046de10__sub_46DE10.c
4045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fd30__FUN_0046fd30.c
4046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470cc0__FUN_00470cc0.c
4047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472340__FUN_00472340.c
4048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473bd0__FUN_00473bd0.c
4049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475020__FUN_00475020.c
4050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004761c0__FUN_004761c0.c
4051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004775f0__FUN_004775f0.c
4052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004781e0__FUN_004781e0.c
4053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479700__FUN_00479700.c
4054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c30__FUN_00479c30.c
4055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a580__FUN_0047a580.c
4056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bb40__FUN_0047bb40.c
4057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c9d0__FUN_0047c9d0.c
4058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f230__FUN_0047f230.c
4059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004857e0__sub_4857E0.c
4060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004862c0__FUN_004862c0.c
4061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486730__FUN_00486730.c
4062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487250__FUN_00487250.c
4063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487d50__FUN_00487d50.c
4064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488b40__FUN_00488b40.c
4065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489950__FUN_00489950.c
4066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048aa40__FUN_0048aa40.c
4067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c0d0__FUN_0048c0d0.c
4068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d360__FUN_0048d360.c
4069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e110__FUN_0048e110.c
4070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ebd0__FUN_0048ebd0.c
4071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fdf0__FUN_0048fdf0.c
4072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490660__FUN_00490660.c
4073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491680__FUN_00491680.c
4074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e40__FUN_00491e40.c
4075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494de0__FUN_00494de0.c
4076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495300__FUN_00495300.c
4077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496280__FUN_00496280.c
4078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497590__FUN_00497590.c
4079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497f90__FUN_00497f90.c
4080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498940__FUN_00498940.c
4081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499180__FUN_00499180.c
4082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004998c0__FUN_004998c0.c
4083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ce0__FUN_00499ce0.c
4084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a180__FUN_0049a180.c
4085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a990__FUN_0049a990.c
4086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afc0__sub_49AFC0.c
4087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ba90__FUN_0049ba90.c
4088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d8b0__FUN_0049d8b0.c
4089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049eb40__FUN_0049eb40.c
4090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffc0__FUN_0049ffc0.c
4091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0d90__FUN_004a0d90.c
4092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1a60__FUN_004a1a60.c
4093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a27d0__FUN_004a27d0.c
4094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40b0__FUN_004a40b0.c
4095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a57f0__FUN_004a57f0.c
4096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6ff0__FUN_004a6ff0.c
4097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0220__FUN_004b0220.c
4098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1950__FUN_004b1950.c
4099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1f50__FUN_004b1f50.c
4100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2840__FUN_004b2840.c
4101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c20__FUN_004b2c20.c
4102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3d70__sub_4B3D70.c
4103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4800__FUN_004b4800.c
4104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b57f0__FUN_004b57f0.c
4105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6c90__FUN_004b6c90.c
4106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b87a0__FUN_004b87a0.c
4107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9a10__FUN_004b9a10.c
4108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba150__FUN_004ba150.c
4109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bac40__FUN_004bac40.c
4110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb800__FUN_004bb800.c
4111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd760__FUN_004bd760.c
4112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be1d0__FUN_004be1d0.c
4113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bff70__FUN_004bff70.c
4114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c13c0__FUN_004c13c0.c
4115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c29b0__FUN_004c29b0.c
4116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3030__FUN_004c3030.c
4117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4ff0__FUN_004c4ff0.c
4118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6960__FUN_004c6960.c
4119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c10__FUN_004c7c10.c
4120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8560__FUN_004c8560.c
4121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8f80__FUN_004c8f80.c
4122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9b70__FUN_004c9b70.c
4123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb5a0__FUN_004cb5a0.c
4124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cdb20__FUN_004cdb20.c
4125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0080__FUN_004d0080.c
4126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1bc0__FUN_004d1bc0.c
4127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4780__FUN_004d4780.c
4128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5af0__FUN_004d5af0.c
4129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7b00__FUN_004d7b00.c
4130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d82a0__FUN_004d82a0.c
4131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9420__sub_4D9420.c
4132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db090__sub_4DB090.c
4133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbde0__FUN_004dbde0.c
4134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcba0__FUN_004dcba0.c
4135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd467__sub_4DD467.c
4136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfa50__FUN_004dfa50.c
4137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e18c0__FUN_004e18c0.c
4138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2ca0__FUN_004e2ca0.c
4139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e49b0__FUN_004e49b0.c
4140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9300__FUN_004e9300.c
4141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed030__FUN_004ed030.c
4142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef5a0__FUN_004ef5a0.c
4143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1120__FUN_004f1120.c
4144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f2320__FUN_004f2320.c
4145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6af0__FUN_004f6af0.c
4146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8440__FUN_004f8440.c
4147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8f10__FUN_004f8f10.c
4148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fad80__FUN_004fad80.c
4149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9c0__FUN_004fc9c0.c
4150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff680__FUN_004ff680.c
4151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005008c2___vector_constructor_iterator_.c
4152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bea__FUN_00502bea.c
4153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503f75__FUN_00503f75.c
4154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506554__thunk_FUN_005064cf.c
4155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507ee4__FUN_00507ee4.c
4156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509244__FUN_00509244.c
4157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509fde__FUN_00509fde.c
4158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab35__FUN_0050ab35.c
4159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b399__FUN_0050b399.c
4160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b82b__thunk_FUN_00506fd9.c
4161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c3bb__FUN_0050c3bb.c
4162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cbb6__FUN_0050cbb6.c
4163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d84a__FUN_0050d84a.c
4164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df9b__FUN_0050df9b.c
4165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e6d3__FUN_0050e6d3.c
4166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fa0e__FUN_0050fa0e.c
4167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051126a__sub_51126A.c
4168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512114__FUN_00512114.c
4169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512894__FUN_00512894.c
4170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513d63__FUN_00513d63.c
4171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515986__FUN_00515986.c
4172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005164a6__FUN_005164a6.c
4173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005174cb__sub_5174CB.c
4174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051868c__FUN_0051868c.c
4175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519eb7__FUN_00519eb7.c
4176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bcfc__FUN_0051bcfc.c
4177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c94f__FUN_0051c94f.c
4178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dfa8__FUN_0051dfa8.c
4179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ecee__sub_51ECEE.c
4180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051fbf0__sub_51FBF0.c
4181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520fc6__FUN_00520fc6.c
4182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522a6c__sub_522A6C.c
4183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005267a7__FUN_005267a7.c
4184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
4185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d970__FUN_0052d970.c
4186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e320__FUN_0052e320.c
4187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534120__FUN_00534120.c
4188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005355f0__FUN_005355f0.c
4189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537ce0__FUN_00537ce0.c
4190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539720__FUN_00539720.c
4191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b130__FUN_0053b130.c
4192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c150__FUN_0053c150.c
4193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ca00__FUN_0053ca00.c
4194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d430__FUN_0053d430.c
4195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005401a0__FUN_005401a0.c
4196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005414a0__FUN_005414a0.c
4197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005423c0__FUN_005423c0.c
4198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543440__FUN_00543440.c
4199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544db0__FUN_00544db0.c
4200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005457f0__FUN_005457f0.c
4201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005469c0__FUN_005469c0.c
4202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005474d0__FUN_005474d0.c
4203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548dd0__FUN_00548dd0.c
4204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a160__FUN_0054a160.c
4205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b3f0__FUN_0054b3f0.c
4206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c030__FUN_0054c030.c
4207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d080__FUN_0054d080.c
4208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eb40__FUN_0054eb40.c
4209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc80__FUN_0054fc80.c
4210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005506a0__FUN_005506a0.c
4211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551560__FUN_00551560.c
4212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005528f0__FUN_005528f0.c
4213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553aa0__FUN_00553aa0.c
4214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554b20__FUN_00554b20.c
4215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005565b0__FUN_005565b0.c
4216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556b10__FUN_00556b10.c
4217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558a30__FUN_00558a30.c
4218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559760__FUN_00559760.c
4219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bdd0__FUN_0055bdd0.c
4220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7f0__FUN_0055c7f0.c
4221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d410__FUN_0055d410.c
4222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055fbc0__FUN_0055fbc0.c
4223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560f10__FUN_00560f10.c
4224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561e20__FUN_00561e20.c
4225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562c80__FUN_00562c80.c
4226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563e70__FUN_00563e70.c
4227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564620__sub_564620.c
4228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564a00__FUN_00564a00.c
4229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565e20__FUN_00565e20.c
4230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566b20__FUN_00566b20.c
4231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567400__FUN_00567400.c
4232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567b00__thunk_FUN_00567b10.c
4233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568910__FUN_00568910.c
4234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569670__FUN_00569670.c
4235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056bde0__FUN_0056bde0.c
4236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056e970__FUN_0056e970.c
4237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579f89__FUN_00579f89.c
4238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a3f0__FUN_0057a3f0.c
4239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a830__FUN_0057a830.c
4240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ab20__FUN_0057ab20.c
4241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b330__FUN_0057b330.c
4242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b9f0__FUN_0057b9f0.c
4243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dd40__FUN_0057dd40.c
4244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ef80__sub_57EF80.c
4245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581820__FUN_00581820.c
4246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582360__FUN_00582360.c
4247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583270__FUN_00583270.c
4248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583ae0__FUN_00583ae0.c
4249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585270__FUN_00585270.c
4250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585de0__FUN_00585de0.c
4251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005864e0__FUN_005864e0.c
4252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586ed0__FUN_00586ed0.c
4253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587250__FUN_00587250.c
4254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876f0__FUN_005876f0.c
4255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587c03__operator_new.c
4256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005883e5__FUN_005883e5.c
4257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588a19__FUN_00588a19.c
4258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589898__FUN_00589898.c
4259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589e6c__FUN_00589e6c.c
4260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a55a__FUN_0058a55a.c
4261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ab31__FUN_0058ab31.c
4262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b8ad__FUN_0058b8ad.c
4263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c0d0__FUN_0058c0d0.c
4264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058cf35__FUN_0058cf35.c
4265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd3e__FUN_0058dd3e.c
4266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ef2e__FUN_0058ef2e.c
4267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ff65__FUN_0058ff65.c
4268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005908b0__sub_5908B0.c
4269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e66__FUN_00591e66.c
4270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059325d__FUN_0059325d.c
4271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593e1b__FUN_00593e1b.c
4272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595207__FUN_00595207.c
4273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595a61__FUN_00595a61.c
4274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596bf3__FUN_00596bf3.c
4275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597568_____add_12.c
4276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598636__getsockname.c
4277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986bf__FUN_005986bf.c
4278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987ff__FUN_005987ff.c
4279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e07__FUN_00598e07.c
4280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599475___Gninc.c
4281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997e1__sub_5997E1.c
4282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059991f__sub_59991F.c
4283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a0d5__FUN_0059a0d5.c
4284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a541__FUN_0059a541.c
4285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aaa2__FUN_0059aaa2.c
4286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059afc2__FUN_0059afc2.c
4287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ba1d__FUN_0059ba1d.c
4288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c1e7__FUN_0059c1e7.c
4289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c504__Unwind_0059c504.c
4290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c60c__Unwind_0059c60c.c
4291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6d4__Unwind_0059c6d4.c
4292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c828__Unwind_0059c828.c
4293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c92c__Unwind_0059c92c.c
4294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059caa0__Unwind_0059caa0.c
4295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc08__Unwind_0059cc08.c
4296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd60__Unwind_0059cd60.c
4297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cedf__Unwind_0059cedf.c
4298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cff6__Unwind_0059cff6.c
4299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0f6__Unwind_0059d0f6.c
4300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2b4__Unwind_0059d2b4.c
4301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d444__Unwind_0059d444.c
4302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5bc__Unwind_0059d5bc.c
4303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db09__FUN_0059db09.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_M.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
