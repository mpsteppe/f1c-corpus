// f1c  0x004c69e0  size=45
_BYTE *__fastcall sub_4C69E0(int a1)
{
  unsigned int v1; // edx
  _BYTE *result; // eax

  v1 = a1 + 18196;
  result = (_BYTE *)(a1 + 18196 + strlen((const char *)(a1 + 18196)));
  if ( (unsigned int)result > v1 )
  {
    while ( *result != 92 )
    {
      if ( (unsigned int)--result <= v1 )
        return result;
    }
    ++result;
  }
  return result;
}
