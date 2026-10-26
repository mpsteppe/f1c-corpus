BOOL sub_56E430()
{
  BOOL result; // eax
  struct tagMSG Msg; // [esp+10h] [ebp-1Ch] BYREF

  for ( result = PeekMessageA(&Msg, dword_7E0818, 0, 0, 0); result; result = PeekMessageA(&Msg, dword_7E0818, 0, 0, 0) )
  {
    result = GetMessageA(&Msg, dword_7E0818, 0, 0);
    if ( !result )
      break;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  return result;
}
