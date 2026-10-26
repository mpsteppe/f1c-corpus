bool __thiscall sub_494770(_DWORD **this)
{
  const char *v2; // edi
  char *v3; // eax
  bool result; // al
  int v5; // [esp+0h] [ebp-8h]

  v2 = (const char *)sub_4CE170(this);
  if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 49) )
  {
    sub_4D0AC0(v5);
    v3 = sub_41D840(&byte_91CC38, "Reading Folder...");
    sub_4D93B0(v3, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 52) )
    sub_4D0AC0(v5);
  result = CGarageOnline::SetFolder((CGarageOnline *)dword_B6CBB4, v2, 1);
  if ( result )
    return CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB4, WindowName);
  return result;
}
