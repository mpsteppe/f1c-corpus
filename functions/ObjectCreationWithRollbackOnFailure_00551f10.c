int __stdcall sub_551F10(int **a1, const char *a2, char a3, int a4)
{
  _DWORD *v4; // eax
  int *v5; // eax
  int result; // eax
  int *v7; // esi

  if ( !a1 )
    return -1;
  v4 = (_DWORD *)OperatorNewNhMallocWrapper(20);
  if ( v4 )
    v5 = StructInitWithDefaultScale(v4);
  else
    v5 = 0;
  *a1 = v5;
  result = sub_551A50(v5, a2, a3, a4);
  if ( result )
  {
    v7 = *a1;
    if ( *a1 )
    {
      EmptyStub_7470(*a1);
      FreeWrapper_7bcf(v7);
    }
    *a1 = 0;
    return -1;
  }
  return result;
}
