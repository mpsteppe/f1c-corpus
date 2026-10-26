unsigned int __stdcall sub_67A35B(_DWORD *a1)
{
  unsigned int result; // eax
  int v2; // eax
  int v3; // ecx

  result = a1[53];
  if ( result < a1[48] )
  {
    while ( 1 )
    {
      if ( sub_6B8942(a1 + 25, 2) )
      {
        if ( a1[31] )
          sub_679F05((int)a1, a1[31]);
        sub_679F05((int)a1, (int)"zlib error");
      }
      if ( a1[29] )
        break;
      sub_6B7BD3(a1, a1[39], a1[40]);
      a1[28] = a1[39];
      a1[29] = a1[40];
    }
    v2 = a1[40];
    v3 = a1[29];
    if ( v2 != v3 )
    {
      sub_6B7BD3(a1, a1[39], v2 - v3);
      a1[28] = a1[39];
      a1[29] = a1[40];
    }
    a1[74] = 0;
    return sub_67A826(a1);
  }
  return result;
}
