int __thiscall sub_5AB0A0(int this, int a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  int result; // eax
  _DWORD *i; // esi
  int v7; // edi
  int v8; // ebx
  _DWORD *v9; // esi
  int v10; // edi
  int v11; // ebx

  v3 = 0;
  if ( *(int *)(this + 5136) > 0 )
  {
    v4 = (_DWORD *)(this + 4568);
    do
    {
      sub_5AA7A0(v4, 0);
      ++v3;
      v4 += 17;
    }
    while ( v3 < *(_DWORD *)(this + 5136) );
  }
  result = a2;
  if ( a2 )
  {
    result = *(_DWORD *)(a2 + 276);
    for ( i = *(_DWORD **)(result + 40); i; i = (_DWORD *)i[3] )
    {
      result = i[22];
      v7 = 0;
      if ( result > 0 )
      {
        v8 = (int)i;
        do
        {
          if ( (*(_DWORD *)(i[4] + 56) & 0x80000) == 0 )
            sub_5AB000((char *)this, v8);
          result = i[22];
          ++v7;
          v8 += 96;
        }
        while ( v7 < result );
      }
    }
    v9 = (_DWORD *)dword_7E5EC0;
    if ( dword_7E5EC0 )
    {
      do
      {
        result = v9[22];
        v10 = 0;
        if ( result > 0 )
        {
          v11 = (int)v9;
          do
          {
            if ( (*(_DWORD *)(v9[4] + 56) & 0x80000) == 0 )
              sub_5AB000((char *)this, v11);
            result = v9[22];
            ++v10;
            v11 += 96;
          }
          while ( v10 < result );
        }
        v9 = (_DWORD *)v9[3];
      }
      while ( v9 );
    }
  }
  return result;
}
