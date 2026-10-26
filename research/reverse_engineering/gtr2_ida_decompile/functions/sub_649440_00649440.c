int sub_649440(char *Buffer, unsigned int a2, char *Format, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, Format);
  if ( a2 <= 0x7FFFFFFF )
    return sub_649374(Buffer, a2, Format, va);
  else
    return -2147024809;
}
