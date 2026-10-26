unsigned int __stdcall sub_49A330(LPCSTR lpSrcStr)
{
  unsigned int result; // eax

  sub_589901(lpSrcStr);
  result = *lpSrcStr - 65;
  if ( result >= 0x1A )
    return -1;
  return result;
}

