int sub_4BB880()
{
  signed int v0; // eax
  struct tagMSG Msg; // [esp+10h] [ebp-1Ch] BYREF

  if ( PeekMessageA(&Msg, hWndParent, 0, 0, 0) )
  {
    while ( GetMessageA(&Msg, hWndParent, 0, 0) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
      if ( !PeekMessageA(&Msg, hWndParent, 0, 0, 0) )
        goto LABEL_4;
    }
    return -1;
  }
  else
  {
LABEL_4:
    if ( !byte_76621C )
    {
      v0 = sub_4CE920(&unk_7663E0);
      if ( v0 >= 0 )
        Sleep(v0);
    }
    return 0;
  }
}
