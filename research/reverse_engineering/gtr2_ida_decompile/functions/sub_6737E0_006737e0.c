int __stdcall sub_6737E0(int a1, int a2)
{
  int v2; // edi
  int result; // eax

  v2 = 0;
  if ( !*(_DWORD *)(a1 + 24) )
    return 0;
  while ( 1 )
  {
    result = sub_6736EA(*(_DWORD **)(*(_DWORD *)(a1 + 20) + 4 * v2), a2, 0);
    if ( result < 0 )
      break;
    if ( (unsigned int)++v2 >= *(_DWORD *)(a1 + 24) )
      return 0;
  }
  return result;
}
