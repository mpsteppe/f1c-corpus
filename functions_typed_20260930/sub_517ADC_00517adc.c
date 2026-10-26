int __cdecl sub_517ADC(unsigned __int8 **a1, int a2)
{
  int v2; // ebx
  unsigned __int8 *v3; // eax
  int v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ecx
  int v10; // ebx
  bool v11; // zf
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // ecx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // ecx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v27; // eax
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // ecx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // eax
  unsigned __int8 *v37; // ecx
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // eax
  int v41; // [esp+18h] [ebp+8h]

  v2 = 0;
  if ( !a1 )
    return -2;
  v3 = a1[7];
  if ( !v3 || !*a1 )
    return -2;
  v4 = -5;
  if ( a2 == 4 )
    v2 = -5;
  v41 = v2;
  while ( 1 )
  {
    switch ( *(_DWORD *)v3 )
    {
      case 0:
        v5 = a1[1];
        if ( !v5 )
          return v4;
        v6 = a1[7];
        ++a1[2];
        a1[1] = v5 - 1;
        *((_DWORD *)v6 + 1) = **a1;
        v7 = a1[7];
        LOBYTE(v6) = *((_DWORD *)v7 + 1) & 0xF;
        ++*a1;
        v4 = v2;
        if ( (_BYTE)v6 == 8 )
        {
          if ( (unsigned int)((*((_DWORD *)v7 + 1) >> 4) + 8) <= *((_DWORD *)v7 + 4) )
          {
            *(_DWORD *)v7 = 1;
LABEL_14:
            v8 = a1[1];
            if ( !v8 )
              return v4;
            v9 = a1[7];
            ++a1[2];
            a1[1] = v8 - 1;
            v4 = v2;
            v10 = *(*a1)++;
            if ( !((v10 + (*((_DWORD *)v9 + 1) << 8)) % 0x1Fu) )
            {
              v11 = (v10 & 0x20) == 0;
              v2 = v41;
              if ( v11 )
              {
                *(_DWORD *)v9 = 7;
                goto LABEL_37;
              }
              *(_DWORD *)a1[7] = 2;
LABEL_43:
              v27 = a1[1];
              if ( !v27 )
                return v4;
              v28 = a1[7];
              ++a1[2];
              a1[1] = v27 - 1;
              *((_DWORD *)v28 + 2) = **a1 << 24;
              v29 = a1[7];
              ++*a1;
              v4 = v2;
              *(_DWORD *)v29 = 3;
LABEL_45:
              v30 = a1[1];
              if ( !v30 )
                return v4;
              v31 = *a1;
              ++a1[2];
              a1[1] = v30 - 1;
              *((_DWORD *)a1[7] + 2) += *v31 << 16;
              v32 = a1[7];
              ++*a1;
              v4 = v2;
              *(_DWORD *)v32 = 4;
LABEL_47:
              v33 = a1[1];
              if ( !v33 )
                return v4;
              v34 = *a1;
              ++a1[2];
              a1[1] = v33 - 1;
              *((_DWORD *)a1[7] + 2) += *v34 << 8;
              v35 = a1[7];
              ++*a1;
              v4 = v2;
              *(_DWORD *)v35 = 5;
LABEL_49:
              v36 = a1[1];
              if ( !v36 )
                return v4;
              v37 = *a1;
              ++a1[2];
              a1[1] = v36 - 1;
              *((_DWORD *)a1[7] + 2) += *v37;
              v38 = a1[7];
              ++*a1;
              a1[12] = (unsigned __int8 *)*((_DWORD *)v38 + 2);
              *(_DWORD *)v38 = 6;
              return 2;
            }
            v2 = v41;
            *(_DWORD *)v9 = 13;
            a1[6] = "incorrect header check";
          }
          else
          {
            *(_DWORD *)v7 = 13;
            a1[6] = "invalid window size";
          }
        }
        else
        {
          *(_DWORD *)v7 = 13;
          a1[6] = "unknown compression method";
        }
LABEL_36:
        *((_DWORD *)a1[7] + 1) = 5;
LABEL_37:
        v3 = a1[7];
        break;
      case 1:
        goto LABEL_14;
      case 2:
        goto LABEL_43;
      case 3:
        goto LABEL_45;
      case 4:
        goto LABEL_47;
      case 5:
        goto LABEL_49;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v39 = a1[7];
        a1[6] = "need dictionary";
        *((_DWORD *)v39 + 1) = 0;
        return -2;
      case 7:
        v12 = sub_527752(*((_DWORD *)a1[7] + 5), a1, v4);
        v4 = v12;
        if ( v12 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
          goto LABEL_37;
        }
        if ( !v12 )
          v4 = v2;
        if ( v4 != 1 )
          return v4;
        v4 = v2;
        sub_52765A(*((_DWORD *)a1[7] + 5), a1, a1[7] + 4);
        v13 = a1[7];
        if ( *((_DWORD *)v13 + 3) )
        {
          *(_DWORD *)v13 = 12;
          goto LABEL_37;
        }
        *(_DWORD *)v13 = 8;
LABEL_27:
        v14 = a1[1];
        if ( !v14 )
          return v4;
        v15 = a1[7];
        ++a1[2];
        a1[1] = v14 - 1;
        *((_DWORD *)v15 + 2) = **a1 << 24;
        v16 = a1[7];
        ++*a1;
        v4 = v2;
        *(_DWORD *)v16 = 9;
LABEL_29:
        v17 = a1[1];
        if ( !v17 )
          return v4;
        v18 = *a1;
        ++a1[2];
        a1[1] = v17 - 1;
        *((_DWORD *)a1[7] + 2) += *v18 << 16;
        v19 = a1[7];
        ++*a1;
        v4 = v2;
        *(_DWORD *)v19 = 10;
LABEL_31:
        v20 = a1[1];
        if ( !v20 )
          return v4;
        v21 = *a1;
        ++a1[2];
        a1[1] = v20 - 1;
        *((_DWORD *)a1[7] + 2) += *v21 << 8;
        v22 = a1[7];
        ++*a1;
        v4 = v2;
        *(_DWORD *)v22 = 11;
LABEL_33:
        v23 = a1[1];
        if ( !v23 )
          return v4;
        v24 = *a1;
        ++a1[2];
        a1[1] = v23 - 1;
        *((_DWORD *)a1[7] + 2) += *v24;
        v25 = a1[7];
        ++*a1;
        v4 = v2;
        if ( *((_DWORD *)v25 + 1) != *((_DWORD *)v25 + 2) )
        {
          *(_DWORD *)v25 = 13;
          a1[6] = "incorrect data check";
          goto LABEL_36;
        }
        *(_DWORD *)a1[7] = 12;
        return 1;
      case 8:
        goto LABEL_27;
      case 9:
        goto LABEL_29;
      case 0xA:
        goto LABEL_31;
      case 0xB:
        goto LABEL_33;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

