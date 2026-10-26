BOOL __cdecl sub_5919DA(char a1, double *a2, __int16 a3)
{
  int v3; // edi
  int v4; // ecx
  double *v5; // ecx
  double v7; // st7
  char v8; // c0
  char v9; // c3
  char v11; // c0
  char v12; // c3
  BOOL v13; // esi
  int v14; // ecx
  BOOL v15; // edx
  __int16 v16; // ax
  int v17; // eax
  double v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+20h] [ebp-4h] BYREF

  v3 = a1 & 0x1F;
  if ( (a1 & 8) != 0 && (a3 & 1) != 0 )
  {
    EmptyStub_1e89(1);
    v3 = a1 & 0x17;
    goto LABEL_46;
  }
  if ( (a1 & 4) != 0 && (a3 & 4) != 0 )
  {
    EmptyStub_1e89(4);
    v3 = a1 & 0x1B;
    goto LABEL_46;
  }
  if ( (a1 & 1) != 0 && (a3 & 8) != 0 )
  {
    EmptyStub_1e89(8);
    v4 = a3 & 0xC00;
    if ( (a3 & 0xC00) != 0 )
    {
      switch ( v4 )
      {
        case 1024:
          v5 = a2;
          if ( *a2 <= 0.0 )
            v7 = -dbl_5E7718;
          else
            v7 = dbl_5E7728;
          break;
        case 2048:
          v5 = a2;
          if ( *a2 <= 0.0 )
            v7 = -dbl_5E7728;
          else
            v7 = dbl_5E7718;
          break;
        case 3072:
          v5 = a2;
          v7 = dbl_5E7728;
          if ( v8 != 0 || v9 != 0 )
            v7 = -dbl_5E7728;
          break;
        default:
LABEL_25:
          v3 = a1 & 0x1E;
          goto LABEL_46;
      }
    }
    else
    {
      v5 = a2;
      v7 = dbl_5E7718;
      if ( v11 != 0 || v12 != 0 )
        v7 = -dbl_5E7718;
    }
    *v5 = v7;
    goto LABEL_25;
  }
  if ( (a1 & 2) != 0 && (a3 & 0x10) != 0 )
  {
    v13 = (a1 & 0x10) != 0;
    v19 = *a2;
    if ( v19 == 0.0 )
    {
      v13 = 1;
    }
    else
    {
      sub_591D88(v19, (int)&v20);
      v14 = v20 - 1536;
      if ( v20 - 1536 >= -1074 )
      {
        v15 = v19 < 0.0;
        v16 = BYTE6(v19) & 0xF;
        LOBYTE(v16) = v16 | 0x10;
        HIWORD(v19) = v16;
        if ( v14 < -1021 )
        {
          v17 = -1021 - v14;
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
        if ( v15 )
          v19 = -v19;
      }
      else
      {
        v13 = 1;
        v19 = 0.0;
      }
      *a2 = v19;
    }
    if ( v13 )
      EmptyStub_1e89(16);
    v3 = a1 & 0x1D;
  }
LABEL_46:
  if ( (a1 & 0x10) != 0 && (a3 & 0x20) != 0 )
  {
    EmptyStub_1e89(32);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

