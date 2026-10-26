void __thiscall sub_5AAED0(int *this, _DWORD *a2)
{
  int *v2; // edi
  _DWORD *i; // ebp
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // esi
  int j; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // ecx

  v2 = this;
  if ( a2 )
  {
    for ( i = *(_DWORD **)(sub_598170(a2) + 36); i; i = (_DWORD *)i[42] )
    {
      v4 = 0;
      if ( (int)i[43] > 0 )
      {
        v5 = (_DWORD *)(i[44] + 140);
        do
        {
          if ( (*(_BYTE *)(v5 - 19) & 2) != 0 )
          {
            v6 = *(_DWORD *)(*v5 + 16);
            if ( *(_DWORD *)(v6 + 8) )
            {
              sub_5A65C0(v2, *(_DWORD *)(v6 + 8));
              v7 = *(_DWORD *)(*v5 + 16);
              if ( *(_DWORD *)(v7 + 8) )
              {
                j_nullsub_6(*(void **)(v7 + 8));
                sub_5BE8AE();
              }
              v2 = this;
              *(_DWORD *)(*(_DWORD *)(*v5 + 16) + 8) = 0;
            }
            sub_5AB000(*v5);
          }
          v5 += 37;
          ++v4;
        }
        while ( v4 < i[43] );
      }
    }
    v8 = (_DWORD *)dword_7E5EC0;
    if ( dword_7E5EC0 )
    {
      do
      {
        for ( j = 0; j < v8[22]; ++j )
        {
          v10 = v8[4];
          if ( (*(_DWORD *)(v10 + 56) & 0x40000) != 0 )
          {
            v11 = *(_DWORD *)(v10 + 8);
            if ( v11 )
            {
              sub_5A65C0(v2, v11);
              v12 = v8[4];
              if ( *(_DWORD *)(v12 + 8) )
              {
                j_nullsub_6(*(void **)(v12 + 8));
                sub_5BE8AE();
              }
              v2 = this;
              *(_DWORD *)(v8[4] + 8) = 0;
            }
            sub_5AB000(v8);
          }
        }
        v8 = (_DWORD *)v8[3];
      }
      while ( v8 );
    }
  }
}
