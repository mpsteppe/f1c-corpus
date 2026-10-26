// f1c  0x004a6b80  size=455
int __thiscall sub_4A6B80(_DWORD *this)
{
  int result; // eax
  bool v3; // bl
  int v4; // eax
  float *v5; // ecx
  long double v6; // st7
  long double v7; // st7
  int i; // edx
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  _DWORD *v12; // ecx
  float v13; // [esp+4h] [ebp-1Ch]
  float v14; // [esp+8h] [ebp-18h]
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+10h] [ebp-10h]
  float v17; // [esp+14h] [ebp-Ch]
  float v18; // [esp+18h] [ebp-8h]
  float v19; // [esp+1Ch] [ebp-4h]

  result = this[5];
  if ( result )
  {
    v3 = *(float *)(*this + 14752) > 0.0;
    v4 = sub_4E9630(*this + 12);
    v5 = *(float **)(v4 + 272);
    v17 = *v5 - *(float *)v4;
    v18 = v5[1] - *(float *)(v4 + 4);
    v14 = v17;
    v15 = v18;
    v19 = v5[2] - *(float *)(v4 + 8);
    v16 = v19;
    v6 = v19 * v19 + v18 * v18 + v17 * v17;
    if ( v6 > 0.0 )
    {
      v7 = 1.0 / sqrt(v6);
      v14 = v17 * v7;
      v15 = v18 * v7;
      v16 = v19 * v7;
    }
    for ( i = 0; i < dword_5C329C; ++i )
    {
      if ( i != this[1] )
      {
        v9 = dword_7C54F0[i];
        if ( *(_BYTE *)(v9 + 13388) )
        {
          v10 = v16 * *(float *)(v9 + 13568) + v15 * *(float *)(v9 + 13564) + v14 * *(float *)(v9 + 13560);
          if ( v10 != 0.0 )
          {
            v13 = v16 * *(float *)(*this + 13544) + v15 * *(float *)(*this + 13540) + v14 * *(float *)(*this + 13536);
            v11 = (v13 - (v16 * *(float *)(v9 + 13544) + v15 * *(float *)(v9 + 13540) + v14 * *(float *)(v9 + 13536)))
                / v10;
            if ( v11 > 0.0 && v11 < 5.5 )
              v3 = 0;
          }
        }
      }
    }
    v12 = (_DWORD *)this[5];
    result = v12[30];
    if ( v3 )
    {
      if ( result == 1 )
      {
        v12[30] = 2;
        if ( v12[25] )
          return sub_54C030(1, 1, 1, 0);
      }
    }
    else if ( result == 2 )
    {
      return sub_4A4000(v12);
    }
  }
  return result;
}
