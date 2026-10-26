int sub_65CBD1()
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
  dword_FB9238 = 0;
  dword_FB9234 = 0;
  dword_FB922C = (int)&word_FB8E38;
  dword_FB9228 = (int)&unk_FB8668;
  word_FB8E38 = 0;
LABEL_2:
  v1 = -1;
  for ( dword_FB9230 = -1; ; v1 = dword_FB9230 )
  {
    while ( 1 )
    {
LABEL_3:
      v2 = word_914508[v0];
      if ( word_914508[v0] )
        goto LABEL_17;
      if ( v1 < 0 )
      {
        v1 = sub_65BE3E(dword_FB9260);
        dword_FB9230 = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          dword_FB9230 = 0;
        }
      }
      if ( !word_9145C8[v0] )
        break;
      v3 = v1 + word_9145C8[v0];
      if ( v3 > 0x171 )
        break;
      v4 = v3;
      if ( word_914A10[v4] != v1 )
        break;
      v5 = dword_FB922C;
      if ( dword_FB922C >= (unsigned int)&word_FB921E )
        goto LABEL_47;
      v0 = word_914728[v4];
      dword_FB922C += 2;
      *(_WORD *)(v5 + 2) = v0;
      dword_FB9228 += 4;
      *(_DWORD *)dword_FB9228 = dword_FB9220;
      v1 = -1;
      dword_FB9230 = -1;
      if ( dword_FB9234 > 0 )
        --dword_FB9234;
    }
    if ( word_914668[v0] )
    {
      v6 = v1 + word_914668[v0];
      if ( v6 <= 0x171 )
      {
        v7 = v6;
        if ( word_914A10[v7] == v1 )
          break;
      }
    }
    if ( !dword_FB9234 )
    {
      sub_65A0B7((_DWORD *)dword_FB9260, "syntax error");
      ++dword_FB9238;
      v1 = dword_FB9230;
    }
    if ( dword_FB9234 >= 3 )
    {
      if ( v1 )
        goto LABEL_2;
      return 1;
    }
    dword_FB9234 = 3;
    for ( i = (__int16 *)dword_FB922C; ; dword_FB922C = (int)i )
    {
      if ( word_9145C8[*i] )
      {
        v20 = word_9145C8[*i] + 256;
        if ( v20 <= 0x171 && word_914A10[v20] == 256 )
          break;
      }
      if ( i <= &word_FB8E38 )
        return 1;
      --i;
      dword_FB9228 -= 4;
    }
    if ( i >= &word_FB921E )
    {
LABEL_47:
      sub_65A0B7((_DWORD *)dword_FB9260, "yacc stack overflow");
      return 1;
    }
    v0 = word_914728[v20];
    dword_FB922C = (int)(i + 1);
    i[1] = v0;
    v18 = dword_FB9220;
LABEL_44:
    dword_FB9228 += 4;
    *(_DWORD *)dword_FB9228 = v18;
  }
  v2 = word_914728[v7];
LABEL_17:
  v8 = word_9144A8[v2];
  dword_FB9224 = *(_DWORD *)(dword_FB9228 - 4 * v8 + 4);
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
      result = off_16C94E8();
      break;
    default:
      v10 = word_914448[v2];
      v11 = (__int16 *)(dword_FB922C - 2 * v8);
      dword_FB922C = (int)v11;
      v12 = *v11;
      dword_FB9228 -= 4 * v8;
      if ( v12 || v10 )
      {
        v14 = v10;
        v15 = word_914708[v10];
        if ( v15 && (v16 = v12 + v15, v16 <= 0x171) && (v17 = v16, word_914A10[v17] == v12) )
          v0 = word_914728[v17];
        else
          v0 = word_9145A8[v14];
        if ( v11 < &word_FB921E )
        {
          dword_FB922C = (int)(v11 + 1);
          v11[1] = v0;
          v18 = dword_FB9224;
          goto LABEL_44;
        }
        goto LABEL_47;
      }
      dword_FB922C = (int)(v11 + 1);
      v0 = 15;
      v11[1] = 15;
      dword_FB9228 += 4;
      *(_DWORD *)dword_FB9228 = dword_FB9224;
      v1 = dword_FB9230;
      v13 = dword_FB9230 == 0;
      if ( dword_FB9230 < 0 )
      {
        v1 = sub_65BE3E(dword_FB9260);
        v13 = v1 == 0;
        dword_FB9230 = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          dword_FB9230 = 0;
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
