char __cdecl _forcdecpt(char *a1)
{
  char *v1; // esi
  bool i; // zf
  char result; // al
  char *v4; // esi
  char v5; // cl

  v1 = a1;
  for ( i = sub_635155(*a1) == 101; !i; i = isdigit(*v1) == 0 )
    ++v1;
  result = *v1;
  *v1 = byte_9131A4;
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
