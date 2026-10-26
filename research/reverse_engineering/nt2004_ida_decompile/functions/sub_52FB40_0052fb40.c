int sub_52FB40(char *Format, ...)
{
  CHAR OutputString[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+108h] [ebp+8h] BYREF

  va_start(va, Format);
  vsprintf(OutputString, Format, va);
  OutputDebugStringA(OutputString);
  return 0;
}
