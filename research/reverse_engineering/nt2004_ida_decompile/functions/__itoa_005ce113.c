char *__cdecl _itoa(int Value, char *Buffer, int Radix)
{
  if ( Radix == 10 && Value < 0 )
    xtoa(Value, Buffer, 10, 1);
  else
    xtoa(Value, Buffer, Radix, 0);
  return Buffer;
}
