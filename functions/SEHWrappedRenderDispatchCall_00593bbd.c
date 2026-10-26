int __cdecl sub_593BBD(int a1)
{
  int result; // eax
  int v2; // ecx

  result = a1;
  if ( a1 )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a1 + 28) + 4);
    if ( v2 )
      return AtomicLOCKUNLOCKWithIndirectCall(*(_DWORD *)(a1 + 24), v2);
  }
  return result;
}
