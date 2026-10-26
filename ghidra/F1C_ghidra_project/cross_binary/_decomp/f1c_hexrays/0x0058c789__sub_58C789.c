// f1c  0x0058c789  size=115
DWORD __cdecl sub_58C789(int a1, LONG lDistanceToMove, DWORD dwMoveMethod)
{
  void *v3; // eax
  DWORD v4; // edi
  DWORD LastError; // eax

  v3 = (void *)sub_595A1F(a1);
  if ( v3 == (void *)-1 )
  {
    *(_DWORD *)sub_58AFCF() = 9;
    return -1;
  }
  v4 = SetFilePointer(v3, lDistanceToMove, 0, dwMoveMethod);
  if ( v4 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  if ( LastError )
  {
    sub_58AF5C(LastError);
    return -1;
  }
  *(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) &= ~2u;
  return v4;
}
