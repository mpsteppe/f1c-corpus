int __cdecl _output(FILE *File, char *a2, int a3)
{
  int v3; // esi
  char v4; // bl
  char *v5; // edi
  bool v6; // zf
  int v7; // ecx
  int v8; // eax
  int int_arg; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  char *v13; // ecx
  char *i; // eax
  int v15; // edx
  wchar_t short_arg; // ax
  __int16 *v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // eax
  char *j; // eax
  int v22; // edx
  _WORD *v23; // eax
  __int64 v24; // rax
  unsigned __int64 v25; // rdi
  int v26; // eax
  int v27; // ebx
  unsigned __int64 v28; // kr08_8
  _BYTE *v29; // eax
  char *v30; // eax
  char v31; // bl
  int v32; // esi
  wchar_t *v33; // ebx
  int v34; // edi
  wchar_t v35; // ax
  int v36; // eax
  char MbCh; // [esp+Ch] [ebp-248h] BYREF
  char v40; // [esp+20Bh] [ebp-49h] BYREF
  int v41; // [esp+20Ch] [ebp-48h]
  int v42; // [esp+210h] [ebp-44h]
  __int64 v43; // [esp+214h] [ebp-40h]
  char v44[4]; // [esp+21Ch] [ebp-38h] BYREF
  int v45; // [esp+220h] [ebp-34h]
  int v46; // [esp+224h] [ebp-30h]
  int v47; // [esp+228h] [ebp-2Ch]
  int v48; // [esp+22Ch] [ebp-28h]
  int v49; // [esp+230h] [ebp-24h]
  int v50; // [esp+234h] [ebp-20h]
  int v51; // [esp+238h] [ebp-1Ch]
  _WORD v52[3]; // [esp+23Eh] [ebp-16h] BYREF
  int v53; // [esp+244h] [ebp-10h]
  int v54; // [esp+248h] [ebp-Ch]
  int p_MbCh; // [esp+24Ch] [ebp-8h]
  int v56; // [esp+250h] [ebp-4h]
  char *v57; // [esp+260h] [ebp+Ch]

  v3 = 0;
  v4 = *a2;
  v5 = a2 + 1;
  v6 = *a2 == 0;
  v54 = 0;
  *(_DWORD *)&v52[1] = 0;
  v57 = a2 + 1;
  if ( !v6 )
  {
    v7 = v53;
    while ( 1 )
    {
      if ( *(int *)&v52[1] < 0 )
        return *(_DWORD *)&v52[1];
      if ( v4 < 32 || v4 > 120 )
        v8 = 0;
      else
        v8 = aIsprocessorfea[v4 + 16] & 0xF;
      v46 = byte_5F6710[8 * v8 + v3] >> 4;
      switch ( v46 )
      {
        case 0:
          goto $NORMAL_STATE$1535;
        case 1:
          v53 = -1;
          v45 = 0;
          v48 = 0;
          v50 = 0;
          v51 = 0;
          v56 = 0;
          v49 = 0;
          goto LABEL_171;
        case 2:
          switch ( v4 )
          {
            case ' ':
              v56 |= 2u;
              break;
            case '#':
              LOBYTE(v56) = v56 | 0x80;
              break;
            case '+':
              v56 |= 1u;
              break;
            case '-':
              v56 |= 4u;
              break;
            case '0':
              v56 |= 8u;
              break;
          }
          goto LABEL_171;
        case 3:
          if ( v4 == 42 )
          {
            int_arg = get_int_arg(&a3);
            v50 = int_arg;
            if ( int_arg >= 0 )
              goto LABEL_171;
            v56 |= 4u;
            v10 = -int_arg;
          }
          else
          {
            v10 = v4 + 10 * v50 - 48;
          }
          v50 = v10;
          goto LABEL_171;
        case 4:
          v53 = 0;
          goto LABEL_171;
        case 5:
          if ( v4 == 42 )
          {
            v53 = get_int_arg(&a3);
            if ( v53 < 0 )
              v53 = -1;
          }
          else
          {
            v53 = v4 + 10 * v7 - 48;
          }
          goto LABEL_171;
        case 6:
          switch ( v4 )
          {
            case 'I':
              if ( *v5 == 54 && v5[1] == 52 )
              {
                BYTE1(v56) |= 0x80u;
                v57 = v5 + 2;
              }
              else
              {
                v46 = 0;
$NORMAL_STATE$1535:
                v49 = 0;
                if ( *((char *)off_625680 + 2 * (unsigned __int8)v4 + 1) < 0 )
                {
                  write_char(v4, File, (int)&v52[1]);
                  v4 = *v5;
                  v57 = v5 + 1;
                }
                write_char(v4, File, (int)&v52[1]);
              }
              break;
            case 'h':
              v56 |= 0x20u;
              break;
            case 'l':
              v56 |= 0x10u;
              break;
            case 'w':
              BYTE1(v56) |= 8u;
              break;
          }
          goto LABEL_171;
        case 7:
          if ( v4 > 103 )
          {
            switch ( v4 )
            {
              case 'i':
                goto LABEL_114;
              case 'n':
                v23 = (_WORD *)get_int_arg(&a3);
                if ( (v56 & 0x20) != 0 )
                  *v23 = v52[1];
                else
                  *(_DWORD *)v23 = *(_DWORD *)&v52[1];
                v48 = 1;
                goto LABEL_171;
              case 'o':
                v54 = 8;
                if ( (v56 & 0x80u) != 0 )
                  BYTE1(v56) |= 2u;
                break;
              default:
                switch ( v4 )
                {
                  case 'p':
                    v53 = 8;
LABEL_105:
                    v47 = 7;
                    break;
                  case 's':
                    goto LABEL_55;
                  case 'u':
                    goto LABEL_115;
                  case 'x':
                    v47 = 39;
                    break;
                  default:
                    goto LABEL_148;
                }
                v54 = 16;
                if ( (v56 & 0x80u) != 0 )
                {
                  LOBYTE(v52[0]) = 48;
                  v51 = 2;
                  HIBYTE(v52[0]) = v47 + 81;
                }
                break;
            }
LABEL_116:
            if ( (v56 & 0x8000) == 0 )
            {
              if ( (v56 & 0x20) != 0 )
              {
                if ( (v56 & 0x40) != 0 )
                  LODWORD(v24) = (__int16)get_int_arg(&a3);
                else
                  LODWORD(v24) = (unsigned __int16)get_int_arg(&a3);
              }
              else
              {
                if ( (v56 & 0x40) == 0 )
                {
                  v24 = (unsigned int)get_int_arg(&a3);
                  goto LABEL_126;
                }
                LODWORD(v24) = get_int_arg(&a3);
              }
              v24 = (int)v24;
            }
            else
            {
              LODWORD(v24) = get_int64_arg(&a3);
            }
LABEL_126:
            if ( (v56 & 0x40) != 0 && v24 < 0 )
            {
              HIDWORD(v25) = -(int)v24;
              BYTE1(v56) |= 1u;
              LODWORD(v25) = (unsigned __int64)-v24 >> 32;
            }
            else
            {
              v25 = __PAIR64__(v24, HIDWORD(v24));
            }
            if ( (v56 & 0x8000) == 0 )
              LODWORD(v25) = 0;
            if ( v53 >= 0 )
              v56 &= ~8u;
            else
              v53 = 1;
            if ( !v25 )
              v51 = 0;
            p_MbCh = (int)&v40;
            while ( 1 )
            {
              v26 = v53--;
              if ( v26 <= 0 && !v25 )
                break;
              v43 = v54;
              v27 = __PAIR64__(v25, HIDWORD(v25)) % v54 + 48;
              v28 = __PAIR64__(v25, HIDWORD(v25)) / v54;
              v25 = __PAIR64__(v28, HIDWORD(v28));
              if ( v27 > 57 )
                LOBYTE(v27) = v47 + v27;
              v29 = (_BYTE *)p_MbCh--;
              *v29 = v27;
            }
            v30 = &v40 - p_MbCh++;
            v54 = (int)v30;
            if ( (v56 & 0x200) != 0 && (*(_BYTE *)p_MbCh != 48 || !v30) )
            {
              --p_MbCh;
              v20 = (int)(v30 + 1);
              *(_BYTE *)p_MbCh = 48;
              goto LABEL_147;
            }
            goto LABEL_148;
          }
          if ( v4 >= 101 )
            goto LABEL_65;
          if ( v4 > 88 )
          {
            if ( v4 == 90 )
            {
              v17 = (__int16 *)get_int_arg(&a3);
              if ( v17 && (v18 = *((_DWORD *)v17 + 1)) != 0 )
              {
                if ( (v56 & 0x800) != 0 )
                {
                  v19 = (unsigned int)*v17 >> 1;
                  p_MbCh = v18;
                  v54 = v19;
                  v49 = 1;
                  goto LABEL_148;
                }
                v49 = 0;
                p_MbCh = v18;
                v20 = *v17;
              }
              else
              {
                p_MbCh = (int)off_625678;
                v20 = strlen(off_625678);
              }
              goto LABEL_147;
            }
            if ( v4 == 99 )
              goto LABEL_69;
            if ( v4 != 100 )
              goto LABEL_148;
LABEL_114:
            v56 |= 0x40u;
LABEL_115:
            v54 = 10;
            goto LABEL_116;
          }
          switch ( v4 )
          {
            case 'X':
              goto LABEL_105;
            case 'C':
              if ( (v56 & 0x830) == 0 )
                BYTE1(v56) |= 8u;
LABEL_69:
              if ( (v56 & 0x810) != 0 )
              {
                short_arg = get_short_arg(&a3);
                v54 = wctomb(&MbCh, short_arg);
                if ( v54 < 0 )
                  v48 = 1;
              }
              else
              {
                MbCh = get_int_arg(&a3);
                v54 = 1;
              }
              p_MbCh = (int)&MbCh;
              break;
            case 'E':
            case 'G':
              v45 = 1;
              v4 += 32;
LABEL_65:
              v56 |= 0x40u;
              p_MbCh = (int)&MbCh;
              if ( v7 >= 0 )
              {
                if ( !v7 && v4 == 103 )
                  v53 = 1;
              }
              else
              {
                v53 = 6;
              }
              a3 += 8;
              v41 = *(_DWORD *)(a3 - 8);
              v42 = *(_DWORD *)(a3 - 4);
              off_6253E0[0]();
            case 'S':
              if ( (v56 & 0x830) == 0 )
                BYTE1(v56) |= 8u;
LABEL_55:
              v11 = v53;
              if ( v53 == -1 )
                v11 = 0x7FFFFFFF;
              v12 = get_int_arg(&a3);
              v13 = (char *)v12;
              p_MbCh = v12;
              if ( (v56 & 0x810) != 0 )
              {
                if ( !v12 )
                {
                  v13 = (char *)off_62567C;
                  p_MbCh = (int)off_62567C;
                }
                v49 = 1;
                for ( i = v13; ; i += 2 )
                {
                  v15 = v11--;
                  if ( !v15 || !*(_WORD *)i )
                    break;
                }
                v20 = (i - v13) >> 1;
              }
              else
              {
                if ( !v12 )
                {
                  v13 = off_625678;
                  p_MbCh = (int)off_625678;
                }
                for ( j = v13; ; ++j )
                {
                  v22 = v11--;
                  if ( !v22 || !*j )
                    break;
                }
                v20 = j - v13;
              }
LABEL_147:
              v54 = v20;
              break;
          }
LABEL_148:
          if ( v48 )
            goto LABEL_171;
          v31 = v56;
          if ( (v56 & 0x40) == 0 )
            goto LABEL_157;
          if ( (v56 & 0x100) != 0 )
          {
            LOBYTE(v52[0]) = 45;
LABEL_156:
            v51 = 1;
            goto LABEL_157;
          }
          if ( (v56 & 1) != 0 )
          {
            LOBYTE(v52[0]) = 43;
            goto LABEL_156;
          }
          if ( (v56 & 2) != 0 )
          {
            LOBYTE(v52[0]) = 32;
            goto LABEL_156;
          }
LABEL_157:
          v32 = v50 - v51 - v54;
          if ( (v56 & 0xC) == 0 )
            write_multi_char(32, v50 - v51 - v54, File, (int)&v52[1]);
          write_string((int)v52, v51, File, (int)&v52[1]);
          if ( (v31 & 8) != 0 && (v31 & 4) == 0 )
            write_multi_char(48, v32, File, (int)&v52[1]);
          if ( v49 && v54 > 0 )
          {
            v33 = (wchar_t *)p_MbCh;
            v34 = v54 - 1;
            do
            {
              v35 = *v33++;
              v36 = wctomb(v44, v35);
              if ( v36 <= 0 )
                break;
              write_string((int)v44, v36, File, (int)&v52[1]);
            }
            while ( v34-- );
          }
          else
          {
            write_string(p_MbCh, v54, File, (int)&v52[1]);
          }
          if ( (v56 & 4) != 0 )
            write_multi_char(32, v32, File, (int)&v52[1]);
LABEL_171:
          v4 = *v57;
          v5 = v57 + 1;
          v6 = *v57++ == 0;
          if ( v6 )
            return *(_DWORD *)&v52[1];
          v7 = v53;
          v3 = v46;
          break;
        default:
          goto LABEL_171;
      }
    }
  }
  return *(_DWORD *)&v52[1];
}
