# WORKER J — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker J of 20, items 2980–3310.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_J.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

2980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401c90__FUN_00401c90.c
2981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404830__FUN_00404830.c
2982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404fe0__FUN_00404fe0.c
2983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004059f0__FUN_004059f0.c
2984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004066c0__FUN_004066c0.c
2985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004078a0__FUN_004078a0.c
2986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408260__FUN_00408260.c
2987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
2988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b560__FUN_0040b560.c
2989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c720__FUN_0040c720.c
2990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d360__FUN_0040d360.c
2991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1e0__sub_40E1E0.c
2992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f0d0__FUN_0040f0d0.c
2993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b40__FUN_00410b40.c
2994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411b50__FUN_00411b50.c
2995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414200__FUN_00414200.c
2996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415520__FUN_00415520.c
2997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418970__FUN_00418970.c
2998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00419690__FUN_00419690.c
2999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b250__FUN_0041b250.c
3000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041efe0__FUN_0041efe0.c
3001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421470__FUN_00421470.c
3002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421ab0__FUN_00421ab0.c
3003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424040__FUN_00424040.c
3004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004270a0__FUN_004270a0.c
3005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042adb0__FUN_0042adb0.c
3006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bd60__FUN_0042bd60.c
3007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e1c0__FUN_0042e1c0.c
3008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430a50__FUN_00430a50.c
3009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004326d0__FUN_004326d0.c
3010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433290__FUN_00433290.c
3011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004347c0__FUN_004347c0.c
3012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004363d0__FUN_004363d0.c
3013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043b930__FUN_0043b930.c
3014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ec00__FUN_0043ec00.c
3015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443150__FUN_00443150.c
3016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447bb0__FUN_00447bb0.c
3017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448e20__FUN_00448e20.c
3018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449ed0__FUN_00449ed0.c
3019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ba40__FUN_0044ba40.c
3020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c800__FUN_0044c800.c
3021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb30__FUN_0044cb30.c
3022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cdb4__sub_44CDB4.c
3023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d040__FUN_0044d040.c
3024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3a0__FUN_0044d3a0.c
3025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d760__FUN_0044d760.c
3026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db20__FUN_0044db20.c
3027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dee0__FUN_0044dee0.c
3028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2a0__FUN_0044e2a0.c
3029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e660__FUN_0044e660.c
3030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea20__FUN_0044ea20.c
3031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f010__FUN_0044f010.c
3032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fa60__FUN_0044fa60.c
3033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00453370__FUN_00453370.c
3034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456080__FUN_00456080.c
3035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457cd0__FUN_00457cd0.c
3036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004599c0__FUN_004599c0.c
3037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b9c0__FUN_0045b9c0.c
3038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf50__FUN_0045bf50.c
3039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ca20__FUN_0045ca20.c
3040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5b0__FUN_0045e5b0.c
3041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461470__FUN_00461470.c
3042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461ff0__FUN_00461ff0.c
3043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462940__FUN_00462940.c
3044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463ca0__FUN_00463ca0.c
3045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a10__FUN_00464a10.c
3046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004652d0__FUN_004652d0.c
3047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662e0__FUN_004662e0.c
3048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004677e0__sub_4677E0.c
3049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a4e0__FUN_0046a4e0.c
3050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c710__FUN_0046c710.c
3051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046dc60__FUN_0046dc60.c
3052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f890__FUN_0046f890.c
3053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004707c0__FUN_004707c0.c
3054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471b20__FUN_00471b20.c
3055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473650__FUN_00473650.c
3056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474c80__FUN_00474c80.c
3057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004760d0__FUN_004760d0.c
3058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004773a0__FUN_004773a0.c
3059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478140__FUN_00478140.c
3060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479600__FUN_00479600.c
3061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a40__FUN_00479a40.c
3062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a290__FUN_0047a290.c
3063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b910__FUN_0047b910.c
3064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c910__FUN_0047c910.c
3065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f180__FUN_0047f180.c
3066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004856c0__FUN_004856c0.c
3067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486260__FUN_00486260.c
3068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004866ad__sub_4866AD.c
3069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487200__sub_487200.c
3070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487900__FUN_00487900.c
3071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488a30__sub_488A30.c
3072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004896c0__FUN_004896c0.c
3073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a8a0__sub_48A8A0.c
3074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048bbe0__FUN_0048bbe0.c
3075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d1a0__FUN_0048d1a0.c
3076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e070__FUN_0048e070.c
3077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea40__FUN_0048ea40.c
3078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fd60__FUN_0048fd60.c
3079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490450__sub_490450.c
3080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491350__FUN_00491350.c
3081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491d30__FUN_00491d30.c
3082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494c15__sub_494C15.c
3083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495150__FUN_00495150.c
3084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495bd0__FUN_00495bd0.c
3085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004972b0__FUN_004972b0.c
3086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497d20__FUN_00497d20.c
3087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988a0__FUN_004988a0.c
3088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499050__FUN_00499050.c
3089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499840__FUN_00499840.c
3090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499c10__FUN_00499c10.c
3091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a102__sub_49A102.c
3092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a580__FUN_0049a580.c
3093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049af30__FUN_0049af30.c
3094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b9a0__FUN_0049b9a0.c
3095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d4c0__FUN_0049d4c0.c
3096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e930__FUN_0049e930.c
3097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f790__FUN_0049f790.c
3098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0cf0__FUN_004a0cf0.c
3099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1990__sub_4A1990.c
3100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a21d0__FUN_004a21d0.c
3101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4000__FUN_004a4000.c
3102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5700__FUN_004a5700.c
3103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6db0__FUN_004a6db0.c
3104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004af3a0__FUN_004af3a0.c
3105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b16b0__FUN_004b16b0.c
3106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1d90__FUN_004b1d90.c
3107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b26d0__FUN_004b26d0.c
3108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b80__FUN_004b2b80.c
3109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3d40__FUN_004b3d40.c
3110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b46f0__FUN_004b46f0.c
3111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b54e0__FUN_004b54e0.c
3112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b69d0__FUN_004b69d0.c
3113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b85d0__FUN_004b85d0.c
3114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9880__FUN_004b9880.c
3115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9fa0__FUN_004b9fa0.c
3116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004baac0__FUN_004baac0.c
3117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb650__FUN_004bb650.c
3118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc330__FUN_004bc330.c
3119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdfe0__FUN_004bdfe0.c
3120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bfcd0__FUN_004bfcd0.c
3121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1370__FUN_004c1370.c
3122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2860__FUN_004c2860.c
3123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fe0__FUN_004c2fe0.c
3124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4cb0__FUN_004c4cb0.c
3125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6810__FUN_004c6810.c
3126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7bd0__FUN_004c7bd0.c
3127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c82f0__FUN_004c82f0.c
3128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8de0__FUN_004c8de0.c
3129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9980__sub_4C9980.c
3130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004caed0__FUN_004caed0.c
3131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cd8d0__FUN_004cd8d0.c
3132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0030__FUN_004d0030.c
3133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1a50__FUN_004d1a50.c
3134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d3740__FUN_004d3740.c
3135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5960__FUN_004d5960.c
3136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7a50__FUN_004d7a50.c
3137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ff0__FUN_004d7ff0.c
3138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9280__FUN_004d9280.c
3139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dae80__FUN_004dae80.c
3140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbac3__FUN_004dbac3.c
3141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc960__FUN_004dc960.c
3142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd3a0__FUN_004dd3a0.c
3143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df030__FUN_004df030.c
3144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e16c0__FUN_004e16c0.c
3145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2a60__FUN_004e2a60.c
3146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4790__FUN_004e4790.c
3147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8b80__FUN_004e8b80.c
3148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec050__FUN_004ec050.c
3149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef2e0__FUN_004ef2e0.c
3150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0d20__FUN_004f0d20.c
3151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1c20__FUN_004f1c20.c
3152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f69e0__FUN_004f69e0.c
3153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8330__FUN_004f8330.c
3154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d20__FUN_004f8d20.c
3155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f60__FUN_004f9f60.c
3156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc901__sub_4FC901.c
3157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff2b0__FUN_004ff2b0.c
3158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006d5__FUN_005006d5.c
3159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005026a4__FUN_005026a4.c
3160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503b94__FUN_00503b94.c
3161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005064cf__FUN_005064cf.c
3162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507bc5__FUN_00507bc5.c
3163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508f3d__FUN_00508f3d.c
3164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509e85__FUN_00509e85.c
3165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a911__FUN_0050a911.c
3166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b260__FUN_0050b260.c
3167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b7e3__FUN_0050b7e3.c
3168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2b9__FUN_0050c2b9.c
3169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cad9__sub_50CAD9.c
3170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d6ac__FUN_0050d6ac.c
3171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050decf__sub_50DECF.c
3172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e540__sub_50E540.c
3173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f86a__FUN_0050f86a.c
3174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511060__FUN_00511060.c
3175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511f23__FUN_00511f23.c
3176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005125c9__FUN_005125c9.c
3177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513cf0__FUN_00513cf0.c
3178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515917__FUN_00515917.c
3179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051623e__FUN_0051623e.c
3180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516fb0__FUN_00516fb0.c
3181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f72__FUN_00517f72.c
3182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005199d5__FUN_005199d5.c
3183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ba70__FUN_0051ba70.c
3184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c6be__FUN_0051c6be.c
3185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dc01__FUN_0051dc01.c
3186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ec00__FUN_0051ec00.c
3187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f89e__sub_51F89E.c
3188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520c0e__sub_520C0E.c
3189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522952__sub_522952.c
3190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526466__sub_526466.c
3191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052855a__FUN_0052855a.c
3192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8b0__DirectInput8Create.c
3193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e170__FUN_0052e170.c
3194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00531830__FUN_00531830.c
3195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535550__FUN_00535550.c
3196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536ff0__sub_536FF0.c
3197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539600__sub_539600.c
3198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b000__sub_53B000.c
3199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053be60__sub_53BE60.c
3200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c800__FUN_0053c800.c
3201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d3a0__FUN_0053d3a0.c
3202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540050__FUN_00540050.c
3203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541340__FUN_00541340.c
3204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541f60__FUN_00541f60.c
3205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543230__FUN_00543230.c
3206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544af0__FUN_00544af0.c
3207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545670__FUN_00545670.c
3208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546330__FUN_00546330.c
3209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005473d0__FUN_005473d0.c
3210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548aa0__FUN_00548aa0.c
3211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549470__FUN_00549470.c
3212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b2c0__FUN_0054b2c0.c
3213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bdc0__FUN_0054bdc0.c
3214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c6c0__FUN_0054c6c0.c
3215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ead0__FUN_0054ead0.c
3216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc40__FUN_0054fc40.c
3217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005504d0__FUN_005504d0.c
3218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551480__FUN_00551480.c
3219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552760__FUN_00552760.c
3220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553980__FUN_00553980.c
3221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005546a0__FUN_005546a0.c
3222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556440__FUN_00556440.c
3223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556930__FUN_00556930.c
3224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557630__FUN_00557630.c
3225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005593d0__FUN_005593d0.c
3226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bc00__FUN_0055bc00.c
3227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c650__FUN_0055c650.c
3228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2f0__FUN_0055d2f0.c
3229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ef88__FUN_0055ef88.c
3230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560c10__FUN_00560c10.c
3231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561b2a__sub_561B2A.c
3232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005628f0__FUN_005628f0.c
3233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563dc0__FUN_00563dc0.c
3234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564580__FUN_00564580.c
3235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564960__FUN_00564960.c
3236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ca0__FUN_00565ca0.c
3237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668f0__FUN_005668f0.c
3238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005670d0__FUN_005670d0.c
3239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a30__FUN_00567a30.c
3240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568560__FUN_00568560.c
3241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005692a0__FUN_005692a0.c
3242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056b5d0__FUN_0056b5d0.c
3243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d430__FUN_0056d430.c
3244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00575bbd__FUN_00575bbd.c
3245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a260__FUN_0057a260.c
3246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a800__FUN_0057a800.c
3247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aa50__FUN_0057aa50.c
3248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b100__sub_57B100.c
3249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b910__FUN_0057b910.c
3250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057d8d0__FUN_0057d8d0.c
3251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057edd0__FUN_0057edd0.c
3252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581750__FUN_00581750.c
3253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005822b0__FUN_005822b0.c
3254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583150__sub_583150.c
3255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005837f0__FUN_005837f0.c
3256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585040__FUN_00585040.c
3257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585cd0__FUN_00585cd0.c
3258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005862c0__FUN_005862c0.c
3259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d70__FUN_00586d70.c
3260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587210__FUN_00587210.c
3261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587690__FUN_00587690.c
3262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587b97__FUN_00587b97.c
3263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005881c0__FUN_005881c0.c
3264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588931____NLG_Notify1.c
3265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005896ee__FUN_005896ee.c
3266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d74__FUN_00589d74.c
3267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a40a__FUN_0058a40a.c
3268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aa39__FUN_0058aa39.c
3269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b59f__FUN_0058b59f.c
3270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bf45__FUN_0058bf45.c
3271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c9b4__FUN_0058c9b4.c
3272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dccc__FUN_0058dccc.c
3273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e4a8__FUN_0058e4a8.c
3274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fcb0__FUN_0058fcb0.c
3275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059070a__FUN_0059070a.c
3276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591d88__FUN_00591d88.c
3277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592dfa__FUN_00592dfa.c
3278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593d53__FUN_00593d53.c
3279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005950a3__FUN_005950a3.c
3280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595924__FUN_00595924.c
3281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596888__FUN_00596888.c
3282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597388__FUN_00597388.c
3283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598569__FUN_00598569.c
3284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059869c__WSAStartup.c
3285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987d0__FUN_005987d0.c
3286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cf9__FUN_00598cf9.c
3287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005993eb__FUN_005993eb.c
3288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997b7__sub_5997B7.c
3289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998e5__FUN_005998e5.c
3290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599e71__FUN_00599e71.c
3291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a473__FUN_0059a473.c
3292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a980__FUN_0059a980.c
3293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aeda__FUN_0059aeda.c
3294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b758__FUN_0059b758.c
3295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c0ac__FUN_0059c0ac.c
3296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4d2__Unwind_0059c4d2.c
3297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5ee__Unwind_0059c5ee.c
3298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6b6__Unwind_0059c6b6.c
3299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c804__Unwind_0059c804.c
3300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c902__Unwind_0059c902.c
3301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca69__sub_59CA69.c
3302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cbe0__Unwind_0059cbe0.c
3303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd1e__Unwind_0059cd1e.c
3304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cebb__Unwind_0059cebb.c
3305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfcc__Unwind_0059cfcc.c
3306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0c8__Unwind_0059d0c8.c
3307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d248__Unwind_0059d248.c
3308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d41f__Unwind_0059d41f.c
3309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d580__Unwind_0059d580.c
3310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059dab7__FUN_0059dab7.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_J.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
