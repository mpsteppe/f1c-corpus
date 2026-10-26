int __thiscall sub_685FA9(_DWORD *this)
{
  unsigned int v1; // ebx
  int v2; // edi
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // esi
  _DWORD *v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // esi
  unsigned int i; // edi
  int v10; // eax
  int v11; // edx
  int v12; // esi

  v1 = 0;
  v2 = 0;
  if ( this[2] )
  {
    do
    {
      v3 = this[5];
      v4 = *(_DWORD **)(v3 + 4 * v1);
      v5 = v4[14];
      if ( v5 != -1 )
      {
        v6 = *(_DWORD **)(v3 + 4 * v5);
        v4[1] = v6[1];
        v4[2] = v6[2];
        v4[3] = v6[3];
        v4[4] = v6[4];
        v4[18] = v6[18];
        v4[19] = v6[19];
        v4[20] = v6[20];
        v7 = v6[21];
        if ( v7 == -1 )
        {
          v6[21] = v4[21];
          v6[22] = v4[22];
          v6[23] = v4[23];
        }
        else
        {
          if ( v7 >= v4[21] )
            v7 = v4[21];
          v4[21] = v7;
          v6[21] = v7;
          v8 = v6[22];
          if ( v8 <= v4[22] )
            v8 = v4[22];
          v4[22] = v8;
          v6[22] = v8;
          v6[23] += v4[23];
        }
        v2 = 1;
      }
      ++v1;
    }
    while ( v1 < this[2] );
    if ( v2 )
    {
      for ( i = 0; i < this[2]; ++i )
      {
        v10 = this[5];
        v11 = *(_DWORD *)(v10 + 4 * i);
        v12 = *(_DWORD *)(v11 + 56);
        if ( v12 != -1 )
          *(_DWORD *)(v11 + 84) = *(_DWORD *)(*(_DWORD *)(v10 + 4 * v12) + 84);
      }
    }
  }
  return 0;
}
