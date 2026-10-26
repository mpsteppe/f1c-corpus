FILE *__cdecl _fsopen(const char *FileName, const char *Mode, int ShFlag)
{
  FILE *result; // eax
  FILE *v4; // esi
  FILE *v5; // edi

  result = (FILE *)_getstream();
  v4 = result;
  if ( result )
  {
    v5 = (FILE *)_openfile((char *)FileName, (int)Mode, ShFlag, (int)result);
    _unlock_file(v4);
    return v5;
  }
  return result;
}
