char __thiscall sub_4FF8F0(void *this, int a2, int a3, int a4, int a5)
{
  double v6; // st7
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // edx
  __int16 v10; // ax
  double v11; // st7
  __int16 v12; // ax
  double v13; // st7
  int v14; // eax
  char *v15; // ebp
  double v16; // st7
  __int16 *v17; // ecx
  double v18; // st6
  float v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  char v24; // al
  int v25; // edx
  __int16 v26; // ax
  float v28; // [esp+0h] [ebp-B0h]
  float v29; // [esp+0h] [ebp-B0h]
  float v30; // [esp+0h] [ebp-B0h]
  float v31; // [esp+0h] [ebp-B0h]
  float v32; // [esp+14h] [ebp-9Ch]
  float v33; // [esp+14h] [ebp-9Ch]
  int v34; // [esp+14h] [ebp-9Ch]
  float v35; // [esp+14h] [ebp-9Ch]
  float v36; // [esp+18h] [ebp-98h]
  float v37; // [esp+1Ch] [ebp-94h]
  int v38; // [esp+20h] [ebp-90h]
  int v39; // [esp+20h] [ebp-90h]
  char *v40; // [esp+20h] [ebp-90h]
  __int16 *v41; // [esp+24h] [ebp-8Ch]
  float v42; // [esp+24h] [ebp-8Ch]
  float v43; // [esp+2Ch] [ebp-84h]
  _DWORD *v44; // [esp+2Ch] [ebp-84h]
  float v45; // [esp+30h] [ebp-80h] BYREF
  float v46; // [esp+34h] [ebp-7Ch]
  float v47; // [esp+38h] [ebp-78h]
  int i; // [esp+3Ch] [ebp-74h]
  int v49; // [esp+40h] [ebp-70h]
  int v50[3]; // [esp+44h] [ebp-6Ch] BYREF
  float v51[3]; // [esp+50h] [ebp-60h] BYREF
  int v52[3]; // [esp+5Ch] [ebp-54h] BYREF
  float v53[3]; // [esp+68h] [ebp-48h] BYREF
  int v54[3]; // [esp+74h] [ebp-3Ch] BYREF
  int v55[4]; // [esp+80h] [ebp-30h] BYREF
  int v56[4]; // [esp+90h] [ebp-20h] BYREF
  char v57[16]; // [esp+A0h] [ebp-10h] BYREF

  if ( *(float *)&a2 >= (double)*(float *)(a3 + 4) )
  {
    if ( *(float *)&a2 > (double)*(float *)(a4 + 4) )
      a2 = *(int *)(a4 + 4);
  }
  else
  {
    a2 = *(int *)(a3 + 4);
  }
  ProgressBarEventEncode(
    (_DWORD *)a5,
    *(_DWORD *)a3 >> 29,
    (*(_DWORD *)a3 >> 18) & 0x3F,
    (*(_DWORD *)a3 >> 8) & 0x3FF,
    (unsigned __int8)*(_DWORD *)a3,
    a2,
    0);
  v6 = *(float *)(a4 + 4) - *(float *)(a3 + 4);
  v43 = v6;
  if ( v6 > 5.0 )
  {
    if ( (unsigned __int8)FieldCompareConstant(this) )
    {
LABEL_7:
      v36 = 0.0;
      v37 = 1.0;
      goto LABEL_8;
    }
LABEL_11:
    v36 = 1.0;
    v37 = 0.0;
    goto LABEL_8;
  }
  v16 = *(float *)(a4 + 8) - *(float *)(a3 + 8);
  v17 = (__int16 *)(a3 + 8);
  v18 = *(float *)(a4 + 16) - *(float *)(a3 + 16);
  v42 = 1.0 / v43;
  if ( (v18 * v18 + v16 * v16) * v42 >= 14981.386 )
    goto LABEL_11;
  if ( v43 == 0.0 )
    goto LABEL_7;
  v36 = (*(float *)&a2 - *(float *)(a3 + 4)) * v42;
  v37 = 1.0 - v36;
  if ( v37 > 0.0 && v37 < 1.0 )
  {
    v19 = *(float *)v17;
    v51[1] = *(float *)(a3 + 12);
    v51[0] = v19;
    v51[2] = *(float *)(a3 + 16);
    ShortVectorToFloatWithScale(v17, v53);
    v20 = *(_DWORD *)(a4 + 12);
    v21 = *(_DWORD *)(a4 + 16);
    v52[0] = *(_DWORD *)(a4 + 8);
    v52[1] = v20;
    v52[2] = v21;
    ShortVectorToFloatWithScale((__int16 *)(a4 + 8), (float *)v54);
    F_3DHermiteSplineInterpolation(v51, v53, (float *)v52, (float *)v54, v36, v50);
    v22 = v50[1];
    v7 = (_DWORD *)(a5 + 8);
    *(_DWORD *)(a5 + 8) = v50[0];
    v23 = v50[2];
    *(_DWORD *)(a5 + 12) = v22;
    *(_DWORD *)(a5 + 16) = v23;
    goto LABEL_9;
  }
LABEL_8:
  v7 = (_DWORD *)(a5 + 8);
  *(float *)(a5 + 8) = v37 * *(float *)(a3 + 8) + v36 * *(float *)(a4 + 8);
  *(float *)(a5 + 12) = v37 * *(float *)(a3 + 12) + v36 * *(float *)(a4 + 12);
  *(float *)(a5 + 16) = v37 * *(float *)(a3 + 16) + v36 * *(float *)(a4 + 16);
LABEL_9:
  v8 = *(__int16 *)(a3 + 24);
  v44 = v7;
  v38 = *(__int16 *)(a3 + 22);
  v45 = (double)*(__int16 *)(a3 + 20) * 0.00048828125;
  v46 = (double)v38 * 0.00048828125;
  v47 = (double)v8 * 0.00048828125;
  QuaternionFromEulerAngles(&v45, v56);
  v9 = *(__int16 *)(a4 + 24);
  v39 = *(__int16 *)(a4 + 22);
  v45 = (double)*(__int16 *)(a4 + 20) * 0.00048828125;
  v46 = (double)v39 * 0.00048828125;
  v47 = (double)v9 * 0.00048828125;
  QuaternionFromEulerAngles(&v45, v55);
  sub_567580((int)v56, (int)v55, v36);
  sub_567010(v57, &v45);
  v10 = CRTFtol(v45 * 2048.0);
  v11 = v46 * 2048.0;
  *(_WORD *)(a5 + 20) = v10;
  v12 = CRTFtol(v11);
  v13 = v47 * 2048.0;
  *(_WORD *)(a5 + 22) = v12;
  *(_WORD *)(a5 + 24) = CRTFtol(v13);
  v41 = (__int16 *)(a4 + 30);
  v49 = a5 - a4;
  v14 = a3 - a4;
  v15 = (char *)(a4 + 26);
  v40 = (char *)(a4 + 26);
  for ( i = a3 - a4; ; v14 = i )
  {
    v24 = CRTFtol((double)v15[v14] * v37 + (double)*v15 * v36 + 0.5);
    v25 = i;
    v40[v49] = v24;
    v26 = CRTFtol((double)*(__int16 *)((char *)v41 + v25) * v37 + (double)*v41 * v36);
    *(__int16 *)((char *)v41 + v49) = v26;
    v15 = v40 + 1;
    ++v41;
    v40 = v15;
    if ( (int)&v15[-26 - a4] >= 4 )
      break;
  }
  *(_WORD *)(a5 + 38) = CRTFtol((double)*(__int16 *)(a3 + 38) * v37 + (double)*(__int16 *)(a4 + 38) * v36);
  *(_WORD *)(a5 + 40) = CRTFtol((double)*(__int16 *)(a3 + 40) * v37 + (double)*(__int16 *)(a4 + 40) * v36);
  *(_WORD *)(a5 + 42) = CRTFtol((double)*(__int16 *)(a3 + 42) * v37 + (double)*(__int16 *)(a4 + 42) * v36);
  *(_WORD *)(a5 + 48) = CRTFtol((double)*(__int16 *)(a3 + 48) * v37 + (double)*(__int16 *)(a4 + 48) * v36);
  *(_WORD *)(a5 + 50) = CRTFtol((double)*(__int16 *)(a3 + 50) * v37 + (double)*(__int16 *)(a4 + 50) * v36);
  *(_BYTE *)(a5 + 44) = CRTFtol((double)*(char *)(a3 + 44) * v37 + (double)*(char *)(a4 + 44) * v36);
  *(_WORD *)(a5 + 46) = (char)CRTFtol((double)*(__int16 *)(a3 + 46) * v37 + (double)*(__int16 *)(a4 + 46) * v36);
  *(_BYTE *)(a5 + 45) = CRTFtol((double)*(char *)(a3 + 45) * v37 + (double)*(char *)(a4 + 45) * v36);
  if ( v36 <= 0.0 )
  {
    *(_DWORD *)(a5 + 52) = *(_DWORD *)(a3 + 52);
    *(_DWORD *)(a5 + 56) = *(_DWORD *)(a3 + 56);
  }
  else
  {
    *(_DWORD *)(a5 + 52) = *(_DWORD *)(a4 + 52);
    *(_DWORD *)(a5 + 56) = *(_DWORD *)(a4 + 56);
    if ( v36 < 1.0 )
    {
      v32 = BitfieldToFloatConversion((_DWORD *)(a3 + 8)) * v37;
      v28 = BitfieldToFloatConversion((_DWORD *)(a4 + 8)) * v36 + v32;
      FloatToBitfieldEncoder(v44, v28);
      v33 = ShortComputation_29f0((_DWORD *)(a3 + 8)) * v37;
      v29 = ShortComputation_29f0((_DWORD *)(a4 + 8)) * v36 + v33;
      BitfieldInsert(v44, v29);
      v34 = BitfieldExtract((_DWORD *)(a3 + 8));
      if ( v34 == BitfieldExtract((_DWORD *)(a4 + 8)) )
      {
        v35 = BitfieldExtractScale((_DWORD *)(a3 + 8)) * v37;
        v30 = BitfieldExtractScale((_DWORD *)(a4 + 8)) * v36 + v35;
        FloatToBitfieldPack(v44, v30);
        return 1;
      }
      if ( (*(float *)(a3 + 4) + *(float *)(a4 + 4)) * 0.5 > *(float *)&a2 )
      {
        v31 = BitfieldExtractScale((_DWORD *)(a3 + 8));
        FloatToBitfieldPack(v44, v31);
        return 1;
      }
    }
  }
  return 1;
}
