int __thiscall sub_470210(char *this, double a2, char a3)
{
  double *v4; // esi
  double v5; // st7
  long double v6; // st7
  long double v7; // st6
  long double v8; // st6
  double v10; // st6
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  double v14; // st7
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c3
  double v18; // st7
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c3
  long double v21; // st7
  long double v22; // st6
  long double v23; // st6
  double v25; // st6
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c3
  double v29; // st7
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c3
  double v33; // st7
  unsigned __int8 v34; // c0
  unsigned __int8 v35; // c3
  double v36; // st7
  double v37; // st6
  double v38; // st7
  double v39; // st6
  double v40; // st7
  double v41; // st6
  double v42; // st5
  long double v43; // st7
  float v44; // ecx
  long double v45; // st7
  long double v46; // st6
  long double v47; // st5
  float *v48; // ebx
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double *v52; // ecx
  double v53; // st7
  double v54; // st6
  double v55; // st7
  double v56; // st7
  double v57; // st7
  double v58; // st7
  double v59; // st7
  double v60; // st6
  double v61; // st5
  double v62; // st4
  double v63; // st5
  double v64; // st4
  double v65; // st3
  double v66; // st2
  unsigned __int8 v68; // c0
  unsigned __int8 v69; // c2
  double v70; // st2
  long double v71; // st5
  long double v72; // st5
  double v73; // st5
  long double v74; // st5
  double v75; // st7
  unsigned __int8 v77; // c0
  unsigned __int8 v78; // c3
  double v79; // st7
  double *v80; // ecx
  bool v81; // cc
  double v82; // st7
  int v83; // eax
  unsigned int v84; // ecx
  double *v85; // edx
  double *v86; // edx
  int v87; // ecx
  double v88; // st7
  int v89; // edx
  unsigned int v90; // ecx
  double *v91; // eax
  double *v92; // eax
  int v93; // ecx
  double *v94; // ebx
  double v95; // st7
  double v96; // st7
  int v97; // ebx
  double v98; // st7
  double *v99; // ecx
  int v100; // ebx
  float *v101; // edx
  double v102; // st7
  double v103; // st6
  double v104; // st5
  double v105; // st7
  double v106; // st6
  double v107; // st7
  int result; // eax
  double v109; // st7
  double v110; // st6
  double v111; // st5
  double v112; // st7
  double v113; // st7
  float *v114; // [esp+18h] [ebp-5E8h]
  double v115; // [esp+18h] [ebp-5E8h]
  double v116; // [esp+18h] [ebp-5E8h]
  double v117; // [esp+18h] [ebp-5E8h]
  double v118; // [esp+18h] [ebp-5E8h]
  double v119; // [esp+18h] [ebp-5E8h]
  int v120; // [esp+18h] [ebp-5E8h]
  double *v121; // [esp+20h] [ebp-5E0h]
  double v122; // [esp+20h] [ebp-5E0h]
  double v123; // [esp+20h] [ebp-5E0h]
  double v124; // [esp+20h] [ebp-5E0h]
  double v125; // [esp+20h] [ebp-5E0h]
  double v126; // [esp+28h] [ebp-5D8h]
  double v127; // [esp+28h] [ebp-5D8h]
  double v128; // [esp+30h] [ebp-5D0h]
  double v129; // [esp+30h] [ebp-5D0h]
  double v130; // [esp+30h] [ebp-5D0h]
  double v131; // [esp+30h] [ebp-5D0h]
  double v132; // [esp+38h] [ebp-5C8h]
  double v133; // [esp+38h] [ebp-5C8h]
  int v134; // [esp+44h] [ebp-5BCh]
  int v135; // [esp+44h] [ebp-5BCh]
  double v136; // [esp+48h] [ebp-5B8h]
  double v137; // [esp+50h] [ebp-5B0h]
  double v138; // [esp+50h] [ebp-5B0h]
  int v139; // [esp+64h] [ebp-59Ch]
  double v140; // [esp+78h] [ebp-588h]
  double v141; // [esp+80h] [ebp-580h]
  double v142; // [esp+80h] [ebp-580h]
  double v143; // [esp+88h] [ebp-578h]
  double v144; // [esp+88h] [ebp-578h]
  double v145; // [esp+90h] [ebp-570h]
  double v146; // [esp+90h] [ebp-570h]
  int v147; // [esp+98h] [ebp-568h]
  float v148; // [esp+9Ch] [ebp-564h]
  double v149; // [esp+A0h] [ebp-560h]
  double v150; // [esp+A8h] [ebp-558h]
  double v151; // [esp+B0h] [ebp-550h]
  double v152; // [esp+B8h] [ebp-548h]
  double v153; // [esp+C0h] [ebp-540h]
  double v154; // [esp+C0h] [ebp-540h]
  int v155; // [esp+D0h] [ebp-530h] BYREF
  int v156; // [esp+D4h] [ebp-52Ch]
  int v157; // [esp+D8h] [ebp-528h]
  float v158; // [esp+DCh] [ebp-524h]
  float v159; // [esp+E0h] [ebp-520h]
  float v160; // [esp+E4h] [ebp-51Ch]
  double v161; // [esp+E8h] [ebp-518h]
  double v162; // [esp+F0h] [ebp-510h]
  double v163; // [esp+F8h] [ebp-508h]
  double v164; // [esp+100h] [ebp-500h]
  double v165; // [esp+108h] [ebp-4F8h]
  double v166; // [esp+110h] [ebp-4F0h]
  double v167; // [esp+118h] [ebp-4E8h]
  double v168; // [esp+120h] [ebp-4E0h]
  double v169; // [esp+128h] [ebp-4D8h]
  long double v170; // [esp+130h] [ebp-4D0h]
  double v171; // [esp+138h] [ebp-4C8h]
  double v172; // [esp+140h] [ebp-4C0h]
  double v173; // [esp+148h] [ebp-4B8h]
  double v174; // [esp+150h] [ebp-4B0h]
  double v175; // [esp+158h] [ebp-4A8h]
  long double v176; // [esp+160h] [ebp-4A0h]
  double v177; // [esp+168h] [ebp-498h]
  double v178; // [esp+170h] [ebp-490h]
  double v179; // [esp+178h] [ebp-488h]
  double v180; // [esp+180h] [ebp-480h]
  double v181; // [esp+188h] [ebp-478h]
  long double v182; // [esp+190h] [ebp-470h]
  long double v183; // [esp+198h] [ebp-468h]
  long double v184; // [esp+1A0h] [ebp-460h]
  double v185; // [esp+1A8h] [ebp-458h]
  double v186; // [esp+1B0h] [ebp-450h]
  double v187; // [esp+1B8h] [ebp-448h]
  double v188; // [esp+1C0h] [ebp-440h]
  double v189; // [esp+1C8h] [ebp-438h]
  double v190; // [esp+1D0h] [ebp-430h]
  double v191; // [esp+1D8h] [ebp-428h]
  double v192; // [esp+1E0h] [ebp-420h]
  double v193; // [esp+1E8h] [ebp-418h]
  double v194; // [esp+1F0h] [ebp-410h]
  double v195; // [esp+1F8h] [ebp-408h]
  double v196; // [esp+200h] [ebp-400h]
  double v197; // [esp+208h] [ebp-3F8h]
  double v198; // [esp+210h] [ebp-3F0h]
  double v199; // [esp+218h] [ebp-3E8h]
  long double v200; // [esp+220h] [ebp-3E0h]
  long double v201; // [esp+228h] [ebp-3D8h]
  long double v202; // [esp+230h] [ebp-3D0h]
  double v203; // [esp+238h] [ebp-3C8h]
  double v204; // [esp+240h] [ebp-3C0h]
  double v205; // [esp+248h] [ebp-3B8h]
  double v206; // [esp+250h] [ebp-3B0h]
  double v207; // [esp+258h] [ebp-3A8h]
  double v208; // [esp+260h] [ebp-3A0h]
  double v209; // [esp+268h] [ebp-398h]
  double v210; // [esp+270h] [ebp-390h]
  double v211; // [esp+278h] [ebp-388h]
  double v212; // [esp+280h] [ebp-380h]
  double v213; // [esp+288h] [ebp-378h]
  double v214; // [esp+290h] [ebp-370h]
  double v215; // [esp+298h] [ebp-368h]
  double v216; // [esp+2A0h] [ebp-360h]
  double v217; // [esp+2A8h] [ebp-358h]
  double v218; // [esp+2B0h] [ebp-350h]
  int v219[2]; // [esp+2B8h] [ebp-348h] BYREF
  double v220; // [esp+2C0h] [ebp-340h]
  double v221; // [esp+2C8h] [ebp-338h]
  double v222; // [esp+2D0h] [ebp-330h]
  double v223; // [esp+2D8h] [ebp-328h]
  int v224; // [esp+2E8h] [ebp-318h]
  double v225; // [esp+2F0h] [ebp-310h]
  double v226; // [esp+2F8h] [ebp-308h]
  double v227[3]; // [esp+308h] [ebp-2F8h] BYREF
  double v228; // [esp+320h] [ebp-2E0h]
  double v229; // [esp+328h] [ebp-2D8h]
  double v230; // [esp+340h] [ebp-2C0h]
  double v231; // [esp+350h] [ebp-2B0h]
  double v232; // [esp+360h] [ebp-2A0h]
  int v233[11]; // [esp+368h] [ebp-298h] BYREF
  float v234; // [esp+394h] [ebp-26Ch]
  float v235; // [esp+398h] [ebp-268h]
  float v236; // [esp+39Ch] [ebp-264h]
  float v237; // [esp+3A0h] [ebp-260h]
  float v238; // [esp+3A4h] [ebp-25Ch]
  float v239; // [esp+3A8h] [ebp-258h]
  float v240; // [esp+3ACh] [ebp-254h]
  int v241[9]; // [esp+3B0h] [ebp-250h] BYREF
  float v242; // [esp+3D4h] [ebp-22Ch]
  float v243; // [esp+3D8h] [ebp-228h]
  float v244; // [esp+3DCh] [ebp-224h]
  float v245; // [esp+3E0h] [ebp-220h]
  float v246; // [esp+3E4h] [ebp-21Ch]
  float v247; // [esp+3E8h] [ebp-218h]
  double v248; // [esp+400h] [ebp-200h]
  _QWORD v249[6]; // [esp+408h] [ebp-1F8h] BYREF
  char v250; // [esp+438h] [ebp-1C8h] BYREF
  _BYTE v251[448]; // [esp+440h] [ebp-1C0h] BYREF

  v147 = 0;
  v4 = (double *)(this + 224);
  do
  {
    v4[39] = 0.0;
    v4[40] = 0.0;
    v4[41] = 0.0;
    v4[42] = 0.0;
    v4[43] = 0.0;
    v4[44] = 0.0;
    v5 = *((double *)this + 50) * -9.81;
    *((double *)this + 67) = *((double *)this + 67);
    *((double *)this + 68) = v5 + *((double *)this + 68);
    *((double *)this + 69) = *((double *)this + 69);
    v170 = *((double *)this + 41) * *((double *)this + 41);
    v171 = *((double *)this + 42) * *((double *)this + 42);
    v128 = v171;
    v172 = *((double *)this + 43) * *((double *)this + 43);
    v6 = v170;
    v132 = v172;
    v7 = v132 * v132 + v128 * v128 + v170 * v170;
    if ( v7 > 268435456.0 )
    {
      v8 = 16384.0 / sqrt(v7);
      v6 = v170 * v8;
      v128 = v171 * v8;
      v132 = v8 * v172;
    }
    v10 = *((double *)this + 9);
    if ( !(v11 | v12) )
      v10 = -v10;
    v126 = v10 * v6;
    v14 = *((double *)this + 9);
    if ( !(v15 | v16) )
      v14 = -v14;
    v129 = v14 * v128;
    v18 = *((double *)this + 9);
    if ( !(v19 | v20) )
      v18 = -v18;
    *((double *)this + 67) = v126 + *((double *)this + 67);
    *((double *)this + 68) = v129 + *((double *)this + 68);
    *((double *)this + 69) = v18 * v132 + *((double *)this + 69);
    v176 = *((double *)this + 44) * *((double *)this + 44);
    v177 = *((double *)this + 45) * *((double *)this + 45);
    v130 = v177;
    v178 = *((double *)this + 46) * *((double *)this + 46);
    v21 = v176;
    v133 = v178;
    v22 = v133 * v133 + v130 * v130 + v176 * v176;
    if ( v22 > 268435456.0 )
    {
      v23 = 16384.0 / sqrt(v22);
      v21 = v176 * v23;
      v130 = v177 * v23;
      v133 = v23 * v178;
    }
    v25 = *((double *)this + 10);
    if ( !(v26 | v27) )
      v25 = -v25;
    v127 = v25 * v21;
    v29 = *((double *)this + 10);
    if ( !(v30 | v31) )
      v29 = -v29;
    v131 = v29 * v130;
    v33 = *((double *)this + 10);
    if ( !(v34 | v35) )
      v33 = -v33;
    *((double *)this + 70) = v127 + *((double *)this + 70);
    *((double *)this + 71) = v131 + *((double *)this + 71);
    *((double *)this + 72) = v33 * v133 + *((double *)this + 72);
    if ( v147 == 1 )
    {
      v36 = *((float *)this + 50);
      HIDWORD(v220) = 0;
      v37 = *((float *)this + 51);
      v221 = 0.0;
      v248 = *((float *)this + 52);
      v228 = v36 - v4[1];
      v38 = v37 - v4[2];
      v39 = v248 - v4[3];
      v225 = v39 * v4[10] + v38 * v4[7] + v228 * v4[4];
      v226 = v39 * v4[11] + v38 * v4[8] + v228 * v4[5];
      v40 = v39 * v4[12] + v38 * v4[9] + v228 * v4[6];
      v41 = *((double *)this + 31);
      v42 = *((double *)this + 30);
      *((float *)this + 50) = *((double *)this + 29);
      *((float *)this + 51) = v42;
      *((float *)this + 52) = v41;
      *(float *)v219 = v225;
      *(float *)&v219[1] = v226;
      *(float *)&v220 = v40;
      v43 = sqrt(v40 * v40 + v226 * v226 + v225 * v225);
      if ( v43 >= *((float *)this + 53) )
        v148 = v43;
      else
        v148 = *((float *)this + 53);
    }
    else
    {
      v44 = *((float *)this + 53);
      v219[0] = 0;
      v219[1] = 0;
      v220 = 0.0;
      v221 = 0.0;
      v148 = v44;
    }
    sub_5ED900(*((_DWORD *)this + 54), (int)v219, 0);
    (*(void (__thiscall **)(char *))(*(_DWORD *)this + 8))(this);
    v45 = -asin(*((double *)this + 37));
    if ( 1.0 == fabs(*((double *)this + 37)) )
    {
      v46 = atan2(-*((double *)this + 38), *((double *)this + 32));
      v47 = 0.0;
    }
    else
    {
      v46 = atan2(*((double *)this + 34), *((double *)this + 40));
      v47 = atan2(*((double *)this + 35), *((double *)this + 36));
    }
    *(float *)&v155 = *((double *)this + 29);
    *(float *)&v156 = *((double *)this + 30);
    *(float *)&v157 = *((double *)this + 31);
    v158 = v45;
    v159 = v46;
    v160 = v47;
    sub_5DB2B0(v155, v156, v157, v158, v159, v160);
    if ( !a3 )
      sub_5300D0(*((_DWORD *)this + 54), (int)&v155, v148);
    v139 = 0;
    v134 = 1;
    if ( *((int *)this + 22) > 1 )
    {
      v48 = (float *)(this + 108);
      v121 = (double *)v249;
      v114 = (float *)(this + 108);
      do
      {
        if ( sub_5ED580(*((_DWORD *)this + 54), v134, (int)v233) )
        {
          v49 = *(v48 - 1);
          v50 = *v48;
          v51 = v48[1];
          v52 = v121;
          v213 = v235;
          ++v139;
          v214 = v236;
          v121 += 7;
          v215 = v237;
          v152 = v51 * v4[6] + v50 * v4[5] + v49 * v4[4];
          v153 = v51 * v4[9] + v50 * v4[8] + v49 * v4[7];
          v53 = v51 * v4[12] + v50 * v4[11] + v49 * v4[10];
          v54 = v152 + v4[1];
          v162 = v153 + v4[2];
          v163 = v53 + v4[3];
          v216 = v235 - v54;
          v164 = v216;
          v217 = v236 - v162;
          v165 = v217;
          v218 = v237 - v163;
          v166 = v218;
          v191 = v54 + v235;
          v173 = v191;
          v192 = v162 + v236;
          v174 = v192;
          v193 = v163 + v237;
          v175 = v193;
          v197 = v191 * 0.5;
          v179 = v197;
          v198 = v192 * 0.5;
          v180 = v198;
          v199 = v193 * 0.5;
          v55 = v197 - *((double *)this + 29);
          v181 = v199;
          v203 = v55;
          v56 = v198 - *((double *)this + 30);
          v52[1] = v203;
          v204 = v56;
          v57 = v181;
          *((_DWORD *)v52 + 4) = LODWORD(v204);
          v58 = v57 - *((double *)this + 31);
          *((_DWORD *)v52 + 5) = HIDWORD(v204);
          v205 = v58;
          v59 = *(float *)&v233[9];
          *((_DWORD *)v52 + 6) = LODWORD(v205);
          v230 = *(float *)&v233[10];
          *((_DWORD *)v52 + 7) = HIDWORD(v205);
          v60 = v234;
          v209 = v164 * v59 + v166 * v234 + v165 * v230;
          v61 = v4[17] * v52[3] - v4[18] * v52[2];
          v62 = v4[18] * v52[1] - v52[3] * v4[16];
          v232 = v52[2] * v4[16] - v4[17] * v52[1];
          v231 = v61 + v4[13];
          v63 = v62 + v4[14];
          v64 = v232 + v4[15];
          v65 = v231 * v59 + v64 * v234 + v63 * v230;
          if ( v209 >= 0.0 )
          {
            v66 = v209 * *((double *)this + 6) - v65 * *((double *)this + 7);
            *v52 = v66;
            if ( v68 | v69 )
              *v52 = v66 * 0.5;
          }
          else
          {
            *v52 = 0.0;
          }
          if ( fabs(*v52) > 65536.0 )
          {
            if ( *v52 <= 0.0 )
              v70 = -65536.0;
            else
              v70 = 65536.0;
            *v52 = v70;
          }
          v188 = v65 * v59;
          v206 = v188;
          v189 = v230 * v65;
          v207 = v189;
          v190 = v65 * v60;
          v208 = v190;
          v194 = v231 - v188;
          v149 = v194;
          v195 = v63 - v189;
          v150 = v195;
          v196 = v64 - v190;
          v151 = v64 - v190;
          v71 = v194 * v194 + v196 * v196 + v195 * v195;
          if ( v71 > 1.0 )
          {
            v72 = 1.0 / sqrt(v71);
            v149 = v194 * v72;
            v150 = v195 * v72;
            v151 = v151 * v72;
          }
          v73 = *((double *)this + 8) * *v52;
          v210 = v149 * v73;
          v185 = v210;
          v211 = v150 * v73;
          v186 = v211;
          v212 = v151 * v73;
          v187 = v212;
          v74 = *v52;
          v200 = v74 * v59;
          v182 = v200;
          v201 = v230 * v74;
          v183 = v201;
          v202 = v74 * v60;
          v184 = v202;
          v167 = v200 - v210;
          v141 = v167;
          v168 = v201 - v211;
          v143 = v168;
          v169 = v202 - v212;
          v145 = v169;
          v75 = sqrt((v182 - v185) * (v182 - v185) + v169 * v169 + (v183 - v186) * (v183 - v186));
          *v52 = v75;
          if ( v77 | v78 )
          {
            v52[4] = 0.0;
            v52[5] = 0.0;
            v52[6] = 0.0;
          }
          else
          {
            v79 = 1.0 / v75;
            v80 = v52 + 4;
            *v80 = v141 * v79;
            v80[1] = v143 * v79;
            v80[2] = v145 * v79;
          }
          sub_5ED990(v134);
          v48 = v114;
        }
        v48 += 3;
        v81 = ++v134 < *((_DWORD *)this + 22);
        v114 = v48;
      }
      while ( v81 );
      if ( v139 > 0 )
      {
        if ( v139 > 1 )
        {
          v82 = 0.0;
          v83 = 0;
          v122 = 0.0;
          if ( v139 >= 4 )
          {
            v84 = ((unsigned int)(v139 - 4) >> 2) + 1;
            v85 = (double *)v251;
            v135 = 4 * v84;
            do
            {
              v115 = *(v85 - 7);
              if ( v115 > v82 )
                v82 = v115;
              v123 = v115 + v122;
              v116 = *v85;
              if ( v116 > v82 )
                v82 = v116;
              v124 = v116 + v123;
              v117 = v85[7];
              if ( v117 > v82 )
                v82 = v117;
              v125 = v117 + v124;
              v118 = v85[14];
              if ( v118 > v82 )
                v82 = v118;
              v85 += 28;
              --v84;
              v122 = v118 + v125;
            }
            while ( v84 );
            v83 = v135;
          }
          if ( v83 < v139 )
          {
            v86 = (double *)&v249[7 * v83];
            v87 = v139 - v83;
            do
            {
              v119 = *v86;
              if ( v119 > v82 )
                v82 = v119;
              v86 += 7;
              --v87;
              v122 = v119 + v122;
            }
            while ( v87 );
          }
          if ( v122 <= 0.0 )
            v88 = 0.0;
          else
            v88 = v82 / v122;
          v89 = 0;
          if ( v139 >= 4 )
          {
            v90 = ((unsigned int)(v139 - 4) >> 2) + 1;
            v91 = (double *)v251;
            v89 = 4 * v90;
            do
            {
              v91 += 28;
              --v90;
              *(v91 - 35) = v88 * *(v91 - 35);
              *(v91 - 28) = v88 * *(v91 - 28);
              *(v91 - 21) = v88 * *(v91 - 21);
              *(v91 - 14) = v88 * *(v91 - 14);
            }
            while ( v90 );
          }
          if ( v89 < v139 )
          {
            v92 = (double *)&v249[7 * v89];
            v93 = v139 - v89;
            do
            {
              v92 += 7;
              --v93;
              *(v92 - 7) = v88 * *(v92 - 7);
            }
            while ( v93 );
          }
        }
        v94 = (double *)&v250;
        v120 = v139;
        do
        {
          v95 = *(v94 - 6);
          v227[0] = v95 * *(v94 - 2);
          v137 = v95 * *(v94 - 1);
          v96 = v95 * *v94;
          v227[1] = v137;
          v227[2] = v96;
          sub_619450(v94 - 5, v227);
          v94 += 7;
          --v120;
        }
        while ( v120 );
      }
    }
    v97 = v147;
    if ( v147 )
      sub_619760(a2);
    else
      sub_619590(a2 * 0.5);
    ++v147;
  }
  while ( v97 + 1 < 2 );
  if ( a3 )
  {
    *(double *)v219 = *((double *)this + 29);
    v98 = *((double *)this + 30) + 2.0;
    v224 = 0;
    v220 = v98;
    v221 = *((double *)this + 31);
    v222 = 0.0;
    v223 = 9.999999933815813e36;
    v99 = (double *)sub_45D190(dbl_B68610, (int)v219);
    if ( v99 )
    {
      v100 = 1;
      if ( *((int *)this + 22) > 1 )
      {
        v101 = (float *)(this + 108);
        do
        {
          v102 = *(v101 - 1);
          v103 = *v101;
          v104 = v101[1];
          v154 = v104 * v4[9] + v102 * v4[7] + v103 * v4[8];
          v105 = v102 * v4[10] + v103 * v4[11] + v104 * v4[12];
          v106 = v104 * v4[6] + *(v101 - 1) * v4[4] + v103 * v4[5] + v4[1];
          v229 = v154 + v4[2];
          v107 = (v106 * *v99 + (v105 + v4[3]) * v99[2] + v99[3]) * v106
               + ((v105 + v4[3]) * v99[1] + v99[4]) * (v105 + v4[3])
               + v99[5];
          if ( v229 < v107 )
          {
            *((double *)this + 30) = v107 - v229 + *((double *)this + 30);
            *((double *)this + 42) = 0.0;
            *((double *)this + 41) = *((double *)this + 41) * 0.949999988079071;
            *((double *)this + 43) = *((double *)this + 43) * 0.949999988079071;
            *((double *)this + 52) = 0.0;
            *((double *)this + 53) = 0.0;
            *((double *)this + 54) = 0.0;
            *((double *)this + 70) = 0.0;
            *((double *)this + 71) = 0.0;
            *((double *)this + 72) = 0.0;
            *((double *)this + 67) = 0.0;
            *((double *)this + 68) = 0.0;
            *((double *)this + 69) = 0.0;
            *((double *)this + 44) = 0.0;
            *((double *)this + 45) = 0.0;
            *((double *)this + 46) = 0.0;
          }
          ++v100;
          v101 += 3;
        }
        while ( v100 < *((_DWORD *)this + 22) );
      }
    }
  }
  result = sub_5ED580(*((_DWORD *)this + 54), 0, (int)v241);
  if ( result )
  {
    v109 = *((float *)this + 23);
    v110 = *((float *)this + 24);
    v111 = *((float *)this + 25);
    v161 = v245;
    v162 = v246;
    v163 = v247;
    v142 = v242;
    v144 = v243;
    v146 = v244;
    *(float *)&v233[2] = (v247 - (v111 * v4[12] + v110 * v4[11] + v109 * v4[10] + v4[3])) * v244
                       + (v246 - (v111 * v4[9] + v110 * v4[8] + v109 * v4[7] + v4[2])) * v243
                       + (v245 - (v111 * v4[6] + v110 * v4[5] + v109 * v4[4] + v4[1])) * v242
                       + 0.009999999776482582;
    v238 = v242;
    v239 = v243;
    v240 = v244;
    sub_470140((int)this, (float *)v233, (float *)this + 50);
    v112 = v146 * *((double *)this + 43) + v144 * *((double *)this + 42) + v142 * *((double *)this + 41);
    v140 = v112 * v146;
    v136 = *((double *)this + 41) - v142 * v112;
    v138 = *((double *)this + 42) - v144 * v112;
    v113 = *((double *)this + 43);
    *((double *)this + 41) = v136;
    *((double *)this + 42) = v138;
    *((double *)this + 43) = v113 - v140;
    return sub_5ED990(0);
  }
  return result;
}
