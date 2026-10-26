_DWORD *__userpurge sub_5F6160@<eax>(__int32 a1@<ebx>, int a2, _DWORD *a3, int a4)
{
  int v4; // esi

  if ( !a3 || !a2 )
    return 0;
  v4 = a4;
  sub_5E59F0(a1, (int)&a3, a2, a4 | 0x10000);
  *a3 |= v4;
  return a3;
}
