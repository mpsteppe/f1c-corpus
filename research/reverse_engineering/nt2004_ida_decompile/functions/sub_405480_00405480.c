int sub_405480(char *Buffer, size_t BufferCount, char *Format, ...)
{
  int result; // eax
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, Format);
  result = _vsnprintf(Buffer, BufferCount, Format, va);
  Buffer[BufferCount] = 0;
  return result;
}
