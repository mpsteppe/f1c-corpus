unsigned int __thiscall sub_4E9780(_DWORD *this)
{
  int v1; // ebp
  unsigned int result; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  float v14; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)(dword_75AAC4 + 20848);
  result = this[1];
  v4 = dword_75AAC4 + 84;
  v5 = dword_75AAC4 + 20836;
  if ( result )
  {
    *(float *)(result + 24) = *(float *)(dword_75AAC4 + 18820);
    *(float *)(this[1] + 28) = *(float *)(v4 + 18740);
    *(float *)(this[1] + 36) = *(float *)(v4 + 18708);
    *(float *)(this[1] + 40) = *(float *)(v4 + 18712);
    *(float *)(this[1] + 56) = sub_4E9B20(v4 + 17544);
    *(_DWORD *)(this[1] + 60) = dword_7D74B8;
    v6 = this[1];
    if ( *(_DWORD *)(v6 + 60) == 0x7FFFFFFF )
      *(_DWORD *)(v6 + 60) = -1;
    *(_DWORD *)(this[1] + 64) = *(_DWORD *)(v5 + 12);
    *(float *)(this[1] + 68) = *(float *)(v5 + 124);
    v7 = this[1];
    if ( *(_DWORD *)(v7 + 68) == -1082130432 )
      *(_DWORD *)(v7 + 68) = -1082130432;
    if ( v1 <= 0 )
    {
      *(_DWORD *)(this[1] + 72) = -1082130432;
    }
    else
    {
      *(float *)(this[1] + 72) = sub_4DD0C0((_DWORD *)v5, v1 - 1);
      v8 = this[1];
      if ( *(_DWORD *)(v8 + 72) == -1082130432 )
        *(_DWORD *)(v8 + 72) = -1082130432;
    }
    v14 = dbl_7DA9D0 - *(float *)(v5 + 120);
    if ( *(_DWORD *)(v5 + 116) != 2 || v14 < 0.0 || *(_DWORD *)(v5 + 56) || *(_BYTE *)(v5 + 36) || dword_75CBB4 <= 3 )
      *(_DWORD *)(this[1] + 76) = -1082130432;
    else
      *(float *)(this[1] + 76) = v14;
    *(_DWORD *)(this[1] + 80) = *(_DWORD *)(v5 + 48);
    *(_DWORD *)(this[1] + 84) = NumOfElements;
    *(_DWORD *)(this[1] + 88) = *(_DWORD *)(v4 + 18828);
    *(_DWORD *)(this[1] + 144) = *(_DWORD *)(v4 + 1892);
    *(_DWORD *)(this[1] + 148) = *(_DWORD *)(v4 + 1896);
    *(_DWORD *)(this[1] + 152) = *(_DWORD *)(v4 + 1900);
    *(_DWORD *)(this[1] + 156) = *(_DWORD *)(v4 + 1892);
    *(_DWORD *)(this[1] + 160) = *(_DWORD *)(v4 + 1896);
    *(_DWORD *)(this[1] + 164) = *(_DWORD *)(v4 + 1900);
    *(_DWORD *)(this[1] + 168) = *(_DWORD *)(v4 + 17628);
    *(_DWORD *)(this[1] + 172) = *(_DWORD *)(v4 + 17632);
    *(_DWORD *)(this[1] + 176) = *(_DWORD *)(v4 + 17636);
    if ( (unsigned __int8)sub_4EED40(dword_75AAC4) )
    {
      *(float *)(this[1] + 32) = sub_44A2D0(&dbl_75E930);
      v9 = this[1];
      if ( *(_DWORD *)(v9 + 32) == -1082130432 )
        *(_DWORD *)(v9 + 32) = -1082129593;
      *(float *)(this[1] + 44) = dbl_760960 - 273.16;
      v10 = this[1];
      if ( *(_DWORD *)(v10 + 44) == -1082130432 )
        *(_DWORD *)(v10 + 44) = -1082129593;
      *(float *)(this[1] + 48) = dbl_760920 - 273.16;
      v11 = this[1];
      if ( *(_DWORD *)(v11 + 48) == -1082130432 )
        *(_DWORD *)(v11 + 48) = -1082129593;
      *(float *)(this[1] + 52) = dbl_760948;
      v12 = this[1];
      if ( *(_DWORD *)(v12 + 52) == -1082130432 )
        *(_DWORD *)(v12 + 52) = -1082129593;
      *(float *)(this[1] + 92) = dbl_75EF84[0] - 273.16;
      *(float *)(this[1] + 96) = dbl_75EF8C - 273.16;
      *(float *)(this[1] + 100) = dbl_75EF94 - 273.16;
      *(float *)(this[1] + 104) = dbl_75F46C - 273.16;
      *(float *)(this[1] + 108) = dbl_75F474 - 273.16;
      *(float *)(this[1] + 112) = dbl_75F47C - 273.16;
      *(float *)(this[1] + 116) = dbl_75F954 - 273.16;
      *(float *)(this[1] + 120) = dbl_75F95C - 273.16;
      *(float *)(this[1] + 124) = dbl_75F964 - 273.16;
      *(float *)(this[1] + 128) = dbl_75FE3C - 273.16;
      *(float *)(this[1] + 132) = dbl_75FE44 - 273.16;
      result = this[1];
      *(float *)(result + 136) = dbl_75FE4C - 273.16;
      *(_DWORD *)(this[1] + 140) = *(_DWORD *)(v5 + 64);
    }
    else
    {
      *(_DWORD *)(this[1] + 32) = -1082130432;
      *(_DWORD *)(this[1] + 44) = -1082130432;
      *(_DWORD *)(this[1] + 48) = -1082130432;
      *(_DWORD *)(this[1] + 52) = -1082130432;
      result = 92;
      do
      {
        v13 = 3;
        do
        {
          *(_DWORD *)(result + this[1]) = -1082130432;
          result += 4;
          --v13;
        }
        while ( v13 );
      }
      while ( result < 0x8C );
      *(_DWORD *)(this[1] + 140) = -1;
    }
  }
  return result;
}
