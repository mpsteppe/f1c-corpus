double __thiscall sub_54AEB0(_DWORD *this, float a2)
{
  int i; // ecx
  int v4; // eax
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  int v9; // [esp+0h] [ebp-30h]
  float v10; // [esp+4h] [ebp-2Ch]
  float v11; // [esp+8h] [ebp-28h]
  float v12; // [esp+Ch] [ebp-24h]
  float v13; // [esp+14h] [ebp-1Ch]
  float v14; // [esp+18h] [ebp-18h]
  float v15; // [esp+1Ch] [ebp-14h]
  float v16; // [esp+20h] [ebp-10h]
  float v17[3]; // [esp+24h] [ebp-Ch] BYREF

  v10 = 0.0;
  sub_4095D0((int)v17, v9);
  v11 = sub_409310(this);
  for ( i = 0; i < dword_757C10; ++i )
  {
    v4 = *(&dword_91E088 + i);
    if ( *(_DWORD *)(v4 + 19380) != 2 )
    {
      v14 = v17[0] - *(float *)(v4 + 15988);
      v15 = v17[1] - *(float *)(v4 + 15992);
      v12 = v14;
      v16 = v17[2] - *(float *)(v4 + 15996);
      v13 = v16;
      v5 = v15 * v15 + v16 * v16 + v14 * v14;
      if ( v5 <= 10000.0 )
      {
        if ( v5 > 0.0 )
        {
          v6 = 1.0 / sqrt(v5);
          v12 = v14 * v6;
          v13 = v6 * v16;
        }
        v7 = cos(v11) * v13 + sin(v11) * v12;
        if ( v7 > v10 )
          v10 = v7;
        if ( v10 >= (double)a2 )
          break;
      }
    }
  }
  return v10;
}
