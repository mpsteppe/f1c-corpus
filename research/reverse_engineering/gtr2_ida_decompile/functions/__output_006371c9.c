int __cdecl _output(int a1, char *a2, __int64 *a3)
{
  char v3; // bl
  char *v4; // edi
  int v5; // eax
  char v6; // al
  int v7; // eax
  int v8; // ecx
  char *v9; // eax
  char *v10; // eax
  __int64 v11; // rax
  __int16 *v12; // eax
  char *v13; // ecx
  int v14; // eax
  char *v15; // eax
  char *j; // eax
  _WORD *v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  char *i; // esi
  int v21; // eax
  int v22; // ecx
  unsigned __int64 v23; // kr08_8
  char *v24; // eax
  char *v25; // esi
  char v26; // bl
  int v27; // esi
  wchar_t *v28; // ebx
  int v29; // eax
  int v31; // [esp+24h] [ebp-74h]
  char v32; // [esp+30h] [ebp-68h]
  int v33; // [esp+34h] [ebp-64h]
  int v34; // [esp+3Ch] [ebp-5Ch]
  int v35; // [esp+40h] [ebp-58h]
  int v36; // [esp+44h] [ebp-54h]
  _BYTE v37[4]; // [esp+48h] [ebp-50h] BYREF
  int v38; // [esp+4Ch] [ebp-4Ch] BYREF
  int v39; // [esp+50h] [ebp-48h]
  char *v40; // [esp+54h] [ebp-44h]
  int v41; // [esp+58h] [ebp-40h]
  int v42; // [esp+5Ch] [ebp-3Ch]
  char MbCh[511]; // [esp+60h] [ebp-38h] BYREF
  char v44; // [esp+25Fh] [ebp+1C7h] BYREF
  char v45[8]; // [esp+260h] [ebp+1C8h] BYREF
  int v46; // [esp+268h] [ebp+1D0h]
  _BYTE *v47; // [esp+278h] [ebp+1E0h]

  v46 = dword_912B08;
  v39 = 0;
  v38 = 0;
  v3 = *a2;
  if ( *a2 )
  {
    v4 = a2 + 1;
    v47 = a2 + 1;
    if ( v3 < 32 || v3 > 120 )
      v5 = 0;
    else
      v5 = byte_7307A0[v3] & 0xF;
    switch ( byte_7307C0[8 * v5] >> 4 )
    {
      case 0:
        goto LABEL_46;
      case 1:
        v41 = -1;
        v42 = 0;
        return off_16C94E0(a1, v47, a3);
      case 2:
        switch ( v3 )
        {
          case ' ':
            v42 |= 2u;
            break;
          case '#':
            LOBYTE(v42) = v42 | 0x80;
            break;
          case '+':
            v42 |= 1u;
            break;
          case '-':
            v42 |= 4u;
            break;
          case '0':
            v42 |= 8u;
            break;
        }
        return off_16C94E0(a1, v47, a3);
      case 3:
        if ( v3 == 42 )
        {
          a3 = (__int64 *)((char *)a3 + 4);
          if ( *((int *)a3 - 1) < 0 )
            v42 |= 4u;
        }
        return off_16C94E0(a1, v47, a3);
      case 4:
        v41 = 0;
        return off_16C94E0(a1, v47, a3);
      case 5:
        if ( v3 == 42 )
        {
          a3 = (__int64 *)((char *)a3 + 4);
          v41 = *((_DWORD *)a3 - 1);
          if ( v41 < 0 )
            v41 = -1;
        }
        else
        {
          v41 = v3 + 10 * v41 - 48;
        }
        return off_16C94E0(a1, v47, a3);
      case 6:
        switch ( v3 )
        {
          case 'I':
            v6 = *v4;
            if ( *v4 == 54 && v4[1] == 52 )
            {
              BYTE1(v42) |= 0x80u;
              v47 = v4 + 2;
            }
            else if ( v6 == 51 && v4[1] == 50 )
            {
              BYTE1(v42) &= ~0x80u;
              v47 = v4 + 2;
            }
            else if ( v6 != 100 && v6 != 105 && v6 != 111 && v6 != 117 && v6 != 120 && v6 != 88 )
            {
LABEL_46:
              v7 = (unsigned __int8)v3;
              if ( (off_913150[(unsigned __int8)v3] & 0x8000u) != 0 )
              {
                LOBYTE(v7) = v3;
                v7 = write_char(v7, a1, &v38);
                v3 = *v4;
                v47 = v4 + 1;
              }
              LOBYTE(v7) = v3;
              write_char(v7, a1, &v38);
            }
            break;
          case 'h':
            v42 |= 0x20u;
            break;
          case 'l':
            v42 |= 0x10u;
            break;
          case 'w':
            BYTE1(v42) |= 8u;
            break;
        }
        return off_16C94E0(a1, v47, a3);
      case 7:
        if ( v3 > 103 )
        {
          if ( v3 != 105 )
          {
            switch ( v3 )
            {
              case 'n':
                a3 = (__int64 *)((char *)a3 + 4);
                v17 = (_WORD *)*((_DWORD *)a3 - 1);
                if ( (v42 & 0x20) != 0 )
                  *v17 = v38;
                else
                  *(_DWORD *)v17 = v38;
                return off_16C94E0(a1, v47, a3);
              case 'o':
                v39 = 8;
                if ( (v42 & 0x80u) != 0 )
                  BYTE1(v42) |= 2u;
LABEL_78:
                if ( (v42 & 0x8000) != 0 )
                {
                  v11 = *a3++;
                  goto LABEL_132;
                }
                a3 = (__int64 *)((char *)a3 + 4);
                if ( (v42 & 0x20) != 0 )
                {
                  if ( (v42 & 0x40) != 0 )
                    LODWORD(v11) = *((__int16 *)a3 - 2);
                  else
                    LODWORD(v11) = *((unsigned __int16 *)a3 - 2);
                }
                else
                {
                  LODWORD(v11) = *((_DWORD *)a3 - 1);
                  if ( (v42 & 0x40) == 0 )
                  {
                    HIDWORD(v11) = 0;
LABEL_132:
                    if ( (v42 & 0x40) != 0 && v11 < 0 )
                    {
                      v11 = -v11;
                      BYTE1(v42) |= 1u;
                    }
                    v19 = HIDWORD(v11);
                    v18 = v11;
                    if ( (v42 & 0x8000) == 0 )
                      v19 = 0;
                    if ( v41 >= 0 )
                    {
                      v42 &= ~8u;
                      if ( v41 > 512 )
                        v41 = 512;
                    }
                    else
                    {
                      v41 = 1;
                    }
                    if ( !(v19 | (unsigned int)v11) )
                      v36 = 0;
                    for ( i = &v44; ; --i )
                    {
                      v21 = v41--;
                      if ( v21 <= 0 && !(v19 | v18) )
                        break;
                      v22 = __PAIR64__(v19, v18) % v39 + 48;
                      v23 = __PAIR64__(v19, v18) / v39;
                      v19 = HIDWORD(v23);
                      v18 = v23;
                      if ( v22 > 57 )
                        LOBYTE(v22) = v32 + v22;
                      *i = v22;
                    }
                    v24 = (char *)(&v44 - i);
                    v25 = i + 1;
                    v39 = (int)v24;
                    v40 = v25;
                    if ( (v42 & 0x200) == 0 || *v25 == 48 && v24 )
                    {
LABEL_154:
                      if ( !v33 )
                      {
                        v26 = v42;
                        if ( (v42 & 0x40) != 0 )
                        {
                          if ( (v42 & 0x100) != 0 )
                          {
                            v37[0] = 45;
LABEL_162:
                            v36 = 1;
                            goto LABEL_163;
                          }
                          if ( (v42 & 1) != 0 )
                          {
                            v37[0] = 43;
                            goto LABEL_162;
                          }
                          if ( (v42 & 2) != 0 )
                          {
                            v37[0] = 32;
                            goto LABEL_162;
                          }
                        }
LABEL_163:
                        v27 = v35 - v36 - v39;
                        if ( (v42 & 0xC) == 0 )
                          write_multi_char((int)&v38, 32, v35 - v36 - v39, a1);
                        write_string((int)&v38, v37, a1, v36);
                        if ( (v26 & 8) != 0 && (v26 & 4) == 0 )
                          write_multi_char((int)&v38, 48, v27, a1);
                        if ( v34 && v39 > 0 )
                        {
                          v28 = (wchar_t *)v40;
                          v31 = v39;
                          do
                          {
                            --v31;
                            v29 = wctomb(v45, *v28++);
                            if ( v29 <= 0 )
                              break;
                            write_string((int)&v38, v45, a1, v29);
                          }
                          while ( v31 );
                        }
                        else
                        {
                          write_string((int)&v38, v40, a1, v39);
                        }
                        if ( (v42 & 4) != 0 )
                          write_multi_char((int)&v38, 32, v27, a1);
                      }
                      return off_16C94E0(a1, v47, a3);
                    }
                    *--v40 = 48;
                    v14 = (int)(v24 + 1);
LABEL_153:
                    v39 = v14;
                    goto LABEL_154;
                  }
                }
                v11 = (int)v11;
                goto LABEL_132;
              case 'p':
                v41 = 8;
LABEL_117:
                v32 = 7;
LABEL_118:
                v39 = 16;
                if ( (v42 & 0x80u) != 0 )
                {
                  v37[0] = 48;
                  v37[1] = v32 + 81;
                  v36 = 2;
                }
                goto LABEL_78;
              case 's':
LABEL_59:
                v8 = v41;
                if ( v41 == -1 )
                  v8 = 0x7FFFFFFF;
                a3 = (__int64 *)((char *)a3 + 4);
                v9 = (char *)*((_DWORD *)a3 - 1);
                v40 = v9;
                if ( (v42 & 0x810) != 0 )
                {
                  if ( !v9 )
                    v40 = (char *)off_913054;
                  v10 = v40;
                  v34 = 1;
                  while ( v8 )
                  {
                    --v8;
                    if ( !*(_WORD *)v10 )
                      break;
                    v10 += 2;
                  }
                  v14 = (v10 - v40) >> 1;
                }
                else
                {
                  if ( !v9 )
                    v40 = off_913050;
                  for ( j = v40; v8; ++j )
                  {
                    --v8;
                    if ( !*j )
                      break;
                  }
                  v14 = j - v40;
                }
                goto LABEL_153;
            }
            if ( v3 != 117 )
            {
              if ( v3 != 120 )
                goto LABEL_154;
              v32 = 39;
              goto LABEL_118;
            }
LABEL_77:
            v39 = 10;
            goto LABEL_78;
          }
        }
        else
        {
          if ( v3 >= 101 )
            goto LABEL_66;
          if ( v3 <= 88 )
          {
            if ( v3 != 88 )
            {
              if ( v3 != 67 )
              {
                if ( v3 != 69 && v3 != 71 )
                {
                  if ( v3 != 83 )
                    goto LABEL_154;
                  if ( (v42 & 0x830) == 0 )
                    BYTE1(v42) |= 8u;
                  goto LABEL_59;
                }
                v3 += 32;
LABEL_66:
                v42 |= 0x40u;
                v40 = MbCh;
                if ( v41 >= 0 )
                {
                  if ( v41 )
                  {
                    if ( v41 > 512 )
                      v41 = 512;
                    if ( v41 > 163 )
                    {
                      v15 = (char *)malloc(v41 + 349);
                      if ( v15 )
                        v40 = v15;
                      else
                        v41 = 163;
                    }
                  }
                  else
                  {
                    v41 = v3 == 103;
                  }
                }
                else
                {
                  v41 = 6;
                }
                off_912C80[0]();
              }
              if ( (v42 & 0x830) == 0 )
                BYTE1(v42) |= 8u;
              goto LABEL_70;
            }
            goto LABEL_117;
          }
          if ( v3 == 90 )
          {
            a3 = (__int64 *)((char *)a3 + 4);
            v12 = (__int16 *)*((_DWORD *)a3 - 1);
            if ( v12 && (v13 = (char *)*((_DWORD *)v12 + 1)) != 0 )
            {
              v14 = *v12;
              v40 = v13;
              if ( (v42 & 0x800) != 0 )
              {
                v14 /= 2;
                v34 = 1;
              }
              else
              {
                v34 = 0;
              }
            }
            else
            {
              v40 = off_913050;
              v14 = sub_6354D0((int)off_913050);
            }
            goto LABEL_153;
          }
          if ( v3 == 99 )
          {
LABEL_70:
            a3 = (__int64 *)((char *)a3 + 4);
            if ( (v42 & 0x810) != 0 )
            {
              v39 = wctomb(MbCh, *((_WORD *)a3 - 2));
              if ( v39 < 0 )
                v33 = 1;
            }
            else
            {
              MbCh[0] = *((_BYTE *)a3 - 4);
              v39 = 1;
            }
            v40 = MbCh;
            goto LABEL_154;
          }
          if ( v3 != 100 )
            goto LABEL_154;
        }
        v42 |= 0x40u;
        goto LABEL_77;
      default:
        return off_16C94E0(a1, v47, a3);
    }
  }
  return v38;
}
