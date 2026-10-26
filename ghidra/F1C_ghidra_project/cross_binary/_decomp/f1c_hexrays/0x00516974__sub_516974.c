// f1c  0x00516974  size=28
int __cdecl sub_516974(int a1)
{
  int result; // eax

  result = (**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 130);
  *(_BYTE *)(result + 128) = 0;
  return result;
}
