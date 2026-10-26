int __thiscall sub_55E320(_DWORD *this, float *a2)
{
  int v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  float v7; // edi
  void (__cdecl **v8)(int, int, float *, int); // edx
  int v9; // eax
  float *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  float v14; // ecx
  float v15; // edx
  int result; // eax
  int v17; // edx
  int v18; // edi
  int v19; // eax
  float *v20; // ecx
  int v21; // eax
  double v22; // st7
  double v23; // st6
  double v24; // st5
  int v25; // edx
  double v26; // st4
  double v27; // st3
  double v28; // st2
  long double v29; // st4
  float *v30; // ecx
  double v31; // st7
  double v32; // st7
  double v33; // st7
  int v34; // eax
  double v35; // st7
  int v36; // edx
  double v37; // st6
  double v38; // st5
  long double v39; // st5
  double v40; // st7
  double v41; // st6
  double v42; // st6
  bool v43; // cc
  int v44; // [esp+28h] [ebp-FCh]
  int v45; // [esp+38h] [ebp-ECh]
  float v46; // [esp+38h] [ebp-ECh]
  float v47; // [esp+38h] [ebp-ECh]
  float v48; // [esp+38h] [ebp-ECh]
  float v49; // [esp+38h] [ebp-ECh]
  int v50; // [esp+3Ch] [ebp-E8h]
  int v51; // [esp+3Ch] [ebp-E8h]
  float v52; // [esp+3Ch] [ebp-E8h]
  int v53; // [esp+3Ch] [ebp-E8h]
  float v54; // [esp+40h] [ebp-E4h]
  float v55; // [esp+40h] [ebp-E4h]
  float v56; // [esp+40h] [ebp-E4h]
  float v57; // [esp+40h] [ebp-E4h]
  float v58; // [esp+40h] [ebp-E4h]
  float v59; // [esp+40h] [ebp-E4h]
  float v60; // [esp+44h] [ebp-E0h] BYREF
  float v61; // [esp+48h] [ebp-DCh]
  float v62; // [esp+4Ch] [ebp-D8h]
  float v63; // [esp+50h] [ebp-D4h] BYREF
  float v64; // [esp+54h] [ebp-D0h]
  float v65; // [esp+58h] [ebp-CCh]
  float v66[3]; // [esp+5Ch] [ebp-C8h] BYREF
  float v67[3]; // [esp+68h] [ebp-BCh] BYREF
  float v68; // [esp+74h] [ebp-B0h]
  float v69[4]; // [esp+78h] [ebp-ACh] BYREF
  float v70; // [esp+88h] [ebp-9Ch] BYREF
  float v71; // [esp+8Ch] [ebp-98h]
  float v72; // [esp+90h] [ebp-94h]
  __int64 v73; // [esp+94h] [ebp-90h]
  float v74; // [esp+9Ch] [ebp-88h]
  int v75; // [esp+A0h] [ebp-84h]
  __m64 v76; // [esp+A4h] [ebp-80h]
  int v77; // [esp+B0h] [ebp-74h]
  int v78; // [esp+B4h] [ebp-70h]
  int v79; // [esp+B8h] [ebp-6Ch]
  float v80; // [esp+BCh] [ebp-68h]
  float v81; // [esp+C0h] [ebp-64h]
  float v82; // [esp+C4h] [ebp-60h]
  float v83; // [esp+C8h] [ebp-5Ch]
  __m64 v84; // [esp+CCh] [ebp-58h]
  float v85; // [esp+D4h] [ebp-50h]
  float v86; // [esp+D8h] [ebp-4Ch]
  float v87[2]; // [esp+DCh] [ebp-48h] BYREF
  float v88[2]; // [esp+E4h] [ebp-40h]
  __m64 v89; // [esp+ECh] [ebp-38h] BYREF
  float v90; // [esp+F4h] [ebp-30h]
  __int16 v91; // [esp+FCh] [ebp-28h]
  __int16 v92; // [esp+100h] [ebp-24h]
  __int16 v93; // [esp+104h] [ebp-20h]
  __int16 v94; // [esp+108h] [ebp-1Ch]
  int v95; // [esp+10Ch] [ebp-18h]
  int v96; // [esp+110h] [ebp-14h]
  __int16 v97; // [esp+114h] [ebp-10h]
  int v98; // [esp+118h] [ebp-Ch]
  __int16 v99; // [esp+11Ch] [ebp-8h]
  int v100; // [esp+120h] [ebp-4h]

  v3 = this[6];
  v50 = v3 + 256;
  v4 = ((unsigned int)&unk_800000 & *(_DWORD *)(v3 + 20)) == 0;
  v5 = this[3];
  v78 = v5;
  if ( v4 )
  {
    v6 = v5 + 12;
    v75 = 12;
  }
  else
  {
    v6 = v5 + 28;
    v75 = 16;
  }
  v7 = *(float *)(dword_8B8F28 + 288);
  v44 = *(_DWORD *)(v3 + 312) + 340;
  HIDWORD(v73) = v6;
  v8 = *(void (__cdecl ***)(int, int, float *, int))dword_8B8F24;
  v68 = v7;
  (*v8)(dword_8B8F24, LODWORD(v7) + 68, v67, v44);
  (**(void (__cdecl ***)(int, int, float *, int))dword_8B8F24)(dword_8B8F24, v50, v66, *(_DWORD *)(this[6] + 312) + 340);
  if ( (*this & 0x100) != 0 && (v9 = this[6], *(int *)(v9 + 268) > 0) )
  {
    v10 = *(float **)(v9 + 272);
    v79 = 1;
    v77 = 0;
    do
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, __m64 *))(*(_DWORD *)dword_8B8F24 + 24))(
        dword_8B8F24,
        0,
        *(_DWORD *)v10,
        this[1],
        &v89);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, float *))(*(_DWORD *)dword_8B8F24 + 20))(
        dword_8B8F24,
        *(_DWORD *)v10,
        this[1],
        v87);
      v10 += 14;
      v11 = v77 + 1;
      *(v10 - 9) = v87[0] + v89.m64_f32[0];
      v77 = v11;
      *(v10 - 8) = v87[1] + v89.m64_f32[1];
      *(v10 - 7) = v88[0] + v90;
    }
    while ( v11 < *(_DWORD *)(this[6] + 268) );
    v7 = v68;
  }
  else
  {
    v79 = 0;
  }
  v12 = this[1];
  v13 = *(_DWORD *)(v12 + 156);
  v51 = v13;
  v95 = v13 & 0x40;
  if ( (v13 & 0x40) != 0 )
  {
    if ( (v13 & 0x4000000) != 0 )
    {
      v14 = *(float *)(v12 + 104);
      v85 = *(float *)(v12 + 100);
      v15 = *(float *)(v12 + 108);
      v81 = v14;
      v86 = v15;
    }
    else
    {
      v85 = *(float *)(v12 + 100) * *(float *)(LODWORD(v7) + 36);
      v81 = *(float *)(v12 + 104) * *(float *)(LODWORD(v7) + 36);
      v86 = *(float *)(v12 + 108) * *(float *)(LODWORD(v7) + 36);
    }
  }
  (*(void (__thiscall **)(int, int, float, int, float *))(*(_DWORD *)dword_8B8F24 + 24))(
    dword_8B8F24,
    dword_8B8F28,
    COERCE_FLOAT(LODWORD(v7)),
    v12,
    &v70);
  (*(void (__thiscall **)(int, float, _DWORD, float *))(*(_DWORD *)dword_8B8F24 + 20))(
    dword_8B8F24,
    COERCE_FLOAT(LODWORD(v7)),
    this[1],
    v69);
  result = v51;
  if ( (v51 & 0x4000) != 0 )
    v52 = *(float *)(this[1] + 80) * *(float *)(LODWORD(v7) + 36) * 255.0;
  else
    v52 = *(float *)(this[1] + 80) * 255.0;
  LOWORD(v74) = (__int16)v52;
  v84.m64_i16[3] = LOWORD(v74);
  v76.m64_i16[3] = LOWORD(v74);
  v76.m64_i16[0] = (__int16)v70;
  v76.m64_i16[1] = (__int16)v71;
  v17 = this[2];
  v76.m64_i16[2] = (__int16)v72;
  v53 = _mm_cvtsi64_si32(_m_packuswb(v76, (__m64)qword_8B6C20));
  v89.m64_i16[3] = 0;
  _m_empty();
  v77 = 0;
  if ( v17 > 0 )
  {
    v96 = result & 0x80;
    v76.m64_i16[3] = 0;
    v98 = 4 * v75;
    v18 = 0;
    while ( 1 )
    {
      v76.m64_i16[2] = 0;
      v76.m64_i32[0] = 0;
      if ( v79 )
      {
        (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          v78,
          &v60,
          *(_DWORD *)(this[6] + 312) + 416);
        v19 = this[6];
        v20 = *(float **)(v19 + 272);
        v21 = *(_DWORD *)(v19 + 268);
        v68 = 0.0;
        *(float *)&v75 = 0.0;
        v80 = 0.0;
        if ( v21 > 0 )
        {
          v22 = v80;
          v45 = v21;
          v23 = *(float *)&v75;
          v24 = v68;
          do
          {
            v25 = *(_DWORD *)v20;
            v26 = *(float *)(*(_DWORD *)v20 + 64) - v62;
            v83 = *(float *)(*(_DWORD *)v20 + 80);
            v27 = *(float *)(v25 + 60) - v61;
            v28 = *(float *)(v25 + 56) - v60;
            v68 = v28 * v28 + v27 * v27 + v26 * v26;
            if ( v83 * v83 > v68 )
            {
              if ( (*(_DWORD *)v25 & 0x100) != 0 )
              {
                v22 = v22 + v20[5];
                v23 = v23 + v20[6];
                v24 = v24 + v20[7];
              }
              else
              {
                v29 = 1.0 - sqrt(v68) * v20[4];
                v22 = v22 + v29 * v20[5];
                v23 = v23 + v29 * v20[6];
                v24 = v24 + v29 * v20[7];
              }
            }
            v20 += 14;
            --v45;
          }
          while ( v45 );
          v68 = v24;
          *(float *)&v75 = v23;
          v80 = v22;
        }
        LOWORD(v74) = (__int16)v80;
        v76.m64_i16[0] = LOWORD(v74);
        LOWORD(v100) = (__int16)*(float *)&v75;
        v76.m64_i16[1] = v100;
        LOWORD(v82) = (__int16)v68;
        v76.m64_i16[2] = LOWORD(v82);
        if ( SLOWORD(v74) < 0 && (v100 & 0x8000u) != 0 && SLOWORD(v82) < 0 )
          break;
      }
      v30 = (float *)HIDWORD(v73);
      v31 = -(v67[0] * *(float *)HIDWORD(v73))
          - v67[1] * *(float *)(HIDWORD(v73) + 4)
          - v67[2] * *(float *)(HIDWORD(v73) + 8);
      v46 = v31;
      if ( v31 <= 0.0 )
      {
        *(_DWORD *)(v18 + this[8] + 24) = v53;
      }
      else
      {
        v54 = v69[0] * v46 + v70;
        v91 = (__int16)v54;
        v84.m64_i16[0] = v91;
        v55 = v69[1] * v46 + v71;
        v93 = (__int16)v55;
        v84.m64_i16[1] = v93;
        v56 = v69[2] * v46 + v72;
        v97 = (__int16)v56;
        v84.m64_i16[2] = v97;
        *(_DWORD *)(v18 + this[8] + 24) = _mm_cvtsi64_si32(_m_packuswb(_m_paddsw(v84, v76), (__m64)qword_8B6C20));
        _m_empty();
      }
      if ( !v95 )
        goto LABEL_38;
      v32 = v66[0] * *v30 + v66[2] * v30[2] + v66[1] * v30[1];
      if ( v32 > 0.0 )
      {
        v47 = v32;
        v33 = sub_53AC40((int *)*(_DWORD *)(this[1] + 180), v47);
        v48 = v33;
        v57 = v33 * v86;
        v99 = (__int16)v57;
        v89.m64_i16[0] = v99;
        v58 = v48 * v81;
        v92 = (__int16)v58;
        v89.m64_i16[1] = v92;
        v59 = v48 * v85;
        v94 = (__int16)v59;
        v34 = this[8];
        v89.m64_i16[2] = v94;
        *(_DWORD *)(v18 + v34 + 28) = _mm_cvtsi64_si32(_m_packuswb(v89, (__m64)qword_8B6C20));
        _m_empty();
LABEL_37:
        v30 = (float *)HIDWORD(v73);
        goto LABEL_38;
      }
      *(_DWORD *)(v18 + this[8] + 28) = 0;
LABEL_38:
      if ( v96 )
      {
        if ( !v79 )
        {
          (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
            dword_8B8F24,
            v78,
            &v60,
            *(_DWORD *)(this[6] + 312) + 416);
          v30 = (float *)HIDWORD(v73);
        }
        (**(void (__cdecl ***)(int, float *, float *, int))dword_8B8F24)(
          dword_8B8F24,
          v30,
          &v63,
          *(_DWORD *)(this[6] + 312) + 276);
        v35 = v60 + a2[9];
        v36 = this[8];
        v30 = (float *)HIDWORD(v73);
        v37 = v61 + a2[10];
        v38 = v62 + a2[11];
        v88[0] = v38;
        v39 = 1.0 / sqrt(v38 * v88[0] + v37 * v37 + v35 * v35);
        v49 = v39;
        v87[0] = v39 * v35;
        v40 = v49 * v37;
        v41 = v49 * v88[0] * v65 + v64 * v40 + v63 * v87[0];
        v42 = v41 + v41;
        *(float *)(v18 + v36 + 40) = (v63 * v42 - v87[0]) * 0.5 + 0.5;
        *(float *)(v18 + this[8] + 44) = (v64 * v42 - v40) * 0.5 + 0.5;
      }
      HIDWORD(v73) = &v30[v98 / 4u];
      result = v77 + 1;
      v18 += 64;
      v43 = v77 + 1 < this[2];
      v78 += v98;
      ++v77;
      if ( !v43 )
        return result;
    }
    *(_DWORD *)(v18 + this[8] + 24) = v53;
    *(_DWORD *)(v18 + this[8] + 28) = 0;
    goto LABEL_37;
  }
  return result;
}
