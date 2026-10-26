int __thiscall sub_4AF890(_DWORD **this)
{
  int v2; // eax
  int v3; // edi
  char *v4; // eax
  int result; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // [esp+10h] [ebp-108h]
  char v9[256]; // [esp+18h] [ebp-100h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 51);
  v3 = 0;
  if ( !v2 || !sub_4CE170(v2) )
    return v3;
  sub_4ABA50();
  sub_4DF020(this[12]);
  if ( CGarageOnline::FileExists((CGarageOnline *)dword_B6CBB4, v9) )
  {
    switch ( CGarageOnline::CanUploadFile((CGarageOnline *)dword_B6CBB4, (char *)(dword_B6CBB0 + 305), v9) )
    {
      case 0:
        sub_4CD6D0("GARAGE_SAVE_FILE_OVERWRITE_CONFIRMATION_ONLINE");
        goto LABEL_16;
      case 0xB:
LABEL_10:
        v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. File too large.");
        goto LABEL_14;
      case 0xC:
LABEL_11:
        v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Invalid Setup File.");
        goto LABEL_14;
      case 0xD:
        v7 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Could not read setup file.");
        sub_615860(v7);
        sub_4CD6D0("JOIN FAILURE PAGE");
        goto LABEL_13;
      case 0xE:
LABEL_13:
        v6 = sub_41D840(&byte_91CC38, "Cannot overwrite setup. You are not the owner of this file.");
LABEL_14:
        sub_615860(v6);
LABEL_15:
        sub_4CD6D0("JOIN FAILURE PAGE");
LABEL_16:
        v3 = -1;
        break;
      default:
        return v3;
    }
    return v3;
  }
  switch ( CGarageOnline::UploadFile((CGarageOnline *)dword_B6CBB4, (char *)(dword_B6CBB0 + 305), byte_B6DCF0, v9) )
  {
    case 0:
      CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB4, WindowName);
      if ( !(*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 49) )
        goto LABEL_16;
      sub_4D0AC0(v8);
      v4 = sub_41D840(&byte_91CC38, "Reading Folder...");
      sub_4D93B0(v4, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      result = -1;
      break;
    case 0xB:
      goto LABEL_10;
    case 0xC:
      goto LABEL_11;
    case 0xD:
      v6 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Could not read setup file.");
      goto LABEL_14;
    default:
      goto LABEL_15;
  }
  return result;
}
