int sub_52E4E0(int a1, ...)
{
  CHAR OutputString[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+108h] [ebp+8h] BYREF

  va_start(va, a1);
  SafeStringFormat(OutputString, a1, va);
  OutputDebugStringA(OutputString);
  return 0;
}
