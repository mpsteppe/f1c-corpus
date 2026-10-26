void __cdecl sub_550AA5(int a1, int a2, int a3, __int16 a4)
{
  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 8) |= 8u;
      *(_DWORD *)(a2 + 16) = a3;
      *(_WORD *)(a2 + 20) = a4;
    }
  }
}
