int __thiscall sub_4A3820(_DWORD *this, float *a2)
{
  double v2; // st7
  int v4; // ecx
  double v5; // st7
  int result; // eax
  int v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // ebx
  int v12; // ecx
  int v13; // eax
  float *v14; // ecx
  bool v15; // cc
  float v16; // [esp+0h] [ebp-7Ch]
  int v17; // [esp+18h] [ebp-64h]
  float v18[18]; // [esp+1Ch] [ebp-60h] BYREF
  float v19; // [esp+64h] [ebp-18h]
  int v20; // [esp+68h] [ebp-14h]
  float v21; // [esp+6Ch] [ebp-10h]
  float v22; // [esp+70h] [ebp-Ch]
  float v23; // [esp+74h] [ebp-8h]
  int v24; // [esp+78h] [ebp-4h]
  int v25; // [esp+80h] [ebp+4h]

  v2 = *a2 - 3.5999999;
  v4 = this[3];
  v18[13] = 0.0;
  v18[14] = v2;
  memset(&v18[15], 0, 12);
  v5 = *a2;
  v20 = 0;
  v24 = 0;
  v19 = v5 * 0.5;
  v21 = *a2 * 0.25;
  v22 = v19;
  result = 0;
  v17 = 0;
  v23 = *a2 * 0.75;
  if ( v4 > 0 )
  {
    v25 = 0;
    do
    {
      v7 = this[4];
      v8 = *(_DWORD *)(v7 + v25 + 112);
      v9 = v25 + v7;
      v10 = 0;
      if ( v8 > 0 )
      {
        v11 = 0;
        do
        {
          v12 = *(_DWORD *)(v9 + 116);
          v13 = *(_DWORD *)(v12 + v11 + 24);
          v14 = (float *)(v11 + v12);
          v16 = v14[4] - v14[3] + v18[v13];
          RangeProportionInitializer(v14, v18[v13], v16);
          ++v10;
          v11 += 28;
        }
        while ( v10 < *(_DWORD *)(v9 + 112) );
      }
      result = v17 + 1;
      v15 = ++v17 < this[3];
      v25 += 120;
    }
    while ( v15 );
  }
  return result;
}

