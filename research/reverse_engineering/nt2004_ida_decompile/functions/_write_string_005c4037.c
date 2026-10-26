_DWORD *__cdecl write_string(char *a1, _DWORD *a2, FILE *File, _DWORD *a4)
{
  _DWORD *result; // eax
  _DWORD *i; // ebx
  int v7; // eax

  result = a2;
  for ( i = (_DWORD *)((char *)a2 - 1); (int)result > 0; i = (_DWORD *)((char *)i - 1) )
  {
    v7 = *a1++;
    result = write_char(v7, File, a4);
    if ( *a4 == -1 )
      break;
    result = i;
  }
  return result;
}
