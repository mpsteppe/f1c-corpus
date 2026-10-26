int __thiscall sub_5614C0(_DWORD *this)
{
  int i; // esi
  int result; // eax
  int j; // ebx
  int v5; // esi
  float v6; // [esp+10h] [ebp-4h]

  *this = -1;
  this[3] = -1;
  this[1] = -1;
  this[4] = -1;
  this[2] = -1;
  this[5] = -1;
  for ( i = 0; i < 3; ++i )
  {
    if ( i == 1 )
    {
      this[7] = 0;
    }
    else if ( i )
    {
      this[i + 6] = dword_91BDE0[i];
    }
    else
    {
      this[6] = LODWORD(flt_91BDEC);
    }
    this[i + 9] = LODWORD(flt_91BDE4[i]);
    result = dword_FADE94;
    for ( j = 0; j < dword_FADE94; ++j )
    {
      v6 = *(float *)(sub_553C00(dword_FADD40, j) + 104);
      if ( *(float *)&this[i + 6] <= (double)v6 && v6 <= (double)*(float *)&this[i + 9] )
      {
        if ( this[i] == -1 || v6 < (double)*(float *)(sub_553C00(dword_FADD40, this[i]) + 104) )
          this[i] = j;
        if ( this[i + 3] == -1 || v6 > (double)*(float *)(sub_553C00(dword_FADD40, this[i]) + 104) )
          this[i + 3] = j;
      }
      result = dword_FADE94;
    }
  }
  v5 = 0;
  this[12] = 0;
  if ( dword_91BDD8 > 0 )
  {
    while ( 1 )
    {
      result = sub_401190();
      if ( result )
      {
        if ( *(_DWORD *)(result + 304) == 1 )
          break;
      }
      result = dword_91BDD8;
      if ( ++v5 >= dword_91BDD8 )
        return result;
    }
    this[12] = *(_DWORD *)(result + 76);
  }
  return result;
}
