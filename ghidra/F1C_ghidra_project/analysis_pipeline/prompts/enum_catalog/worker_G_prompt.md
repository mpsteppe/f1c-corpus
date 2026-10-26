# WORKER G — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker G of 20, items 1987–2317.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_G.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

1987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401180__FUN_00401180.c
1988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404790__FUN_00404790.c
1989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f00__FUN_00404f00.c
1990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004058a0__FUN_004058a0.c
1991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004064c0__FUN_004064c0.c
1992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407450__FUN_00407450.c
1993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408210__FUN_00408210.c
1994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408de0__FUN_00408de0.c
1995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b360__FUN_0040b360.c
1996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c5b0__FUN_0040c5b0.c
1997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d2ca__sub_40D2CA.c
1998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e170__FUN_0040e170.c
1999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ed10__FUN_0040ed10.c
2000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410ad0__FUN_00410ad0.c
2001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411a00__FUN_00411a00.c
2002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414180__FUN_00414180.c
2003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415090__FUN_00415090.c
2004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004186f0__FUN_004186f0.c
2005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00419120__FUN_00419120.c
2006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041afd0__FUN_0041afd0.c
2007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041eda0__FUN_0041eda0.c
2008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00420490__FUN_00420490.c
2009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a50__FUN_00421a50.c
2010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423db0__FUN_00423db0.c
2011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c
2012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ad00__FUN_0042ad00.c
2013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bc10__FUN_0042bc10.c
2014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dd72__sub_42DD72.c
2015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042f140__FUN_0042f140.c
2016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431db0__FUN_00431db0.c
2017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433090__FUN_00433090.c
2018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434420__FUN_00434420.c
2019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435e60__FUN_00435e60.c
2020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438f00__FUN_00438f00.c
2021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ea70__FUN_0043ea70.c
2022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00442060__FUN_00442060.c
2023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447780__FUN_00447780.c
2024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448730__FUN_00448730.c
2025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449a00__FUN_00449a00.c
2026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b110__FUN_0044b110.c
2027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c770__FUN_0044c770.c
2028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cad0__FUN_0044cad0.c
2029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd54__sub_44CD54.c
2030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cfe0__FUN_0044cfe0.c
2031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d310__FUN_0044d310.c
2032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d6d0__FUN_0044d6d0.c
2033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da90__FUN_0044da90.c
2034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de50__FUN_0044de50.c
2035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e210__FUN_0044e210.c
2036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e5d0__FUN_0044e5d0.c
2037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e990__FUN_0044e990.c
2038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ee10__FUN_0044ee10.c
2039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f7d0__FUN_0044f7d0.c
2040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00453100__FUN_00453100.c
2041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456010__FUN_00456010.c
2042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457a00__FUN_00457a00.c
2043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459830__FUN_00459830.c
2044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b660__FUN_0045b660.c
2045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bea0__FUN_0045bea0.c
2046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c850__FUN_0045c850.c
2047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d730__FUN_0045d730.c
2048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460dd0__FUN_00460dd0.c
2049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461f70__FUN_00461f70.c
2050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462848__sub_462848.c
2051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463c40__FUN_00463c40.c
2052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464940__FUN_00464940.c
2053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465150__FUN_00465150.c
2054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466270__FUN_00466270.c
2055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467430__FUN_00467430.c
2056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a220__FUN_0046a220.c
2057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046bf10__FUN_0046bf10.c
2058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d6c0__FUN_0046d6c0.c
2059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f490__FUN_0046f490.c
2060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470490__sub_470490.c
2061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004718e0__FUN_004718e0.c
2062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473430__FUN_00473430.c
2063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474ba0__FUN_00474ba0.c
2064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476050__sub_476050.c
2065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477080__FUN_00477080.c
2066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004780b0__FUN_004780b0.c
2067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479320__FUN_00479320.c
2068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799a0__FUN_004799a0.c
2069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a210__FUN_0047a210.c
2070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b1e0__FUN_0047b1e0.c
2071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c7c0__FUN_0047c7c0.c
2072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f010__FUN_0047f010.c
2073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485630__FUN_00485630.c
2074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486080__FUN_00486080.c
2075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486600__FUN_00486600.c
2076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487160__FUN_00487160.c
2077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487740__FUN_00487740.c
2078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488900__FUN_00488900.c
2079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489560__FUN_00489560.c
2080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a3b0__FUN_0048a3b0.c
2081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b91a__sub_48B91A.c
2082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ccb0__FUN_0048ccb0.c
2083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d9d0__sub_48D9D0.c
2084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e890__FUN_0048e890.c
2085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc50__FUN_0048fc50.c
2086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490330__FUN_00490330.c
2087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004912f0__FUN_004912f0.c
2088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491cb0__FUN_00491cb0.c
2089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494a30__FUN_00494a30.c
2090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495110__FUN_00495110.c
2091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495ae0__FUN_00495ae0.c
2092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497250__FUN_00497250.c
2093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979f0__FUN_004979f0.c
2094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498740__FUN_00498740.c
2095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f80__FUN_00498f80.c
2096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499670__FUN_00499670.c
2097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b80__FUN_00499b80.c
2098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499eb0__FUN_00499eb0.c
2099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a460__FUN_0049a460.c
2100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adc0__FUN_0049adc0.c
2101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b8f0__FUN_0049b8f0.c
2102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d3f0__FUN_0049d3f0.c
2103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e7b0__FUN_0049e7b0.c
2104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f6a0__FUN_0049f6a0.c
2105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ba0__FUN_004a0ba0.c
2106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11f0__sub_4A11F0.c
2107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f80__FUN_004a1f80.c
2108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3b30__FUN_004a3b30.c
2109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5600__FUN_004a5600.c
2110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a68b0__FUN_004a68b0.c
2111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ae750__FUN_004ae750.c
2112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1410__FUN_004b1410.c
2113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1bb0__sub_4B1BB0.c
2114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2480__FUN_004b2480.c
2115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b10__FUN_004b2b10.c
2116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3bd0__FUN_004b3bd0.c
2117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b44e0__FUN_004b44e0.c
2118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5380__FUN_004b5380.c
2119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6920__FUN_004b6920.c
2120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8360__FUN_004b8360.c
2121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9820__FUN_004b9820.c
2122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9e30__FUN_004b9e30.c
2123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba980__FUN_004ba980.c
2124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb490__FUN_004bb490.c
2125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2e8__sub_4BC2E8.c
2126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdde0__FUN_004bdde0.c
2127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf640__FUN_004bf640.c
2128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1050__FUN_004c1050.c
2129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2810__FUN_004c2810.c
2130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2f20__FUN_004c2f20.c
2131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4aa0__FUN_004c4aa0.c
2132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c62c0__FUN_004c62c0.c
2133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7aa0__FUN_004c7aa0.c
2134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c81f0__FUN_004c81f0.c
2135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d80__FUN_004c8d80.c
2136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9820__FUN_004c9820.c
2137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca410__FUN_004ca410.c
2138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cce90__FUN_004cce90.c
2139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cf010__FUN_004cf010.c
2140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1410__FUN_004d1410.c
2141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d24a0__FUN_004d24a0.c
2142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5840__FUN_004d5840.c
2143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7920__FUN_004d7920.c
2144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7f60__FUN_004d7f60.c
2145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9030__FUN_004d9030.c
2146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dad50__FUN_004dad50.c
2147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db9a0__FUN_004db9a0.c
2148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc450__FUN_004dc450.c
2149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd000__FUN_004dd000.c
2150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ded20__FUN_004ded20.c
2151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0e20__FUN_004e0e20.c
2152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2610__FUN_004e2610.c
2153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4570__FUN_004e4570.c
2154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8780__FUN_004e8780.c
2155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004eb430__FUN_004eb430.c
2156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee230__FUN_004ee230.c
2157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f01b0__FUN_004f01b0.c
2158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1b50__FUN_004f1b50.c
2159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6880__FUN_004f6880.c
2160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f81d0__FUN_004f81d0.c
2161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ce0__FUN_004f8ce0.c
2162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9d60__FUN_004f9d60.c
2163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc700__FUN_004fc700.c
2164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff127__sub_4FF127.c
2165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500560__FUN_00500560.c
2166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005020bf__sub_5020BF.c
2167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005038ef__FUN_005038ef.c
2168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506003__FUN_00506003.c
2169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005078b5__FUN_005078b5.c
2170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508c22__FUN_00508c22.c
2171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509cc2__FUN_00509cc2.c
2172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a7e1__FUN_0050a7e1.c
2173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b20c__FUN_0050b20c.c
2174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b797__FUN_0050b797.c
2175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c27f__sub_50C27F.c
2176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c97a__FUN_0050c97a.c
2177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d5f9__FUN_0050d5f9.c
2178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050de19__FUN_0050de19.c
2179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3da__thunk_FUN_0050e3cd.c
2180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f632__FUN_0050f632.c
2181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510acc__FUN_00510acc.c
2182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051189c__FUN_0051189c.c
2183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051249f__FUN_0051249f.c
2184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513c80__FUN_00513c80.c
2185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515869__sub_515869.c
2186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005160ad__FUN_005160ad.c
2187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516e28__sub_516E28.c
2188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f04__FUN_00517f04.c
2189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005198b3__FUN_005198b3.c
2190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051b37d__FUN_0051b37d.c
2191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c3e2__FUN_0051c3e2.c
2192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d897__FUN_0051d897.c
2193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ea90__FUN_0051ea90.c
2194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f6a0__sub_51F6A0.c
2195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005208fe__sub_5208FE.c
2196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052273b__sub_52273B.c
2197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005262c2__FUN_005262c2.c
2198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052804a__FUN_0052804a.c
2199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052ab4e__FUN_0052ab4e.c
2200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df90__FUN_0052df90.c
2201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00530840__FUN_00530840.c
2202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005352d0__FUN_005352d0.c
2203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536a70__sub_536A70.c
2204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00538a90__FUN_00538a90.c
2205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ad80__sub_53AD80.c
2206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bb30__FUN_0053bb30.c
2207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6a0__FUN_0053c6a0.c
2208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d2e0__FUN_0053d2e0.c
2209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fc30__FUN_0053fc30.c
2210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541090__FUN_00541090.c
2211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541cd0__FUN_00541cd0.c
2212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005426a0__FUN_005426a0.c
2213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a80__FUN_00543a80.c
2214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005454a0__FUN_005454a0.c
2215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546200__FUN_00546200.c
2216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547370__FUN_00547370.c
2217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005489a0__FUN_005489a0.c
2218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549380__FUN_00549380.c
2219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a770__FUN_0054a770.c
2220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bcd0__FUN_0054bcd0.c
2221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c2f0__FUN_0054c2f0.c
2222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e270__FUN_0054e270.c
2223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fb70__FUN_0054fb70.c
2224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550300__FUN_00550300.c
2225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551210__FUN_00551210.c
2226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551f80__FUN_00551f80.c
2227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553620__FUN_00553620.c
2228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005545e0__FUN_005545e0.c
2229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556260__FUN_00556260.c
2230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005568d0__FUN_005568d0.c
2231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557480__FUN_00557480.c
2232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559390__FUN_00559390.c
2233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb70__FUN_0055bb70.c
2234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c3c0__FUN_0055c3c0.c
2235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d230__FUN_0055d230.c
2236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ee20__FUN_0055ee20.c
2237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560b90__FUN_00560b90.c
2238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561a86__FUN_00561a86.c
2239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562710__FUN_00562710.c
2240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563870__FUN_00563870.c
2241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005644a0__FUN_005644a0.c
2242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005648c0__FUN_005648c0.c
2243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005654a0__FUN_005654a0.c
2244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566810__FUN_00566810.c
2245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566f40__FUN_00566f40.c
2246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679a5__FUN_005679a5.c
2247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568320__FUN_00568320.c
2248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568fb0__FUN_00568fb0.c
2249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a5d0__FUN_0056a5d0.c
2250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d2d0__FUN_0056d2d0.c
2251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056fa96__FUN_0056fa96.c
2252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a1e0__FUN_0057a1e0.c
2253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a730__FUN_0057a730.c
2254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a9b0__sub_57A9B0.c
2255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057afa0__FUN_0057afa0.c
2256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b820__FUN_0057b820.c
2257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057d5d0__FUN_0057d5d0.c
2258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ea30__sub_57EA30.c
2259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005813e0__FUN_005813e0.c
2260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582110__FUN_00582110.c
2261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582fd0__FUN_00582fd0.c
2262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005836e0__FUN_005836e0.c
2263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584ff0__FUN_00584ff0.c
2264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585870__FUN_00585870.c
2265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005861e0__FUN_005861e0.c
2266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586c90__FUN_00586c90.c
2267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005871c0__FUN_005871c0.c
2268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005875c0__FUN_005875c0.c
2269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587b3e__FUN_00587b3e.c
2270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058806e__FUN_0058806e.c
2271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588884__sub_588884.c
2272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005895a2__FUN_005895a2.c
2273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589cc6__FUN_00589cc6.c
2274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a331__FUN_0058a331.c
2275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a947____nh_malloc.c
2276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b130__FUN_0058b130.c
2277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bd8f____fassign.c
2278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c789__FUN_0058c789.c
2279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dc57____startOneArgErrorHandling.c
2280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e22b__FUN_0058e22b.c
2281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fc20__FUN_0058fc20.c
2282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059067e____cintrindisp1.c
2283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591cf3____frnd.c
2284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592af4__FUN_00592af4.c
2285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c50____CallSettingFrame_12.c
2286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594ff0____aulldiv.c
2287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595733__FUN_00595733.c
2288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596773__FUN_00596773.c
2289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059733d__FUN_0059733d.c
2290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598323__FUN_00598323.c
2291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059868a__setsockopt.c
2292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987a1__FUN_005987a1.c
2293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c88__FUN_00598c88.c
2294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992ef__FUN_005992ef.c
2295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599796__FUN_00599796.c
2296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998c0__FUN_005998c0.c
2297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d52__FUN_00599d52.c
2298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a428__FUN_0059a428.c
2299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a8d8__FUN_0059a8d8.c
2300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae24__FUN_0059ae24.c
2301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b530__FUN_0059b530.c
2302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfa0___exception.c
2303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4aa__Unwind_0059c4aa.c
2304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5d0__Unwind_0059c5d0.c
2305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c698__Unwind_0059c698.c
2306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7e0__Unwind_0059c7e0.c
2307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d8__Unwind_0059c8d8.c
2308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca3b__sub_59CA3B.c
2309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb93__Unwind_0059cb93.c
2310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd00__Unwind_0059cd00.c
2311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce9a__Unwind_0059ce9a.c
2312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfa2__Unwind_0059cfa2.c
2313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0a7__Unwind_0059d0a7.c
2314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1f8__Unwind_0059d1f8.c
2315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3cc__Unwind_0059d3cc.c
2316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d544__Unwind_0059d544.c
2317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d9d7__FUN_0059d9d7.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_G.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
