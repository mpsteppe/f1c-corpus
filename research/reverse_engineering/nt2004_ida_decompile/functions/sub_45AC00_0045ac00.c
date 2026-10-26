int __thiscall sub_45AC00(int this, double a2)
{
  double v3; // st7
  double v4; // st7
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  double v9; // st6
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  double v13; // st6
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  double v17; // st6
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  long double v20; // st7
  long double v21; // st7
  long double v22; // st7
  double v24; // st6
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c3
  double v28; // st6
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  double v32; // st6
  unsigned __int8 v33; // c0
  unsigned __int8 v34; // c3
  int v35; // edi
  bool v36; // zf
  double v37; // st7
  double v38; // st6
  double v39; // st5
  long double v40; // st7
  float v41; // eax
  long double v42; // st7
  long double v43; // st6
  long double v44; // st5
  bool v45; // cc
  float *v46; // esi
  double *v47; // edi
  double v48; // st7
  double v49; // st6
  double v50; // st5
  double v51; // st4
  double v52; // st7
  double v53; // st6
  double v54; // st7
  double v55; // st6
  double v56; // st5
  double v57; // st4
  double v58; // st4
  long double v59; // st7
  long double v60; // st7
  double v61; // st7
  long double v62; // st5
  long double v63; // st7
  long double v64; // st6
  double v65; // st5
  double v66; // rt2
  int v67; // eax
  int v68; // edx
  double v69; // st7
  double *v70; // ecx
  int v71; // esi
  double v72; // st6
  double v73; // st7
  double *v74; // eax
  int v75; // ecx
  double *v76; // eax
  double v77; // st7
  double v78; // st6
  double *v79; // eax
  int v80; // esi
  int result; // eax
  double v82; // st7
  int v83; // [esp+14h] [ebp-4F4h]
  double *v84; // [esp+14h] [ebp-4F4h]
  float *v85; // [esp+18h] [ebp-4F0h]
  int v86; // [esp+18h] [ebp-4F0h]
  double v87; // [esp+20h] [ebp-4E8h]
  double v88; // [esp+20h] [ebp-4E8h]
  double v89; // [esp+28h] [ebp-4E0h]
  double v90; // [esp+28h] [ebp-4E0h]
  double v91; // [esp+30h] [ebp-4D8h]
  double v92; // [esp+30h] [ebp-4D8h]
  double v93[3]; // [esp+38h] [ebp-4D0h] BYREF
  int v94; // [esp+50h] [ebp-4B8h]
  int v95; // [esp+54h] [ebp-4B4h]
  float v96; // [esp+58h] [ebp-4B0h]
  double *v97; // [esp+5Ch] [ebp-4ACh]
  double v98; // [esp+60h] [ebp-4A8h]
  int v99; // [esp+68h] [ebp-4A0h] BYREF
  int v100; // [esp+6Ch] [ebp-49Ch]
  int v101; // [esp+70h] [ebp-498h]
  long double v102; // [esp+74h] [ebp-494h]
  long double v103; // [esp+7Ch] [ebp-48Ch]
  long double v104; // [esp+84h] [ebp-484h]
  float v105; // [esp+8Ch] [ebp-47Ch]
  float v106; // [esp+90h] [ebp-478h]
  float v107; // [esp+94h] [ebp-474h]
  double v108[3]; // [esp+98h] [ebp-470h] BYREF
  double v109[3]; // [esp+B0h] [ebp-458h] BYREF
  double v110[3]; // [esp+C8h] [ebp-440h] BYREF
  double v111; // [esp+E0h] [ebp-428h] BYREF
  double v112; // [esp+E8h] [ebp-420h]
  double v113; // [esp+F0h] [ebp-418h]
  float v114; // [esp+F8h] [ebp-410h] BYREF
  float v115; // [esp+FCh] [ebp-40Ch]
  float v116; // [esp+100h] [ebp-408h]
  int v117; // [esp+104h] [ebp-404h]
  int v118; // [esp+108h] [ebp-400h]
  int v119; // [esp+10Ch] [ebp-3FCh]
  double v120[3]; // [esp+118h] [ebp-3F0h] BYREF
  double v121; // [esp+130h] [ebp-3D8h]
  double v122; // [esp+138h] [ebp-3D0h]
  double v123; // [esp+140h] [ebp-3C8h]
  double v124; // [esp+148h] [ebp-3C0h]
  double v125[4]; // [esp+150h] [ebp-3B8h] BYREF
  long double v126; // [esp+170h] [ebp-398h]
  double v127; // [esp+178h] [ebp-390h]
  double v128[3]; // [esp+180h] [ebp-388h] BYREF
  double v129[3]; // [esp+198h] [ebp-370h] BYREF
  double v130; // [esp+1B0h] [ebp-358h] BYREF
  double v131; // [esp+1B8h] [ebp-350h]
  double v132; // [esp+1C0h] [ebp-348h]
  double v133; // [esp+1C8h] [ebp-340h]
  double v134; // [esp+1D8h] [ebp-330h]
  double v135[3]; // [esp+1E0h] [ebp-328h] BYREF
  double v136[3]; // [esp+1F8h] [ebp-310h] BYREF
  double v137[3]; // [esp+210h] [ebp-2F8h] BYREF
  float v138[10]; // [esp+228h] [ebp-2E0h] BYREF
  float v139; // [esp+250h] [ebp-2B8h]
  float v140; // [esp+254h] [ebp-2B4h]
  float v141; // [esp+258h] [ebp-2B0h]
  float v142; // [esp+25Ch] [ebp-2ACh]
  float v143; // [esp+260h] [ebp-2A8h]
  float v144; // [esp+264h] [ebp-2A4h]
  float v145; // [esp+268h] [ebp-2A0h]
  float v146; // [esp+26Ch] [ebp-29Ch]
  char v147[36]; // [esp+270h] [ebp-298h] BYREF
  float v148; // [esp+294h] [ebp-274h]
  float v149; // [esp+298h] [ebp-270h]
  float v150; // [esp+29Ch] [ebp-26Ch]
  float v151; // [esp+2A0h] [ebp-268h]
  float v152; // [esp+2A4h] [ebp-264h]
  float v153; // [esp+2A8h] [ebp-260h]
  double v154; // [esp+2C0h] [ebp-248h]
  double v155; // [esp+2D8h] [ebp-230h]
  _BYTE v156[24]; // [esp+2E0h] [ebp-228h] BYREF
  double v157; // [esp+2F8h] [ebp-210h]
  _BYTE v158[48]; // [esp+310h] [ebp-1F8h] BYREF
  _BYTE v159[456]; // [esp+340h] [ebp-1C8h] BYREF

  v94 = 0;
  do
  {
    *(_DWORD *)(this + 524) = 0;
    *(_DWORD *)(this + 528) = 0;
    *(_DWORD *)(this + 532) = 0;
    *(_DWORD *)(this + 536) = 0;
    *(_DWORD *)(this + 540) = 0;
    *(_DWORD *)(this + 544) = 0;
    *(_DWORD *)(this + 548) = 0;
    *(_DWORD *)(this + 552) = 0;
    *(_DWORD *)(this + 556) = 0;
    *(_DWORD *)(this + 560) = 0;
    *(_DWORD *)(this + 564) = 0;
    *(_DWORD *)(this + 568) = 0;
    v3 = *(double *)(this + 388);
    *(_DWORD *)(this + 528) = *(_DWORD *)(this + 528);
    *(_DWORD *)(this + 544) = *(_DWORD *)(this + 544);
    v4 = v3 * -9.81 + *(double *)(this + 532);
    *(_DWORD *)(this + 524) = 0;
    *(_DWORD *)(this + 540) = *(_DWORD *)(this + 540);
    *(double *)(this + 532) = v4;
    v110[0] = *(double *)(this + 316) * *(double *)(this + 316);
    v110[1] = *(double *)(this + 324) * *(double *)(this + 324);
    v110[2] = *(double *)(this + 332) * *(double *)(this + 332);
    qmemcpy(v93, v110, sizeof(v93));
    v5 = v110[2] * v110[2] + v110[1] * v110[1] + v110[0] * v110[0];
    if ( v5 <= 268435456.0 )
    {
      v7 = v93[2];
    }
    else
    {
      v6 = 16384.0 / sqrt(v5);
      v93[0] = v110[0] * v6;
      v93[1] = v93[1] * v6;
      v7 = v6 * v93[2];
    }
    v9 = *(double *)(this + 64);
    if ( !(v10 | v11) )
      v9 = -v9;
    v93[0] = v9 * v93[0];
    v13 = *(double *)(this + 64);
    if ( !(v14 | v15) )
      v13 = -v13;
    v93[1] = v13 * v93[1];
    v17 = *(double *)(this + 64);
    if ( !(v18 | v19) )
      v17 = -v17;
    v93[2] = v17 * v7;
    *(double *)(this + 524) = v93[0] + *(double *)(this + 524);
    *(double *)(this + 532) = v93[1] + *(double *)(this + 532);
    *(double *)(this + 540) = v93[2] + *(double *)(this + 540);
    v109[0] = *(double *)(this + 340) * *(double *)(this + 340);
    v109[1] = *(double *)(this + 348) * *(double *)(this + 348);
    v109[2] = *(double *)(this + 356) * *(double *)(this + 356);
    qmemcpy(v93, v109, sizeof(v93));
    v20 = v109[0] * v109[0] + v109[2] * v109[2] + v109[1] * v109[1];
    if ( v20 <= 268435456.0 )
    {
      v22 = v93[2];
    }
    else
    {
      v21 = 16384.0 / sqrt(v20);
      v93[0] = v109[0] * v21;
      v93[1] = v93[1] * v21;
      v22 = v21 * v93[2];
    }
    v24 = *(double *)(this + 72);
    if ( !(v25 | v26) )
      v24 = -v24;
    v93[0] = v24 * v93[0];
    v28 = *(double *)(this + 72);
    if ( !(v29 | v30) )
      v28 = -v28;
    v93[1] = v28 * v93[1];
    v32 = *(double *)(this + 72);
    if ( !(v33 | v34) )
      v32 = -v32;
    v35 = 1;
    v36 = v94 == 1;
    v93[2] = v32 * v22;
    *(double *)(this + 548) = v93[0] + *(double *)(this + 548);
    *(double *)(this + 556) = v93[1] + *(double *)(this + 556);
    *(double *)(this + 564) = v93[2] + *(double *)(this + 564);
    if ( v36 )
    {
      v136[0] = *(float *)(this + 192);
      v136[1] = *(float *)(this + 196);
      v136[2] = *(float *)(this + 200);
      sub_4388F0((double *)(this + 244), (double *)(this + 220), v136, &v111);
      v37 = *(double *)(this + 236);
      v38 = *(double *)(this + 228);
      v39 = *(double *)(this + 220);
      v117 = 0;
      *(float *)(this + 192) = v39;
      v118 = 0;
      *(float *)(this + 196) = v38;
      v119 = 0;
      *(float *)(this + 200) = v37;
      v114 = v111;
      v115 = v112;
      v116 = v113;
      v40 = sqrt(v113 * v113 + v112 * v112 + v111 * v111);
      if ( v40 < *(float *)(this + 204) )
        v40 = *(float *)(this + 204);
      v96 = v40;
    }
    else
    {
      v41 = *(float *)(this + 204);
      v114 = 0.0;
      v115 = 0.0;
      v116 = 0.0;
      v117 = 0;
      v118 = 0;
      v119 = 0;
      v96 = v41;
    }
    sub_5A11B0(&v114, 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
    v42 = -asin(*(double *)(this + 284));
    if ( fabs(*(double *)(this + 284)) == 1.0 )
    {
      v43 = atan2(-*(double *)(this + 292), *(double *)(this + 244));
      v44 = 0.0;
    }
    else
    {
      v43 = atan2(*(double *)(this + 260), *(double *)(this + 308));
      v44 = atan2(*(double *)(this + 268), *(double *)(this + 276));
    }
    *(float *)&v99 = *(double *)(this + 220);
    *(float *)&v100 = *(double *)(this + 228);
    *(float *)&v101 = *(double *)(this + 236);
    v105 = v42;
    v106 = v43;
    v107 = v44;
    sub_59E170(v99, v100, v101, v105, v106, v107);
    sub_4E0CD0(*(_DWORD *)(this + 212), (int)&v99, v96);
    v45 = *(_DWORD *)(this + 80) <= 1;
    v83 = 0;
    v95 = 1;
    if ( !v45 )
    {
      v46 = (float *)(this + 100);
      v97 = (double *)v158;
      v85 = (float *)(this + 100);
      do
      {
        if ( sub_5A1240(v35, v138) )
        {
          v47 = v97;
          v137[0] = *(v46 - 1);
          v137[1] = *v46;
          v137[2] = v46[1];
          v97 += 7;
          v122 = v141;
          ++v83;
          v123 = v142;
          v124 = v143;
          sub_43D900((double *)(this + 244), (double *)(this + 220), v137, &v130);
          v48 = v122 - v130;
          v49 = v123 - v131;
          v50 = v124 - v132;
          v154 = v132 + v124;
          v157 = (v130 + v122) * 0.5;
          v135[0] = v157 - *(double *)(this + 220);
          v135[1] = (v131 + v123) * 0.5 - *(double *)(this + 228);
          v135[2] = v154 * 0.5 - *(double *)(this + 236);
          v51 = v138[9];
          qmemcpy(v47 + 1, v135, 0x18u);
          v87 = v51;
          v89 = v139;
          v91 = v140;
          v121 = v48 * v51 + v50 * v140 + v49 * v139;
          v52 = v47[3] * *(double *)(this + 348) - v47[2] * *(double *)(this + 356);
          v53 = *(double *)(this + 356) * v47[1] - v47[3] * *(double *)(this + 340);
          v134 = v47[2] * *(double *)(this + 340) - *(double *)(this + 348) * v47[1];
          v133 = v52 + *(double *)(this + 316);
          v54 = v53 + *(double *)(this + 324);
          v55 = v134 + *(double *)(this + 332);
          v56 = v133 * v51 + v55 * v140 + v54 * v139;
          if ( v121 >= 0.0 )
          {
            v57 = v121 * *(double *)(this + 40) - v56 * *(double *)(this + 48);
            *v47 = v57;
            if ( v57 < 0.0 )
              *v47 = v57 * 0.5;
          }
          else
          {
            *(_DWORD *)v47 = 0;
            *((_DWORD *)v47 + 1) = 0;
          }
          if ( fabs(*v47) > 65536.0 )
          {
            if ( *v47 <= 0.0 )
              v58 = -65536.0;
            else
              v58 = 65536.0;
            *v47 = v58;
          }
          v155 = v56 * v91;
          v108[0] = v133 - v87 * v56;
          v108[1] = v54 - v56 * v89;
          v108[2] = v55 - v155;
          qmemcpy(v120, v108, sizeof(v120));
          v59 = v108[0] * v108[0] + v108[2] * v108[2] + v108[1] * v108[1];
          if ( v59 > 1.0 )
          {
            v60 = 1.0 / sqrt(v59);
            v120[0] = v108[0] * v60;
            v120[1] = v120[1] * v60;
            v120[2] = v120[2] * v60;
          }
          v61 = *(double *)(this + 56) * *v47;
          v129[1] = v120[1] * v61;
          v129[2] = v120[2] * v61;
          v62 = *v47;
          v102 = v87 * v62;
          v103 = v89 * v62;
          v104 = v62 * v91;
          v63 = v102 - v120[0] * v61;
          v126 = v103 - v129[1];
          v64 = v104 - v129[2];
          v65 = sqrt(v63 * v63 + v64 * v64 + v126 * v126);
          *v47 = v65;
          if ( v65 <= 0.0 )
          {
            *((_DWORD *)v47 + 8) = 0;
            *((_DWORD *)v47 + 9) = 0;
            *((_DWORD *)v47 + 10) = 0;
            *((_DWORD *)v47 + 11) = 0;
            *((_DWORD *)v47 + 12) = 0;
            *((_DWORD *)v47 + 13) = 0;
          }
          else
          {
            v66 = 1.0 / v65;
            v125[0] = v63 * v66;
            v125[1] = v126 * v66;
            v125[2] = v64 * v66;
            qmemcpy(v47 + 4, v125, 0x18u);
          }
          sub_5A1290(v95);
          v46 = v85;
          v35 = v95;
        }
        v67 = *(_DWORD *)(this + 80);
        ++v35;
        v46 += 3;
        v95 = v35;
        v85 = v46;
      }
      while ( v35 < v67 );
      v68 = v83;
      if ( v83 > 0 )
      {
        if ( v83 > 1 )
        {
          v69 = 0.0;
          v98 = 0.0;
          v70 = (double *)v158;
          v71 = v83;
          do
          {
            v72 = *v70;
            if ( v72 > v98 )
              v98 = v72;
            v70 += 7;
            v69 = v69 + v72;
            --v71;
          }
          while ( v71 );
          if ( v69 <= 0.0 )
            v73 = 0.0;
          else
            v73 = v98 / v69;
          v74 = (double *)v158;
          v75 = v83;
          do
          {
            v74 += 7;
            --v75;
            *(v74 - 7) = v73 * *(v74 - 7);
          }
          while ( v75 );
        }
        v76 = (double *)v159;
        v84 = (double *)v159;
        v86 = v68;
        while ( 1 )
        {
          v77 = *(v76 - 6);
          v78 = v77 * *(v76 - 2);
          v79 = v76 - 5;
          v128[0] = v78;
          v128[1] = v77 * v79[4];
          v128[2] = v77 * v79[5];
          qmemcpy(v156, v128, sizeof(v156));
          sub_57C860(v79, v156);
          v36 = v86 == 1;
          v84 += 7;
          --v86;
          if ( v36 )
            break;
          v76 = v84;
        }
      }
    }
    v80 = v94;
    if ( v94 )
      sub_57CB70(a2);
    else
      sub_57C9A0(a2 * 0.5);
    v94 = v80 + 1;
  }
  while ( v80 + 1 < 2 );
  result = sub_5A1240(0, v147);
  if ( result )
  {
    v128[0] = *(float *)(this + 84);
    v128[1] = *(float *)(this + 88);
    v128[2] = *(float *)(this + 92);
    v102 = v151;
    v103 = v152;
    v104 = v153;
    sub_43D900((double *)(this + 244), (double *)(this + 220), v128, v125);
    v88 = v148;
    v90 = v149;
    v92 = v150;
    v138[2] = (v104 - v125[2]) * v150 + (v103 - v125[1]) * v149 + (v102 - v125[0]) * v148 + 0.009999999776482582;
    v144 = v148;
    v145 = v149;
    v146 = v150;
    sub_45AB60(this, v138, (float *)(this + 192));
    v82 = v92 * *(double *)(this + 332) + v90 * *(double *)(this + 324) + v88 * *(double *)(this + 316);
    v126 = v82 * v90;
    v127 = v82 * v92;
    v129[0] = *(double *)(this + 316) - v88 * v82;
    v129[1] = *(double *)(this + 324) - v126;
    v129[2] = *(double *)(this + 332) - v127;
    qmemcpy((void *)(this + 316), v129, 0x18u);
    return sub_5A1290(0);
  }
  return result;
}
