int __cdecl sub_58D04D(int a1, char *a2, int a3)
{
  int v3; // esi
  char v4; // bl
  char *v5; // edi
  bool v6; // zf
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // esi
  char *v12; // eax
  char *v13; // ecx
  char *i; // eax
  int v15; // edx
  CHAR *v16; // edi
  WCHAR v17; // ax
  __int16 *v18; // eax
  CHAR *v19; // ecx
  unsigned int v20; // eax
  int v21; // eax
  int v22; // esi
  char *j; // eax
  int v24; // edx
  _WORD *v25; // eax
  __int64 v26; // rax
  unsigned __int64 v27; // rdi
  int v28; // eax
  int v29; // ebx
  __int64 v30; // kr08_8
  CHAR *v31; // eax
  _BYTE *v32; // eax
  char v33; // bl
  int v34; // esi
  WCHAR *v35; // ebx
  int v36; // edi
  WCHAR v37; // ax
  int v38; // eax
  CHAR v41; // [esp+Ch] [ebp-248h] BYREF
  _BYTE v42[510]; // [esp+Dh] [ebp-247h] BYREF
  char v43; // [esp+20Bh] [ebp-49h] BYREF
  int v44; // [esp+20Ch] [ebp-48h]
  int v45; // [esp+210h] [ebp-44h]
  __int64 v46; // [esp+214h] [ebp-40h]
  CHAR v47[4]; // [esp+21Ch] [ebp-38h] BYREF
  int v48; // [esp+220h] [ebp-34h]
  int v49; // [esp+224h] [ebp-30h]
  int v50; // [esp+228h] [ebp-2Ch]
  int v51; // [esp+22Ch] [ebp-28h]
  int v52; // [esp+230h] [ebp-24h]
  int v53; // [esp+234h] [ebp-20h]
  int v54; // [esp+238h] [ebp-1Ch]
  _BYTE v55[2]; // [esp+23Eh] [ebp-16h] BYREF
  int v56; // [esp+240h] [ebp-14h] BYREF
  int v57; // [esp+244h] [ebp-10h]
  int v58; // [esp+248h] [ebp-Ch]
  CHAR *v59; // [esp+24Ch] [ebp-8h]
  int v60; // [esp+250h] [ebp-4h]
  char *v61; // [esp+260h] [ebp+Ch]

  v3 = 0;
  v4 = *a2;
  v5 = a2 + 1;
  v6 = *a2 == 0;
  v58 = 0;
  v56 = 0;
  v61 = a2 + 1;
  if ( !v6 )
  {
    v7 = v57;
    while ( 1 )
    {
      if ( v56 < 0 )
        return v56;
      if ( v4 < 32 || v4 > 120 )
        v8 = 0;
      else
        v8 = aIsprocessorfea[v4 + 16] & 0xF;
      v49 = byte_5B8D88[8 * v8 + v3] >> 4;
      switch ( v49 )
      {
        case 0:
          goto LABEL_42;
        case 1:
          v57 = -1;
          v48 = 0;
          v51 = 0;
          v53 = 0;
          v54 = 0;
          v60 = 0;
          v52 = 0;
          goto LABEL_179;
        case 2:
          switch ( v4 )
          {
            case ' ':
              v60 |= 2u;
              break;
            case '#':
              LOBYTE(v60) = v60 | 0x80;
              break;
            case '+':
              v60 |= 1u;
              break;
            case '-':
              v60 |= 4u;
              break;
            case '0':
              v60 |= 8u;
              break;
          }
          goto LABEL_179;
        case 3:
          if ( v4 == 42 )
          {
            v9 = sub_58D82C(&a3);
            v53 = v9;
            if ( v9 >= 0 )
              goto LABEL_179;
            v60 |= 4u;
            v10 = -v9;
          }
          else
          {
            v10 = v4 + 10 * v53 - 48;
          }
          v53 = v10;
          goto LABEL_179;
        case 4:
          v57 = 0;
          goto LABEL_179;
        case 5:
          if ( v4 == 42 )
          {
            v57 = sub_58D82C(&a3);
            if ( v57 < 0 )
              v57 = -1;
          }
          else
          {
            v57 = v4 + 10 * v7 - 48;
          }
          goto LABEL_179;
        case 6:
          switch ( v4 )
          {
            case 'I':
              if ( *v5 == 54 && v5[1] == 52 )
              {
                BYTE1(v60) |= 0x80u;
                v61 = v5 + 2;
              }
              else
              {
                v49 = 0;
LABEL_42:
                v52 = 0;
                if ( off_5E69C8[0][(unsigned __int8)v4] < 0 )
                {
                  sub_58D78E(v4, a1, &v56);
                  v4 = *v5;
                  v61 = v5 + 1;
                }
                sub_58D78E(v4, a1, &v56);
              }
              break;
            case 'h':
              v60 |= 0x20u;
              break;
            case 'l':
              v60 |= 0x10u;
              break;
            case 'w':
              BYTE1(v60) |= 8u;
              break;
          }
          goto LABEL_179;
        case 7:
          if ( v4 <= 103 )
          {
            if ( v4 >= 101 )
              goto LABEL_65;
            if ( v4 > 88 )
            {
              if ( v4 == 90 )
              {
                v18 = (__int16 *)sub_58D82C(&a3);
                if ( v18 && (v19 = (CHAR *)*((_DWORD *)v18 + 1)) != 0 )
                {
                  if ( (v60 & 0x800) != 0 )
                  {
                    v20 = (unsigned int)*v18 >> 1;
                    v59 = v19;
                    v58 = v20;
                    v52 = 1;
                    goto LABEL_156;
                  }
                  v52 = 0;
                  v59 = v19;
                  v21 = *v18;
                }
                else
                {
                  v59 = off_5E6BE0;
                  v21 = sub_58E1B0(off_5E6BE0);
                }
                goto LABEL_155;
              }
              if ( v4 == 99 )
                goto LABEL_69;
              if ( v4 != 100 )
                goto LABEL_156;
LABEL_122:
              v60 |= 0x40u;
LABEL_123:
              v58 = 10;
              goto LABEL_124;
            }
            if ( v4 != 88 )
            {
              if ( v4 != 67 )
              {
                if ( v4 == 69 || v4 == 71 )
                {
                  v48 = 1;
                  v4 += 32;
LABEL_65:
                  v60 |= 0x40u;
                  v16 = &v41;
                  v59 = &v41;
                  if ( v7 >= 0 )
                  {
                    if ( !v7 && v4 == 103 )
                      v57 = 1;
                  }
                  else
                  {
                    v57 = 6;
                  }
                  a3 += 8;
                  v44 = *(_DWORD *)(a3 - 8);
                  v45 = *(_DWORD *)(a3 - 4);
                  off_5E6730();
                  v22 = v60 & 0x80;
                  if ( (v60 & 0x80) != 0 && !v57 )
                    off_5E673C();
                  if ( v4 == 103 && !v22 )
                    off_5E6734();
                  if ( v41 == 45 )
                  {
                    BYTE1(v60) |= 1u;
                    v16 = v42;
                    v59 = v42;
                  }
                  v21 = sub_58E1B0(v16);
                }
                else
                {
                  if ( v4 != 83 )
                    goto LABEL_156;
                  if ( (v60 & 0x830) == 0 )
                    BYTE1(v60) |= 8u;
LABEL_55:
                  v11 = v57;
                  if ( v57 == -1 )
                    v11 = 0x7FFFFFFF;
                  v12 = (char *)sub_58D82C(&a3);
                  v13 = v12;
                  v59 = v12;
                  if ( (v60 & 0x810) != 0 )
                  {
                    if ( !v12 )
                    {
                      v13 = (char *)off_5E6BE4;
                      v59 = (CHAR *)off_5E6BE4;
                    }
                    v52 = 1;
                    for ( i = v13; ; i += 2 )
                    {
                      v15 = v11--;
                      if ( !v15 || !*(_WORD *)i )
                        break;
                    }
                    v21 = (i - v13) >> 1;
                  }
                  else
                  {
                    if ( !v12 )
                    {
                      v13 = off_5E6BE0;
                      v59 = off_5E6BE0;
                    }
                    for ( j = v13; ; ++j )
                    {
                      v24 = v11--;
                      if ( !v24 || !*j )
                        break;
                    }
                    v21 = j - v13;
                  }
                }
LABEL_155:
                v58 = v21;
                goto LABEL_156;
              }
              if ( (v60 & 0x830) == 0 )
                BYTE1(v60) |= 8u;
LABEL_69:
              if ( (v60 & 0x810) != 0 )
              {
                v17 = sub_58D849(&a3);
                v58 = sub_596030(&v41, v17);
                if ( v58 < 0 )
                  v51 = 1;
              }
              else
              {
                v41 = sub_58D82C(&a3);
                v58 = 1;
              }
              v59 = &v41;
              goto LABEL_156;
            }
            goto LABEL_113;
          }
          if ( v4 == 105 )
            goto LABEL_122;
          if ( v4 == 110 )
          {
            v25 = (_WORD *)sub_58D82C(&a3);
            if ( (v60 & 0x20) != 0 )
              *v25 = v56;
            else
              *(_DWORD *)v25 = v56;
            v51 = 1;
            goto LABEL_179;
          }
          if ( v4 != 111 )
          {
            if ( v4 != 112 )
            {
              if ( v4 == 115 )
                goto LABEL_55;
              if ( v4 == 117 )
                goto LABEL_123;
              if ( v4 != 120 )
                goto LABEL_156;
              v50 = 39;
              goto LABEL_114;
            }
            v57 = 8;
LABEL_113:
            v50 = 7;
LABEL_114:
            v58 = 16;
            if ( (v60 & 0x80u) != 0 )
            {
              v55[0] = 48;
              v54 = 2;
              v55[1] = v50 + 81;
            }
            goto LABEL_124;
          }
          v58 = 8;
          if ( (v60 & 0x80u) != 0 )
            BYTE1(v60) |= 2u;
LABEL_124:
          if ( (v60 & 0x8000) == 0 )
          {
            if ( (v60 & 0x20) != 0 )
            {
              if ( (v60 & 0x40) != 0 )
                LODWORD(v26) = (__int16)sub_58D82C(&a3);
              else
                LODWORD(v26) = (unsigned __int16)sub_58D82C(&a3);
            }
            else
            {
              if ( (v60 & 0x40) == 0 )
              {
                v26 = (unsigned int)sub_58D82C(&a3);
                goto LABEL_134;
              }
              LODWORD(v26) = sub_58D82C(&a3);
            }
            v26 = (int)v26;
          }
          else
          {
            LODWORD(v26) = sub_58D839(&a3);
          }
LABEL_134:
          if ( (v60 & 0x40) != 0 && v26 < 0 )
          {
            HIDWORD(v27) = -(int)v26;
            BYTE1(v60) |= 1u;
            LODWORD(v27) = (unsigned __int64)-v26 >> 32;
          }
          else
          {
            v27 = __PAIR64__(v26, HIDWORD(v26));
          }
          if ( (v60 & 0x8000) == 0 )
            LODWORD(v27) = 0;
          if ( v57 >= 0 )
            v60 &= ~8u;
          else
            v57 = 1;
          if ( !v27 )
            v54 = 0;
          v59 = &v43;
          while ( 1 )
          {
            v28 = v57--;
            if ( v28 <= 0 && !v27 )
              break;
            v46 = v58;
            v29 = sub_596100(HIDWORD(v27), v27, v58, v58 >> 31) + 48;
            v30 = sub_594FF0(HIDWORD(v27), v27, v46, HIDWORD(v46));
            v27 = __PAIR64__(v30, HIDWORD(v30));
            if ( v29 > 57 )
              LOBYTE(v29) = v50 + v29;
            v31 = v59--;
            *v31 = v29;
          }
          v32 = (_BYTE *)(&v43 - v59++);
          v58 = (int)v32;
          if ( (v60 & 0x200) != 0 && (*v59 != 48 || !v32) )
          {
            --v59;
            v21 = (int)(v32 + 1);
            *v59 = 48;
            goto LABEL_155;
          }
LABEL_156:
          if ( v51 )
            goto LABEL_179;
          v33 = v60;
          if ( (v60 & 0x40) == 0 )
            goto LABEL_165;
          if ( (v60 & 0x100) != 0 )
          {
            v55[0] = 45;
LABEL_164:
            v54 = 1;
            goto LABEL_165;
          }
          if ( (v60 & 1) != 0 )
          {
            v55[0] = 43;
            goto LABEL_164;
          }
          if ( (v60 & 2) != 0 )
          {
            v55[0] = 32;
            goto LABEL_164;
          }
LABEL_165:
          v34 = v53 - v54 - v58;
          if ( (v60 & 0xC) == 0 )
            sub_58D7C3(32, v53 - v54 - v58, a1, &v56);
          sub_58D7F4(v55, v54, a1, &v56);
          if ( (v33 & 8) != 0 && (v33 & 4) == 0 )
            sub_58D7C3(48, v34, a1, &v56);
          if ( v52 && v58 > 0 )
          {
            v35 = (WCHAR *)v59;
            v36 = v58 - 1;
            do
            {
              v37 = *v35++;
              v38 = sub_596030(v47, v37);
              if ( v38 <= 0 )
                break;
              sub_58D7F4(v47, v38, a1, &v56);
            }
            while ( v36-- );
          }
          else
          {
            sub_58D7F4(v59, v58, a1, &v56);
          }
          if ( (v60 & 4) != 0 )
            sub_58D7C3(32, v34, a1, &v56);
LABEL_179:
          v4 = *v61;
          v5 = v61 + 1;
          v6 = *v61++ == 0;
          if ( v6 )
            return v56;
          v7 = v57;
          v3 = v49;
          break;
        default:
          goto LABEL_179;
      }
    }
  }
  return v56;
}
