int __thiscall sub_4AE490(int this)
{
  int v2; // edx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  float *v6; // ecx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int result; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  float v21; // [esp-8h] [ebp-Ch]
  float v22; // [esp-8h] [ebp-Ch]
  int v23; // [esp-4h] [ebp-8h]
  int v24; // [esp-4h] [ebp-8h]
  int v25; // [esp-4h] [ebp-8h]
  int v26; // [esp-4h] [ebp-8h]
  float v27; // [esp-4h] [ebp-8h]
  int v28; // [esp-4h] [ebp-8h]
  int v29; // [esp-4h] [ebp-8h]
  int v30; // [esp-4h] [ebp-8h]
  int v31; // [esp-4h] [ebp-8h]
  float v32; // [esp-4h] [ebp-8h]
  int v33; // [esp-4h] [ebp-8h]
  int v34; // [esp-4h] [ebp-8h]
  int v35; // [esp-4h] [ebp-8h]
  int v36; // [esp-4h] [ebp-8h]
  int v37; // [esp-4h] [ebp-8h]
  int v38; // [esp-4h] [ebp-8h]

  if ( *(_DWORD *)(this + 6856) == 1 )
  {
    v7 = *(_DWORD *)(this + 2840);
    v28 = *(_DWORD *)(this + 2844);
    *(_DWORD *)(this + 2832) = 0;
    ClampByRange((int *)(this + 2832), v7, v28);
    v29 = *(_DWORD *)(this + 2880);
    v8 = *(_DWORD *)(this + 2876);
    *(_DWORD *)(this + 2868) = 0;
    ClampByRange((int *)(this + 2868), v8, v29);
    v9 = *(_DWORD *)(this + 2912);
    v30 = *(_DWORD *)(this + 2916);
    *(_DWORD *)(this + 2904) = 0;
    ClampByRange((int *)(this + 2904), v9, v30);
    v31 = *(_DWORD *)(this + 7228);
    v10 = *(_DWORD *)(this + 7224);
    *(_DWORD *)(this + 7216) = 1;
    ClampByRange((int *)(this + 7216), v10, v31);
    v32 = *(float *)(this + 9044);
    v22 = *(float *)(this + 9040);
    *(_DWORD *)(this + 9032) = 1028443341;
    FloatClamp((float *)(this + 9032), v22, v32);
    v6 = (float *)(this + 9068);
    *(_DWORD *)(this + 9068) = 1028443341;
  }
  else
  {
    if ( *(_DWORD *)(this + 6856) != 2 )
      goto LABEL_6;
    v2 = *(_DWORD *)(this + 2840);
    v23 = *(_DWORD *)(this + 2844);
    *(_DWORD *)(this + 2832) = 1;
    ClampByRange((int *)(this + 2832), v2, v23);
    v24 = *(_DWORD *)(this + 2880);
    v3 = *(_DWORD *)(this + 2876);
    *(_DWORD *)(this + 2868) = 1;
    ClampByRange((int *)(this + 2868), v3, v24);
    v4 = *(_DWORD *)(this + 2912);
    v25 = *(_DWORD *)(this + 2916);
    *(_DWORD *)(this + 2904) = 1;
    ClampByRange((int *)(this + 2904), v4, v25);
    v26 = *(_DWORD *)(this + 7228);
    v5 = *(_DWORD *)(this + 7224);
    *(_DWORD *)(this + 7216) = 0;
    ClampByRange((int *)(this + 7216), v5, v26);
    v27 = *(float *)(this + 9044);
    v21 = *(float *)(this + 9040);
    *(_DWORD *)(this + 9032) = 1056964608;
    FloatClamp((float *)(this + 9032), v21, v27);
    v6 = (float *)(this + 9068);
    *(_DWORD *)(this + 9068) = 1056964608;
  }
  FloatClamp(v6, *(float *)(this + 9076), *(float *)(this + 9080));
LABEL_6:
  result = *(_DWORD *)(this + 6856);
  if ( result )
  {
    v12 = *(_DWORD *)(this + 9976);
    v33 = *(_DWORD *)(this + 9980);
    *(_DWORD *)(this + 9968) = 1;
    ClampByRange((int *)(this + 9968), v12, v33);
    v34 = *(_DWORD *)(this + 10016);
    v13 = *(_DWORD *)(this + 10012);
    *(_DWORD *)(this + 10004) = 1;
    ClampByRange((int *)(this + 10004), v13, v34);
    v14 = *(_DWORD *)(this + 10048);
    v35 = *(_DWORD *)(this + 10052);
    *(_DWORD *)(this + 10040) = 1;
    ClampByRange((int *)(this + 10040), v14, v35);
    v36 = *(_DWORD *)(this + 10232);
    v15 = *(_DWORD *)(this + 10228);
    *(_DWORD *)(this + 10220) = 1;
    ClampByRange((int *)(this + 10220), v15, v36);
    v16 = *(_DWORD *)(this + 10264);
    v37 = *(_DWORD *)(this + 10268);
    *(_DWORD *)(this + 10256) = 1;
    ClampByRange((int *)(this + 10256), v16, v37);
    v38 = *(_DWORD *)(this + 10304);
    v17 = *(_DWORD *)(this + 10300);
    *(_DWORD *)(this + 10292) = 1;
    ClampByRange((int *)(this + 10292), v17, v38);
    ArithmeticComparison_20d0(2);
    ArithmeticComparison_20d0(2);
    ArithmeticComparison_20d0(2);
    v18 = ShortComputation_3060(dword_5EC3D0);
    ArithmeticComparison_20d0(v18 - 1);
    v19 = ShortComputation_3060(dword_5EC3D0);
    ArithmeticComparison_20d0(v19 - 1);
    v20 = ShortComputation_3060(dword_5EC3D0);
    ArithmeticComparison_20d0(v20 - 1);
    return ArithmeticComparison_20d0(23);
  }
  return result;
}
