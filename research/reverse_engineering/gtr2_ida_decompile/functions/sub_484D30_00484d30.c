HANDLE sub_484D30()
{
  int v0; // esi
  int v1; // eax
  HWND v2; // edi
  DWORD v3; // eax
  _DWORD *v4; // eax
  HANDLE result; // eax

  v0 = sub_484CD0();
  v1 = *(_DWORD *)(v0 + 848);
  if ( v1 != 2 )
  {
    v2 = sub_47F5F0(v1);
    if ( dword_B6CE68 )
      ShowWindow(dword_B6CE68, 5);
    if ( v2 )
      ShowWindow(v2, 0);
    *(_DWORD *)(v0 + 848) = 2;
  }
  sub_484CD0();
  if ( hMutex && ((v3 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v3 == 128) )
    v4 = &unk_759EA8;
  else
    v4 = 0;
  *v4 = 3;
  sub_484CD0();
  result = hMutex;
  if ( hMutex )
    return (HANDLE)ReleaseMutex(hMutex);
  return result;
}
