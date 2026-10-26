int __stdcall sub_432BF0(_DWORD *a1)
{
  int result; // eax

  result = 1;
  if ( a1 )
  {
    if ( *a1 )
    {
      BufferWriteWithStringLengthCheck(a1, aS_7);
      BufferWriteWithStringLengthCheck(a1, asc_5C4060);
      BufferWriteWithStringLengthCheck(a1, aSS_4);
      BufferWriteWithStringLengthCheck(a1, aSS_4);
      BufferWriteWithStringLengthCheck(a1, aSD);
      BufferWriteWithStringLengthCheck(a1, aSS_4);
      BufferWriteWithStringLengthCheck(a1, asc_5C4044);
      return 0;
    }
  }
  return result;
}
