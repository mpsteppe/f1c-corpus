int __thiscall sub_459AE0(int this, double a2)
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
  double v42; // st7
  double v43; // st7
  long double v44; // st6
  long double v45; // st5
  bool v46; // cc
  float *v47; // esi
  double *v48; // edi
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st4
  double v53; // st7
  double v54; // st6
  double v55; // st7
  double v56; // st6
  double v57; // st5
  double v58; // st4
  double v59; // st4
  long double v60; // st7
  long double v61; // st7
  double v62; // st7
  long double v63; // st5
  long double v64; // st7
  long double v65; // st6
  double v66; // st5
  double v67; // rt2
  int v68; // eax
  int v69; // edx
  double v70; // st7
  double *v71; // ecx
  int v72; // esi
  double v73; // st6
  double v74; // st7
  double *v75; // eax
  int v76; // ecx
  double *v77; // eax
  double v78; // st7
  double v79; // st6
  double *v80; // eax
  int v81; // esi
  int result; // eax
  double v83; // st7
  int v84; // [esp+14h] [ebp-504h]
  double *v85; // [esp+14h] [ebp-504h]
  float *v86; // [esp+18h] [ebp-500h]
  int v87; // [esp+18h] [ebp-500h]
  double v88; // [esp+20h] [ebp-4F8h]
  double v89; // [esp+20h] [ebp-4F8h]
  double v90; // [esp+28h] [ebp-4F0h]
  double v91; // [esp+28h] [ebp-4F0h]
  double v92; // [esp+30h] [ebp-4E8h]
  double v93; // [esp+30h] [ebp-4E8h]
  double v94[3]; // [esp+38h] [ebp-4E0h] BYREF
  int v95; // [esp+50h] [ebp-4C8h]
  int v96; // [esp+54h] [ebp-4C4h]
  float v97; // [esp+58h] [ebp-4C0h]
  double *v98; // [esp+5Ch] [ebp-4BCh]
  double v99; // [esp+60h] [ebp-4B8h]
  int v100; // [esp+68h] [ebp-4B0h] BYREF
  int v101; // [esp+6Ch] [ebp-4ACh]
  int v102; // [esp+70h] [ebp-4A8h]
  long double v103; // [esp+74h] [ebp-4A4h]
  long double v104; // [esp+7Ch] [ebp-49Ch]
  long double v105; // [esp+84h] [ebp-494h]
  float v106; // [esp+8Ch] [ebp-48Ch]
  float v107; // [esp+90h] [ebp-488h]
  float v108; // [esp+94h] [ebp-484h]
  double v109[3]; // [esp+98h] [ebp-480h] BYREF
  double v110[3]; // [esp+B0h] [ebp-468h] BYREF
  double v111[3]; // [esp+C8h] [ebp-450h] BYREF
  double v112; // [esp+E0h] [ebp-438h] BYREF
  double v113; // [esp+E8h] [ebp-430h]
  double v114; // [esp+F0h] [ebp-428h]
  double v115[3]; // [esp+F8h] [ebp-420h] BYREF
  double v116; // [esp+110h] [ebp-408h]
  double v117; // [esp+118h] [ebp-400h]
  double v118; // [esp+120h] [ebp-3F8h]
  double v119; // [esp+128h] [ebp-3F0h]
  double v120[3]; // [esp+130h] [ebp-3E8h] BYREF
  double v121[4]; // [esp+148h] [ebp-3D0h] BYREF
  long double v122; // [esp+168h] [ebp-3B0h]
  double v123; // [esp+170h] [ebp-3A8h]
  double v124[3]; // [esp+178h] [ebp-3A0h] BYREF
  float v125; // [esp+190h] [ebp-388h] BYREF
  float v126; // [esp+194h] [ebp-384h]
  float v127; // [esp+198h] [ebp-380h]
  int v128; // [esp+19Ch] [ebp-37Ch]
  int v129; // [esp+1A0h] [ebp-378h]
  int v130; // [esp+1A4h] [ebp-374h]
  float v131; // [esp+1BCh] [ebp-35Ch]
  float v132; // [esp+1C0h] [ebp-358h]
  float v133; // [esp+1C4h] [ebp-354h]
  double v134; // [esp+1C8h] [ebp-350h] BYREF
  double v135; // [esp+1D0h] [ebp-348h]
  double v136; // [esp+1D8h] [ebp-340h]
  double v137; // [esp+1E0h] [ebp-338h]
  double v138; // [esp+1F0h] [ebp-328h]
  double v139[3]; // [esp+1F8h] [ebp-320h] BYREF
  double v140[3]; // [esp+210h] [ebp-308h] BYREF
  double v141[3]; // [esp+228h] [ebp-2F0h] BYREF
  char v142[36]; // [esp+240h] [ebp-2D8h] BYREF
  float v143; // [esp+264h] [ebp-2B4h]
  float v144; // [esp+268h] [ebp-2B0h]
  float v145; // [esp+26Ch] [ebp-2ACh]
  float v146; // [esp+270h] [ebp-2A8h]
  float v147; // [esp+274h] [ebp-2A4h]
  float v148; // [esp+278h] [ebp-2A0h]
  char v149[36]; // [esp+280h] [ebp-298h] BYREF
  float v150; // [esp+2A4h] [ebp-274h]
  float v151; // [esp+2A8h] [ebp-270h]
  float v152; // [esp+2ACh] [ebp-26Ch]
  float v153; // [esp+2B0h] [ebp-268h]
  float v154; // [esp+2B4h] [ebp-264h]
  float v155; // [esp+2B8h] [ebp-260h]
  double v156; // [esp+2D0h] [ebp-248h]
  double v157; // [esp+2E8h] [ebp-230h]
  _BYTE v158[24]; // [esp+2F0h] [ebp-228h] BYREF
  double v159; // [esp+308h] [ebp-210h]
  _BYTE v160[48]; // [esp+320h] [ebp-1F8h] BYREF
  _BYTE v161[456]; // [esp+350h] [ebp-1C8h] BYREF

  v95 = 0;
  do
  {
    *(_DWORD *)(this + 520) = 0;
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
    v3 = *(double *)(this + 384);
    *(_DWORD *)(this + 524) = *(_DWORD *)(this + 524);
    *(_DWORD *)(this + 540) = *(_DWORD *)(this + 540);
    v4 = v3 * -9.81 + *(double *)(this + 528);
    *(_DWORD *)(this + 520) = 0;
    *(_DWORD *)(this + 536) = *(_DWORD *)(this + 536);
    *(double *)(this + 528) = v4;
    v110[0] = *(double *)(this + 312) * *(double *)(this + 312);
    v110[1] = *(double *)(this + 320) * *(double *)(this + 320);
    v110[2] = *(double *)(this + 328) * *(double *)(this + 328);
    qmemcpy(v94, v110, sizeof(v94));
    v5 = v110[2] * v110[2] + v110[1] * v110[1] + v110[0] * v110[0];
    if ( v5 <= 268435456.0 )
    {
      v7 = v94[2];
    }
    else
    {
      v6 = 16384.0 / sqrt(v5);
      v94[0] = v110[0] * v6;
      v94[1] = v94[1] * v6;
      v7 = v6 * v94[2];
    }
    v9 = *(double *)(this + 64);
    if ( !(v10 | v11) )
      v9 = -v9;
    v94[0] = v9 * v94[0];
    v13 = *(double *)(this + 64);
    if ( !(v14 | v15) )
      v13 = -v13;
    v94[1] = v13 * v94[1];
    v17 = *(double *)(this + 64);
    if ( !(v18 | v19) )
      v17 = -v17;
    v94[2] = v17 * v7;
    *(double *)(this + 520) = v94[0] + *(double *)(this + 520);
    *(double *)(this + 528) = v94[1] + *(double *)(this + 528);
    *(double *)(this + 536) = v94[2] + *(double *)(this + 536);
    v109[0] = *(double *)(this + 336) * *(double *)(this + 336);
    v109[1] = *(double *)(this + 344) * *(double *)(this + 344);
    v109[2] = *(double *)(this + 352) * *(double *)(this + 352);
    qmemcpy(v94, v109, sizeof(v94));
    v20 = v109[0] * v109[0] + v109[2] * v109[2] + v109[1] * v109[1];
    if ( v20 <= 268435456.0 )
    {
      v22 = v94[2];
    }
    else
    {
      v21 = 16384.0 / sqrt(v20);
      v94[0] = v109[0] * v21;
      v94[1] = v94[1] * v21;
      v22 = v21 * v94[2];
    }
    v24 = *(double *)(this + 72);
    if ( !(v25 | v26) )
      v24 = -v24;
    v94[0] = v24 * v94[0];
    v28 = *(double *)(this + 72);
    if ( !(v29 | v30) )
      v28 = -v28;
    v94[1] = v28 * v94[1];
    v32 = *(double *)(this + 72);
    if ( !(v33 | v34) )
      v32 = -v32;
    v35 = 1;
    v36 = v95 == 1;
    v94[2] = v32 * v22;
    *(double *)(this + 544) = v94[0] + *(double *)(this + 544);
    *(double *)(this + 552) = v94[1] + *(double *)(this + 552);
    *(double *)(this + 560) = v94[2] + *(double *)(this + 560);
    if ( v36 )
    {
      v139[0] = *(float *)(this + 192);
      v139[1] = *(float *)(this + 196);
      v139[2] = *(float *)(this + 200);
      F_3DVectorTransformBy33Matrix((double *)(this + 240), (double *)(this + 216), v139, &v112);
      v37 = *(double *)(this + 232);
      v38 = *(double *)(this + 224);
      v39 = *(double *)(this + 216);
      v128 = 0;
      *(float *)(this + 192) = v39;
      v129 = 0;
      *(float *)(this + 196) = v38;
      v130 = 0;
      *(float *)(this + 200) = v37;
      v125 = v112;
      v126 = v113;
      v127 = v114;
      v40 = sqrt(v114 * v114 + v113 * v113 + v112 * v112);
      if ( v40 < *(float *)(this + 204) )
        v40 = *(float *)(this + 204);
      v97 = v40;
    }
    else
    {
      v41 = *(float *)(this + 204);
      v125 = 0.0;
      v126 = 0.0;
      v127 = 0.0;
      v128 = 0;
      v129 = 0;
      v130 = 0;
      v97 = v41;
    }
    NetworkPacketDataWriter(&v125, 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
    v42 = *(double *)(this + 280);
    FloatConvertWrapper();
    v43 = -v42;
    if ( fabs(*(double *)(this + 280)) == 1.0 )
    {
      v44 = atan2(-*(double *)(this + 288), *(double *)(this + 240));
      v45 = 0.0;
    }
    else
    {
      v44 = atan2(*(double *)(this + 256), *(double *)(this + 304));
      v45 = atan2(*(double *)(this + 264), *(double *)(this + 272));
    }
    *(float *)&v100 = *(double *)(this + 216);
    *(float *)&v101 = *(double *)(this + 224);
    *(float *)&v102 = *(double *)(this + 232);
    v106 = v43;
    v107 = v44;
    v108 = v45;
    sub_54B4D0(v100, v101, v102, v106, v107, v108);
    SpriteGridRender(*(_DWORD *)(this + 208), (int)&v100, v97);
    v46 = *(_DWORD *)(this + 80) <= 1;
    v84 = 0;
    v96 = 1;
    if ( !v46 )
    {
      v47 = (float *)(this + 100);
      v98 = (double *)v160;
      v86 = (float *)(this + 100);
      do
      {
        if ( NetworkPacketDataReader(v35, v149) )
        {
          v48 = v98;
          v140[0] = *(v47 - 1);
          v140[1] = *v47;
          v140[2] = v47[1];
          v98 += 7;
          v117 = v153;
          ++v84;
          v118 = v154;
          v119 = v155;
          TransformApply3D((double *)(this + 240), (double *)(this + 216), v140, &v134);
          v49 = v117 - v134;
          v50 = v118 - v135;
          v51 = v119 - v136;
          v156 = v136 + v119;
          v159 = (v134 + v117) * 0.5;
          v141[0] = v159 - *(double *)(this + 216);
          v141[1] = (v135 + v118) * 0.5 - *(double *)(this + 224);
          v141[2] = v156 * 0.5 - *(double *)(this + 232);
          v52 = v150;
          qmemcpy(v48 + 1, v141, 0x18u);
          v88 = v52;
          v90 = v151;
          v92 = v152;
          v116 = v49 * v52 + v51 * v152 + v50 * v151;
          v53 = v48[3] * *(double *)(this + 344) - v48[2] * *(double *)(this + 352);
          v54 = *(double *)(this + 352) * v48[1] - v48[3] * *(double *)(this + 336);
          v138 = v48[2] * *(double *)(this + 336) - *(double *)(this + 344) * v48[1];
          v137 = v53 + *(double *)(this + 312);
          v55 = v54 + *(double *)(this + 320);
          v56 = v138 + *(double *)(this + 328);
          v57 = v137 * v52 + v56 * v152 + v55 * v151;
          if ( v116 >= 0.0 )
          {
            v58 = v116 * *(double *)(this + 40) - v57 * *(double *)(this + 48);
            *v48 = v58;
            if ( v58 < 0.0 )
              *v48 = v58 * 0.5;
          }
          else
          {
            *(_DWORD *)v48 = 0;
            *((_DWORD *)v48 + 1) = 0;
          }
          if ( fabs(*v48) > 65536.0 )
          {
            if ( *v48 <= 0.0 )
              v59 = -65536.0;
            else
              v59 = 65536.0;
            *v48 = v59;
          }
          v157 = v57 * v92;
          v111[0] = v137 - v88 * v57;
          v111[1] = v55 - v57 * v90;
          v111[2] = v56 - v157;
          qmemcpy(v115, v111, sizeof(v115));
          v60 = v111[0] * v111[0] + v111[2] * v111[2] + v111[1] * v111[1];
          if ( v60 > 1.0 )
          {
            v61 = 1.0 / sqrt(v60);
            v115[0] = v111[0] * v61;
            v115[1] = v115[1] * v61;
            v115[2] = v115[2] * v61;
          }
          v62 = *(double *)(this + 56) * *v48;
          v124[1] = v115[1] * v62;
          v124[2] = v115[2] * v62;
          v63 = *v48;
          v103 = v88 * v63;
          v104 = v90 * v63;
          v105 = v63 * v92;
          v64 = v103 - v115[0] * v62;
          v122 = v104 - v124[1];
          v65 = v105 - v124[2];
          v66 = sqrt(v64 * v64 + v65 * v65 + v122 * v122);
          *v48 = v66;
          if ( v66 <= 0.0 )
          {
            *((_DWORD *)v48 + 8) = 0;
            *((_DWORD *)v48 + 9) = 0;
            *((_DWORD *)v48 + 10) = 0;
            *((_DWORD *)v48 + 11) = 0;
            *((_DWORD *)v48 + 12) = 0;
            *((_DWORD *)v48 + 13) = 0;
          }
          else
          {
            v67 = 1.0 / v66;
            v120[0] = v64 * v67;
            v120[1] = v122 * v67;
            v120[2] = v65 * v67;
            qmemcpy(v48 + 4, v120, 0x18u);
          }
          BufferEntryClear(v96);
          v47 = v86;
          v35 = v96;
        }
        v68 = *(_DWORD *)(this + 80);
        ++v35;
        v47 += 3;
        v96 = v35;
        v86 = v47;
      }
      while ( v35 < v68 );
      v69 = v84;
      if ( v84 > 0 )
      {
        if ( v84 > 1 )
        {
          v70 = 0.0;
          v99 = 0.0;
          v71 = (double *)v160;
          v72 = v84;
          do
          {
            v73 = *v71;
            if ( v73 > v99 )
              v99 = v73;
            v71 += 7;
            v70 = v70 + v73;
            --v72;
          }
          while ( v72 );
          if ( v70 <= 0.0 )
            v74 = 0.0;
          else
            v74 = v99 / v70;
          v75 = (double *)v160;
          v76 = v84;
          do
          {
            v75 += 7;
            --v76;
            *(v75 - 7) = v74 * *(v75 - 7);
          }
          while ( v76 );
        }
        v77 = (double *)v161;
        v85 = (double *)v161;
        v87 = v69;
        while ( 1 )
        {
          v78 = *(v77 - 6);
          v79 = v78 * *(v77 - 2);
          v80 = v77 - 5;
          v121[0] = v79;
          v121[1] = v78 * v80[4];
          v121[2] = v78 * v80[5];
          qmemcpy(v158, v121, sizeof(v158));
          AccumulateAngularMomentum(v80, v158);
          v36 = v87 == 1;
          v85 += 7;
          --v87;
          if ( v36 )
            break;
          v77 = v85;
        }
      }
    }
    v81 = v95;
    if ( v95 )
      sub_569DE0(a2);
    else
      sub_569C10(a2 * 0.5);
    v95 = v81 + 1;
  }
  while ( v81 + 1 < 2 );
  result = NetworkPacketDataReader(0, v142);
  if ( result )
  {
    v121[0] = *(float *)(this + 84);
    v121[1] = *(float *)(this + 88);
    v121[2] = *(float *)(this + 92);
    v103 = v146;
    v104 = v147;
    v105 = v148;
    TransformApply3D((double *)(this + 240), (double *)(this + 216), v121, v120);
    v89 = v143;
    v91 = v144;
    v93 = v145;
    v127 = (v105 - v120[2]) * v145 + (v104 - v120[1]) * v144 + (v103 - v120[0]) * v143 + 0.009999999776482582;
    v131 = v143;
    v132 = v144;
    v133 = v145;
    PhysicsStateIntegration((double *)this, &v125, (float *)(this + 192));
    v83 = v93 * *(double *)(this + 328) + v91 * *(double *)(this + 320) + v89 * *(double *)(this + 312);
    v122 = v83 * v91;
    v123 = v83 * v93;
    v124[0] = *(double *)(this + 312) - v89 * v83;
    v124[1] = *(double *)(this + 320) - v122;
    v124[2] = *(double *)(this + 328) - v123;
    qmemcpy((void *)(this + 312), v124, 0x18u);
    return BufferEntryClear(0);
  }
  return result;
}
