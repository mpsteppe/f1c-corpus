unsigned int __stdcall sub_6B7D98(_DWORD *a1, int a2)
{
  int v2; // edx
  unsigned int v3; // ecx
  unsigned int result; // eax

  a1[25] = a2;
  a1[26] = a1[61] + 1;
  do
  {
    if ( sub_6B8942(a1 + 25, 0) )
    {
      if ( a1[31] )
        sub_679F05((int)a1, a1[31]);
      sub_679F05((int)a1, (int)"zlib error");
    }
    if ( !a1[29] )
    {
      sub_6B7BD3((int)a1, a1[39], a1[40]);
      a1[28] = a1[39];
      a1[29] = a1[40];
    }
  }
  while ( a1[26] );
  v2 = a1[54];
  if ( v2 )
  {
    a1[54] = a1[55];
    a1[55] = v2;
  }
  sub_6B7C17((int)a1);
  v3 = a1[73];
  result = ++a1[74];
  if ( v3 && result >= v3 )
    return sub_67A35B(a1);
  return result;
}
