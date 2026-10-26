float *__thiscall sub_403D10(_DWORD *this, float *a2, int a3)
{
  int v4; // ebp
  _DWORD *v5; // esi
  int v7; // ecx
  float *v8; // ebx
  double v9; // st6
  double v10; // st4
  double v11; // st7
  double v12; // st5
  double v13; // st3
  double v14; // st4
  int i; // ecx
  double v16; // st5
  double v17; // st3
  double v18; // st4
  double v19; // st7
  float *result; // eax
  int v21; // esi
  int v22; // eax
  float *v23; // esi
  double v24; // st6
  double v25; // st7
  double v26; // st7
  float v27; // [esp+10h] [ebp-28h]
  float *v29; // [esp+18h] [ebp-20h]
  int v30; // [esp+1Ch] [ebp-1Ch]
  float v31; // [esp+2Ch] [ebp-Ch]
  float v32; // [esp+2Ch] [ebp-Ch]
  float v33; // [esp+30h] [ebp-8h]
  float v34; // [esp+30h] [ebp-8h]
  float v35; // [esp+34h] [ebp-4h]
  float v36; // [esp+34h] [ebp-4h]
  float v37; // [esp+3Ch] [ebp+4h]
  float v38; // [esp+40h] [ebp+8h]
  float v39; // [esp+40h] [ebp+8h]
  float v40; // [esp+40h] [ebp+8h]

  v4 = 0;
  v5 = this;
  if ( a3 )
  {
    v7 = *(_DWORD *)(a3 + 296);
    v8 = (float *)a3;
    v9 = a2[2] - *(float *)(a3 + 8);
    v10 = *a2 - *(float *)a3;
    v11 = v9 * v9 + v10 * v10;
    while ( 1 )
    {
      v12 = a2[2] - *(float *)(v7 + 8);
      v13 = *a2 - *(float *)v7;
      v14 = v12 * v12 + v13 * v13;
      if ( v14 >= v11 )
        break;
      v8 = (float *)v7;
      v38 = v14;
      v11 = v38;
      v7 = *(_DWORD *)(v7 + 296);
    }
    for ( i = *(_DWORD *)(a3 + 292); ; i = *(_DWORD *)(i + 292) )
    {
      v16 = a2[2] - *(float *)(i + 8);
      v17 = *a2 - *(float *)i;
      v18 = v16 * v16 + v17 * v17;
      if ( v18 >= v11 )
        break;
      v39 = v18;
      v11 = v39;
      v8 = (float *)i;
    }
    v19 = sub_5297B0(a2);
    v40 = v19;
    if ( v19 < 0.0 )
      return v8;
    v29 = v8;
    v31 = *a2 - *v8;
    v33 = a2[1] - v8[1];
    v35 = a2[2] - v8[2];
    v37 = v35 * v35 + v31 * v31 + v33 * 4.0 * (v33 * 4.0);
    v27 = (v40 + 30.0) * (v40 + 30.0);
  }
  else
  {
    v8 = 0;
    v40 = 1000000000.0;
    v37 = 3.4028235e38;
    v27 = 3.4028235e38;
    v29 = 0;
  }
  v30 = 0;
  if ( (int)v5[89] > 0 )
  {
    while ( 1 )
    {
      v21 = v5[90];
      v22 = *(_DWORD *)(v21 + v4 + 328);
      v23 = (float *)(v4 + v21);
      if ( !v22 || (v22 == 1 || (int)this[101] > 1) && (v22 == 1 || v22 == 2) )
      {
        v32 = *a2 - *v23;
        v34 = a2[1] - v23[1];
        v36 = a2[2] - v23[2];
        v24 = v36 * v36 + v32 * v32 + v34 * 4.0 * (v34 * 4.0);
        if ( v24 < v37 )
        {
          v37 = v24;
          v8 = v23;
        }
        if ( v40 > 0.0 && v24 < v27 )
        {
          v25 = sub_5297B0(a2);
          if ( v25 < v40 )
          {
            v40 = v25;
            v29 = v23;
            v27 = (v25 + 30.0) * (v25 + 30.0);
          }
        }
      }
      v4 += 348;
      if ( ++v30 >= this[89] )
        break;
      v5 = this;
    }
  }
  v26 = sub_5297B0(a2);
  result = v8;
  if ( v26 >= 0.0 )
    return v29;
  return result;
}
