int sub_4942D0()
{
  char *v0; // eax
  int v1; // eax

  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 33) )
  {
    v0 = sub_41D840(&byte_91CC38, "Start downloading GTR Update ?");
    sub_615860(v0);
  }
  v1 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753);
  if ( v1 )
    *(_DWORD *)(v1 + 276) = 2;
  sub_4CD6D0("OK CANCEL POPUP");
  return -1;
}
