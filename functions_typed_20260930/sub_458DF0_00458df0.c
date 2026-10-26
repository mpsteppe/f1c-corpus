int __thiscall sub_458DF0(int this, float *a2, int a3, float *a4, int a5, int a6)
{
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  float v10; // ebx
  float *v11; // edi
  float v12; // ecx
  double v13; // st7
  char v14; // al
  long double v15; // st7
  long double v16; // st7
  long double v17; // st7
  double v18; // st7
  float v20; // [esp+Ch] [ebp-30h]
  float v21; // [esp+10h] [ebp-2Ch]
  float v22; // [esp+14h] [ebp-28h]
  float v23; // [esp+18h] [ebp-24h] BYREF
  float v24; // [esp+1Ch] [ebp-20h]
  float v25; // [esp+20h] [ebp-1Ch]
  float v26; // [esp+24h] [ebp-18h] BYREF
  float v27; // [esp+28h] [ebp-14h]
  float v28; // [esp+2Ch] [ebp-10h]
  _DWORD v29[3]; // [esp+30h] [ebp-Ch] BYREF

  v7 = this + 24;
  v8 = *(_DWORD *)(this + 24);
  v9 = *(_DWORD *)(v7 + 4);
  v29[2] = *(_DWORD *)(v7 + 8);
  LOBYTE(v7) = *(_BYTE *)(this + 160);
  v29[0] = v8;
  v29[1] = v9;
  if ( (_BYTE)v7 )
    *(_BYTE *)(this + 160) = 0;
  v10 = *(float *)&a6;
  v11 = a2;
  if ( *(_DWORD *)(this + 176) )
    SuspensionWheelForceCalculation(this, a2, a4, a6);
  v12 = *(float *)(this + 20);
  v13 = *(float *)(this + 12) + *v11;
  v24 = *(float *)(this + 16);
  v25 = v12;
  v20 = v13;
  v23 = v20;
  v21 = v24 + v11[1];
  v24 = v21;
  v14 = *(_BYTE *)(this + 116);
  v22 = v12 + v11[2];
  v25 = v22;
  if ( (v14 & 1) != 0 )
  {
    DoubleFieldGetterAt0x300x34((_DWORD *)this, &a6, &a2);
    v15 = 35.0 / sqrt(v22 * v22 + v21 * v21 + v20 * v20);
    if ( v15 >= 0.1 )
    {
      if ( v15 > 1.0 )
        v15 = 1.0;
    }
    else
    {
      v15 = 0.1;
    }
    *(float *)(this + 56) = *(float *)&a6 * v15;
    *(float *)(this + 60) = v15 * *(float *)&a2;
  }
  v16 = v22 * v22 + v21 * v21 + v20 * v20;
  if ( v16 > 0.0 )
  {
    v17 = 1.0 / sqrt(v16);
    v23 = v20 * v17;
    v24 = v24 * v17;
    v25 = v17 * v25;
  }
  FloatConvertWrapper(COERCE_UNSIGNED_INT64(v24));
  v26 = v24;
  if ( v23 == 0.0 && v25 == 0.0 )
    v27 = 0.0;
  else
    v27 = 3.1415927 - atan2(-v23, -v25);
  v18 = *(float *)(this + 164);
  v28 = 0.0;
  if ( v18 > 0.0 )
  {
    CollisionResponseFilter((float *)this, COERCE_FLOAT(&v26), (int)v29, &v23, v10);
    v26 = v23;
    v27 = v24;
    v28 = v25;
  }
  VectorCopy((_DWORD *)this, &v26);
  return 0;
}

