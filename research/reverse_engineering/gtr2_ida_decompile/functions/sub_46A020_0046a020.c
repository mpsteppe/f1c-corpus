int __fastcall sub_46A020(CNet *a1, int a2, int a3)
{
  const char *ServerData; // eax
  const char *v4; // eax
  const char *v5; // eax
  char *v7; // [esp+8h] [ebp-54h]
  char Buffer[80]; // [esp+Ch] [ebp-50h] BYREF

  Buffer[0] = 0;
  byte_B6CBA0 = 1;
  switch ( a2 )
  {
    case 0:
      ServerData = CNet::GetServerData(a1, a3, 30, (char *)WindowName);
      sprintf(Buffer, "Added %s", ServerData);
      break;
    case 1:
      v4 = CNet::GetServerData(a1, a3, 1, "(NONE)");
      sprintf(Buffer, "Updated %s", v4);
      break;
    case 2:
      v5 = CNet::GetServerData(a1, a3, 30, (char *)WindowName);
      sprintf(Buffer, "Couldn't update %s", v5);
      break;
    case 3:
      sprintf(Buffer, "Server deleted from list");
      break;
    case 4:
      sprintf(Buffer, "Update Complete");
      break;
    default:
      break;
  }
  v7 = sub_41D840(&byte_91CC38, Buffer);
  return sub_4738F0(v7);
}
