_DWORD *__thiscall sub_5E86C0(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax

  result = (_DWORD *)(a2 - 1);
  switch ( a2 )
  {
    case 1:
      if ( a3 )
        *a3 = this[22];
      if ( a4 )
        *a4 = this[23];
      result = a5;
      if ( a5 )
        *a5 = this[24];
      break;
    case 2:
      if ( a3 )
        *a3 = this[18];
      if ( a4 )
        *a4 = this[19];
      result = a5;
      if ( a5 )
        *a5 = this[20];
      break;
    case 3:
      if ( a3 )
        *a3 = this[26];
      if ( a4 )
        *a4 = this[27];
      result = a5;
      if ( a5 )
        *a5 = this[28];
      break;
    case 4:
      if ( a3 )
        *a3 = this[30];
      if ( a4 )
        *a4 = this[31];
      result = a5;
      if ( a5 )
        *a5 = this[32];
      break;
    default:
      return result;
  }
  return result;
}
