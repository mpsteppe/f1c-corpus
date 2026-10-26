_BYTE *__fastcall sub_4EDED0(int a1)
{
  unsigned int v1; // edx
  _BYTE *result; // eax

  v1 = a1 + 24992;
  result = (_BYTE *)(a1 + 24992 + strlen((const char *)(a1 + 24992)));
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
