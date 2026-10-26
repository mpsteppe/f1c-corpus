int __stdcall sub_6958A1(_DWORD *a1, int *a2)
{
  _DWORD *v2; // esi
  int v3; // edi
  int v6; // eax
  int *v7; // ecx
  int v8; // edx
  unsigned int i; // ebx
  int v10; // eax
  int v11; // [esp-4h] [ebp-14h]

  v2 = a1;
  v3 = 0;
  if ( !a1 )
    return 0;
  switch ( a1[1] )
  {
    case 1:
      do
      {
        if ( v2[1] != 1 )
          break;
        v10 = sub_6958A1(v2[2], &a2[4 * v3]);
        v2 = (_DWORD *)v2[3];
        v3 += v10;
      }
      while ( v2 );
      if ( v2 )
        v3 += sub_6958A1(v2, &a2[4 * v3]);
      return v3;
    case 6:
      return sub_6958A1(a1[6], a2);
    case 8:
      for ( i = 0; i < a1[5]; ++i )
        v3 += sub_6958A1(a1[4], &a2[4 * v3]);
      return v3;
    case 9:
      v3 = a1[6] * a1[7];
      v6 = 3;
      switch ( a1[5] )
      {
        case 0:
          v6 = 0;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
          v6 = 1;
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          v11 = 2;
          goto LABEL_15;
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
          v6 = 5;
          break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x1D:
          v11 = 4;
LABEL_15:
          v6 = v11;
          break;
        default:
          break;
      }
      if ( v3 )
      {
        v7 = a2;
        v8 = a1[6] * a1[7];
        do
        {
          *v7 = v6;
          v7 += 4;
          --v8;
        }
        while ( v8 );
      }
      return v3;
    case 0xB:
      return sub_6958A1(a1[8], a2);
  }
  return v3;
}
