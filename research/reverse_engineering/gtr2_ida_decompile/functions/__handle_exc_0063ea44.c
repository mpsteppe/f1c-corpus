BOOL __cdecl _handle_exc(char a1, double *a2, __int16 a3)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  double v7; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  BOOL v13; // esi
  double v14; // st7
  int v15; // ecx
  double v16; // st7
  int v17; // eax
  double v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+20h] [ebp-8h] BYREF
  int v21; // [esp+24h] [ebp-4h]

  v3 = a1 & 0x1F;
  v21 = v3;
  if ( (a1 & 8) != 0 && (a3 & 1) != 0 )
  {
    _set_statfp(1);
    v3 = a1 & 0x17;
    goto LABEL_47;
  }
  if ( (a1 & 4) != 0 && (a3 & 4) != 0 )
  {
    _set_statfp(4);
    v3 = a1 & 0x1B;
    goto LABEL_47;
  }
  if ( (a1 & 1) != 0 && (a3 & 8) != 0 )
  {
    _set_statfp(8);
    v4 = a3 & 0xC00;
    if ( (a3 & 0xC00) != 0 )
    {
      switch ( v4 )
      {
        case 1024:
          v5 = a2;
          if ( *a2 <= 0.0 )
            v7 = -dbl_913458;
          else
            v7 = dbl_913468;
          break;
        case 2048:
          v5 = a2;
          if ( *a2 <= 0.0 )
            v7 = -dbl_913468;
          else
            v7 = dbl_913458;
          break;
        case 3072:
          v5 = a2;
          v7 = dbl_913468;
          if ( v8 | v9 )
            v7 = -dbl_913468;
          break;
        default:
LABEL_25:
          v3 = a1 & 0x1E;
          goto LABEL_47;
      }
    }
    else
    {
      v5 = a2;
      v7 = dbl_913458;
      if ( v11 | v12 )
        v7 = -dbl_913458;
    }
    *v5 = v7;
    goto LABEL_25;
  }
  if ( (a1 & 2) != 0 && (a3 & 0x10) != 0 )
  {
    v13 = (a1 & 0x10) != 0;
    if ( *a2 == 0.0 )
    {
      v13 = 1;
      goto LABEL_44;
    }
    v14 = _decomp(*a2, &v20);
    v19 = v14;
    v15 = v20 - 1536;
    if ( v20 - 1536 >= -1074 )
    {
      HIWORD(v19) = BYTE6(v19) & 0xF | 0x10;
      if ( v15 < -1021 )
      {
        v17 = -1021 - v15;
        do
        {
          if ( (LOBYTE(v19) & 1) != 0 && !v13 )
            v13 = 1;
          LODWORD(v19) >>= 1;
          if ( (BYTE4(v19) & 1) != 0 )
            BYTE3(v19) |= 0x80u;
          HIDWORD(v19) >>= 1;
          --v17;
        }
        while ( v17 );
      }
      if ( v14 >= 0.0 )
        goto LABEL_42;
      v16 = -v19;
    }
    else
    {
      v16 = v14 * 0.0;
      v13 = 1;
    }
    v19 = v16;
LABEL_42:
    *a2 = v19;
LABEL_44:
    if ( v13 )
      _set_statfp(16);
    v21 &= ~2u;
    v3 = v21;
  }
LABEL_47:
  if ( (a1 & 0x10) != 0 && (a3 & 0x20) != 0 )
  {
    _set_statfp(32);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}
