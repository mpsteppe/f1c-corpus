void __cdecl sub_513B8A(int a1, int a2, int a3, int a4, int a5)
{
  if ( a1 && a2 )
  {
    if ( a3 )
      *(_DWORD *)(a2 + 48) = a3;
    if ( a5 )
    {
      *(_DWORD *)(a2 + 52) = *(_DWORD *)a5;
      *(_DWORD *)(a2 + 56) = *(_DWORD *)(a5 + 4);
      *(_WORD *)(a2 + 60) = *(_WORD *)(a5 + 8);
      if ( !a4 )
        LOWORD(a4) = 1;
    }
    *(_DWORD *)(a2 + 8) |= 0x10u;
    *(_WORD *)(a2 + 22) = a4;
  }
}
