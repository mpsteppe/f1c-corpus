int __usercall sub_4B05E0@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  char *v4; // eax
  char v6[256]; // [esp+14h] [ebp-100h] BYREF

  v3 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 49);
  if ( !v3 )
    return 0;
  if ( !sub_4CE170(v3) )
    return 0;
  sub_4DF020(*(_DWORD *)(a1 + 48));
  sub_4ABA50();
  CGarageOnline::DownloadFile((CGarageOnline *)dword_B6CBB4, v6);
  CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB4, WindowName);
  if ( (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 49) )
  {
    sub_4D0AC0(a2);
    v4 = sub_41D840(&byte_91CC38, "Reading Folder...");
    sub_4D93B0(v4, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  return -1;
}
