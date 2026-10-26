_DWORD *__thiscall sub_4B1220(_DWORD *this, char *String1)
{
  _DWORD *v2; // esi
  CHAR *v3; // eax

  if ( !String1 )
    return 0;
  v2 = (_DWORD *)*this;
  if ( !*this )
    return 0;
  while ( 1 )
  {
    v3 = unknown_libname_44(v2);
    if ( !_strcmpi(String1, v3) )
      break;
    v2 = (_DWORD *)sub_5A4730(v2);
    if ( !v2 )
      return 0;
  }
  return v2;
}
