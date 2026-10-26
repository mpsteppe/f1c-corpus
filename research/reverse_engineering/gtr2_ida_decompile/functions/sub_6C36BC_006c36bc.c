int __thiscall sub_6C36BC(_DWORD *this, int a2, int a3, unsigned int a4, int a5)
{
  int v8; // ebx
  int v9; // ecx
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  _DWORD *v20; // [esp+28h] [ebp+10h]

  if ( a4 > 0x1E )
    return -2147467259;
  if ( this[63] < this[3] )
  {
    v8 = a3;
    do
    {
      v9 = *(_DWORD *)(this[6] + 4 * this[63]);
      v10 = *(_DWORD *)v9 & 0xFFF00000;
      v20 = (_DWORD *)v9;
      if ( v10 == 1933574144 || a5 && (v10 == 1930428416 || v10 == 1932525568) )
        return 0;
      if ( v10 == 1929379840 || v10 == 1932525568 || v10 == 1930428416 || v10 == 1931476992 )
      {
        v19 = 1;
        if ( v10 == 1930428416 || v10 == 1931476992 )
          v19 = 0;
        v17 = 0;
        if ( a4 )
        {
          v16 = **(_DWORD **)(v9 + 16);
          v11 = (_DWORD *)(v8 + 4);
          v18 = a4;
          do
          {
            if ( v16 == *(_DWORD *)((char *)v11 + a2 - v8) && *v11 == v19 )
              v17 = 1;
            ++v11;
            --v18;
          }
          while ( v18 );
          if ( v17 )
          {
            if ( v10 == 1929379840 || v10 == 1931476992 )
              *v20 = 0;
            else
              *v20 = 1933574144;
            ++this[63];
            v8 = a3;
            *(_DWORD *)(a2 + 4 * a4 + 4) = *(_DWORD *)(a2 + 4 * a4);
            *(_DWORD *)(a3 + 4 * a4 + 4) = *(_DWORD *)(a3 + 4 * a4);
            sub_6C36BC(a2, a3, a4 + 1, 1);
            v12 = *(_DWORD **)(this[6] + 4 * this[63]);
            v13 = *v12 & 0xFFF00000;
            switch ( v13 )
            {
              case 0x73400000u:
                *v12 = 0;
                break;
              case 0x73100000u:
                *v12 = 1931476993;
                break;
              case 0x73300000u:
                *v12 = 1929379841;
                break;
            }
            goto LABEL_37;
          }
          v8 = a3;
          v9 = *(_DWORD *)(this[6] + 4 * this[63]);
        }
        if ( v10 == 1929379840 || v10 == 1931476992 )
        {
          ++this[63];
          *(_DWORD *)(a2 + 4 * a4 + 4) = **(_DWORD **)(v9 + 16);
          *(_DWORD *)(v8 + 4 * a4 + 4) = v19;
          sub_6C36BC(a2, v8, a4 + 1, 0);
        }
      }
LABEL_37:
      v14 = this[63];
      if ( v14 >= this[3] )
        return -2147467259;
      v15 = **(_DWORD **)(this[6] + 4 * v14) & 0xFFF00000;
      if ( v15 == 1930428416 || v15 == 1932525568 )
        *(_DWORD *)(v8 + 4 * a4) = *(_DWORD *)(v8 + 4 * a4) == 0;
      ++this[63];
    }
    while ( this[63] < this[3] );
  }
  return 0;
}
