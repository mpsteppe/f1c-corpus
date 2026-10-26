unsigned int __cdecl sub_5F7920(int a1, int a2)
{
  int v2; // edi
  unsigned int result; // eax
  int *v4; // edx
  int *v5; // esi
  int v6; // ecx

  v2 = a2;
  result = 0;
  if ( *(int *)(a2 + 340) > 0 )
  {
    v4 = &a2;
    v5 = (int *)(a2 + 344);
    do
    {
      ++v4;
      if ( result >= 8 )
        v6 = 0;
      else
        v6 = *v5;
      *(_DWORD *)(v6 + 240) = *v4;
      ++result;
      ++v5;
    }
    while ( (signed int)result < *(_DWORD *)(v2 + 340) );
  }
  return result;
}
