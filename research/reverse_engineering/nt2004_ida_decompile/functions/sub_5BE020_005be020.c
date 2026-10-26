int __fastcall sub_5BE020(int a1, int a2)
{
  int v4; // ebx
  int v5; // eax

  v4 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a2, *(_DWORD *)(a1 + 4));
  v5 = sub_5BE340(*(_DWORD *)(a1 + 16), 0, 0);
  if ( v5 == -1 )
    return sub_5BE1C0(*(_DWORD *)(*(_DWORD *)a1 + 4 * v4), a2);
  else
    return sub_5BE2F0(v5);
}
