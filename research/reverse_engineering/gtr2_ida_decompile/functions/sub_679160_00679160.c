int __stdcall sub_679160(int *a1, int a2)
{
  int result; // eax
  int v3; // esi

  result = a2;
  v3 = *a1;
  if ( a2 >= 0 )
  {
    if ( *(_DWORD *)(v3 + 104) >= a2 )
      return (*(int (__stdcall **)(int *))(v3 + 8))(a1);
  }
  else
  {
    result = *(_DWORD *)(v3 + 108);
    if ( !result || *(int *)(v3 + 104) >= 3 )
      result = (*(int (__stdcall **)(int *))(v3 + 8))(a1);
    ++*(_DWORD *)(v3 + 108);
  }
  return result;
}
