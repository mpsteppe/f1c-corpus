// f1c  0x0054c0b0  size=44
unsigned int *__thiscall sub_54C0B0(_DWORD *this, unsigned int *a2, unsigned int *a3)
{
  unsigned int *result; // eax

  if ( a2 )
    *a2 = ((unsigned int)~this[15] >> 1) & 1;
  result = a3;
  if ( a3 )
    *a3 = ((unsigned int)~this[15] >> 2) & 1;
  return result;
}
