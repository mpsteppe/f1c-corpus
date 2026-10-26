char *__stdcall sub_457840(_DWORD *a1)
{
  char *result; // eax
  unsigned int v2; // [esp+4h] [ebp+4h]
  int v3; // [esp+4h] [ebp+4h]

  if ( *a1 )
  {
    if ( *a1 == 1 )
    {
      v2 = a1[1];
      result = &byte_629120;
      if ( v2 < 0x6E )
        return &aNA_0[9 * v2];
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v3 = a1[1];
    result = &byte_629120;
    if ( v3 < 128 )
    {
      if ( (unsigned int)v3 < 0x5A )
        return &aPause_0[16 * v3];
    }
    else if ( (unsigned int)(v3 - 128) < 0x58 )
    {
      return &aNA[16 * v3 - 2048];
    }
  }
  return result;
}
