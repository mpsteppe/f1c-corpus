int __usercall sub_4ED0E5@<eax>(HWND a1@<eax>)
{
  signed int v1; // eax
  tagMSG Msg; // [esp+10h] [ebp-1Ch] BYREF

  if ( PeekMessageA(&Msg, a1, 0, 0, 0) )
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
    if ( !byte_B6F1BC )
    {
      v1 = sub_501E70(&byte_B6F530);
      if ( v1 >= 0 )
        Sleep(v1);
    }
    return 0;
  }
}
