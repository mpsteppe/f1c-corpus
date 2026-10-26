int sub_494530()
{
  char *v0; // eax
  int v1; // eax

  CINet::UpdateExecuteNow((CINet *)dword_B6CBB0, 1);
  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 33) )
  {
    v0 = sub_41D840(&byte_91CC38, "GTR will now close and the update will be installed.");
    sub_615860(v0);
  }
  v1 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753);
  if ( v1 )
    *(_DWORD *)(v1 + 276) = 3;
  sub_4CD6D0("OK CANCEL POPUP");
  return -1;
}
