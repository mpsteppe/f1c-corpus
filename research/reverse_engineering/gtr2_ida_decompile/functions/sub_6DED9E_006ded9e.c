int __stdcall sub_6DED9E(_DWORD *a1, _DWORD *a2, int a3)
{
  _BYTE *v5; // edx
  int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  unsigned int v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  int v20; // eax
  unsigned int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // ecx
  int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // ecx
  unsigned __int8 *v34; // ecx
  int v36; // eax
  unsigned __int8 *v37; // ebx
  int v38; // [esp-4h] [ebp-28h]
  int v39; // [esp+Ch] [ebp-18h]
  unsigned int v40; // [esp+Ch] [ebp-18h]
  unsigned int v41; // [esp+Ch] [ebp-18h]
  _BYTE *v42; // [esp+14h] [ebp-10h]
  unsigned int v43; // [esp+18h] [ebp-Ch]
  unsigned int v44; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v45; // [esp+20h] [ebp-4h]
  unsigned int v46; // [esp+2Ch] [ebp+8h]
  unsigned int v47; // [esp+30h] [ebp+Ch]
  int v48; // [esp+34h] [ebp+10h]

  v45 = (unsigned __int8 *)*a2;
  v5 = (_BYTE *)a1[13];
  v6 = a1[1];
  v44 = a2[1];
  v47 = a1[8];
  v46 = a1[7];
  v7 = a1[12];
  if ( (unsigned int)v5 >= v7 )
    v8 = a1[11] - (_DWORD)v5;
  else
    v8 = v7 - (_DWORD)v5 - 1;
LABEL_82:
  v43 = v8;
  while ( 2 )
  {
    switch ( *(_DWORD *)v6 )
    {
      case 0:
        if ( v8 >= 0x102 && v44 >= 0xA )
        {
          a1[8] = v47;
          a1[7] = v46;
          a2[1] = v44;
          a2[2] += &v45[-*a2];
          *a2 = v45;
          a1[13] = v5;
          v9 = sub_6DF93A(
                 *(unsigned __int8 *)(v6 + 16),
                 *(unsigned __int8 *)(v6 + 17),
                 *(_DWORD *)(v6 + 20),
                 *(_DWORD *)(v6 + 24),
                 a1,
                 a2);
          v5 = (_BYTE *)a1[13];
          a3 = v9;
          v45 = (unsigned __int8 *)*a2;
          v44 = a2[1];
          v47 = a1[8];
          v46 = a1[7];
          v10 = a1[12];
          v11 = (unsigned int)v5 >= v10 ? a1[11] - (_DWORD)v5 : v10 - (_DWORD)v5 - 1;
          v43 = v11;
          if ( a3 )
          {
            *(_DWORD *)v6 = 2 * (a3 != 1) + 7;
            goto LABEL_36;
          }
        }
        *(_DWORD *)(v6 + 12) = *(unsigned __int8 *)(v6 + 16);
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 20);
        *(_DWORD *)v6 = 1;
        goto LABEL_15;
      case 1:
LABEL_15:
        while ( 2 )
        {
          v12 = *(_DWORD *)(v6 + 12);
          if ( v46 >= v12 )
          {
            v13 = (unsigned __int8 *)(*(_DWORD *)(v6 + 8) + 8 * (v47 & dword_91BBC0[v12]));
            v47 >>= v13[1];
            v46 -= v13[1];
            v39 = *v13;
            if ( *v13 )
            {
              if ( (v39 & 0x10) != 0 )
              {
                *(_DWORD *)(v6 + 8) = v39 & 0xF;
                *(_DWORD *)(v6 + 4) = *((_DWORD *)v13 + 1);
                *(_DWORD *)v6 = 2;
                goto LABEL_36;
              }
              if ( (v39 & 0x40) != 0 )
              {
                if ( (v39 & 0x20) != 0 )
                {
                  *(_DWORD *)v6 = 7;
                  goto LABEL_36;
                }
                *(_DWORD *)v6 = 9;
                a2[6] = "invalid literal/length code";
LABEL_88:
                v38 = -3;
                goto LABEL_84;
              }
              *(_DWORD *)(v6 + 12) = v39;
              v14 = &v13[8 * *((_DWORD *)v13 + 1)];
            }
            else
            {
              v14 = (unsigned __int8 *)*((_DWORD *)v13 + 1);
              *(_DWORD *)v6 = 6;
            }
            goto LABEL_35;
          }
          if ( v44 )
          {
            a3 = 0;
            --v44;
            v47 |= *v45++ << v46;
            v46 += 8;
            continue;
          }
          goto LABEL_90;
        }
      case 2:
        while ( 2 )
        {
          v15 = *(_DWORD *)(v6 + 8);
          if ( v46 < v15 )
          {
            if ( v44 )
            {
              a3 = 0;
              --v44;
              v47 |= *v45++ << v46;
              v46 += 8;
              continue;
            }
LABEL_90:
            v38 = a3;
            a1[8] = v47;
            a1[7] = v46;
            a2[1] = 0;
            goto LABEL_85;
          }
          break;
        }
        v16 = *(_DWORD *)(v6 + 8);
        *(_DWORD *)(v6 + 4) += v47 & dword_91BBC0[v15];
        v47 >>= v16;
        v46 -= v16;
        *(_DWORD *)(v6 + 12) = *(unsigned __int8 *)(v6 + 17);
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 24);
        *(_DWORD *)v6 = 3;
LABEL_30:
        while ( 1 )
        {
          v17 = *(_DWORD *)(v6 + 12);
          if ( v46 >= v17 )
            break;
          if ( !v44 )
            goto LABEL_90;
          a3 = 0;
          --v44;
          v47 |= *v45++ << v46;
          v46 += 8;
        }
        v18 = (unsigned __int8 *)(*(_DWORD *)(v6 + 8) + 8 * (v47 & dword_91BBC0[v17]));
        v47 >>= v18[1];
        v46 -= v18[1];
        v19 = v18;
        v20 = *v18;
        if ( (v20 & 0x10) != 0 )
        {
          *(_DWORD *)(v6 + 8) = v20 & 0xF;
          *(_DWORD *)(v6 + 12) = *((_DWORD *)v19 + 1);
          *(_DWORD *)v6 = 4;
          goto LABEL_36;
        }
        if ( (v20 & 0x40) != 0 )
        {
          *(_DWORD *)v6 = 9;
          a2[6] = "invalid distance code";
          goto LABEL_88;
        }
        *(_DWORD *)(v6 + 12) = v20;
        v14 = &v19[8 * *((_DWORD *)v19 + 1)];
LABEL_35:
        *(_DWORD *)(v6 + 8) = v14;
LABEL_36:
        v8 = v43;
        continue;
      case 3:
        goto LABEL_30;
      case 4:
        while ( 2 )
        {
          v21 = *(_DWORD *)(v6 + 8);
          if ( v46 < v21 )
          {
            if ( v44 )
            {
              a3 = 0;
              --v44;
              v47 |= *v45++ << v46;
              v46 += 8;
              continue;
            }
            goto LABEL_90;
          }
          break;
        }
        v22 = *(_DWORD *)(v6 + 8);
        *(_DWORD *)(v6 + 12) += v47 & dword_91BBC0[v21];
        v47 >>= v22;
        v46 -= v22;
        *(_DWORD *)v6 = 5;
LABEL_41:
        v23 = a1[10];
        v42 = &v5[-*(_DWORD *)(v6 + 12)];
        if ( (unsigned int)v42 < v23 )
        {
          do
            v42 += a1[11] - v23;
          while ( (unsigned int)v42 < a1[10] );
        }
        v8 = v43;
LABEL_44:
        if ( !*(_DWORD *)(v6 + 4) )
        {
          *(_DWORD *)v6 = 0;
          continue;
        }
        if ( v8 )
          goto LABEL_61;
        if ( v5 == (_BYTE *)a1[11] )
        {
          v24 = a1[12];
          v25 = a1[10];
          if ( v24 != v25 )
          {
            v5 = (_BYTE *)a1[10];
            v8 = v25 >= v24 ? a1[11] - v25 : v24 - v25 - 1;
            if ( v8 )
              goto LABEL_61;
          }
        }
        a1[13] = v5;
        v26 = sub_6DF829(a1, a2, a3);
        v5 = (_BYTE *)a1[13];
        v48 = v26;
        v27 = a1[12];
        v40 = v27;
        if ( (unsigned int)v5 >= v27 )
          v8 = a1[11] - (_DWORD)v5;
        else
          v8 = v27 - (_DWORD)v5 - 1;
        if ( v5 == (_BYTE *)a1[11] )
        {
          v28 = a1[10];
          if ( v40 != v28 )
          {
            v5 = (_BYTE *)a1[10];
            if ( v28 >= v40 )
              v8 = a1[11] - v28;
            else
              v8 = v40 - v28 - 1;
          }
        }
        if ( v8 )
        {
LABEL_61:
          a3 = 0;
          *v5++ = *v42++;
          v43 = --v8;
          if ( v42 == (_BYTE *)a1[11] )
            v42 = (_BYTE *)a1[10];
          --*(_DWORD *)(v6 + 4);
          goto LABEL_44;
        }
LABEL_91:
        v38 = v48;
LABEL_84:
        a1[8] = v47;
        a1[7] = v46;
        a2[1] = v44;
LABEL_85:
        v34 = &v45[-*a2];
        *a2 = v45;
        a2[2] += v34;
LABEL_86:
        a1[13] = v5;
        return sub_6DF829(a1, a2, v38);
      case 5:
        goto LABEL_41;
      case 6:
        if ( !v8 )
        {
          if ( v5 != (_BYTE *)a1[11]
            || (v29 = a1[12], v30 = a1[10], v29 == v30)
            || ((v5 = (_BYTE *)a1[10], v30 >= v29) ? (v8 = a1[11] - v30) : (v8 = v29 - v30 - 1), !v8) )
          {
            a1[13] = v5;
            v31 = sub_6DF829(a1, a2, a3);
            v5 = (_BYTE *)a1[13];
            v48 = v31;
            v32 = a1[12];
            v41 = v32;
            if ( (unsigned int)v5 >= v32 )
              v8 = a1[11] - (_DWORD)v5;
            else
              v8 = v32 - (_DWORD)v5 - 1;
            if ( v5 == (_BYTE *)a1[11] )
            {
              v33 = a1[10];
              if ( v41 != v33 )
              {
                v5 = (_BYTE *)a1[10];
                if ( v33 >= v41 )
                  v8 = a1[11] - v33;
                else
                  v8 = v41 - v33 - 1;
              }
            }
            if ( !v8 )
              goto LABEL_91;
          }
        }
        a3 = 0;
        *v5++ = *(_BYTE *)(v6 + 8);
        --v8;
        *(_DWORD *)v6 = 0;
        goto LABEL_82;
      case 7:
        if ( v46 > 7 )
        {
          v46 -= 8;
          ++v44;
          --v45;
        }
        a1[13] = v5;
        v36 = sub_6DF829(a1, a2, a3);
        v5 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v5 )
        {
          a1[8] = v47;
          a1[7] = v46;
          a2[1] = v44;
          v37 = &v45[-*a2];
          *a2 = v45;
          a2[2] += v37;
          v38 = v36;
          goto LABEL_86;
        }
        *(_DWORD *)v6 = 8;
LABEL_97:
        v38 = 1;
        goto LABEL_84;
      case 8:
        goto LABEL_97;
      case 9:
        goto LABEL_88;
      default:
        v38 = -2;
        goto LABEL_84;
    }
  }
}
