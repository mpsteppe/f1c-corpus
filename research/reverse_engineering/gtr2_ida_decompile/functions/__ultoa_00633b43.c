char *__cdecl _ultoa(unsigned int Value, char *Buffer, int Radix)
{
  xtoa(Value, Buffer, Radix, 0);
  return Buffer;
}
