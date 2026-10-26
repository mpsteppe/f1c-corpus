HANDLE __stdcall sub_468880(int a1)
{
  DWORD v1; // eax
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  int v5; // edx
  HWND DlgItem; // eax
  HANDLE result; // eax

  if ( dword_7652A0 && ((v1 = WaitForSingleObject(dword_7652A0, dword_7652A4)) == 0 || v1 == 128) )
    v2 = &unk_765290;
  else
    v2 = 0;
  v3 = operator new(4u);
  *v3 = a1;
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
  if ( *v2 )
  {
    *(_DWORD *)(v2[1] + 4) = v4;
  }
  else
  {
    *v2 = v4;
    v2[2] = v4;
  }
  v5 = v2[3];
  v2[1] = v4;
  v2[3] = v5 + 1;
  switch ( a1 )
  {
    case 1:
      DlgItem = GetDlgItem(hDlg, 1005);
      break;
    case 2:
      DlgItem = GetDlgItem(hDlg, 1185);
      break;
    case 3:
      DlgItem = GetDlgItem(dword_7652C0, 1034);
      break;
    default:
      goto LABEL_19;
  }
  EnableWindow(DlgItem, 0);
LABEL_19:
  result = dword_7652A0;
  if ( dword_7652A0 )
    return (HANDLE)ReleaseMutex(dword_7652A0);
  return result;
}
