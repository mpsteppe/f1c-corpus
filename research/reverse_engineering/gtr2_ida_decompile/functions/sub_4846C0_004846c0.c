int sub_4846C0()
{
  _DWORD *v0; // esi
  LRESULT v1; // edi
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  const CHAR **v5; // edi
  const CHAR *v6; // eax
  const CHAR *v7; // eax
  LRESULT v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // edi
  int v13; // eax
  const char *v14; // eax
  HWND DlgItem; // edi
  HWND v16; // esi
  const char *v18; // [esp-8h] [ebp-AE0h]
  int v19; // [esp+Ch] [ebp-ACCh] BYREF
  _DWORD *v20; // [esp+10h] [ebp-AC8h]
  _DWORD *v21; // [esp+14h] [ebp-AC4h]
  _DWORD *v22; // [esp+18h] [ebp-AC0h]
  int v23; // [esp+1Ch] [ebp-ABCh]
  LRESULT v24; // [esp+20h] [ebp-AB8h]
  CHAR Buffer[4]; // [esp+24h] [ebp-AB4h] BYREF
  char v26; // [esp+28h] [ebp-AB0h]
  CHAR String[84]; // [esp+74h] [ebp-A64h] BYREF
  LPARAM v28[64]; // [esp+C8h] [ebp-A10h] BYREF
  LPARAM v29[64]; // [esp+1C8h] [ebp-910h] BYREF
  LPARAM lParam[256]; // [esp+2C8h] [ebp-810h] BYREF
  LPARAM v31[256]; // [esp+6C8h] [ebp-410h] BYREF
  int v32; // [esp+AD4h] [ebp-4h]

  memset(v29, 0, sizeof(v29));
  v0 = 0;
  v24 = SendDlgItemMessageA(hWnd, 1003, 0x191u, 0x100u, (LPARAM)lParam);
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v1 = 0;
  v32 = 0;
  if ( v24 > 0 )
  {
    do
    {
      SendDlgItemMessageA(hWnd, 1003, 0x189u, lParam[v1], (LPARAM)v29);
      v2 = operator new(8u);
      v3 = v2;
      *(_DWORD *)Buffer = v2;
      LOBYTE(v32) = 1;
      if ( v2 )
      {
        *v2 = 0;
        v2[1] = -1;
        sub_615860(v29);
      }
      else
      {
        v3 = 0;
      }
      LOBYTE(v32) = 0;
      if ( v3 )
      {
        v4 = operator new(0xCu);
        if ( v4 )
        {
          *v4 = v3;
          v4[1] = 0;
          *((_BYTE *)v4 + 8) = 1;
        }
        else
        {
          v4 = 0;
        }
        if ( v20 )
        {
          v21[1] = v4;
        }
        else
        {
          v20 = v4;
          v22 = v4;
        }
        v21 = v4;
        ++v23;
      }
      ++v1;
    }
    while ( v1 < v24 );
    v0 = v20;
  }
  v22 = v0;
  if ( v0 )
  {
    v5 = (const CHAR **)*v0;
    if ( *v0 )
    {
      do
      {
        v6 = *v5;
        if ( !*v5 )
          v6 = WindowName;
        SendDlgItemMessageA(hWnd, 1000, 0x180u, 0, (LPARAM)v6);
        v7 = *v5;
        if ( !*v5 )
          v7 = WindowName;
        v8 = SendDlgItemMessageA(hWnd, 1003, 0x18Fu, 0, (LPARAM)v7);
        SendDlgItemMessageA(hWnd, 1003, 0x182u, v8, 0);
        v0 = (_DWORD *)v0[1];
        if ( !v0 )
          break;
        v5 = (const CHAR **)*v0;
      }
      while ( *v0 );
      v22 = v0;
    }
  }
  memset(v28, 0, sizeof(v28));
  String[4] = 0;
  v26 = 0;
  if ( SendDlgItemMessageA(hWnd, 1003, 0x191u, 0x100u, (LPARAM)v31) == 1 )
  {
    SendDlgItemMessageA(hWnd, 1003, 0x189u, v31[0], (LPARAM)v28);
    if ( sub_616840("SeasonRaces") )
    {
      v9 = sub_53B670(&unk_BE1CFD, v28);
      if ( v9 )
      {
        if ( sub_616630((char *)(v9 + 260)) )
        {
          v10 = sub_616630("TrackName");
          if ( v10 )
          {
            v11 = (const char *)sub_48D380(v10);
            sub_41D810(String, 0x4Fu, "%s", v11);
          }
          v12 = sub_616630("Track Type");
          v13 = sub_616630("Length");
          if ( v12 && v13 )
          {
            v18 = (const char *)sub_48D380(v13);
            v14 = (const char *)sub_48D380(v12);
            sub_41D810(Buffer, 0x4Fu, "%s, %s", v14, v18);
          }
        }
      }
    }
  }
  DlgItem = GetDlgItem(hWnd, 1041);
  v16 = GetDlgItem(hWnd, 1046);
  SetWindowTextA(DlgItem, String);
  SetWindowTextA(v16, Buffer);
  return sub_409FB0(&v19);
}
