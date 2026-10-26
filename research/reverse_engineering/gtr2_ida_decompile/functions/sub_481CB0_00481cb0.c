HANDLE __stdcall sub_481CB0(int a1)
{
  _DWORD *v1; // eax
  HWND DlgItem; // eax
  HANDLE result; // eax

  if ( hHandle )
    WaitForSingleObject(hHandle, dword_B6CECC);
  v1 = operator new(4u);
  *v1 = a1;
  sub_5FDFB0(v1, 1);
  switch ( a1 )
  {
    case 1:
      DlgItem = GetDlgItem(hDlg, 1005);
      break;
    case 2:
      DlgItem = GetDlgItem(hDlg, 1185);
      break;
    case 4:
      DlgItem = GetDlgItem(dword_B6CE78, 1034);
      break;
    default:
      goto LABEL_10;
  }
  EnableWindow(DlgItem, 0);
LABEL_10:
  result = hHandle;
  if ( hHandle )
    return (HANDLE)ReleaseMutex(hHandle);
  return result;
}
