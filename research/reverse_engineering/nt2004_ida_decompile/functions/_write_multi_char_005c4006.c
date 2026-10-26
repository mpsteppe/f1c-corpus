_DWORD *__cdecl write_multi_char(int a1, _DWORD *a2, FILE *File, _DWORD *a4)
{
  _DWORD *result; // eax
  _DWORD *i; // edi

  result = a2;
  for ( i = (_DWORD *)((char *)a2 - 1); (int)result > 0; i = (_DWORD *)((char *)i - 1) )
  {
    result = write_char(a1, File, a4);
    if ( *a4 == -1 )
      break;
    result = i;
  }
  return result;
}
