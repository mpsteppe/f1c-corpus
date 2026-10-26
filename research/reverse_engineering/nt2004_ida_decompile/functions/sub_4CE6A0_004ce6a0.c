char *__thiscall sub_4CE6A0(_DWORD *this, int a2, char *Destination, size_t Count)
{
  const char *v4; // eax
  char *result; // eax

  v4 = (const char *)this[7 * a2 + 3222];
  if ( !v4 )
    v4 = &byte_629120;
  result = strncpy(Destination, v4, Count);
  Destination[Count] = 0;
  return result;
}
