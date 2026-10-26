float *__thiscall sub_402D40(_DWORD *this, float *a2, int a3)
{
  int v4; // ebp
  _DWORD *v5; // esi
  int v7; // ecx
  float *v8; // ebx
  double v9; // st5
  double v10; // st4
  double v11; // st6
  double v12; // st4
  double i; // st7
  double v14; // st7
  double v15; // st6
  int v16; // ecx
  double v17; // st6
  double v18; // st4
  double v19; // st7
  double v20; // st7
  double v21; // st6
  double v22; // st7
  float *result; // eax
  int v24; // esi
  unsigned int v25; // eax
  float *v26; // esi
  double v27; // st6
  double v28; // st7
  double v29; // st7
  float v30; // [esp+10h] [ebp-28h]
  float *v31; // [esp+14h] [ebp-24h]
  int v32; // [esp+18h] [ebp-20h]
  float v34; // [esp+2Ch] [ebp-Ch]
  float v35; // [esp+2Ch] [ebp-Ch]
  float v36; // [esp+30h] [ebp-8h]
  float v37; // [esp+30h] [ebp-8h]
  float v38; // [esp+34h] [ebp-4h]
  float v39; // [esp+34h] [ebp-4h]
  float v40; // [esp+3Ch] [ebp+4h]
  float v41; // [esp+40h] [ebp+8h]
  float v42; // [esp+40h] [ebp+8h]
  float v43; // [esp+40h] [ebp+8h]

  v4 = 0;
  v5 = this;
  if ( a3 )
  {
    v7 = *(_DWORD *)(a3 + 276);
    v8 = (float *)a3;
    v9 = a2[2] - *(float *)(a3 + 12);
    v10 = *a2 - *(float *)(a3 + 4);
    v41 = v9 * v9 + v10 * v10;
    v11 = a2[2] - *(float *)(v7 + 12);
    v12 = *a2 - *(float *)(v7 + 4);
    for ( i = v11 * v11 + v12 * v12; i < v41; i = v15 * v15 + v14 * v14 )
    {
      v41 = i;
      v8 = (float *)v7;
      v7 = *(_DWORD *)(v7 + 276);
      v14 = *a2 - *(float *)(v7 + 4);
      v15 = a2[2] - *(float *)(v7 + 12);
    }
    v16 = *(_DWORD *)(a3 + 272);
    v17 = a2[2] - *(float *)(v16 + 12);
    v18 = *a2 - *(float *)(v16 + 4);
    v19 = v17 * v17 + v18 * v18;
    if ( v19 < v41 )
    {
      do
      {
        v42 = v19;
        v8 = (float *)v16;
        v16 = *(_DWORD *)(v16 + 272);
        v20 = *a2 - *(float *)(v16 + 4);
        v21 = a2[2] - *(float *)(v16 + 12);
        v19 = v21 * v21 + v20 * v20;
      }
      while ( v19 < v42 );
    }
    v22 = sub_592490(a2);
    v40 = v22;
    if ( v22 < 0.0 )
      return v8;
    v31 = v8;
    v34 = *a2 - v8[1];
    v36 = a2[1] - v8[2];
    v38 = a2[2] - v8[3];
    v43 = v38 * v38 + v34 * v34 + v36 * 4.0 * (v36 * 4.0);
    v30 = (v40 + 30.0) * (v40 + 30.0);
  }
  else
  {
    v8 = 0;
    v40 = 1000000000.0;
    v43 = 3.4028235e38;
    v30 = 3.4028235e38;
    v31 = 0;
  }
  v32 = 0;
  if ( (int)v5[78] > 0 )
  {
    while ( 1 )
    {
      v24 = v5[79];
      v25 = *(_DWORD *)(v24 + v4 + 304);
      v26 = (float *)(v4 + v24);
      if ( v25 <= 1 )
      {
        v35 = *a2 - v26[1];
        v37 = a2[1] - v26[2];
        v39 = a2[2] - v26[3];
        v27 = v39 * v39 + v35 * v35 + v37 * 4.0 * (v37 * 4.0);
        if ( v27 < v43 )
        {
          v43 = v27;
          v8 = v26;
        }
        if ( v40 > 0.0 && v27 < v30 )
        {
          v28 = sub_592490(a2);
          if ( v28 < v40 )
          {
            v40 = v28;
            v31 = v26;
            v30 = (v28 + 30.0) * (v28 + 30.0);
          }
        }
      }
      v4 += 320;
      if ( ++v32 >= this[78] )
        break;
      v5 = this;
    }
  }
  v29 = sub_592490(a2);
  result = v8;
  if ( v29 >= 0.0 )
    return v31;
  return result;
}
