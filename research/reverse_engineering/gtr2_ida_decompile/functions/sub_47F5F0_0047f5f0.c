HWND __stdcall sub_47F5F0(int a1)
{
  HWND result; // eax

  switch ( a1 )
  {
    case 1:
      result = (HWND)dwInitParam;
      break;
    case 2:
      result = dword_B6CE68;
      break;
    case 3:
      result = dword_B6CE6C;
      break;
    case 4:
      result = hDlg;
      break;
    case 5:
      result = hWnd;
      break;
    case 6:
      result = dword_B6CE78;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
