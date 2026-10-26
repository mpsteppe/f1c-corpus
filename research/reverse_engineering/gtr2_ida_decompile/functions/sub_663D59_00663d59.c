unsigned int __thiscall sub_663D59(int this, _DWORD *a2, char *a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  unsigned int v6; // ebx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // [esp-8h] [ebp-14h]

  v3 = a2;
  v4 = 0;
  if ( !a2 )
    return 0;
  v6 = 0;
  switch ( a2[1] )
  {
    case 1:
      do
      {
        if ( v3[1] != 1 )
          break;
        v9 = sub_663D59(v3[2], &a3[4 * v6]);
        v3 = (_DWORD *)v3[3];
        v6 += v9;
      }
      while ( v3 );
      if ( v3 )
        v6 += sub_663D59(v3, &a3[4 * v6]);
      return v6;
    case 6:
      return sub_663D59(a2[6], a3);
    case 8:
      if ( a2[5] )
      {
        do
        {
          v6 += sub_663D59(a2[4], &a3[4 * v6]);
          ++v4;
        }
        while ( v4 < a2[5] );
      }
      return v6;
    case 9:
      v6 = a2[6] * a2[7];
      v8 = 0;
      switch ( a2[5] )
      {
        case 0:
          v10 = 23;
          goto LABEL_14;
        case 1:
        case 5:
          v10 = 2;
LABEL_14:
          v8 = v10;
          break;
        case 2:
        case 6:
          v8 = (unsigned int)&dword_2000000 + 2;
          break;
        case 3:
        case 7:
          v8 = 67108866;
          break;
        case 4:
        case 8:
          v8 = 134217730;
          break;
        case 0xA:
          v8 = (unsigned int)&dword_2000000;
          break;
        case 0xB:
          v8 = 0x4000000;
          break;
        case 0xC:
          v8 = 0x8000000;
          break;
        default:
          break;
      }
      if ( (*(_BYTE *)(this + 20) & 0x20) != 0 )
        v8 = (unsigned int)&dword_2000000 | v8 & 0xF3FFFFFF;
      if ( v6 )
        memset32(a3, v8, v6);
      return v6;
    case 0xB:
      return sub_663D59(a2[8], a3);
  }
  sub_663C07((_DWORD *)this, 0, 0, "internal error: unknown node");
  return v6;
}
