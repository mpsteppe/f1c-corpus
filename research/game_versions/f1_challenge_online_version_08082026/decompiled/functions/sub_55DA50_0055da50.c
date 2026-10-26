unsigned int __thiscall sub_55DA50(_DWORD *this, float *a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  float *v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  float v12; // ecx
  float v13; // edx
  int v14; // eax
  double v15; // st7
  int v16; // ecx
  unsigned int result; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // eax
  float v21; // edx
  int v22; // edi
  float v23; // edx
  int v24; // eax
  int v25; // eax
  float *v26; // ecx
  int v27; // eax
  double v28; // st7
  double v29; // st6
  double v30; // st5
  int v31; // edx
  double v32; // st4
  double v33; // st3
  double v34; // st2
  long double v35; // st4
  float v36; // ecx
  float *v37; // edx
  double v38; // st7
  int v39; // edx
  double v40; // st7
  double v41; // st7
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  int v45; // ecx
  int v46; // edx
  int v47; // ecx
  int v48; // eax
  double v49; // st7
  int v50; // ecx
  double v51; // st6
  double v52; // st5
  long double v53; // st5
  double v54; // st7
  double v55; // st6
  double v56; // st6
  double v57; // st5
  int v58; // eax
  int v59; // eax
  bool v60; // zf
  int v61; // [esp+38h] [ebp-F4h]
  BOOL v62; // [esp+38h] [ebp-F4h]
  float v63; // [esp+38h] [ebp-F4h]
  float v64; // [esp+38h] [ebp-F4h]
  float v65; // [esp+38h] [ebp-F4h]
  float v66; // [esp+38h] [ebp-F4h]
  int v67; // [esp+3Ch] [ebp-F0h]
  float *v68; // [esp+3Ch] [ebp-F0h]
  float v69; // [esp+3Ch] [ebp-F0h]
  float v70; // [esp+3Ch] [ebp-F0h]
  float v71; // [esp+40h] [ebp-ECh]
  float v72; // [esp+40h] [ebp-ECh]
  float v73; // [esp+40h] [ebp-ECh]
  float v74; // [esp+40h] [ebp-ECh]
  float v75; // [esp+40h] [ebp-ECh]
  float v76; // [esp+40h] [ebp-ECh]
  int v77; // [esp+40h] [ebp-ECh]
  float v78[3]; // [esp+44h] [ebp-E8h] BYREF
  float v79[3]; // [esp+50h] [ebp-DCh] BYREF
  float v80[3]; // [esp+5Ch] [ebp-D0h] BYREF
  float v81; // [esp+68h] [ebp-C4h] BYREF
  float v82; // [esp+6Ch] [ebp-C0h]
  float v83; // [esp+70h] [ebp-BCh]
  float v84; // [esp+74h] [ebp-B8h] BYREF
  float v85; // [esp+78h] [ebp-B4h]
  float v86; // [esp+7Ch] [ebp-B0h]
  float v87[3]; // [esp+80h] [ebp-ACh] BYREF
  int v88; // [esp+8Ch] [ebp-A0h]
  int v89; // [esp+90h] [ebp-9Ch]
  int v90; // [esp+94h] [ebp-98h]
  float v91; // [esp+98h] [ebp-94h]
  __m64 v92; // [esp+9Ch] [ebp-90h]
  int v93; // [esp+A8h] [ebp-84h]
  __m64 v94; // [esp+ACh] [ebp-80h]
  float v95; // [esp+B4h] [ebp-78h]
  float v96; // [esp+B8h] [ebp-74h]
  float v97; // [esp+BCh] [ebp-70h] BYREF
  float v98; // [esp+C0h] [ebp-6Ch]
  __int64 v99; // [esp+C4h] [ebp-68h]
  float v100; // [esp+CCh] [ebp-60h]
  float v101; // [esp+D0h] [ebp-5Ch]
  float v102; // [esp+D4h] [ebp-58h]
  float v103; // [esp+D8h] [ebp-54h]
  float v104; // [esp+DCh] [ebp-50h]
  int v105; // [esp+E0h] [ebp-4Ch]
  int v106; // [esp+E4h] [ebp-48h]
  int v107; // [esp+E8h] [ebp-44h]
  float v108[2]; // [esp+ECh] [ebp-40h] BYREF
  float v109; // [esp+F4h] [ebp-38h]
  __m64 v110; // [esp+FCh] [ebp-30h]
  int v111; // [esp+104h] [ebp-28h]
  __int16 v112; // [esp+108h] [ebp-24h]
  int v113; // [esp+10Ch] [ebp-20h]
  int v114; // [esp+110h] [ebp-1Ch]
  __int16 v115; // [esp+114h] [ebp-18h]
  int v116; // [esp+118h] [ebp-14h]
  int v117; // [esp+11Ch] [ebp-10h]
  int v118; // [esp+120h] [ebp-Ch]
  __int16 v119; // [esp+124h] [ebp-8h]
  int v120; // [esp+128h] [ebp-4h]

  v3 = this[6];
  v4 = v3 + 256;
  v61 = *(_DWORD *)(dword_8B8F28 + 288);
  (**(void (__cdecl ***)(int, int, float *, int))dword_8B8F24)(dword_8B8F24, v61 + 68, v79, *(_DWORD *)(v3 + 312) + 340);
  (**(void (__cdecl ***)(int, int, float *, int))dword_8B8F24)(dword_8B8F24, v4, v80, *(_DWORD *)(this[6] + 312) + 340);
  if ( (*this & 0x100) == 0 || (v5 = *(_DWORD *)(this[6] + 268), v93 = 1, v5 <= 0) )
    v93 = 0;
  v6 = this[6];
  v7 = *(float **)(v6 + 272);
  if ( v93 )
  {
    v8 = *(_DWORD *)(v6 + 268);
    v90 = 0;
    if ( v8 > 0 )
    {
      do
      {
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, float *))(*(_DWORD *)dword_8B8F24 + 24))(
          dword_8B8F24,
          0,
          *(_DWORD *)v7,
          this[1],
          &v97);
        (*(void (__thiscall **)(int, _DWORD, _DWORD, float *))(*(_DWORD *)dword_8B8F24 + 20))(
          dword_8B8F24,
          *(_DWORD *)v7,
          this[1],
          v108);
        v7 += 14;
        v9 = v90 + 1;
        *(v7 - 9) = v108[0] + v97;
        v90 = v9;
        *(v7 - 8) = v108[1] + v98;
        *(v7 - 7) = v109 + *(float *)&v99;
      }
      while ( v9 < *(_DWORD *)(this[6] + 268) );
    }
  }
  v10 = this[1];
  v11 = *(_DWORD *)(v10 + 156);
  if ( (v11 & 0x40) != 0 )
  {
    if ( (v11 & 0x4000000) != 0 )
    {
      v12 = *(float *)(v10 + 104);
      v100 = *(float *)(v10 + 100);
      v13 = *(float *)(v10 + 108);
      v102 = v12;
      v101 = v13;
    }
    else
    {
      v100 = *(float *)(v10 + 100) * *(float *)(v61 + 36);
      v102 = *(float *)(v10 + 104) * *(float *)(v61 + 36);
      v101 = *(float *)(v10 + 108) * *(float *)(v61 + 36);
    }
  }
  (*(void (__thiscall **)(int, int, int, int, float *))(*(_DWORD *)dword_8B8F24 + 24))(
    dword_8B8F24,
    dword_8B8F28,
    v61,
    v10,
    v87);
  (*(void (__thiscall **)(int, int, _DWORD, float *))(*(_DWORD *)dword_8B8F24 + 20))(dword_8B8F24, v61, this[1], v78);
  v14 = this[1];
  v15 = *(float *)(v14 + 80);
  if ( (*(_DWORD *)(v14 + 156) & 0x4000) != 0 )
    *(float *)&v89 = v15 * *(float *)(v61 + 36) * 255.0;
  else
    *(float *)&v89 = v15 * 255.0;
  LOWORD(v88) = (__int16)*(float *)&v89;
  v92.m64_i16[3] = v88;
  v16 = this[4];
  result = (unsigned int)((unsigned __int64)(1431655766LL * v16) >> 32) >> 31;
  v18 = 0;
  v110.m64_i16[3] = 0;
  if ( v16 / 3 > 0 )
  {
    v94.m64_i16[3] = 0;
    v90 = 0;
    v89 = v16 / 3;
    do
    {
      v19 = this[6];
      v20 = this[5];
      v88 = *(_DWORD *)(v19 + 292) + v90 + 16;
      LODWORD(v21) = *(unsigned __int16 *)(v20 + v18);
      v22 = v18 + 2;
      v97 = v21;
      LODWORD(v23) = *(unsigned __int16 *)(v20 + v22);
      v24 = *(unsigned __int16 *)(v20 + v22 + 2);
      v98 = v23;
      LODWORD(v99) = v24;
      v18 = v22 + 4;
      *(__int32 *)((char *)v94.m64_i32 + 2) = 0;
      v94.m64_i16[0] = 0;
      v62 = 1;
      if ( v93 )
      {
        (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          v88,
          &v81,
          *(_DWORD *)(v19 + 312) + 276);
        v25 = this[6];
        v26 = *(float **)(v25 + 272);
        v27 = *(_DWORD *)(v25 + 268);
        v91 = 0.0;
        v96 = 0.0;
        v95 = 0.0;
        if ( v27 > 0 )
        {
          v28 = v95;
          v67 = v27;
          v29 = v96;
          v30 = v91;
          do
          {
            v31 = *(_DWORD *)v26;
            v32 = *(float *)(*(_DWORD *)v26 + 64) - v83;
            v104 = *(float *)(*(_DWORD *)v26 + 80);
            v33 = *(float *)(v31 + 60) - v82;
            v34 = *(float *)(v31 + 56) - v81;
            v91 = v34 * v34 + v33 * v33 + v32 * v32;
            if ( v104 * v104 > v91 )
            {
              if ( (*(_DWORD *)v31 & 0x100) != 0 )
              {
                v28 = v28 + v26[5];
                v29 = v29 + v26[6];
                v30 = v30 + v26[7];
              }
              else
              {
                v35 = 1.0 - sqrt(v91) * v26[4];
                v28 = v28 + v35 * v26[5];
                v29 = v29 + v35 * v26[6];
                v30 = v30 + v35 * v26[7];
              }
            }
            v26 += 14;
            --v67;
          }
          while ( v67 );
          v91 = v30;
          v96 = v29;
          v95 = v28;
        }
        LOWORD(v106) = (__int16)v95;
        v94.m64_i16[0] = v106;
        LOWORD(v118) = (__int16)v96;
        v94.m64_i16[1] = v118;
        LOWORD(v107) = (__int16)v91;
        v94.m64_i16[2] = v107;
        v62 = (v106 & 0x8000u) == 0 || (v118 & 0x8000u) == 0 || (v107 & 0x8000u) == 0;
      }
      if ( *(_DWORD *)(this[6] + 316) )
      {
        v36 = v97;
        v37 = (float *)((LODWORD(v97) << 6) + this[8] + 12);
      }
      else
      {
        v37 = (float *)(48 * LODWORD(v97) + this[3] + 12);
        v36 = v97;
      }
      v68 = v37;
      LOWORD(v120) = (__int16)v87[0];
      v92.m64_i16[0] = v120;
      LOWORD(v105) = (__int16)v87[1];
      v92.m64_i16[1] = v105;
      LOWORD(v103) = (__int16)v87[2];
      v92.m64_i16[2] = LOWORD(v103);
      if ( v62 )
      {
        v38 = -(v79[0] * *v37) - v79[1] * v37[1] - v79[2] * v37[2];
        v63 = v38;
        if ( v38 > 0.0 )
        {
          v71 = v78[0] * v63;
          LOWORD(v111) = (__int16)v71;
          v92.m64_i16[0] = v120 + v111;
          v72 = v78[1] * v63;
          LOWORD(v113) = (__int16)v72;
          v92.m64_i16[1] = v105 + v113;
          v73 = v78[2] * v63;
          LOWORD(v117) = (__int16)v73;
          v92.m64_i16[2] = LOWORD(v103) + v117;
        }
        v39 = this[1];
        if ( (*(_BYTE *)(v39 + 156) & 0x40) != 0 )
        {
          v40 = v80[1] * v68[1] + v80[2] * v68[2] + v80[0] * *v68;
          if ( v40 <= 0.0 )
          {
            v42 = 0;
          }
          else
          {
            v64 = v40;
            v41 = sub_53AC40((int *)*(_DWORD *)(v39 + 180), v64);
            v65 = v41;
            v74 = v41 * v101;
            v115 = (__int16)v74;
            v110.m64_i16[0] = v115;
            v75 = v65 * v102;
            v119 = (__int16)v75;
            v110.m64_i16[1] = v119;
            v76 = v65 * v100;
            v112 = (__int16)v76;
            v110.m64_i16[2] = v112;
            v36 = v97;
            v42 = _mm_cvtsi64_si32(_m_packuswb(v110, (__m64)qword_8B6C20));
          }
          *(_DWORD *)((LODWORD(v36) << 6) + this[8] + 28) = v42;
          *(_DWORD *)((LODWORD(v98) << 6) + this[8] + 28) = v42;
          *(_DWORD *)(((_DWORD)v99 << 6) + this[8] + 28) = v42;
          v36 = v97;
        }
        v43 = _mm_cvtsi64_si32(_m_packuswb(_m_paddsw(v92, v94), (__m64)qword_8B6C20));
      }
      else
      {
        v43 = _mm_cvtsi64_si32(_m_packuswb(v92, (__m64)qword_8B6C20));
      }
      v44 = LODWORD(v36) << 6;
      *(_DWORD *)(v44 + this[8] + 24) = v43;
      v77 = v44;
      v45 = LODWORD(v98) << 6;
      *(_DWORD *)(this[8] + v45 + 24) = v43;
      v46 = this[8];
      v114 = v45;
      v47 = (_DWORD)v99 << 6;
      *(_DWORD *)(v46 + v47 + 24) = v43;
      v48 = this[1];
      v116 = v47;
      _m_empty();
      if ( *(char *)(v48 + 156) < 0 )
      {
        if ( !v93 )
          (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
            dword_8B8F24,
            v88,
            &v81,
            *(_DWORD *)(this[6] + 312) + 416);
        (**(void (__cdecl ***)(int, float *, float *, int))dword_8B8F24)(
          dword_8B8F24,
          v68,
          &v84,
          *(_DWORD *)(this[6] + 312) + 276);
        v49 = v81 + a2[9];
        v50 = this[8];
        v51 = v82 + a2[10];
        v52 = v83 + a2[11];
        v109 = v52;
        v53 = 1.0 / sqrt(v52 * v109 + v51 * v51 + v49 * v49);
        v69 = v53;
        v108[0] = v53 * v49;
        v54 = v69 * v51;
        v55 = v69 * v109 * v86 + v85 * v54 + v84 * v108[0];
        v56 = v55 + v55;
        v70 = (v84 * v56 - v108[0]) * 0.5 + 0.5;
        v57 = v85 * v56;
        *(float *)(v77 + v50 + 40) = v70;
        v66 = (v57 - v54) * 0.5 + 0.5;
        *(float *)(v77 + this[8] + 44) = v66;
        v58 = v114;
        *(float *)(this[8] + v114 + 40) = v70;
        *(float *)(this[8] + v58 + 44) = v66;
        v59 = v116;
        *(float *)(this[8] + v116 + 40) = v70;
        *(float *)(this[8] + v59 + 44) = v66;
      }
      result = v89 - 1;
      v60 = v89 == 1;
      v90 += 36;
      --v89;
    }
    while ( !v60 );
  }
  return result;
}
