// f1c  0x00595f82  size=133
__int64 __cdecl sub_595F82(int a1, LONG a2, int a3, DWORD dwMoveMethod)
{
  void *v4; // eax
  DWORD LastError; // eax
  __int64 lDistanceToMove; // [esp+8h] [ebp-8h] BYREF

  HIDWORD(lDistanceToMove) = a3;
  v4 = (void *)sub_595A1F(a1);
  if ( v4 == (void *)-1 )
  {
    *(_DWORD *)sub_58AFCF() = 9;
    return -1;
  }
  LODWORD(lDistanceToMove) = SetFilePointer(v4, a2, (PLONG)&lDistanceToMove + 1, dwMoveMethod);
  if ( (_DWORD)lDistanceToMove == -1 )
  {
    LastError = GetLastError();
    if ( LastError )
    {
      sub_58AF5C(LastError);
      return -1;
    }
  }
  *(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) &= ~2u;
  return lDistanceToMove;
}
