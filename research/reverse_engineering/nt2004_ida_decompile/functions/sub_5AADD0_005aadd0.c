void __thiscall sub_5AADD0(void *this, _DWORD *a2)
{
  _DWORD *i; // edi
  int v4; // ebp
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // edi
  int j; // ebp
  int v10; // ecx
  int v11; // eax

  if ( a2 )
  {
    for ( i = *(_DWORD **)(sub_598170(a2) + 36); i; i = (_DWORD *)i[42] )
    {
      v4 = 0;
      if ( (int)i[43] > 0 )
      {
        v5 = i[44] + 140;
        do
        {
          if ( (*(_BYTE *)(v5 - 76) & 2) != 0 )
          {
            v6 = *(_DWORD *)(*(_DWORD *)v5 + 16);
            if ( !*(_DWORD *)(v6 + 24) )
            {
              *(_DWORD *)(v6 + 56) &= ~1u;
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v5 + 16) + 56) |= 8u;
              sub_5A6610((int)this, *(_DWORD *)(*(_DWORD *)v5 + 16), 0);
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v5 + 16) + 56) |= 1u;
            }
          }
          v5 += 148;
          ++v4;
        }
        while ( v4 < i[43] );
      }
    }
    v7 = (_DWORD *)dword_7E5EC0;
    v8 = 0;
    if ( dword_7E5EC0 )
    {
      do
      {
        for ( j = 0; j < v7[22]; ++j )
        {
          v10 = v7[4];
          v11 = *(_DWORD *)(v10 + 56);
          if ( (v11 & 0x40000) != 0 && !*(_DWORD *)(v10 + 24) )
          {
            if ( (v11 & 1) != 0 )
            {
              *(_DWORD *)(v10 + 56) = v11 & 0xFFFFFFFE;
              v8 = 1;
            }
            *(_DWORD *)(v7[4] + 56) |= 8u;
            sub_5A6610((int)this, v7[4], 0);
            if ( v8 )
            {
              *(_DWORD *)(v7[4] + 56) |= 1u;
              v8 = 0;
            }
          }
        }
        v7 = (_DWORD *)v7[3];
      }
      while ( v7 );
    }
  }
}
