_DWORD *__thiscall sub_57A720(_DWORD *this, char *String1)
{
  _DWORD *v2; // esi
  CHAR *v4; // eax

  v2 = (_DWORD *)this[2];
  if ( !String1 )
    return 0;
  for ( ; v2; v2 = (_DWORD *)v2[1] )
  {
    v4 = sub_57A6C0(v2);
    if ( !_strcmpi(String1, v4) )
      break;
  }
  return v2;
}
