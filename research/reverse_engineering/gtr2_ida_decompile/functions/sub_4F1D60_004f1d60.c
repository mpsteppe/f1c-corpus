char __thiscall sub_4F1D60(int *this)
{
  int v2; // eax
  int v3; // ecx
  double v4; // st7
  long double v5; // st7
  long double v6; // st7
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  float v13; // [esp+8h] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-18h]
  float v15; // [esp+10h] [ebp-14h]
  float v16; // [esp+14h] [ebp-10h]
  float v17; // [esp+18h] [ebp-Ch]
  float v18; // [esp+1Ch] [ebp-8h]
  float v19; // [esp+20h] [ebp-4h]

  v2 = sub_5761B0(*this + 16);
  v3 = *(_DWORD *)(v2 + 276);
  v4 = *(float *)(v3 + 4);
  v3 += 4;
  v17 = v4 - *(float *)(v2 + 4);
  v18 = *(float *)(v3 + 4) - *(float *)(v2 + 8);
  v15 = v18;
  v14 = v17;
  v19 = *(float *)(v3 + 8) - *(float *)(v2 + 12);
  v16 = v19;
  v5 = v19 * v19 + v18 * v18 + v17 * v17;
  if ( v5 > 0.0 )
  {
    v6 = 1.0 / sqrt(v5);
    v14 = v17 * v6;
    v15 = v18 * v6;
    v16 = v19 * v6;
  }
  v7 = *this;
  v8 = 0;
  if ( dword_757C10 <= 0 )
    return 1;
  while ( 1 )
  {
    if ( v8 != *(_DWORD *)(v7 + 22468) )
    {
      v9 = *(&dword_91E088 + v8);
      if ( *(_BYTE *)(v9 + 15572) )
      {
        v10 = v16 * *(float *)(v9 + 16020) + v15 * *(float *)(v9 + 16016) + v14 * *(float *)(v9 + 16012);
        if ( v10 != 0.0 )
        {
          v13 = v16 * *(float *)(v7 + 15996) + v15 * *(float *)(v7 + 15992) + v14 * *(float *)(v7 + 15988);
          v11 = (v13 - (v16 * *(float *)(v9 + 15996) + v15 * *(float *)(v9 + 15992) + v14 * *(float *)(v9 + 15988)))
              / v10;
          if ( v11 > 0.0 && v11 < 5.0 )
            break;
        }
      }
    }
    if ( ++v8 >= dword_757C10 )
      return 1;
  }
  return 0;
}
