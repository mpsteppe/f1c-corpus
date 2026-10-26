int sub_591C60(int a1, int a2, char *Format, ...)
{
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, Format);
  dword_7E5D4C = a2;
  return vsprintf(&byte_7E5D60, Format, va);
}
