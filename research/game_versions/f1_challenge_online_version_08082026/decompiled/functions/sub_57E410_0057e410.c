BOOL sub_57E410()
{
  BOOL result; // eax
  struct tagMSG Msg; // [esp+10h] [ebp-1Ch] BYREF

  for ( result = PeekMessageA(&Msg, 0, 0, 0, 0); result; result = PeekMessageA(&Msg, 0, 0, 0, 0) )
  {
    result = GetMessageA(&Msg, 0, 0, 0);
    if ( !result )
      break;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  return result;
}
