int __thiscall sub_545D00(_DWORD *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // ebp
  int i; // esi
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  _DWORD *v8; // ecx
  int v9; // edx
  int v10; // eax
  int result; // eax
  int v12; // edi
  _DWORD *v13; // esi
  _DWORD *v14; // eax
  int v15; // edx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v3 = this;
  if ( (a2 & 0x20) != 0 )
  {
    this[108] = 0;
  }
  else if ( ((unsigned __int8)a3 & 0x20) != 0 )
  {
    this[59] |= 0x800u;
  }
  for ( i = this[64]; i; i = *(_DWORD *)(i + 260) )
  {
    if ( *(_DWORD *)(i + 236) )
      RecursiveTraversal(a2, a3, 0);
  }
  if ( v3[66] )
    RecursiveTraversal(a2, a3, 0);
  v5 = *(_DWORD *)(v3[68] + 36);
  if ( v5 )
  {
    v6 = a2 & 0x1800;
    v7 = (unsigned __int16)a3 & 0x1800;
    do
    {
      switch ( v6 )
      {
        case 2048:
          *(_DWORD *)(v5 + 156) |= 0x40u;
          break;
        case 4096:
          *(_DWORD *)(v5 + 156) |= 0x80u;
          break;
        case 6144:
          *(_BYTE *)(v5 + 156) |= 0xC0u;
          break;
      }
      switch ( v7 )
      {
        case 2048:
          *(_DWORD *)(v5 + 156) &= ~0x40u;
          break;
        case 4096:
          *(_DWORD *)(v5 + 156) &= ~0x80u;
          break;
        case 6144:
          *(_DWORD *)(v5 + 156) &= 0xFFFFFF3F;
          break;
      }
      v5 = *(_DWORD *)(v5 + 192);
    }
    while ( v5 );
    v3 = this;
  }
  v8 = a3;
  v9 = 0;
  v20 = 0;
  do
  {
    switch ( v9 )
    {
      case 0:
        v8 = (_DWORD *)v3[110];
        v10 = v3[109];
        goto LABEL_33;
      case 1:
        v8 = (_DWORD *)v3[112];
        v10 = v3[111];
        goto LABEL_33;
      case 2:
        v8 = (_DWORD *)v3[114];
        v10 = v3[113];
        goto LABEL_33;
      case 3:
        v8 = (_DWORD *)v3[116];
        v10 = v3[115];
LABEL_33:
        a2 = v10;
        break;
      default:
        break;
    }
    result = a2;
    if ( a2 > 0 )
    {
      v12 = (unsigned __int16)a3 & 0x1800;
      v13 = v8 + 9;
      v18 = a2;
      do
      {
        switch ( v12 )
        {
          case 2048:
            *v8 &= ~0x400u;
            break;
          case 4096:
            v16 = v13;
            v17 = 8;
            do
            {
              if ( *v16 == 8 )
              {
                *v16 = 0;
                v16[1] = 0;
                v16[3] = 0;
              }
              v16 += 16;
              --v17;
            }
            while ( v17 );
            break;
          case 6144:
            *v8 &= ~0x400u;
            v14 = v13;
            v15 = 8;
            do
            {
              if ( *v14 == 8 )
              {
                *v14 = 0;
                v14[1] = 0;
                v14[3] = 0;
              }
              v14 += 16;
              --v15;
            }
            while ( v15 );
            break;
        }
        v8 += 132;
        v13 += 132;
        result = --v18;
      }
      while ( v18 );
      v9 = v20;
    }
    v20 = ++v9;
  }
  while ( v9 < 4 );
  return result;
}
