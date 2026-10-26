int __cdecl sub_641CE6(int a1, char **a2, char *a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // kr00_4
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  _BYTE *v11; // esi
  char v12; // cl
  char v13; // bl
  char *v14; // ecx
  int v15; // esi
  int i; // eax
  int v17; // eax
  int v18; // eax
  __int16 v19; // dx
  int v20; // ebx
  unsigned int v21; // esi
  __int16 v22; // ax
  int result; // eax
  int v24; // [esp-10h] [ebp-6Ch]
  int v25; // [esp-10h] [ebp-6Ch]
  int v26; // [esp+0h] [ebp-5Ch]
  int v27; // [esp+4h] [ebp-58h]
  int v28; // [esp+8h] [ebp-54h]
  __int16 v29; // [esp+Ch] [ebp-50h]
  int v30; // [esp+10h] [ebp-4Ch]
  int v31; // [esp+14h] [ebp-48h]
  int v32; // [esp+18h] [ebp-44h]
  char *v33; // [esp+1Ch] [ebp-40h]
  int v34; // [esp+20h] [ebp-3Ch]
  unsigned int v35; // [esp+24h] [ebp-38h]
  _BYTE *v36; // [esp+28h] [ebp-34h]
  _BYTE v37[23]; // [esp+2Ch] [ebp-30h] BYREF
  char v38; // [esp+43h] [ebp-19h]
  _WORD v39[3]; // [esp+48h] [ebp-14h] BYREF
  unsigned int v40; // [esp+4Eh] [ebp-Eh]
  int v41; // [esp+52h] [ebp-Ah]
  int v42; // [esp+58h] [ebp-4h]

  v7 = __readeflags();
  v8 = *(_DWORD *)__ROR4__(dword_16C6E8C, 37);
  __writeeflags(v7);
  v42 = v8;
  v9 = 0;
  v10 = a3;
  v11 = v37;
  v36 = v37;
  v29 = 0;
  v30 = 1;
  v35 = 0;
  v32 = 0;
  v27 = 0;
  v26 = 0;
  v28 = 0;
  v34 = 0;
  v31 = 0;
  v33 = a3;
  while ( 1 )
  {
    v12 = *v10;
    if ( *v10 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v10;
  }
  while ( 2 )
  {
    v13 = *v10++;
    switch ( v9 )
    {
      case 0:
        if ( v13 >= 49 && v13 <= 57 )
          goto LABEL_10;
        if ( v13 == byte_9131A4 )
          goto LABEL_12;
        switch ( v13 )
        {
          case '+':
            v29 = 0;
            v9 = 2;
            continue;
          case '-':
            v9 = 2;
            v29 = 0x8000;
            continue;
          case '0':
            goto LABEL_36;
        }
        HIWORD(v36) = HIWORD(v11);
        --v10;
        goto LABEL_72;
      case 1:
        v9 = 1;
        v32 = 1;
        if ( v13 >= 49 && v13 <= 57 )
          goto LABEL_10;
        if ( v13 == byte_9131A4 )
          goto LABEL_22;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_31;
        if ( v13 == 48 )
          continue;
        goto LABEL_26;
      case 2:
        if ( v13 >= 49 && v13 <= 57 )
        {
LABEL_10:
          v24 = 3;
LABEL_82:
          v9 = v24;
          --v10;
          continue;
        }
        if ( v13 == byte_9131A4 )
        {
LABEL_12:
          v25 = 5;
LABEL_90:
          v9 = v25;
          continue;
        }
        if ( v13 == 48 )
        {
LABEL_36:
          v9 = 1;
          continue;
        }
LABEL_84:
        v10 = v33;
LABEL_71:
        HIWORD(v36) = HIWORD(v11);
LABEL_72:
        *a2 = v10;
        if ( !v32 )
        {
          v31 = 4;
LABEL_119:
          v19 = 0;
          v22 = 0;
          v21 = 0;
          v20 = 0;
          goto LABEL_120;
        }
        if ( v35 > 0x18 )
        {
          if ( v38 >= 5 )
            ++v38;
          --v11;
          ++v34;
          v35 = 24;
        }
        if ( !v35 )
          goto LABEL_119;
        while ( !*--v11 )
        {
          --v35;
          ++v34;
        }
        __mtold12(v37, v35, v39);
        v17 = v28;
        if ( v30 < 0 )
          v17 = -v28;
        v18 = v34 + v17;
        if ( !v26 )
          v18 += a5;
        if ( !v27 )
          v18 -= a6;
        if ( v18 > 5200 )
        {
          v20 = 0;
          v22 = 0x7FFF;
          v21 = 0x80000000;
          v19 = 0;
          v31 = 2;
          goto LABEL_120;
        }
        if ( v18 < -5200 )
        {
          v31 = 1;
          goto LABEL_119;
        }
        __multtenpow12(v39, v18, a4);
        v19 = v39[0];
        v20 = *(_DWORD *)&v39[1];
        v21 = v40;
        v22 = v41;
LABEL_120:
        *(_DWORD *)(a1 + 6) = v21;
        *(_DWORD *)(a1 + 2) = v20;
        *(_WORD *)(a1 + 10) = v29 | v22;
        result = v31;
        *(_WORD *)a1 = v19;
        return result;
      case 3:
        v32 = 1;
        while ( isdigit((unsigned __int8)v13) )
        {
          if ( v35 >= 0x19 )
          {
            ++v34;
          }
          else
          {
            ++v35;
            *v11++ = v13 - 48;
          }
          v13 = *v10++;
        }
        if ( v13 != byte_9131A4 )
          goto LABEL_54;
LABEL_22:
        v25 = 4;
        goto LABEL_90;
      case 4:
        v32 = 1;
        v27 = 1;
        if ( !v35 )
        {
          while ( v13 == 48 )
          {
            --v34;
            v13 = *v10++;
          }
        }
        while ( isdigit((unsigned __int8)v13) )
        {
          if ( v35 < 0x19 )
          {
            ++v35;
            *v11++ = v13 - 48;
            --v34;
          }
          v13 = *v10++;
        }
LABEL_54:
        if ( v13 == 43 || v13 == 45 )
        {
LABEL_31:
          --v10;
          v25 = 11;
        }
        else
        {
LABEL_26:
          if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          {
LABEL_70:
            --v10;
            goto LABEL_71;
          }
          v25 = 6;
        }
        goto LABEL_90;
      case 5:
        v27 = 1;
        if ( !isdigit((unsigned __int8)v13) )
          goto LABEL_84;
        v24 = 4;
        goto LABEL_82;
      case 6:
        v14 = v10 - 2;
        v33 = v10 - 2;
        if ( v13 >= 49 && v13 <= 57 )
          goto LABEL_81;
        if ( v13 == 43 )
          goto LABEL_89;
        if ( v13 == 45 )
          goto LABEL_88;
        if ( v13 != 48 )
          goto LABEL_94;
LABEL_64:
        v25 = 8;
        goto LABEL_90;
      case 7:
        if ( v13 >= 49 && v13 <= 57 )
          goto LABEL_81;
        if ( v13 != 48 )
          goto LABEL_84;
        goto LABEL_64;
      case 8:
        v26 = 1;
        while ( v13 == 48 )
          v13 = *v10++;
        if ( v13 < 49 || v13 > 57 )
          goto LABEL_70;
LABEL_81:
        v24 = 9;
        goto LABEL_82;
      case 9:
        v36 = v11;
        v26 = 1;
        v15 = 0;
        while ( 2 )
        {
          if ( isdigit((unsigned __int8)v13) )
          {
            v15 = v13 + 10 * v15 - 48;
            if ( v15 <= 5200 )
            {
              v13 = *v10++;
              continue;
            }
            v15 = 5201;
          }
          break;
        }
        v28 = v15;
        for ( i = (unsigned __int8)v13; isdigit(i); i = (unsigned __int8)i )
          LOBYTE(i) = *v10++;
        v11 = v36;
        --v10;
        goto LABEL_72;
      case 11:
        if ( a7 )
        {
          v14 = v10 - 1;
          v33 = v10 - 1;
          if ( v13 == 43 )
          {
LABEL_89:
            v25 = 7;
            goto LABEL_90;
          }
          if ( v13 != 45 )
          {
LABEL_94:
            HIWORD(v36) = HIWORD(v11);
            v10 = v14;
            goto LABEL_72;
          }
LABEL_88:
          v30 = -1;
          v9 = 7;
        }
        else
        {
          v9 = 10;
          --v10;
LABEL_92:
          if ( v9 == 10 )
            goto LABEL_71;
        }
        continue;
      default:
        goto LABEL_92;
    }
  }
}
