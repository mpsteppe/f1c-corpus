int __thiscall sub_4576F0(int this, int a2, float *a3)
{
  _DWORD *v4; // eax
  int v5; // edx
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // edx
  double v9; // st7
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // edi
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  _DWORD v18[3]; // [esp+4h] [ebp-6Ch] BYREF
  double v19; // [esp+10h] [ebp-60h] BYREF
  double v20; // [esp+18h] [ebp-58h]
  double v21; // [esp+20h] [ebp-50h]
  double v22; // [esp+28h] [ebp-48h] BYREF
  int v23; // [esp+30h] [ebp-40h]
  int v24; // [esp+34h] [ebp-3Ch]
  int v25; // [esp+38h] [ebp-38h]
  int v26; // [esp+3Ch] [ebp-34h]
  double v27[3]; // [esp+40h] [ebp-30h] BYREF
  _BYTE v28[24]; // [esp+58h] [ebp-18h] BYREF

  v4 = (_DWORD *)(this + 6352);
  v5 = *(_DWORD *)(this + 6356);
  LODWORD(v19) = *(_DWORD *)(this + 6352);
  v6 = *(_DWORD *)(this + 6360);
  HIDWORD(v19) = v5;
  v20 = COERCE_DOUBLE(__PAIR64__(v4[3], v6));
  v7 = v4[4];
  v8 = v4[5];
  v9 = *a3;
  v21 = COERCE_DOUBLE(__PAIR64__(v8, v7));
  v10 = *(_DWORD *)(this + 536);
  v19 = v9 + v19;
  v20 = a3[1] + v20;
  v21 = a3[2] + COERCE_DOUBLE(__PAIR64__(v8, v7));
  v27[0] = 0.0;
  v27[1] = 0.0;
  v27[2] = 0.0;
  if ( v10 )
  {
    sub_43A370((double *)(*(_DWORD *)(this + 6312) + 32), (double *)(*(_DWORD *)(this + 6312) + 8), &v19, &v22);
    v11 = HIDWORD(v22);
    v12 = v23;
    v13 = (_DWORD *)(v10 + 8);
    *v13 = LODWORD(v22);
    v14 = v24;
    v13[1] = v11;
    v15 = v25;
    v13[2] = v12;
    v16 = v26;
    v13[3] = v14;
    v13[4] = v15;
    v13[5] = v16;
    sub_43A2B0(*(_DWORD *)(this + 6312) + 32, (int)v28);
    sub_61B6E0(v28);
  }
  sub_44AD60((double *)(this + 544), *(_DWORD *)(this + 536), a2, (int *)&v19, (int *)v27);
  sub_457250((double **)(this + 544), *(_DWORD *)(this + 6312));
  memset(v18, 0, sizeof(v18));
  return sub_56F1C0(v18);
}
