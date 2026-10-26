// f1c  0x0051e0cd  size=15
int __cdecl sub_51E0CD(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 420);
  *(_BYTE *)(result + 28) = 1;
  return result;
}
