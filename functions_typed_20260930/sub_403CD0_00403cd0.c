_DWORD *__thiscall sub_403CD0(_DWORD *this, int a2, float *a3, _DWORD *a4)
{
  float *v4; // edi
  float *v5; // edx
  int v6; // esi
  float *v7; // edx
  float *v8; // ebx
  double v9; // st7
  double v10; // st7
  _DWORD *v11; // edx
  _DWORD *result; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // ecx
  float v15; // [esp+10h] [ebp-18h]
  float v16; // [esp+14h] [ebp-14h]
  float v17; // [esp+18h] [ebp-10h]
  float v18; // [esp+18h] [ebp-10h]
  float v19; // [esp+1Ch] [ebp-Ch]
  float v20; // [esp+24h] [ebp-4h]

  v4 = (float *)this[84];
  v5 = &v4[7 * a2];
  if ( *v5 == 0.0 && v5[1] == 0.0 && v5[2] == 0.0 && v5[3] == 0.0 && v5[4] == 0.0 && v5[5] == 0.0 )
  {
    v6 = a2 - 2;
    if ( a2 - 2 >= 0 )
    {
      v7 = &v4[7 * v6];
      do
      {
        if ( *v7 != 0.0 )
          break;
        if ( v7[1] != 0.0 )
          break;
        if ( v7[2] != 0.0 )
          break;
        if ( v7[3] != 0.0 )
          break;
        if ( v7[4] != 0.0 )
          break;
        if ( v7[5] != 0.0 )
          break;
        v6 -= 2;
        v7 -= 14;
      }
      while ( v6 >= 0 );
    }
    if ( v6 < 2
      || (v8 = &v4[7 * v6 - 14], *v8 == 0.0)
      && v8[1] == 0.0
      && v8[2] == 0.0
      && v8[3] == 0.0
      && v8[4] == 0.0
      && v8[5] == 0.0 )
    {
      *a3 = *v4;
      a3[1] = v4[1];
      a3[2] = v4[2];
      v13 = (_DWORD *)(this[84] + 12);
      *a4 = *v13;
      a4[1] = v13[1];
      result = (_DWORD *)v13[2];
      a4[2] = result;
    }
    else
    {
      v9 = (double)((a2 - v6) / 2);
      v17 = v4[7 * v6 + 2] - v8[2];
      v19 = (v4[7 * v6] - *v8) * v9;
      v20 = v17 * v9;
      v15 = v19 + v4[7 * v6];
      v16 = (v4[7 * v6 + 1] - v8[1]) * v9 + v4[7 * v6 + 1];
      v10 = v20 + v4[7 * v6 + 2];
      *a3 = v15;
      a3[1] = v16;
      v18 = v10;
      a3[2] = v18;
      v11 = (_DWORD *)(28 * v6 + this[84] + 12);
      result = a4;
      *a4 = *v11;
      a4[1] = v11[1];
      a4[2] = v11[2];
    }
  }
  else
  {
    *a3 = *v5;
    a3[1] = v5[1];
    a3[2] = v5[2];
    v14 = (_DWORD *)(28 * a2 + this[84] + 12);
    *a4 = *v14;
    result = (_DWORD *)v14[1];
    a4[1] = result;
    a4[2] = v14[2];
  }
  return result;
}

