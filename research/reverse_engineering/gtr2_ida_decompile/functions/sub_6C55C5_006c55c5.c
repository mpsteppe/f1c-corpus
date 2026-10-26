int __stdcall sub_6C55C5(_DWORD *a1)
{
  int v3; // edi

  while ( 1 )
  {
    if ( !a1 )
      return 0;
    if ( a1[1] == 1 )
      break;
    switch ( a1[1] )
    {
      case 6:
        a1 = (_DWORD *)a1[6];
        break;
      case 8:
        return a1[5] * sub_6C55C5(a1[4]);
      case 9:
        return a1[6] * a1[7];
      case 0xB:
        a1 = (_DWORD *)a1[8];
        break;
      default:
        return 0;
    }
  }
  v3 = sub_6C55C5(a1[3]);
  return v3 + sub_6C55C5(a1[2]);
}
