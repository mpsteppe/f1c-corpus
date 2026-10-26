int __usercall sub_64C73C@<eax>(_DWORD *a1@<ecx>, unsigned int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // edx
  int v10; // esi
  float *v11; // eax
  int v12; // esi
  int v13; // esi
  char *v14; // eax
  char *v15; // eax
  _DWORD *v16; // ecx
  char *v17; // esi
  char *v18; // edx
  int v19; // esi
  char *v20; // eax
  char *v21; // edi
  int v22; // esi
  int v23; // eax
  int v24; // edi
  float *v25; // ecx
  float *v26; // edx
  double v27; // st6
  double v28; // st5
  double v29; // st4
  float *v30; // ecx
  double v31; // st6
  double v32; // st5
  double v33; // st4
  float *v34; // ecx
  double v35; // st6
  double v36; // st5
  float *v37; // ecx
  double v38; // st5
  float *v39; // ecx
  double v40; // st6
  double v41; // st5
  double v42; // st4
  float *v43; // ecx
  float *v44; // eax
  float *v45; // edi
  float v48; // [esp+4h] [ebp-B4h]
  float v49; // [esp+10h] [ebp-A8h]
  float v50; // [esp+14h] [ebp-A4h]
  float v51; // [esp+20h] [ebp-98h]
  float v52; // [esp+2Ch] [ebp-8Ch]
  float v53; // [esp+30h] [ebp-88h]
  float v54; // [esp+3Ch] [ebp-7Ch]
  float v55; // [esp+40h] [ebp-78h]
  float v56; // [esp+44h] [ebp-74h]
  float v57; // [esp+48h] [ebp-70h]
  float v58; // [esp+54h] [ebp-64h]
  float v59; // [esp+58h] [ebp-60h]
  float v60; // [esp+5Ch] [ebp-5Ch]
  float v61; // [esp+60h] [ebp-58h]
  float v62; // [esp+68h] [ebp-50h]
  float v63; // [esp+6Ch] [ebp-4Ch]
  float v64; // [esp+70h] [ebp-48h]
  float v65; // [esp+74h] [ebp-44h]
  float v66; // [esp+78h] [ebp-40h]
  float v67; // [esp+7Ch] [ebp-3Ch]
  char *v68; // [esp+84h] [ebp-34h]
  char *v69; // [esp+88h] [ebp-30h]
  char *v70; // [esp+8Ch] [ebp-2Ch]
  float *v71; // [esp+90h] [ebp-28h]
  char *v72; // [esp+94h] [ebp-24h]
  char *v73; // [esp+98h] [ebp-20h]
  unsigned int v74; // [esp+9Ch] [ebp-1Ch]
  char *v75; // [esp+A0h] [ebp-18h]
  unsigned int v76; // [esp+A4h] [ebp-14h]
  float *v77; // [esp+A8h] [ebp-10h]
  float *v78; // [esp+ACh] [ebp-Ch]
  char *v79; // [esp+ACh] [ebp-Ch]
  char *v80; // [esp+ACh] [ebp-Ch]
  char *v81; // [esp+ACh] [ebp-Ch]
  unsigned int v82; // [esp+B0h] [ebp-8h]
  char *Block; // [esp+B4h] [ebp-4h]

  if ( *((_BYTE *)a1 + 8) != 5 )
    return -2147467259;
  v5 = (_DWORD *)*a1;
  v6 = *(_DWORD *)(*a1 + 104);
  v7 = (_DWORD *)a1[1];
  v8 = v7[26];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[27];
  if ( v9 != v5[27] >> 1 && (v9 != 1 || v5[27] != 1) )
    return -2147467259;
  if ( v7[28] != v5[28] >> 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[26] &= ~1u;
    *(_DWORD *)(*a1 + 116) -= *(_DWORD *)(*a1 + 120);
  }
  if ( *(_DWORD *)(*a1 + 108) > 1u )
    *(_DWORD *)(*a1 + 108) &= ~1u;
  if ( *(_DWORD *)(*a1 + 112) > 1u )
    *(_DWORD *)(*a1 + 112) &= ~1u;
  v10 = *(_DWORD *)(a1[1] + 104);
  v11 = (float *)operator new(16 * v10);
  v78 = v11;
  if ( v11 )
  {
    sub_41D1B0((int)v11, 16, v10, (int)sub_681563);
    v77 = v78;
  }
  else
  {
    v77 = 0;
  }
  if ( !v77 )
    return -2147024882;
  v12 = *(_DWORD *)(*a1 + 104);
  if ( *(_DWORD *)(*a1 + 108) == 1 )
  {
    v13 = 2 * v12;
    v14 = (char *)operator new(16 * v13);
    v79 = v14;
    if ( v14 )
    {
      sub_41D1B0((int)v14, 16, v13, (int)sub_681563);
      Block = v79;
    }
    else
    {
      Block = 0;
    }
    v15 = Block;
    v16 = (_DWORD *)(*a1 + 104);
    v17 = &Block[16 * *v16];
    v18 = v17;
    v72 = v17;
    v75 = Block;
    v73 = v17;
  }
  else
  {
    v19 = 4 * v12;
    v20 = (char *)operator new(16 * v19);
    v80 = v20;
    if ( v20 )
    {
      sub_41D1B0((int)v20, 16, v19, (int)sub_681563);
      Block = v80;
    }
    else
    {
      Block = 0;
    }
    v16 = (_DWORD *)(*a1 + 104);
    v72 = &Block[16 * *v16];
    v17 = v72;
    v75 = &Block[32 * *v16];
    v73 = &Block[48 * *v16];
    v15 = v75;
    v18 = v73;
  }
  v21 = Block;
  if ( Block )
  {
    if ( *v16 == 1 )
    {
      v69 = Block;
      v70 = v17;
    }
    else
    {
      v69 = Block + 16;
      v15 += 16;
      v70 = v17 + 16;
      v18 += 16;
    }
    v76 = 0;
    v68 = v15;
    v23 = a1[1];
    v81 = v18;
    if ( *(_DWORD *)(v23 + 112) )
    {
      do
      {
        v82 = 0;
        if ( *(_DWORD *)(v23 + 108) )
        {
          do
          {
            v24 = 2 * v76;
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *, unsigned int, float *))(*(_DWORD *)*a1 + 4))(
              *a1,
              2 * v82,
              2 * v76,
              Block,
              a2,
              a3);
            if ( v17 != Block )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(
                *a1,
                2 * v82,
                v24 + 1,
                v17);
            if ( v75 != Block )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(
                *a1,
                2 * v82 + 1,
                v24,
                v75);
            if ( v73 != v17 && v73 != v75 )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(*(_DWORD *)*a1 + 4))(
                *a1,
                2 * v82 + 1,
                v24 + 1,
                v73);
            v74 = 0;
            if ( *(_DWORD *)(a1[1] + 104) )
            {
              v71 = v77;
              do
              {
                v25 = (float *)&v69[32 * v74];
                v26 = (float *)&Block[32 * v74];
                v27 = *v25 + *v26;
                v28 = v25[1] + v26[1];
                v54 = v25[2] + v26[2];
                v29 = v25[3];
                v30 = (float *)&v17[32 * v74];
                v55 = v29 + v26[3];
                v50 = v27 + *v30;
                v31 = v28 + v30[1];
                v32 = v54 + v30[2];
                v33 = v55 + v30[3];
                v34 = (float *)&v70[32 * v74];
                v51 = v33;
                v56 = v50 + *v34;
                v57 = v31 + v34[1];
                v35 = v32 + v34[2];
                v36 = v51 + v34[3];
                v37 = (float *)&v75[32 * v74];
                v65 = v56 + *v37;
                v66 = v57 + v37[1];
                v67 = v35 + v37[2];
                v38 = v36 + v37[3];
                v39 = (float *)&v68[32 * v74];
                v40 = v38;
                v41 = v65 + *v39;
                v62 = v66 + v39[1];
                v63 = v67 + v39[2];
                v42 = v40 + v39[3];
                v43 = (float *)&v73[32 * v74];
                v64 = v42;
                v52 = v63 + v43[2];
                v44 = (float *)&v81[32 * v74];
                v53 = v64 + v43[3];
                v45 = v71;
                ++v74;
                v48 = v41 + *v43 + *v44;
                v71 += 4;
                v49 = v53 + v44[3];
                v58 = v48 * 0.125;
                v59 = (v62 + v43[1] + v44[1]) * 0.125;
                v60 = (v52 + v44[2]) * 0.125;
                v61 = v49 * 0.125;
                *v45++ = v58;
                *v45++ = v59;
                *v45 = v60;
                v45[1] = v61;
                v17 = v72;
              }
              while ( v74 < *(_DWORD *)(a1[1] + 104) );
            }
            a3 = v77;
            a2 = v76;
            (*(void (__thiscall **)(_DWORD, unsigned int))(*(_DWORD *)a1[1] + 8))(a1[1], v82++);
          }
          while ( v82 < *(_DWORD *)(a1[1] + 108) );
        }
        ++v76;
        v23 = a1[1];
      }
      while ( v76 < *(_DWORD *)(v23 + 112) );
      v21 = Block;
    }
    j__free(v21);
    v22 = 0;
  }
  else
  {
    v22 = -2147024882;
  }
  j__free(v77);
  return v22;
}
