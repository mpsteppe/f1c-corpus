HWND __stdcall sub_46C170(int a1)
{
  HWND result; // eax

  switch ( a1 )
  {
    case 1:
      result = dword_7652B0;
      break;
    case 2:
      result = dword_7652B4;
      break;
    case 3:
      result = hDlg;
      break;
    case 4:
      result = hWnd;
      break;
    case 5:
      result = dword_7652C0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
