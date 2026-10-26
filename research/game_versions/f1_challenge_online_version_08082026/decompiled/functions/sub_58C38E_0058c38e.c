int __cdecl sub_58C38E(int a1)
{
  int v1; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( sub_595A1F(a1) == -1
    || (a1 == 1 || a1 == 2) && (v1 = sub_595A1F(2), sub_595A1F(1) == v1)
    || (v2 = (void *)sub_595A1F(a1), CloseHandle(v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  sub_5959A0(a1);
  *(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) = 0;
  if ( !LastError )
    return 0;
  sub_58AF5C(LastError);
  return -1;
}
