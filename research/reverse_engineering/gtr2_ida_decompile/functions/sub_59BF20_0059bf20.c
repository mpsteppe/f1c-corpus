BOOL sub_59BF20()
{
  BOOL result; // eax
  struct tagMSG Msg; // [esp+4h] [ebp-1Ch] BYREF

  for ( result = PeekMessageA(&Msg, dword_FB22D0, 0, 0, 0); result; result = PeekMessageA(&Msg, dword_FB22D0, 0, 0, 0) )
  {
    result = GetMessageA(&Msg, dword_FB22D0, 0, 0);
    if ( !result )
      break;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  return result;
}
