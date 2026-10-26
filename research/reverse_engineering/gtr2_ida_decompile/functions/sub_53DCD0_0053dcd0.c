unsigned int __thiscall sub_53DCD0(_DWORD *this)
{
  unsigned int result; // eax
  int v3; // ecx
  char *v4; // edi
  char *v5; // ebx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  float v11; // [esp+Ch] [ebp-4h]

  result = this[1];
  v3 = *((_DWORD *)dword_91E07C + 4821);
  v4 = dword_91E07C + 16;
  v5 = dword_91E07C + 19272;
  if ( result )
  {
    *(_DWORD *)(result + 24) = *((_DWORD *)dword_91E07C + 4307);
    *(_DWORD *)(this[1] + 28) = *((_DWORD *)v4 + 4304);
    *(_DWORD *)(this[1] + 36) = *((_DWORD *)v4 + 4295);
    *(_DWORD *)(this[1] + 40) = *((_DWORD *)v4 + 4296);
    *(float *)(this[1] + 56) = sqrt(
                                 *((float *)v4 + 3999) * *((float *)v4 + 3999)
                               + *((float *)v4 + 4000) * *((float *)v4 + 4000)
                               + *((float *)v4 + 4001) * *((float *)v4 + 4001));
    *(_DWORD *)(this[1] + 60) = dword_FADE18;
    v6 = this[1];
    if ( *(_DWORD *)(v6 + 60) == 0x7FFFFFFF )
      *(_DWORD *)(v6 + 60) = -1;
    *(_DWORD *)(this[1] + 64) = *((_DWORD *)v5 + 3);
    *(_DWORD *)(this[1] + 68) = *((_DWORD *)v5 + 41);
    v7 = this[1];
    if ( *(float *)(v7 + 68) == -1.0 )
      *(_DWORD *)(v7 + 68) = -1082130432;
    if ( v3 <= 0 )
    {
      *(_DWORD *)(this[1] + 72) = -1082130432;
    }
    else
    {
      *(float *)(this[1] + 72) = sub_52B860(v5, v3 - 1);
      v8 = this[1];
      if ( *(float *)(v8 + 72) == -1.0 )
        *(_DWORD *)(v8 + 72) = -1082130432;
    }
    v11 = dbl_FB1D18 - *((float *)v5 + 40);
    if ( *((_DWORD *)v5 + 39) != 2 || v11 < 0.0 || *((_DWORD *)v5 + 27) || dword_B64134 <= 3 )
      *(_DWORD *)(this[1] + 76) = -1082130432;
    else
      *(float *)(this[1] + 76) = v11;
    *(_DWORD *)(this[1] + 80) = *((_DWORD *)v5 + 13);
    *(_DWORD *)(this[1] + 84) = dword_757C10;
    *(_DWORD *)(this[1] + 88) = *((_DWORD *)v4 + 4326);
    *(_DWORD *)(this[1] + 144) = *((_DWORD *)v4 + 694);
    *(_DWORD *)(this[1] + 148) = *((_DWORD *)v4 + 695);
    *(_DWORD *)(this[1] + 152) = *((_DWORD *)v4 + 696);
    *(_DWORD *)(this[1] + 156) = *((_DWORD *)v4 + 694);
    *(_DWORD *)(this[1] + 160) = *((_DWORD *)v4 + 695);
    *(_DWORD *)(this[1] + 164) = *((_DWORD *)v4 + 696);
    *(_DWORD *)(this[1] + 168) = *((_DWORD *)v4 + 4021);
    *(_DWORD *)(this[1] + 172) = *((_DWORD *)v4 + 4022);
    *(_DWORD *)(this[1] + 176) = *((_DWORD *)v4 + 4023);
    if ( (unsigned __int8)sub_53F260(dword_91E07C) )
    {
      *(float *)(this[1] + 32) = sub_44A300(&dbl_B66040);
      if ( *(float *)(this[1] + 32) == -1.0 )
        *(_DWORD *)(this[1] + 32) = -1082129593;
      *(float *)(this[1] + 44) = dbl_B68348 - 273.16;
      v9 = this[1];
      if ( *(float *)(v9 + 44) == -1.0 )
        *(_DWORD *)(v9 + 44) = -1082129593;
      *(float *)(this[1] + 48) = dbl_B68308 - 273.16;
      if ( *(float *)(this[1] + 48) == -1.0 )
        *(_DWORD *)(this[1] + 48) = -1082129593;
      *(float *)(this[1] + 52) = dbl_B68330;
      v10 = this[1];
      if ( *(float *)(v10 + 52) == -1.0 )
        *(_DWORD *)(v10 + 52) = -1082129593;
      *(float *)(this[1] + 92) = dbl_B666C8 - 273.16;
      *(float *)(this[1] + 96) = dbl_B666D0 - 273.16;
      *(float *)(this[1] + 100) = dbl_B666D8 - 273.16;
      *(float *)(this[1] + 104) = dbl_B66BC8 - 273.16;
      *(float *)(this[1] + 108) = dbl_B66BD0 - 273.16;
      *(float *)(this[1] + 112) = dbl_B66BD8 - 273.16;
      *(float *)(this[1] + 116) = dbl_B670C8 - 273.16;
      *(float *)(this[1] + 120) = dbl_B670D0 - 273.16;
      *(float *)(this[1] + 124) = dbl_B670D8 - 273.16;
      *(float *)(this[1] + 128) = dbl_B675C8 - 273.16;
      *(float *)(this[1] + 132) = dbl_B675D0 - 273.16;
      result = this[1];
      *(float *)(result + 136) = dbl_B675D8 - 273.16;
      *(_DWORD *)(this[1] + 140) = *((_DWORD *)v5 + 30);
    }
    else
    {
      *(_DWORD *)(this[1] + 32) = -1082130432;
      *(_DWORD *)(this[1] + 44) = -1082130432;
      *(_DWORD *)(this[1] + 48) = -1082130432;
      *(_DWORD *)(this[1] + 52) = -1082130432;
      for ( result = 96; result < 0x90; result += 12 )
      {
        *(_DWORD *)(this[1] + result - 4) = -1082130432;
        *(_DWORD *)(result + this[1]) = -1082130432;
        *(_DWORD *)(this[1] + result + 4) = -1082130432;
      }
      *(_DWORD *)(this[1] + 140) = -1;
    }
  }
  return result;
}
