DWORD *__cdecl _getptd()
{
  DWORD LastError; // ebx
  DWORD *v1; // esi
  DWORD *v2; // eax
  DWORD CurrentThreadId; // eax

  LastError = GetLastError();
  v1 = (DWORD *)dword_FB81EC(dword_912CA0);
  if ( !v1 )
  {
    v2 = (DWORD *)calloc(1u, 0x8Cu);
    v1 = v2;
    if ( !v2 || !dword_FB81F0(dword_912CA0, v2) )
      _amsg_exit(0x10u);
    v1[21] = (DWORD)&unk_913618;
    v1[5] = 1;
    CurrentThreadId = GetCurrentThreadId();
    v1[1] = -1;
    *v1 = CurrentThreadId;
  }
  SetLastError(LastError);
  return v1;
}
