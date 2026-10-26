int __thiscall sub_52F560(int *this, int a2)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // edx
  _DWORD *v5; // esi
  int v6; // esi
  int v7; // edi
  int result; // eax
  _DWORD *v9; // esi
  _DWORD *i; // edx
  int v11; // [esp+10h] [ebp-4h]

  v2 = this + 4;
  v11 = 8;
  do
  {
    v3 = 8;
    do
    {
      v4 = 0;
      if ( *v2 > 0 )
      {
        v5 = (_DWORD *)v2[1];
        while ( *v5 != a2 )
        {
          ++v4;
          ++v5;
          if ( v4 >= *v2 )
            goto LABEL_9;
        }
        v6 = *v2 - 1;
        *v2 = v6;
        *(_DWORD *)(v2[1] + 4 * v4) = *(_DWORD *)(v2[1] + 4 * v6);
      }
LABEL_9:
      v2 += 9;
      --v3;
    }
    while ( v3 );
    --v11;
  }
  while ( v11 );
  v7 = this[580];
  result = 0;
  if ( v7 > 0 )
  {
    v9 = (_DWORD *)this[581];
    for ( i = v9; *i != a2; ++i )
    {
      if ( ++result >= this[580] )
        return result;
    }
    this[580] = v7 - 1;
    v9[result] = v9[v7 - 1];
  }
  return result;
}
