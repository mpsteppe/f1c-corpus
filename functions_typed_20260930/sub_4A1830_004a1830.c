int sub_4A1830()
{
  signed int v0; // eax
  tagMSG Msg; // [esp+10h] [ebp-1Ch] BYREF

  if ( PeekMessageA(&Msg, 0, 0, 0, 0) )
  {
    while ( GetMessageA(&Msg, 0, 0, 0) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
      if ( !PeekMessageA(&Msg, 0, 0, 0, 0) )
        goto LABEL_4;
    }
    return -1;
  }
  else
  {
LABEL_4:
    if ( !byte_7CE2E4 )
    {
      v0 = InputClamp(&byte_7CE498);
      if ( v0 >= 0 )
        Sleep(v0);
    }
    return 0;
  }
}

