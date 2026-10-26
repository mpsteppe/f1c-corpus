// f1c  0x005647d0  size=63
int __fastcall sub_5647D0(int a1, int a2)
{
  int v3; // ebx
  int v4; // eax

  v3 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a2, *(_DWORD *)(a1 + 4));
  v4 = sub_564A20(*(_DWORD *)(a1 + 16), 0, 0);
  if ( v4 == -1 )
    return 0;
  else
    return sub_5648B0(*(_DWORD *)(*(_DWORD *)a1 + 4 * v3), v4);
}
