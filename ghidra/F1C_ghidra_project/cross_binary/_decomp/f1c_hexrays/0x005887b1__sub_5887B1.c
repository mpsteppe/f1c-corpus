// f1c  0x005887b1  size=60
int sub_5887B1(int a1, int a2, ...)
{
  int v2; // edi
  int v3; // ebx
  va_list va; // [esp+18h] [ebp+Ch] BYREF

  va_start(va, a2);
  sub_58C1B1(a1);
  v2 = sub_58E41B(a1);
  v3 = sub_58D04D(a1, a2, va);
  sub_58E4A8(v2, a1);
  sub_58C203(a1);
  return v3;
}
