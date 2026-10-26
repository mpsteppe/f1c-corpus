
void FUN_0057e410(void)

{
  int iVar1;
  BOOL BVar2;
  tagMSG tStack_1c;
  
  iVar1 = PeekMessageA(&tStack_1c,(HWND)0x0,0,0,0);
  while ((iVar1 != 0 && (BVar2 = GetMessageA(&tStack_1c,(HWND)0x0,0,0), BVar2 != 0))) {
    TranslateMessage(&tStack_1c);
    DispatchMessageA(&tStack_1c);
    iVar1 = PeekMessageA(&tStack_1c,(HWND)0x0,0,0,0);
  }
  return;
}

