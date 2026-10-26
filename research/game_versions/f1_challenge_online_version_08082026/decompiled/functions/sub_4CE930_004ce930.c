void __thiscall sub_4CE930(_DWORD *this, int a2, float a3, float *a4, float *a5, int a6)
{
  double v7; // st7
  double v8; // st6
  int v9; // edx
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  double v16; // st7
  double v17; // st6
  int v18; // edx
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int v24; // ecx
  double v25; // st7
  double v26; // st6
  int v27; // edx
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // ecx
  double v34; // st7
  double v35; // st6
  double v36; // st5
  double v37; // st7
  double v38; // st7
  float v39; // [esp+0h] [ebp-5Ch]
  float v40; // [esp+Ch] [ebp-50h]
  float v41; // [esp+Ch] [ebp-50h]
  float v42; // [esp+Ch] [ebp-50h]
  float v43; // [esp+Ch] [ebp-50h]
  int v44; // [esp+2Ch] [ebp-30h] BYREF
  float v45; // [esp+30h] [ebp-2Ch]
  float v46; // [esp+34h] [ebp-28h]
  int v47; // [esp+38h] [ebp-24h] BYREF
  float v48; // [esp+3Ch] [ebp-20h]
  float v49; // [esp+40h] [ebp-1Ch]
  int v50; // [esp+44h] [ebp-18h]
  float v51; // [esp+48h] [ebp-14h]
  float v52; // [esp+4Ch] [ebp-10h]
  float v53; // [esp+58h] [ebp-4h]

  if ( byte_7CF9BC )
  {
    if ( byte_7CF9EC )
      a6 = 104;
  }
  else if ( !byte_7CF9EC )
  {
    a6 = -1;
  }
  if ( *(float *)a2 != 0.0 && this[8] && (dword_7CF8A8 > 2 || dword_8AB6E4 == 2 || !(dword_7C5698 % 20)) )
  {
    if ( fabs(a3 - *(float *)(a2 + 4)) > 0.15000001
      || (v8 = a4[2] - *(float *)(a2 + 16), v7 = *a4 - *(float *)(a2 + 8), v8 * v8 + v7 * v7 > 1.0) )
    {
      *(float *)(a2 + 8) = *a4;
      *(float *)(a2 + 12) = a4[1];
      v9 = *((_DWORD *)a4 + 2);
      *(float *)(a2 + 4) = a3;
      *(_DWORD *)(a2 + 16) = v9;
      v10 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v11 = v10 * 0.25 + *a4;
      v45 = a4[1];
      *(float *)&v44 = v11;
      v12 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v46 = v12 * 0.25 + a4[2];
      *(float *)&v50 = *a5 * 0.1;
      v13 = a5[1];
      v47 = v50;
      v51 = v13 * 0.1;
      v14 = a5[2];
      v48 = v51;
      v40 = *(float *)a2;
      v52 = v14 * 0.1;
      v49 = v52;
      v15 = this[8];
      v48 = v51 + 0.25;
      sub_4CBC50(v15, a3, (float *)&v44, (float *)&v47, v40, 0, 0, a6);
    }
  }
  if ( *(float *)(a2 + 20) != 0.0 && this[9] && (dword_7CF8A8 > 2 || dword_8AB6E4 == 2 || !(dword_7C5698 % 20)) )
  {
    if ( fabs(a3 - *(float *)(a2 + 24)) > 0.15000001
      || (v17 = a4[2] - *(float *)(a2 + 36), v16 = *a4 - *(float *)(a2 + 28), v17 * v17 + v16 * v16 > 1.0) )
    {
      *(float *)(a2 + 28) = *a4;
      *(float *)(a2 + 32) = a4[1];
      v18 = *((_DWORD *)a4 + 2);
      *(float *)(a2 + 24) = a3;
      *(_DWORD *)(a2 + 36) = v18;
      v19 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v20 = v19 * 0.25 + *a4;
      v45 = a4[1];
      *(float *)&v44 = v20;
      v21 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v46 = v21 * 0.25 + a4[2];
      *(float *)&v50 = *a5 * 0.1;
      v22 = a5[1];
      v47 = v50;
      v51 = v22 * 0.1;
      v23 = a5[2];
      v48 = v51;
      v41 = *(float *)(a2 + 20);
      v52 = v23 * 0.1;
      v49 = v52;
      v24 = this[9];
      v48 = v51 + 0.25;
      sub_4CBC50(v24, a3, (float *)&v44, (float *)&v47, v41, 0, 0, a6);
    }
  }
  if ( *(float *)(a2 + 40) != 0.0 && this[10] && (dword_7CF8A8 > 1 || dword_8AB6E4 == 2 || !(dword_7C5698 % 20)) )
  {
    if ( fabs(a3 - *(float *)(a2 + 44)) > 0.059999999
      || (v26 = a4[2] - *(float *)(a2 + 56), v25 = *a4 - *(float *)(a2 + 48), v26 * v26 + v25 * v25 > 0.16000001) )
    {
      *(float *)(a2 + 48) = *a4;
      *(float *)(a2 + 52) = a4[1];
      v27 = *((_DWORD *)a4 + 2);
      *(float *)(a2 + 44) = a3;
      *(_DWORD *)(a2 + 56) = v27;
      v28 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v29 = v28 * 0.15000001 + *a4;
      v45 = a4[1];
      *(float *)&v44 = v29;
      v30 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      v46 = v30 * 0.15000001 + a4[2];
      *(float *)&v50 = *a5 * 0.1;
      v31 = a5[1];
      v47 = v50;
      v51 = v31 * 0.1;
      v32 = a5[2];
      v48 = v51;
      v42 = *(float *)(a2 + 40);
      v52 = v32 * 0.1;
      v49 = v52;
      v33 = this[10];
      v48 = v51 + 0.25;
      sub_4CBC50(v33, a3, (float *)&v44, (float *)&v47, v42, 0, 0, a6);
      if ( dword_7CF8A8 > 2 )
      {
        v34 = *a5 * 0.0125;
        v35 = a5[1] * 0.0125;
        v53 = a5[2] * 0.0125;
        *(float *)&v50 = *a4 - v34;
        v36 = a4[1];
        v44 = v50;
        v51 = v36 - v35;
        v45 = v51;
        v52 = a4[2] - v53;
        v46 = v52;
        v37 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.15000001;
        *(float *)&v44 = v37 + *(float *)&v50;
        v38 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v43 = *(float *)(a2 + 40);
        v46 = v38 * 0.15000001 + v52;
        v39 = a3 - 0.0125;
        sub_4CBC50(this[10], v39, (float *)&v44, (float *)&v47, v43, 0, 0, a6);
      }
    }
  }
}
