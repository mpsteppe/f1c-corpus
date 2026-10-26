int __thiscall sub_4A35F0(_DWORD *this, int a2)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st6
  double v8; // st6
  double v9; // st5
  double v10; // st6
  double v11; // st6
  double v12; // st6
  int v13; // ecx
  int result; // eax
  int v15; // esi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  int v20; // ecx
  int v21; // eax
  float *v22; // ecx
  bool v23; // cc
  float v24; // [esp+0h] [ebp-7Ch]
  int v25; // [esp+18h] [ebp-64h]
  int v26; // [esp+1Ch] [ebp-60h]
  float v27; // [esp+20h] [ebp-5Ch]
  int v28; // [esp+24h] [ebp-58h]
  float v29; // [esp+28h] [ebp-54h]
  int v30; // [esp+2Ch] [ebp-50h]
  float v31; // [esp+30h] [ebp-4Ch]
  float v32; // [esp+34h] [ebp-48h]
  float v33; // [esp+38h] [ebp-44h]
  float v34; // [esp+3Ch] [ebp-40h]
  float v35; // [esp+40h] [ebp-3Ch]
  float v36; // [esp+44h] [ebp-38h]
  float v37; // [esp+48h] [ebp-34h]
  float v38; // [esp+4Ch] [ebp-30h]
  float v39; // [esp+80h] [ebp+4h]
  float v40; // [esp+80h] [ebp+4h]
  int v41; // [esp+80h] [ebp+4h]

  v4 = *(float *)(a2 + 52) + *(float *)a2;
  if ( *(_BYTE *)(a2 + 4) )
  {
    v5 = *(float *)(a2 + 8);
    v26 = 0;
    v6 = v5 + *(float *)a2;
    v28 = 0;
    v34 = v6;
    v35 = *(float *)(a2 + 12) + *(float *)a2;
    v36 = *(float *)(a2 + 16) + *(float *)a2;
    v7 = *(float *)(a2 + 20) + *(float *)a2;
    v37 = v7;
    v38 = v7 + 2.0;
    if ( v34 <= (double)v35 )
      v8 = v35;
    else
      v8 = v34;
    if ( v36 <= (double)v37 )
      v9 = v37;
    else
      v9 = v36;
    if ( v8 <= v9 )
    {
      if ( v36 <= (double)v37 )
        v10 = v37;
      else
        v10 = v36;
    }
    else if ( v34 <= (double)v35 )
    {
      v10 = v35;
    }
    else
    {
      v10 = v34;
    }
    v11 = v10 + *(float *)(a2 + 24);
    v27 = v11 - 1.0;
    v29 = v27;
    v39 = v11 + *(float *)(a2 + 28);
    if ( v4 < v39 )
      v4 = v39;
  }
  else
  {
    v26 = 1203982208;
    v28 = 1203982208;
    v34 = 99999.0;
    v35 = 99999.0;
    v36 = 99999.0;
    v37 = 99999.0;
    v38 = 99999.0;
    v27 = 99999.0;
    v29 = 99999.0;
  }
  if ( *(_BYTE *)(a2 + 32) )
  {
    v32 = *(float *)(a2 + 36) + *(float *)a2;
    v12 = *(float *)(a2 + 44) + *(float *)(a2 + 40) + v32;
    v33 = v12 - 1.0;
    v40 = v12 + *(float *)(a2 + 48);
    if ( v4 < v40 )
      v4 = v40;
  }
  else
  {
    v32 = 99999.0;
    v33 = 99999.0;
  }
  v13 = this[3];
  result = 0;
  v31 = v4 - 3.5999999;
  v30 = 0;
  v25 = 0;
  if ( v13 > 0 )
  {
    v41 = 0;
    do
    {
      v15 = this[4];
      v16 = *(_DWORD *)(v15 + v41 + 112);
      v17 = v41 + v15;
      v18 = 0;
      if ( v16 > 0 )
      {
        v19 = 0;
        do
        {
          v20 = *(_DWORD *)(v17 + 116);
          v21 = *(_DWORD *)(v20 + v19 + 24);
          v22 = (float *)(v19 + v20);
          v24 = v22[4] - v22[3] + *((float *)&v26 + v21);
          RangeProportionInitializer(v22, *((float *)&v26 + v21), v24);
          ++v18;
          v19 += 28;
        }
        while ( v18 < *(_DWORD *)(v17 + 112) );
      }
      result = v25 + 1;
      v23 = ++v25 < this[3];
      v41 += 120;
    }
    while ( v23 );
  }
  return result;
}

