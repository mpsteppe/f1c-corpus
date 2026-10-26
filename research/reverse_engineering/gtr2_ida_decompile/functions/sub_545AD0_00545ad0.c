char __thiscall sub_545AD0(_DWORD *this, float *a2)
{
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // ecx
  double v5; // st7
  double v6; // st6

  v2 = this[14];
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = this + 15;
    while ( 2 )
    {
      switch ( *(_DWORD *)(*v4 + 4) )
      {
        case 0:
          v5 = 0.0;
          v6 = a2[11];
          goto LABEL_7;
        case 2:
          v5 = 0.0;
          v6 = a2[10];
          goto LABEL_7;
        case 6:
        case 0x14:
          v5 = 0.0;
          v6 = a2[12];
LABEL_7:
          if ( v6 == v5 )
            goto LABEL_8;
          return 1;
        default:
LABEL_8:
          ++v3;
          ++v4;
          if ( v3 >= v2 )
            return 0;
          continue;
      }
    }
  }
  return 0;
}
