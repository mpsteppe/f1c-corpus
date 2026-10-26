unsigned int __cdecl siglookup(int a1, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( *(_DWORD *)(a2 + 4) != a1 )
  {
    do
      result += 12;
    while ( result < a2 + 12 * dword_62655C && *(_DWORD *)(result + 4) != a1 );
  }
  if ( result >= a2 + 12 * dword_62655C || *(_DWORD *)(result + 4) != a1 )
    return 0;
  return result;
}
