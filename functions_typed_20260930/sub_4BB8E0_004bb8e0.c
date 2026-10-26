unsigned int __thiscall sub_4BB8E0(_DWORD *this)
{
  unsigned int result; // eax
  int v3; // ecx

  result = dword_7C56A4;
  if ( (unsigned int)dword_7C56A4 <= 6 )
  {
    v3 = *this;
    result = *(_DWORD *)(*this + 13000);
    if ( result <= 1 )
    {
      AIRacingLinePathFollowing(v3 + 12);
      if ( this[24] == 2 )
        this[24] = 1;
      result = -1082130432;
      this[6] = -1082130432;
      this[7] = -1082130432;
      this[8] = -1082130432;
    }
  }
  this[44] = 0;
  *((_BYTE *)this + 168) = 0;
  this[43] = 0;
  *((_BYTE *)this + 180) = 0;
  this[52] = 0;
  *((_BYTE *)this + 212) = 0;
  return result;
}

