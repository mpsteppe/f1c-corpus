char __thiscall sub_4590A0(int this, float *a2, int *a3, _DWORD *a4, float a5, int a6)
{
  int v7; // ecx
  double v8; // st7
  int v9; // esi
  int v10; // edi
  int v11; // edx
  double v12; // st7
  int v13; // eax
  int v14; // ecx
  double v15; // st7
  int v16; // ebx
  double v17; // st7
  double v18; // st6
  float v20; // [esp+Ch] [ebp-88h]
  float v21; // [esp+10h] [ebp-84h]
  float v22; // [esp+14h] [ebp-80h]
  float v23[9]; // [esp+18h] [ebp-7Ch] BYREF
  int v24[9]; // [esp+3Ch] [ebp-58h] BYREF
  float v25; // [esp+60h] [ebp-34h] BYREF
  float v26; // [esp+64h] [ebp-30h]
  float v27; // [esp+68h] [ebp-2Ch]
  float v28; // [esp+6Ch] [ebp-28h]
  float v29; // [esp+70h] [ebp-24h]
  float v30; // [esp+74h] [ebp-20h]
  float v31; // [esp+78h] [ebp-1Ch]
  float v32; // [esp+7Ch] [ebp-18h]
  float v33; // [esp+80h] [ebp-14h]
  _DWORD v34[3]; // [esp+84h] [ebp-10h] BYREF
  float v35; // [esp+90h] [ebp-4h]

  if ( *(_DWORD *)(this + 120) && (unsigned __int8)sub_45A5A0() )
  {
    v7 = *(_DWORD *)(this + 120);
    *(float *)(this + 132) = *(float *)(this + 128) * *(float *)(this + 124) * a5 + *(float *)(this + 132);
    v8 = sub_45A590(v7);
    if ( *(float *)(this + 132) >= 0.0 )
    {
      if ( v8 < *(float *)(this + 132) )
        *(float *)(this + 132) = v8;
    }
    else
    {
      *(_DWORD *)(this + 132) = 0;
    }
    sub_45A580(*(float *)(this + 132), (int)v24);
    v9 = v24[4];
    v10 = v24[5];
    v20 = *(float *)v24;
    v11 = v24[3];
    v21 = *(float *)&v24[1];
    v22 = *(float *)&v24[2];
  }
  else
  {
    v20 = *(float *)(this + 20);
    v22 = *(float *)(this + 28);
    v11 = *(_DWORD *)(this + 32);
    v9 = *(_DWORD *)(this + 36);
    v10 = *(_DWORD *)(this + 40);
    v21 = *(float *)(this + 24);
  }
  v12 = *(float *)(this + 136);
  v34[0] = v11;
  v34[1] = v9;
  v34[2] = v10;
  if ( v12 == 0.0 )
  {
    *(_DWORD *)(this + 160) = v11;
    *(_DWORD *)(this + 164) = v9;
    *(_DWORD *)(this + 168) = v10;
    sub_579100(this + 160, v23);
  }
  else
  {
    v13 = a3[1];
    v14 = a3[2];
    v24[0] = *a3;
    v24[2] = v14;
    v24[1] = v13;
    sub_579100(v24, v23);
    sub_579100(v34, &v25);
    *(float *)v24 = v31 * v23[2] + v25 * v23[0] + v28 * v23[1];
    *(float *)&v24[1] = v32 * v23[2] + v26 * v23[0] + v29 * v23[1];
    *(float *)&v24[2] = v33 * v23[2] + v27 * v23[0] + v30 * v23[1];
    *(float *)&v24[3] = v23[5] * v31 + v23[4] * v28 + v23[3] * v25;
    *(float *)&v24[4] = v23[5] * v32 + v23[4] * v29 + v23[3] * v26;
    *(float *)&v24[5] = v23[5] * v33 + v23[4] * v30 + v23[3] * v27;
    *(float *)&v24[6] = v23[8] * v31 + v23[7] * v28 + v23[6] * v25;
    *(float *)&v24[7] = v23[8] * v32 + v23[7] * v29 + v23[6] * v26;
    *(float *)&v24[8] = v23[8] * v33 + v23[7] * v30 + v23[6] * v27;
    *(float *)(this + 160) = -asin(*(float *)&v24[5]);
    if ( fabs(*(float *)&v24[5]) == 1.0 )
    {
      v15 = *(float *)&v24[6];
      *(_DWORD *)(this + 168) = 0;
      *(float *)(this + 164) = atan2(-v15, *(float *)v24);
    }
    else
    {
      *(float *)(this + 164) = atan2(*(float *)&v24[2], *(float *)&v24[8]);
      *(float *)(this + 168) = atan2(*(float *)&v24[3], *(float *)&v24[4]);
    }
    qmemcpy(v23, v24, sizeof(v23));
  }
  v16 = this + 44;
  v17 = v22 * v23[2] + v21 * v23[1] + v20 * v23[0];
  *(float *)(v16 + 104) = v17;
  v18 = v22 * v23[5] + v21 * v23[4] + v23[3] * v20;
  *(float *)(v16 + 108) = v18;
  v35 = v22 * v23[8] + v21 * v23[7] + v23[6] * v20;
  *(float *)(v16 + 112) = v35;
  *(float *)(v16 + 104) = v17 + *a2;
  *(float *)(v16 + 108) = v18 + a2[1];
  *(float *)(v16 + 112) = v35 + a2[2];
  *(_DWORD *)v16 = *a4;
  *(_DWORD *)(v16 + 4) = a4[1];
  *(_DWORD *)(v16 + 8) = a4[2];
  return 1;
}
