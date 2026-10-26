int __thiscall sub_4B09E0(int this)
{
  char v2; // al
  int v3; // ecx
  int v4; // eax
  char *v5; // eax
  _DWORD FileName[4]; // [esp+0h] [ebp-114h] BYREF

  v2 = *(_BYTE *)(this + 276);
  v3 = *(_DWORD *)(this + 48);
  if ( v2 )
    v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 28))(v3, 49);
  else
    v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 28))(v3, 47);
  if ( !v4 || !sub_4CE170(v4) )
    return 0;
  FileName[1] = *(unsigned __int8 *)(this + 276);
  FileName[0] = 256;
  sub_4ABA50();
  if ( !*(_BYTE *)(this + 276) )
  {
    if ( (unsigned __int8)sub_617680((char *)FileName) )
    {
      sub_437C50();
      sub_437830();
    }
    return 0;
  }
  sub_4DF020(*(_DWORD *)(this + 48));
  if ( dword_B6CBB4 )
  {
    CGarageOnline::DeleteRemoteFile((CGarageOnline *)dword_B6CBB4, (char *)FileName);
    CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB4, WindowName);
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48)) )
    {
      sub_4D0AC0(49);
      v5 = sub_41D840(&byte_91CC38, "Reading Folder...");
      sub_4D93B0(v5, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
  }
  return -1;
}
