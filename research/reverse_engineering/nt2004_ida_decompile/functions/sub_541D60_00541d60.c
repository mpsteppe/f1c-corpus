int __usercall sub_541D60@<eax>(_DWORD *a1@<ecx>, unsigned int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // ecx
  unsigned int v6; // eax
  _DWORD *v7; // edx
  int v8; // esi
  int v9; // esi
  _DWORD *v10; // ecx
  _DWORD *v11; // ecx
  int v12; // esi
  float *v13; // eax
  int v14; // esi
  int v15; // esi
  char *v16; // eax
  char *v17; // ecx
  int v18; // eax
  char *v19; // esi
  char *v20; // edx
  int v21; // esi
  char *v22; // eax
  char *v23; // edx
  int v24; // esi
  int v25; // eax
  int v26; // edi
  float *v27; // ecx
  float *v28; // edx
  double v29; // st6
  double v30; // st5
  double v31; // st4
  float *v32; // ecx
  double v33; // st6
  double v34; // st5
  double v35; // st4
  float *v36; // ecx
  double v37; // st6
  double v38; // st5
  float *v39; // ecx
  double v40; // st5
  float *v41; // ecx
  double v42; // st6
  double v43; // st5
  float *v44; // ecx
  float *v45; // edi
  float *v46; // eax
  float v49; // [esp+4h] [ebp-C4h]
  float v50; // [esp+10h] [ebp-B8h]
  float v51; // [esp+14h] [ebp-B4h]
  float v52; // [esp+20h] [ebp-A8h]
  float v53; // [esp+2Ch] [ebp-9Ch]
  float v54; // [esp+30h] [ebp-98h]
  float v55; // [esp+3Ch] [ebp-8Ch]
  float v56; // [esp+40h] [ebp-88h]
  float v57; // [esp+44h] [ebp-84h]
  float v58; // [esp+48h] [ebp-80h]
  float v59; // [esp+54h] [ebp-74h]
  float v60; // [esp+58h] [ebp-70h]
  float v61; // [esp+5Ch] [ebp-6Ch]
  float v62; // [esp+60h] [ebp-68h]
  float v63; // [esp+68h] [ebp-60h]
  float v64; // [esp+6Ch] [ebp-5Ch]
  float v65; // [esp+70h] [ebp-58h]
  float v66; // [esp+74h] [ebp-54h]
  float v67; // [esp+78h] [ebp-50h]
  float v68; // [esp+7Ch] [ebp-4Ch]
  char *v69; // [esp+84h] [ebp-44h]
  char *v70; // [esp+88h] [ebp-40h]
  char *v71; // [esp+8Ch] [ebp-3Ch]
  char *v72; // [esp+90h] [ebp-38h]
  float *v73; // [esp+94h] [ebp-34h]
  char *v74; // [esp+98h] [ebp-30h]
  unsigned int v75; // [esp+9Ch] [ebp-2Ch]
  char *v76; // [esp+A0h] [ebp-28h]
  unsigned int v77; // [esp+A4h] [ebp-24h]
  float *v78; // [esp+A8h] [ebp-20h]
  char *v79; // [esp+ACh] [ebp-1Ch]
  char *v80; // [esp+B0h] [ebp-18h]
  float *v81; // [esp+B4h] [ebp-14h]
  char *v82; // [esp+B4h] [ebp-14h]
  char *v83; // [esp+B4h] [ebp-14h]
  char *i; // [esp+B4h] [ebp-14h]
  unsigned int v85; // [esp+B8h] [ebp-10h]

  if ( *((_BYTE *)a1 + 8) != 5 )
    return -2147467259;
  v5 = (_DWORD *)*a1;
  v6 = *(_DWORD *)(*a1 + 4184);
  v7 = (_DWORD *)a1[1];
  v8 = v7[1046];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[1047];
  if ( v9 != v5[1047] >> 1 && (v9 != 1 || v5[1047] != 1) )
    return -2147467259;
  if ( v7[1048] != v5[1048] >> 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[1046] = v6 & 0xFFFFFFFE;
    *(_DWORD *)(*a1 + 4196) -= *(_DWORD *)(*a1 + 4200);
  }
  v10 = (_DWORD *)(*a1 + 4188);
  if ( *v10 > 1u )
    *v10 &= ~1u;
  v11 = (_DWORD *)(*a1 + 4192);
  if ( *v11 > 1u )
    *v11 &= ~1u;
  v12 = *(_DWORD *)(a1[1] + 4184);
  v13 = (float *)operator new(16 * v12);
  v81 = v13;
  if ( v13 )
  {
    sub_53D688((int)v13, 16, v12, (int (__thiscall *)(int))sub_53D5B2);
    v78 = v81;
  }
  else
  {
    v78 = 0;
  }
  if ( !v78 )
    return -2147024882;
  v14 = *(_DWORD *)(*a1 + 4184);
  if ( *(_DWORD *)(*a1 + 4188) == 1 )
  {
    v15 = 2 * v14;
    v16 = (char *)operator new(16 * v15);
    v82 = v16;
    if ( v16 )
    {
      sub_53D688((int)v16, 16, v15, (int (__thiscall *)(int))sub_53D5B2);
      v17 = v82;
    }
    else
    {
      v17 = 0;
    }
    v18 = *(_DWORD *)(*a1 + 4184);
    v19 = &v17[16 * v18];
    v20 = v19;
    v72 = v17;
    v80 = v17;
    v74 = v19;
    v79 = v17;
    v76 = v19;
  }
  else
  {
    v21 = 4 * v14;
    v22 = (char *)operator new(16 * v21);
    v83 = v22;
    if ( v22 )
    {
      sub_53D688((int)v22, 16, v21, (int (__thiscall *)(int))sub_53D5B2);
      v23 = v83;
    }
    else
    {
      v23 = 0;
    }
    v18 = *(_DWORD *)(*a1 + 4184);
    v74 = &v23[16 * v18];
    v19 = v74;
    v79 = &v23[32 * v18];
    v76 = &v23[48 * v18];
    v17 = v79;
    v72 = v23;
    v80 = v23;
    v20 = v76;
  }
  if ( v72 )
  {
    if ( v18 == 1 )
    {
      v71 = v80;
      v70 = v19;
    }
    else
    {
      v71 = v80 + 16;
      v17 += 16;
      v70 = v19 + 16;
      v20 += 16;
    }
    v25 = a1[1];
    v77 = 0;
    v69 = v17;
    for ( i = v20; v77 < *(_DWORD *)(v25 + 4192); v25 = a1[1] )
    {
      v85 = 0;
      if ( *(_DWORD *)(v25 + 4188) )
      {
        do
        {
          v26 = 2 * v77;
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *, unsigned int, float *))(*(_DWORD *)*a1 + 4))(
            *a1,
            2 * v85,
            2 * v77,
            v80,
            a2,
            a3);
          if ( v19 != v80 )
            (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(*a1, 2 * v85, v26 + 1, v19);
          if ( v79 != v80 )
            (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(*a1, 2 * v85 + 1, v26, v79);
          if ( v76 != v19 && v76 != v79 )
            (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(
              *a1,
              2 * v85 + 1,
              v26 + 1,
              v76);
          v75 = 0;
          if ( *(_DWORD *)(a1[1] + 4184) )
          {
            v73 = v78;
            do
            {
              v27 = (float *)&v71[32 * v75];
              v28 = (float *)&v80[32 * v75];
              v29 = *v27 + *v28;
              v30 = v27[1] + v28[1];
              v55 = v27[2] + v28[2];
              v31 = v27[3];
              v32 = (float *)&v19[32 * v75];
              v56 = v31 + v28[3];
              v51 = v29 + *v32;
              v33 = v30 + v32[1];
              v34 = v55 + v32[2];
              v35 = v56 + v32[3];
              v36 = (float *)&v70[32 * v75];
              v52 = v35;
              v57 = v51 + *v36;
              v58 = v33 + v36[1];
              v37 = v34 + v36[2];
              v38 = v52 + v36[3];
              v39 = (float *)&v79[32 * v75];
              v66 = v57 + *v39;
              v67 = v58 + v39[1];
              v68 = v37 + v39[2];
              v40 = v38 + v39[3];
              v41 = (float *)&v69[32 * v75];
              v42 = v40;
              v43 = v66 + *v41;
              v63 = v67 + v41[1];
              v64 = v68 + v41[2];
              v65 = v42 + v41[3];
              v44 = (float *)&v76[32 * v75];
              v45 = v73;
              v73 += 4;
              v53 = v64 + v44[2];
              v46 = (float *)&i[32 * v75++];
              v54 = v65 + v44[3];
              v49 = v43 + *v44 + *v46;
              v50 = v54 + v46[3];
              v59 = v49 * 0.125;
              v60 = (v63 + v44[1] + v46[1]) * 0.125;
              v61 = (v53 + v46[2]) * 0.125;
              v62 = v50 * 0.125;
              *v45++ = v59;
              *v45++ = v60;
              *v45 = v61;
              v45[1] = v62;
              v19 = v74;
            }
            while ( v75 < *(_DWORD *)(a1[1] + 4184) );
          }
          a3 = v78;
          a2 = v77;
          (*(void (__thiscall **)(_DWORD, unsigned int))(*(_DWORD *)a1[1] + 8))(a1[1], v85++);
        }
        while ( v85 < *(_DWORD *)(a1[1] + 4188) );
      }
      ++v77;
    }
    sub_5BE8AE();
    v24 = 0;
  }
  else
  {
    v24 = -2147024882;
  }
  sub_5BE8AE();
  return v24;
}
