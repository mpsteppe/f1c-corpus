_DWORD *__thiscall sub_607C60(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  int v3; // eax
  int v4; // eax
  _DWORD *result; // eax

  v3 = this[1];
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      result = (_DWORD *)(v4 - 1);
      if ( !result )
      {
        *a2 = this[18];
        a2[1] = this[20];
        result = a3;
        *a3 = this[21];
        a3[1] = this[23];
      }
    }
    else
    {
      *a2 = this[19];
      a2[1] = this[20];
      result = a3;
      *a3 = this[22];
      a3[1] = this[23];
    }
  }
  else
  {
    *a2 = this[18];
    a2[1] = this[19];
    result = a3;
    *a3 = this[21];
    a3[1] = this[22];
  }
  return result;
}
