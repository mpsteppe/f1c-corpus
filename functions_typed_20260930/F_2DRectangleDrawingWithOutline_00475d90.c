int __thiscall sub_475D90(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // ebx
  int v13; // edi
  int v15; // eax
  int v16; // eax
  double v17; // st7
  int v18; // ebx
  int v19; // eax
  int v20; // edi
  int v21; // [esp+4h] [ebp-14h] BYREF
  int v22; // [esp+8h] [ebp-10h] BYREF
  int v23; // [esp+Ch] [ebp-Ch] BYREF
  int v24; // [esp+10h] [ebp-8h] BYREF
  int v25; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)UtilityFunction_7160(0, &v24, &v22) || !(unsigned __int8)UtilityFunction_7160(1, &v23, &v21) )
    return 0;
  v6 = v24;
  if ( v24 > v23 )
  {
    v24 = v23;
    v23 = v6;
  }
  v7 = v22;
  if ( v22 > v21 )
  {
    v22 = v21;
    v21 = v7;
  }
  v8 = GlobalAccessor_5150(&unk_7CDE00);
  FloatVectorWithConditionalTransform(v24, v22, v24, v21 - 1, 0, v8);
  FloatVectorWithConditionalTransform(v24, v21, v23 - 1, v21, 0, v8);
  FloatVectorWithConditionalTransform(v23, v21, v23, v22 + 1, 0, v8);
  FloatVectorWithConditionalTransform(v23, v22, v24 + 1, v22, 0, v8);
  CollisionConfigurationSync();
  v9 = this[70];
  if ( v9 )
  {
    v15 = v9 - 1;
    if ( v15 )
    {
      v16 = v15 - 1;
      if ( v16 )
      {
        if ( v16 == 1 )
          v17 = flt_7CD610;
        else
          v17 = 0.0;
      }
      else
      {
        v17 = flt_7CD2B0;
      }
    }
    else
    {
      v17 = flt_7CD45C;
    }
    v18 = v21;
    v25 = v21 - v22 - 1;
    v19 = CRTFtol(v17);
    v20 = v18 - v19;
    if ( v18 - v19 < v18 )
    {
      do
      {
        FloatVectorWithConditionalTransform(v24 + 1, v20, v23 - 1, v20, 16711680, v8);
        ++v20;
      }
      while ( v20 < v21 );
    }
    return 0;
  }
  v10 = (v23 + v24) >> 1;
  FloatVectorWithConditionalTransform(v10, v22 + 1, v10, v21 - 1, 255, v8);
  if ( flt_7CD458 < 0.0 )
  {
    v12 = v10 - 1;
    v25 = v24 - (v10 - 1) + 1;
    v11 = v10 - 1 - CRTFtol((double)v25 * flt_7CD458 + 0.5);
  }
  else
  {
    v11 = v10 + 1;
    v25 = v23 - (v10 + 1) - 1;
    v12 = v10 + 1 + CRTFtol((double)v25 * flt_7CD458 + 0.5);
  }
  if ( v12 < v11 )
    return 0;
  v13 = v22 + 1;
  if ( v22 + 1 >= v21 )
    return 0;
  do
  {
    FloatVectorWithConditionalTransform(v11, v13, v12, v13, 16711680, v8);
    ++v13;
  }
  while ( v13 < v21 );
  return 0;
}

