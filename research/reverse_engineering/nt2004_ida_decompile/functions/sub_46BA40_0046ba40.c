BOOL sub_46BA40()
{
  int v0; // eax
  void *v1; // edi
  int v2; // eax
  LPARAM v3; // esi
  int v4; // eax
  HWND DlgItem; // eax
  CHAR String[16]; // [esp+0h] [ebp-10h] BYREF

  v0 = sub_46B930((void *)dword_764ED8);
  *(_DWORD *)dword_600760 = v0;
  if ( *(_DWORD *)dword_7652C8 == 9597 )
  {
    v0 = 47;
  }
  else if ( *(_DWORD *)dword_7652C8 )
  {
    if ( v0 >= 2 )
    {
      if ( v0 <= 47 )
        goto LABEL_13;
      v0 = 47;
    }
    else
    {
      v0 = 2;
    }
  }
  else if ( v0 >= 2 )
  {
    if ( v0 <= 16 )
      goto LABEL_13;
    v0 = 16;
  }
  else
  {
    v0 = 2;
  }
  *(_DWORD *)dword_600760 = v0;
LABEL_13:
  SendDlgItemMessageA(hWnd, 1201, 0x406u, 1u, ((unsigned __int16)v0 << 16) | 2);
  v1 = (void *)dword_764ED8;
  v2 = sub_46B930((void *)dword_764ED8);
  v3 = *(_DWORD *)dword_600760;
  if ( v2 >= *(int *)dword_600760 )
    v4 = *(_DWORD *)dword_600760;
  else
    v4 = sub_46B930(v1);
  if ( v4 >= 2 )
  {
    if ( (int)sub_46B930(v1) < v3 )
      v3 = sub_46B930(v1);
  }
  else
  {
    v3 = 2;
  }
  SendDlgItemMessageA(hWnd, 1201, 0x405u, 1u, v3);
  sprintf(String, "%d", v3);
  DlgItem = GetDlgItem(hWnd, 1036);
  return SetWindowTextA(DlgItem, String);
}
