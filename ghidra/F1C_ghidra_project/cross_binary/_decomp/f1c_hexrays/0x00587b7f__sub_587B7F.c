// f1c  0x00587b7f  size=23
int sub_587B7F()
{
  int result; // eax

  sub_587B97();
  dword_8D3E44 = sub_58BCA6();
  result = sub_58BC56();
  __asm { fnclex }
  return result;
}
