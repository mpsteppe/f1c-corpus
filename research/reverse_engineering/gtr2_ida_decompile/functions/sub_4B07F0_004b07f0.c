int __thiscall sub_4B07F0(int this)
{
  int v1; // edi
  int v2; // eax
  char *v4; // eax
  char *v5; // eax
  char v6[256]; // [esp+18h] [ebp-100h] BYREF

  v1 = 0;
  if ( *(_BYTE *)(this + 276) )
  {
    v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 49);
    if ( v2 )
    {
      if ( sub_4CE170(v2) )
      {
        sub_4ABA50();
        if ( CGarageOnline::FileExists((CGarageOnline *)dword_B6CBB4, v6) )
        {
          switch ( CGarageOnline::CanUploadFile((CGarageOnline *)dword_B6CBB4, (char *)(dword_B6CBB0 + 305), v6) )
          {
            case 0:
              sub_4CD6D0("DELETE GARAGE ONLINE SETUP");
              return -1;
            case 0xB:
              v4 = sub_41D840(&byte_91CC38, "Setup Upload Failed. File too large.");
              goto LABEL_11;
            case 0xC:
              v4 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Invalid Setup File.");
              goto LABEL_11;
            case 0xD:
              v5 = sub_41D840(&byte_91CC38, "Setup Upload Failed. Could not read setup file.");
              sub_615860(v5);
              sub_4CD6D0("JOIN FAILURE PAGE");
              goto LABEL_10;
            case 0xE:
LABEL_10:
              v4 = sub_41D840(&byte_91CC38, "Cannot overwrite setup. You are not the owner of this file.");
LABEL_11:
              sub_615860(v4);
              sub_4CD6D0("JOIN FAILURE PAGE");
              v1 = -1;
              break;
            default:
              return v1;
          }
        }
      }
    }
  }
  return v1;
}
