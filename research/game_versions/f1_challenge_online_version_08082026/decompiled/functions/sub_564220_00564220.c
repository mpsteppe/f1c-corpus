_BYTE *__fastcall sub_564220(_BYTE *a1, char a2)
{
  char v2; // bl
  _BYTE *v3; // esi

  if ( a1 )
    dword_8CFAE4 = (int)a1;
  else
    a1 = (_BYTE *)dword_8CFAE4;
  v2 = *a1;
  v3 = a1;
  if ( !*a1 )
    goto LABEL_8;
  do
  {
    if ( v2 == a2 )
      break;
    dword_8CFAE4 = (int)++a1;
    v2 = *a1;
  }
  while ( *a1 );
  if ( a1 == v3 )
LABEL_8:
    v3 = 0;
  if ( *a1 )
  {
    *a1 = 0;
    ++dword_8CFAE4;
  }
  return v3;
}
