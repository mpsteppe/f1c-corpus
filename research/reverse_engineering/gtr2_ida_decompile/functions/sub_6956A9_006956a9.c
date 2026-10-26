int __stdcall sub_6956A9(int a1, int a2, int *a3)
{
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // edx
  unsigned int i; // edx
  int v9; // ecx
  int v10; // eax
  bool v11; // cc

  if ( !a1 || *(_DWORD *)(a1 + 4) != 9 || !a2 || *(_DWORD *)(a2 + 4) != 9 )
    return -2147467259;
  v3 = *(_DWORD *)(a1 + 20);
  v4 = *(_DWORD *)(a2 + 20);
  if ( v3 == v4 )
  {
    *a3 = v3;
    return 0;
  }
  v5 = dword_741410[2 * v4];
  if ( dword_741410[2 * v3] > v5 )
    v5 = dword_741410[2 * v3];
  v6 = dword_741414[2 * v4] & dword_741414[2 * v3];
  v7 = 1;
  if ( (v6 & 1) != 0 )
  {
    *a3 = 0;
    return 0;
  }
  if ( (v6 & 4) != 0 )
  {
    if ( !v5 )
    {
      *a3 = 5;
      return 0;
    }
    v7 = 8;
    switch ( v5 )
    {
      case 8u:
        *a3 = 6;
        return 0;
      case 0x10u:
        *a3 = 7;
        return 0;
      case 0x20u:
      case 0x40u:
LABEL_17:
        *a3 = v7;
        return 0;
    }
    return 0;
  }
  if ( (v6 & 2) != 0 )
  {
    switch ( v5 )
    {
      case 0u:
        goto LABEL_17;
      case 8u:
        *a3 = 2;
        break;
      case 0x10u:
        *a3 = 3;
        break;
      case 0x20u:
      case 0x40u:
        *a3 = 4;
        break;
    }
    return 0;
  }
  if ( (v6 & 8) == 0 )
  {
    if ( (v6 & 0x10) != 0 )
    {
      for ( i = 0; i < 2; ++i )
      {
        v9 = *(_DWORD *)(a1 + 20);
        if ( i )
        {
          v10 = *(_DWORD *)(a2 + 20);
        }
        else
        {
          v9 = *(_DWORD *)(a2 + 20);
          v10 = *(_DWORD *)(a1 + 20);
        }
        if ( v9 == 13 )
        {
LABEL_55:
          *a3 = v10;
          return 0;
        }
        if ( v9 == 15 )
        {
          if ( v10 < 15 )
            continue;
          v11 = v10 <= 19;
        }
        else
        {
          if ( v9 != 20 || v10 < 20 )
            continue;
          v11 = v10 <= 24;
        }
        if ( v11 )
          goto LABEL_55;
      }
    }
    return -2147467259;
  }
  if ( v5 )
  {
    switch ( v5 )
    {
      case 8u:
      case 0x10u:
        *a3 = 10;
        break;
      case 0x20u:
        *a3 = 11;
        break;
      case 0x40u:
        *a3 = 12;
        break;
    }
  }
  else
  {
    *a3 = 9;
  }
  return 0;
}
