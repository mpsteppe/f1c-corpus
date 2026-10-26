int __fastcall sub_5BE070(int a1, int a2)
{
  int v3; // ebx
  int v4; // eax

  v3 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a2, *(_DWORD *)(a1 + 4));
  v4 = sub_5BE340(*(_DWORD *)(a1 + 16), 0, 0);
  if ( v4 == -1 )
    return 0;
  sub_5BE2D0(*(_DWORD *)(*(_DWORD *)a1 + 4 * v3), v4);
  return 1;
}
