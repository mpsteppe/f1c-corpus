int __fastcall sub_5B9BC0(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int result; // eax

  if ( a2 )
  {
    v4 = a2 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        result = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 4, a3, *(_DWORD *)(a4 + 1564));
    }
    else
    {
      result = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 2, a3, *(_DWORD *)(a4 + 1564));
    }
  }
  else
  {
    result = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 1, a3, *(_DWORD *)(a4 + 1564));
  }
  if ( a3 )
  {
    result = *(_DWORD *)a3;
    if ( *(_DWORD *)a3 == *(_DWORD *)(a4 + 1552) && *(_WORD *)(a3 + 4) == *(_WORD *)(a4 + 1556) )
      *(_DWORD *)(a4 + 1552) = 0;
  }
  return result;
}
