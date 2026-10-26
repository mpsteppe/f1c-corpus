// f1c  0x0052e4e0  size=52
int sub_52E4E0(int a1, ...)
{
  CHAR OutputString[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+108h] [ebp+8h] BYREF

  va_start(va, a1);
  sub_58AC95(OutputString, a1, va);
  OutputDebugStringA(OutputString);
  return 0;
}
