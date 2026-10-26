int __usercall sub_4B0220@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  char *v4; // eax
  char *v6; // eax
  char v7[256]; // [esp+14h] [ebp-100h] BYREF

  if ( !*(_BYTE *)(a1 + 276) )
  {
    sub_4ABA50();
    sub_4364D0();
    sub_437830();
    return 0;
  }
  v3 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 51);
  if ( !v3 )
    return 0;
  if ( !sub_4CE170(v3) )
    return 0;
  sub_4DF020(*(_DWORD *)(a1 + 48));
  sub_4ABA50();
  switch ( CGarageOnline::UploadFile((CGarageOnline *)dword_B6CBB4, (char *)(dword_B6CBB0 + 305), byte_B6DCF0, v7) )
  {
    case 0:
      CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB4, WindowName);
      if ( !(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 49) )
        return -1;
      sub_4D0AC0(a2);
      v4 = sub_41D840(&byte_91CC38, "Reading Folder...");
      sub_4D93B0(v4, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      return -1;
    case 0xB:
      v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. File too large.");
      goto LABEL_10;
    case 0xC:
      v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Invalid Setup File.");
      goto LABEL_10;
    case 0xD:
      v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Could not read setup file.");
LABEL_10:
      sub_615860(v6);
      break;
    default:
      break;
  }
  sub_4CD6D0("JOIN FAILURE PAGE");
  return -1;
}
