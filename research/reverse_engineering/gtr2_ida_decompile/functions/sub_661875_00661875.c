int sub_661875()
{
  int v0; // esi
  int v1; // eax
  int v2; // ecx
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  int v8; // esi
  int result; // eax
  int v10; // ecx
  __int16 *v11; // eax
  int v12; // edx
  bool v13; // zf
  int v14; // esi
  int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  int v18; // eax
  __int16 *i; // ecx
  unsigned int v20; // eax

  v0 = 0;
  dword_FB9E38 = 0;
  dword_FB9E34 = 0;
  dword_FB9E2C = (int)&word_FB9A38;
  dword_FB9E28 = (int)&unk_FB9268;
  word_FB9A38 = 0;
LABEL_2:
  v1 = -1;
  for ( dword_FB9E30 = -1; ; v1 = dword_FB9E30 )
  {
    while ( 1 )
    {
LABEL_3:
      v2 = word_914DF8[v0];
      if ( word_914DF8[v0] )
        goto LABEL_17;
      if ( v1 < 0 )
      {
        v1 = sub_660C6A(dword_FB9E40);
        dword_FB9E30 = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          dword_FB9E30 = 0;
        }
      }
      if ( !word_914F40[v0] )
        break;
      v3 = v1 + word_914F40[v0];
      if ( v3 >= 0x128 )
        break;
      v4 = v3;
      if ( word_9153E0[v4] != v1 )
        break;
      v5 = dword_FB9E2C;
      if ( dword_FB9E2C >= (unsigned int)&word_FB9E1E )
        goto LABEL_47;
      v0 = word_915190[v4];
      dword_FB9E2C += 2;
      *(_WORD *)(v5 + 2) = v0;
      dword_FB9E28 += 4;
      *(_DWORD *)dword_FB9E28 = dword_FB9E20;
      v1 = -1;
      dword_FB9E30 = -1;
      if ( dword_FB9E34 > 0 )
        --dword_FB9E34;
    }
    if ( word_915048[v0] )
    {
      v6 = v1 + word_915048[v0];
      if ( v6 < 0x128 )
      {
        v7 = v6;
        if ( word_9153E0[v7] == v1 )
          break;
      }
    }
    if ( !dword_FB9E34 )
    {
      sub_65EC68((double *)dword_FB9E40, "syntax error");
      ++dword_FB9E38;
      v1 = dword_FB9E30;
    }
    if ( dword_FB9E34 >= 3 )
    {
      if ( v1 )
        goto LABEL_2;
      return 1;
    }
    dword_FB9E34 = 3;
    for ( i = (__int16 *)dword_FB9E2C; ; dword_FB9E2C = (int)i )
    {
      if ( word_914F40[*i] )
      {
        v20 = word_914F40[*i] + 256;
        if ( v20 < 0x128 && word_9153E0[v20] == 256 )
          break;
      }
      if ( i <= &word_FB9A38 )
        return 1;
      --i;
      dword_FB9E28 -= 4;
    }
    if ( i >= &word_FB9E1E )
    {
LABEL_47:
      sub_65EC68((double *)dword_FB9E40, "yacc stack overflow");
      return 1;
    }
    v0 = word_915190[v20];
    dword_FB9E2C = (int)(i + 1);
    i[1] = v0;
    v18 = dword_FB9E20;
LABEL_44:
    dword_FB9E28 += 4;
    *(_DWORD *)dword_FB9E28 = v18;
  }
  v2 = word_915190[v7];
LABEL_17:
  v8 = word_914D78[v2];
  dword_FB9E24 = *(_DWORD *)(dword_FB9E28 - 4 * v8 + 4);
  switch ( v2 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
      result = off_16C96C8();
      break;
    default:
      v10 = word_914CF8[v2];
      v11 = (__int16 *)(dword_FB9E2C - 2 * v8);
      dword_FB9E2C = (int)v11;
      v12 = *v11;
      dword_FB9E28 -= 4 * v8;
      if ( v12 || v10 )
      {
        v14 = v10;
        v15 = word_915150[v10];
        if ( v15 && (v16 = v12 + v15, v16 < 0x128) && (v17 = v16, word_9153E0[v17] == v12) )
          v0 = word_915190[v17];
        else
          v0 = word_914F00[v14];
        if ( v11 < &word_FB9E1E )
        {
          dword_FB9E2C = (int)(v11 + 1);
          v11[1] = v0;
          v18 = dword_FB9E24;
          goto LABEL_44;
        }
        goto LABEL_47;
      }
      dword_FB9E2C = (int)(v11 + 1);
      v0 = 16;
      v11[1] = 16;
      dword_FB9E28 += 4;
      *(_DWORD *)dword_FB9E28 = dword_FB9E24;
      v1 = dword_FB9E30;
      v13 = dword_FB9E30 == 0;
      if ( dword_FB9E30 < 0 )
      {
        v1 = sub_660C6A(dword_FB9E40);
        v13 = v1 == 0;
        dword_FB9E30 = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          dword_FB9E30 = 0;
          v13 = 1;
        }
      }
      if ( !v13 )
        goto LABEL_3;
      result = 0;
      break;
  }
  return result;
}
