int __thiscall sub_554E10(int this, int a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  int result; // eax
  _DWORD *i; // esi
  int v7; // edi
  int v8; // ebx

  v3 = 0;
  if ( *(int *)(this + 5040) > 0 )
  {
    v4 = (_DWORD *)(this + 4472);
    do
    {
      sub_554610(v4, 0);
      ++v3;
      v4 += 17;
    }
    while ( v3 < *(_DWORD *)(this + 5040) );
  }
  result = a2;
  if ( a2 )
  {
    result = *(_DWORD *)(a2 + 272);
    for ( i = *(_DWORD **)(result + 40); i; i = (_DWORD *)i[23] )
    {
      result = i[19];
      v7 = 0;
      if ( result > 0 )
      {
        v8 = (int)i;
        do
        {
          if ( (*(_DWORD *)(i[21] + 24) & 0x80000) == 0 )
            sub_554D70((char *)this, v8);
          result = i[19];
          ++v7;
          v8 += 96;
        }
        while ( v7 < result );
      }
    }
  }
  return result;
}
