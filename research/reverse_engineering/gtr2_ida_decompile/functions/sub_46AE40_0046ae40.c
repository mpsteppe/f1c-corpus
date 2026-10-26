bool __userpurge sub_46AE40@<al>(int a1@<ecx>, int a2, int a3, int a4, int a5, bool *a6, int a7)
{
  const char *ServerData; // edi
  const char *v9; // edi
  char *v11; // eax
  char *v12; // eax
  char v13; // [esp+84h] [ebp-Ch]

  if ( a2 >= CNet::GetServerCount(*(CNet **)(a1 + 4)) )
    return 0;
  ServerData = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 2, (char *)WindowName);
  if ( strlen(ServerData) && _stricmp(off_759E28, ServerData) )
    return 0;
  v9 = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 11, "openplaying");
  if ( !_stricmp(v9, "openstaging") )
    return 0;
  *a6 = _stricmp(v9, "openplaying") != 0;
  v13 = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 19, 0) != 0;
  sub_4734F0(2, v13);
  v11 = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 1, (char *)WindowName);
  sub_630FE0(a5, v11, 31);
  *(_BYTE *)(a5 + 31) = 0;
  v12 = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 30, (char *)WindowName);
  *(_WORD *)(a5 + 162) = CNet::GetPing(*(CNet **)(a1 + 4), v12);
  *(_WORD *)(a5 + 164) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 4, 0);
  *(_BYTE *)(a5 + 105) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 8, 0);
  *(_BYTE *)(a5 + 106) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 10, 0);
  *(_BYTE *)(a5 + 160) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 32, 0);
  if ( a6 && a7 > 0 )
  {
    if ( CNet::GetServerData(*(CNet **)(a1 + 4), a2, 5, (char *)WindowName) )
      sub_4152E0();
  }
  *(_DWORD *)(a5 + 152) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 35, 0);
  *(_DWORD *)(a5 + 156) = CNet::GetServerData(*(CNet **)(a1 + 4), a2, 34, 0);
  return a5 + strlen((const char *)a5) + 1 != a5 + 1;
}
