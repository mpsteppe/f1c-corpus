char __cdecl _forcdecpt(char *a1)
{
  char *v1; // esi
  int v2; // eax
  char result; // al
  char *v4; // esi
  char v5; // cl

  v1 = a1;
  if ( tolower(*a1) != 101 )
  {
    do
    {
      ++v1;
      if ( (int)SrcSizeInBytes <= 1 )
        v2 = *((_BYTE *)off_625680 + 2 * *v1) & 4;
      else
        v2 = _isctype(*v1, 4);
    }
    while ( v2 );
  }
  result = *v1;
  *v1 = byte_625890;
  v4 = v1 + 1;
  do
  {
    v5 = *v4;
    *v4 = result;
    result = v5;
  }
  while ( *v4++ );
  return result;
}
