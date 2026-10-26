HANDLE __thiscall sub_484200(_DWORD *this)
{
  DWORD v2; // eax
  _DWORD *v3; // ebp
  _DWORD **v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // eax
  HWND DlgItem; // eax
  int v10; // eax
  _DWORD **v11; // eax
  DWORD v12; // eax
  const char **v13; // edi
  const char *v14; // eax
  HANDLE result; // eax

  if ( hHandle && ((v2 = WaitForSingleObject(hHandle, dword_B6CECC)) == 0 || v2 == 128) )
    v3 = &unk_B6CEB8;
  else
    v3 = 0;
  v4 = (_DWORD **)*v3;
  v5 = *v3 == 0;
  v3[2] = *v3;
  if ( !v5 )
  {
    v6 = *v4;
    if ( v6 )
    {
      while ( 1 )
      {
        v7 = *v6 - 1;
        if ( v7 )
        {
          v8 = v7 - 1;
          if ( v8 )
          {
            if ( v8 == 2 )
            {
              if ( this[217] )
                sub_4839A0(this);
              else
                this[217] = 1;
            }
            goto LABEL_17;
          }
          this[217] = 2;
          DlgItem = GetDlgItem(hDlg, 1185);
        }
        else
        {
          this[217] = 4;
          DlgItem = GetDlgItem(hDlg, 1005);
        }
        EnableWindow(DlgItem, 0);
LABEL_17:
        v10 = v3[2];
        if ( v10 )
        {
          v11 = *(_DWORD ***)(v10 + 4);
          v3[2] = v11;
          if ( v11 )
          {
            v6 = *v11;
            if ( v6 )
              continue;
          }
        }
        break;
      }
    }
  }
  if ( (int)v3[3] > 0 )
    sub_47FAA0(this, 1);
  sub_525140(v3);
  if ( hHandle )
    ReleaseMutex(hHandle);
  if ( dword_B6CEDC && ((v12 = WaitForSingleObject(dword_B6CEDC, dword_B6CEE0)) == 0 || v12 == 128) )
    v13 = (const char **)&unk_B6CED4;
  else
    v13 = 0;
  v14 = *v13;
  if ( !*v13 )
    v14 = WindowName;
  if ( strlen(v14) )
  {
    sub_47F8E0();
    sub_615860(WindowName);
  }
  result = dword_B6CEDC;
  if ( dword_B6CEDC )
    return (HANDLE)ReleaseMutex(dword_B6CEDC);
  return result;
}
