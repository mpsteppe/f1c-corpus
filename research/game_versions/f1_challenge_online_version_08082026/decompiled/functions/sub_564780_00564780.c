int __fastcall sub_564780(int a1, int a2)
{
  int v4; // ebx
  int v5; // eax

  v4 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a2, *(_DWORD *)(a1 + 4));
  v5 = sub_564A20(*(_DWORD *)(a1 + 16), 0, 0);
  if ( v5 == -1 )
    return sub_5648C0(*(_DWORD *)(*(_DWORD *)a1 + 4 * v4), a2);
  else
    return sub_5649D0(v5);
}
