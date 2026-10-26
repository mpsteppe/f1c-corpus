_DWORD *__thiscall sub_4D83D0(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD **v2; // eax
  _DWORD *v3; // eax
  _DWORD **v4; // eax

  result = (_DWORD *)this[236];
  if ( (int)result <= 0 )
  {
    this[515] = 0;
    this[516] = 0;
  }
  else
  {
    v2 = (_DWORD **)this[233];
    this[235] = v2;
    if ( v2 )
      v3 = *v2;
    else
      v3 = 0;
    this[515] = *v3;
    v4 = (_DWORD **)this[234];
    this[235] = v4;
    if ( v4 )
    {
      result = *v4;
      this[516] = *result;
    }
    else
    {
      result = 0;
      this[516] = MEMORY[0];
    }
  }
  return result;
}
