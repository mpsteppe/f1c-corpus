int __thiscall sub_5B6930(_DWORD *this, float *a2)
{
  int v3; // ecx
  bool v4; // zf
  int v5; // eax
  float *v6; // eax
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
  float **v20; // edi
  int v21; // eax
  double v22; // st7
  double v23; // st6
  double v24; // st5
  float *v25; // eax
  int v26; // ecx
  double v27; // st4
  double v28; // st3
  double v29; // st2
  long double v30; // st4
  int v31; // ecx
  float *v32; // edx
  float *v33; // ecx
  double v34; // st7
  double v35; // st7
  double v36; // st7
  int v37; // eax
  double v38; // st7
  int v39; // edx
  double v40; // st6
  double v41; // st5
  long double v42; // st5
  double v43; // st7
  double v44; // st6
  double v45; // st6
  bool v46; // cc
  int v47; // [esp+2Ch] [ebp-F4h]
  int v48; // [esp+38h] [ebp-E8h]
  float v49; // [esp+38h] [ebp-E8h]
  float v50; // [esp+38h] [ebp-E8h]
  float v51; // [esp+38h] [ebp-E8h]
  float v52; // [esp+38h] [ebp-E8h]
  float v53; // [esp+38h] [ebp-E8h]
  float v54; // [esp+38h] [ebp-E8h]
  int v55; // [esp+3Ch] [ebp-E4h]
  float v56; // [esp+3Ch] [ebp-E4h]
  float v57; // [esp+3Ch] [ebp-E4h]
  float v58; // [esp+3Ch] [ebp-E4h]
  float v59; // [esp+3Ch] [ebp-E4h]
  int v60; // [esp+40h] [ebp-E0h]
  int v61; // [esp+40h] [ebp-E0h]
  float v62; // [esp+40h] [ebp-E0h]
  int v63; // [esp+40h] [ebp-E0h]
  float v64; // [esp+44h] [ebp-DCh] BYREF
  float v65; // [esp+48h] [ebp-D8h]
  float v66; // [esp+4Ch] [ebp-D4h]
  float v67; // [esp+50h] [ebp-D0h] BYREF
  float v68; // [esp+54h] [ebp-CCh]
  float v69; // [esp+58h] [ebp-C8h]
  float v70[3]; // [esp+5Ch] [ebp-C4h] BYREF
  float v71[3]; // [esp+68h] [ebp-B8h] BYREF
  float v72; // [esp+74h] [ebp-ACh]
  float v73[4]; // [esp+78h] [ebp-A8h] BYREF
  float *v74; // [esp+88h] [ebp-98h]
  float v75; // [esp+8Ch] [ebp-94h] BYREF
  float v76; // [esp+90h] [ebp-90h]
  float v77; // [esp+94h] [ebp-8Ch]
  int v78; // [esp+9Ch] [ebp-84h]
  __m64 v79; // [esp+A0h] [ebp-80h]
  int v80; // [esp+A8h] [ebp-78h]
  int v81; // [esp+ACh] [ebp-74h]
  int v82; // [esp+B0h] [ebp-70h]
  float v83; // [esp+B4h] [ebp-6Ch]
  float v84; // [esp+B8h] [ebp-68h]
  float v85; // [esp+BCh] [ebp-64h]
  __m64 v86; // [esp+C0h] [ebp-60h]
  float v87; // [esp+C8h] [ebp-58h]
  float v88; // [esp+CCh] [ebp-54h]
  float v89[2]; // [esp+D0h] [ebp-50h] BYREF
  float v90; // [esp+D8h] [ebp-48h]
  __m64 v91; // [esp+E0h] [ebp-40h] BYREF
  float v92; // [esp+E8h] [ebp-38h]
  __int16 v93; // [esp+F0h] [ebp-30h]
  __int16 v94; // [esp+F4h] [ebp-2Ch]
  int v95; // [esp+F8h] [ebp-28h]
  int v96; // [esp+FCh] [ebp-24h]
  int v97; // [esp+100h] [ebp-20h]
  __int16 v98; // [esp+104h] [ebp-1Ch]
  __int16 v99; // [esp+108h] [ebp-18h]
  __int16 v100; // [esp+10Ch] [ebp-14h]
  int v101; // [esp+110h] [ebp-10h]
  __int16 v102; // [esp+114h] [ebp-Ch]
  int v103; // [esp+118h] [ebp-8h]
  int v104; // [esp+11Ch] [ebp-4h]

  v3 = this[6];
  v60 = v3 + 256;
  v4 = ((unsigned int)&unk_800000 & *(_DWORD *)(v3 + 20)) == 0;
  v5 = this[3];
  v80 = v5;
  if ( v4 )
  {
    v6 = (float *)(v5 + 12);
    v78 = 12;
  }
  else
  {
    v6 = (float *)(v5 + 28);
    v78 = 16;
  }
  v7 = *(float *)(dword_7E8E5C + 292);
  v47 = *(_DWORD *)(v3 + 312) + 340;
  v74 = v6;
  v8 = *(void (__cdecl ***)(int, int, float *, int))dword_7E8E58;
  v72 = v7;
  (*v8)(dword_7E8E58, LODWORD(v7) + 68, v71, v47);
  (**(void (__cdecl ***)(int, int, float *, int))dword_7E8E58)(dword_7E8E58, v60, v70, *(_DWORD *)(this[6] + 312) + 340);
  if ( (*this & 0x100) != 0 && (v9 = this[6], *(int *)(v9 + 268) > 0) )
  {
    v10 = *(float **)(v9 + 272);
    v82 = 1;
    v81 = 0;
    do
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, __m64 *))(*(_DWORD *)dword_7E8E58 + 24))(
        dword_7E8E58,
        0,
        *(_DWORD *)v10,
        this[1],
        &v91);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, float *))(*(_DWORD *)dword_7E8E58 + 20))(
        dword_7E8E58,
        *(_DWORD *)v10,
        this[1],
        v89);
      v10 += 14;
      v11 = v81 + 1;
      *(v10 - 9) = v89[0] + v91.m64_f32[0];
      v81 = v11;
      *(v10 - 8) = v89[1] + v91.m64_f32[1];
      *(v10 - 7) = v90 + v92;
    }
    while ( v11 < *(_DWORD *)(this[6] + 268) );
    v7 = v72;
  }
  else
  {
    v82 = 0;
  }
  v12 = this[1];
  v13 = *(_DWORD *)(v12 + 156);
  v61 = v13;
  v96 = v13 & 0x40;
  if ( (v13 & 0x40) != 0 )
  {
    if ( (v13 & 0x4000000) != 0 )
    {
      v14 = *(float *)(v12 + 104);
      v85 = *(float *)(v12 + 100);
      v15 = *(float *)(v12 + 108);
      v84 = v14;
      v88 = v15;
    }
    else
    {
      v85 = *(float *)(v12 + 100) * *(float *)(LODWORD(v7) + 36);
      v84 = *(float *)(v12 + 104) * *(float *)(LODWORD(v7) + 36);
      v88 = *(float *)(v12 + 108) * *(float *)(LODWORD(v7) + 36);
    }
  }
  (*(void (__thiscall **)(int, int, float, int, float *))(*(_DWORD *)dword_7E8E58 + 24))(
    dword_7E8E58,
    dword_7E8E5C,
    COERCE_FLOAT(LODWORD(v7)),
    v12,
    &v75);
  (*(void (__thiscall **)(int, float, _DWORD, float *))(*(_DWORD *)dword_7E8E58 + 20))(
    dword_7E8E58,
    COERCE_FLOAT(LODWORD(v7)),
    this[1],
    v73);
  result = v61;
  if ( (v61 & 0x4000) != 0 )
    v62 = *(float *)(this[1] + 80) * *(float *)(LODWORD(v7) + 36) * 255.0;
  else
    v62 = *(float *)(this[1] + 80) * 255.0;
  v86.m64_i16[3] = (__int16)v62;
  v79.m64_i16[3] = v86.m64_i16[3];
  v79.m64_i16[0] = (__int16)v75;
  v79.m64_i16[1] = (__int16)v76;
  v17 = this[2];
  v79.m64_i16[2] = (__int16)v77;
  v63 = _mm_cvtsi64_si32(_m_packuswb(v79, (__m64)qword_7E5EB0));
  v91.m64_i16[3] = 0;
  _m_empty();
  v81 = 0;
  if ( v17 <= 0 )
    return result;
  v104 = result & 0x80;
  v18 = 0;
  v79.m64_i16[3] = 0;
  v95 = 4 * v78;
  v55 = 0;
  do
  {
    v79.m64_i16[2] = 0;
    v79.m64_i32[0] = 0;
    if ( !v82 )
      goto LABEL_35;
    (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(
      dword_7E8E58,
      v80,
      &v64,
      *(_DWORD *)(this[6] + 312) + 416);
    v72 = 0.0;
    *(float *)&v78 = 0.0;
    v83 = 0.0;
    v19 = this[6];
    v20 = *(float ***)(v19 + 272);
    v21 = *(_DWORD *)(v19 + 268);
    if ( v21 <= 0 )
      goto LABEL_34;
    v22 = v83;
    v48 = v21;
    v23 = *(float *)&v78;
    v24 = v72;
    do
    {
      v25 = *v20;
      v26 = *(_DWORD *)*v20;
      if ( (v26 & 4) != 0 )
      {
        v27 = v25[16] - v66;
        v28 = v25[15] - v65;
        v29 = v25[14] - v64;
        v87 = v25[20];
        v72 = v29 * v29 + v28 * v28 + v27 * v27;
        if ( v87 * v87 <= v72 )
          goto LABEL_32;
        if ( (v26 & 0x100) == 0 )
        {
          v30 = 1.0 - sqrt(v72) * *((float *)v20 + 4);
          v22 = v22 + v30 * *((float *)v20 + 5);
          v23 = v23 + v30 * *((float *)v20 + 6);
          v24 = v24 + v30 * *((float *)v20 + 7);
          goto LABEL_32;
        }
LABEL_31:
        v22 = v22 + *((float *)v20 + 5);
        v23 = v23 + *((float *)v20 + 6);
        v24 = v24 + *((float *)v20 + 7);
        goto LABEL_32;
      }
      if ( (v26 & 8) != 0 )
      {
        v31 = 0;
        v32 = v25 + 22;
        do
        {
          if ( v66 * v32[1] + v64 * *(v32 - 1) + v65 * *v32 > v32[2] )
            break;
          ++v31;
          v32 += 4;
        }
        while ( v31 < 6 );
        if ( v31 == 6 )
          goto LABEL_31;
      }
LABEL_32:
      v20 += 14;
      --v48;
    }
    while ( v48 );
    v72 = v24;
    *(float *)&v78 = v23;
    v83 = v22;
LABEL_34:
    LOWORD(v101) = (__int16)v83;
    v79.m64_i16[0] = v101;
    LOWORD(v103) = (__int16)*(float *)&v78;
    v79.m64_i16[1] = v103;
    LOWORD(v97) = (__int16)v72;
    v79.m64_i16[2] = v97;
    v18 = v55;
    if ( (v101 & 0x8000u) == 0 || (v103 & 0x8000u) == 0 || (v97 & 0x8000u) == 0 )
    {
LABEL_35:
      v33 = v74;
      v34 = v71[0] * *v74 + v71[2] * v74[2] + v71[1] * v74[1];
      v56 = v34;
      if ( v34 >= 0.0 )
      {
        *(_DWORD *)(v18 + this[8] + 24) = v63;
      }
      else
      {
        v49 = v75 - v73[0] * v56;
        v93 = (__int16)v49;
        v86.m64_i16[0] = v93;
        v50 = v76 - v73[1] * v56;
        v99 = (__int16)v50;
        v86.m64_i16[1] = v99;
        v51 = v77 - v73[2] * v56;
        v94 = (__int16)v51;
        v86.m64_i16[2] = v94;
        *(_DWORD *)(v18 + this[8] + 24) = _mm_cvtsi64_si32(_m_packuswb(_m_paddsw(v86, v79), (__m64)qword_7E5EB0));
        _m_empty();
      }
      if ( v96 )
      {
        v35 = v70[0] * *v33 + v70[2] * v33[2] + v70[1] * v33[1];
        if ( v35 > 0.0 )
        {
          v57 = v35;
          v36 = sub_590110((int *)*(_DWORD *)(this[1] + 188), v57);
          v58 = v36;
          v52 = v36 * v88;
          v98 = (__int16)v52;
          v91.m64_i16[0] = v98;
          v53 = v58 * v84;
          v100 = (__int16)v53;
          v91.m64_i16[1] = v100;
          v54 = v58 * v85;
          v102 = (__int16)v54;
          v37 = this[8];
          v91.m64_i16[2] = v102;
          *(_DWORD *)(v18 + v37 + 28) = _mm_cvtsi64_si32(_m_packuswb(v91, (__m64)qword_7E5EB0));
          _m_empty();
          goto LABEL_43;
        }
        *(_DWORD *)(v18 + this[8] + 28) = 0;
      }
    }
    else
    {
      *(_DWORD *)(v55 + this[8] + 24) = v63;
      *(_DWORD *)(v55 + this[8] + 28) = 0;
LABEL_43:
      v33 = v74;
    }
    if ( v104 )
    {
      if ( !v82 )
      {
        (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(
          dword_7E8E58,
          v80,
          &v64,
          *(_DWORD *)(this[6] + 312) + 416);
        v33 = v74;
      }
      (**(void (__cdecl ***)(int, float *, float *, int))dword_7E8E58)(
        dword_7E8E58,
        v33,
        &v67,
        *(_DWORD *)(this[6] + 312) + 276);
      v38 = v64 + a2[9];
      v39 = this[8];
      v33 = v74;
      v40 = v65 + a2[10];
      v41 = v66 + a2[11];
      v90 = v41;
      v42 = 1.0 / sqrt(v41 * v90 + v40 * v40 + v38 * v38);
      v59 = v42;
      v89[0] = v42 * v38;
      v43 = v59 * v40;
      v44 = v59 * v90 * v69 + v68 * v43 + v67 * v89[0];
      v45 = v44 + v44;
      *(float *)(v18 + v39 + 40) = (v67 * v45 - v89[0]) * 0.5 + 0.5;
      *(float *)(v18 + this[8] + 44) = (v68 * v45 - v43) * 0.5 + 0.5;
    }
    v74 = &v33[v95 / 4u];
    result = v81 + 1;
    v18 += 64;
    v46 = v81 + 1 < this[2];
    v80 += v95;
    ++v81;
    v55 = v18;
  }
  while ( v46 );
  return result;
}
