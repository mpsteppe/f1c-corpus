BOOL sub_47FD60()
{
  HWND DialogParamA; // eax
  BOOL result; // eax
  struct tagMSG Msg; // [esp+0h] [ebp-1Ch] BYREF

  DialogParamA = (HWND)dwInitParam;
  if ( !dwInitParam )
  {
    DialogParamA = CreateDialogParamA(dword_B6F1AC, (LPCSTR)0x69, dword_B6F1B8, DialogFunc, 0);
    dwInitParam = (LPARAM)DialogParamA;
  }
  ShowWindow(DialogParamA, 5);
  for ( result = PeekMessageA(&Msg, (HWND)dwInitParam, 0, 0, 0);
        result;
        result = PeekMessageA(&Msg, (HWND)dwInitParam, 0, 0, 0) )
  {
    result = GetMessageA(&Msg, (HWND)dwInitParam, 0, 0);
    if ( result <= 0 )
      break;
    if ( !IsDialogMessageA((HWND)dwInitParam, &Msg) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
  return result;
}
