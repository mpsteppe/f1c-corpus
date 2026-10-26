int __fastcall sub_62C6A0(unsigned __int8 **a1, int a2)
{
  unsigned int *v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  unsigned int v6; // ebp
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // edx
  unsigned __int8 *v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // edx
  unsigned __int8 *v21; // edx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // edx
  unsigned __int8 *v24; // ecx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // edx
  unsigned __int8 *v32; // ecx
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // eax
  unsigned __int8 *v36; // eax
  unsigned __int8 *v37; // ecx
  unsigned __int8 *v38; // edx
  unsigned __int8 *v39; // edx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // edx
  unsigned __int8 *v42; // ecx
  unsigned __int8 *v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // ecx
  unsigned __int8 *v46; // eax
  unsigned __int8 *v47; // edx
  unsigned __int8 *v48; // ecx
  unsigned __int8 *v49; // eax
  unsigned __int8 *v50; // eax
  unsigned __int8 *v51; // eax

  if ( !a1 )
    return -2;
  v3 = (unsigned int *)a1[7];
  if ( !v3 || !*a1 )
    return -2;
  v4 = *v3;
  v5 = -5;
  v6 = a2 != 4 ? 0 : 0xFFFFFFFB;
  while ( 2 )
  {
    switch ( v4 )
    {
      case 0u:
        v7 = a1[1];
        if ( !v7 )
          return v5;
        v8 = a1[7];
        ++a1[2];
        v9 = *a1;
        a1[1] = v7 - 1;
        *((_DWORD *)v8 + 1) = *v9;
        v10 = a1[7];
        LOBYTE(v9) = *((_DWORD *)v10 + 1) & 0xF;
        v5 = v6;
        ++*a1;
        if ( (_BYTE)v9 != 8 )
        {
          *(_DWORD *)v10 = 13;
          v11 = a1[7];
          a1[6] = "unknown compression method";
          *((_DWORD *)v11 + 1) = 5;
          goto LABEL_35;
        }
        if ( (unsigned int)((*((_DWORD *)v10 + 1) >> 4) + 8) > *((_DWORD *)v10 + 4) )
        {
          *(_DWORD *)v10 = 13;
          a1[6] = "invalid window size";
          goto LABEL_34;
        }
        *(_DWORD *)v10 = 1;
        goto LABEL_12;
      case 1u:
LABEL_12:
        v12 = a1[1];
        if ( !v12 )
          return v5;
        v13 = a1[7];
        a1[1] = v12 - 1;
        ++a1[2];
        v14 = *(*a1)++;
        v5 = v6;
        if ( (v14 + (*((_DWORD *)v13 + 1) << 8)) % 0x1Fu )
        {
          *(_DWORD *)v13 = 13;
          v15 = a1[7];
          a1[6] = "incorrect header check";
          *((_DWORD *)v15 + 1) = 5;
LABEL_35:
          v4 = *(_DWORD *)a1[7];
          if ( v4 > 0xD )
            return -2;
          continue;
        }
        if ( (v14 & 0x20) == 0 )
        {
          *(_DWORD *)v13 = 7;
          goto LABEL_35;
        }
        *(_DWORD *)a1[7] = 2;
LABEL_39:
        v36 = a1[1];
        if ( !v36 )
          return v5;
        v37 = a1[7];
        ++a1[2];
        v38 = *a1;
        a1[1] = v36 - 1;
        *((_DWORD *)v37 + 2) = *v38 << 24;
        v39 = a1[7];
        ++*a1;
        v5 = v6;
        *(_DWORD *)v39 = 3;
LABEL_41:
        v40 = a1[1];
        if ( !v40 )
          return v5;
        v41 = a1[2];
        v42 = *a1;
        a1[1] = v40 - 1;
        v43 = a1[7];
        a1[2] = v41 + 1;
        *((_DWORD *)v43 + 2) += *v42 << 16;
        ++*a1;
        v5 = v6;
        *(_DWORD *)a1[7] = 4;
LABEL_43:
        v44 = a1[1];
        if ( !v44 )
          return v5;
        v45 = *a1;
        a1[1] = v44 - 1;
        ++a1[2];
        *((_DWORD *)a1[7] + 2) += *v45 << 8;
        ++*a1;
        v5 = v6;
        *(_DWORD *)a1[7] = 5;
LABEL_45:
        v46 = a1[1];
        if ( !v46 )
          return v5;
        v47 = a1[2];
        v48 = *a1;
        a1[1] = v46 - 1;
        v49 = a1[7];
        a1[2] = v47 + 1;
        *((_DWORD *)v49 + 2) += *v48;
        ++*a1;
        v50 = a1[7];
        a1[12] = (unsigned __int8 *)*((_DWORD *)v50 + 2);
        *(_DWORD *)v50 = 6;
        return 2;
      case 2u:
        goto LABEL_39;
      case 3u:
        goto LABEL_41;
      case 4u:
        goto LABEL_43;
      case 5u:
        goto LABEL_45;
      case 6u:
        *(_DWORD *)a1[7] = 13;
        v51 = a1[7];
        a1[6] = "need dictionary";
        *((_DWORD *)v51 + 1) = 0;
        return -2;
      case 7u:
        v16 = sub_62E820(v5);
        v5 = v16;
        if ( v16 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( !v16 )
            v5 = v6;
          if ( v5 != 1 )
            return v5;
          v5 = v6;
          sub_62E710(a1[7] + 4);
          v17 = a1[7];
          if ( *((_DWORD *)v17 + 3) )
          {
            *(_DWORD *)v17 = 12;
          }
          else
          {
            *(_DWORD *)v17 = 8;
LABEL_25:
            v18 = a1[1];
            if ( !v18 )
              return v5;
            v19 = a1[7];
            ++a1[2];
            v20 = *a1;
            a1[1] = v18 - 1;
            *((_DWORD *)v19 + 2) = *v20 << 24;
            v21 = a1[7];
            ++*a1;
            v5 = v6;
            *(_DWORD *)v21 = 9;
LABEL_27:
            v22 = a1[1];
            if ( !v22 )
              return v5;
            v23 = a1[2];
            v24 = *a1;
            a1[1] = v22 - 1;
            v25 = a1[7];
            a1[2] = v23 + 1;
            *((_DWORD *)v25 + 2) += *v24 << 16;
            ++*a1;
            v5 = v6;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v26 = a1[1];
            if ( !v26 )
              return v5;
            v27 = a1[2];
            v28 = *a1;
            a1[1] = v26 - 1;
            v29 = a1[7];
            a1[2] = v27 + 1;
            *((_DWORD *)v29 + 2) += *v28 << 8;
            ++*a1;
            v5 = v6;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v30 = a1[1];
            if ( !v30 )
              return v5;
            v31 = a1[2];
            v32 = *a1;
            a1[1] = v30 - 1;
            v33 = a1[7];
            a1[2] = v31 + 1;
            *((_DWORD *)v33 + 2) += *v32;
            ++*a1;
            v34 = a1[7];
            v5 = v6;
            if ( *((_DWORD *)v34 + 1) == *((_DWORD *)v34 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v34 = 13;
            a1[6] = "incorrect data check";
LABEL_34:
            *((_DWORD *)a1[7] + 1) = 5;
          }
        }
        goto LABEL_35;
      case 8u:
        goto LABEL_25;
      case 9u:
        goto LABEL_27;
      case 0xAu:
        goto LABEL_29;
      case 0xBu:
        goto LABEL_31;
      case 0xCu:
        return 1;
      case 0xDu:
        return -3;
      default:
        return -2;
    }
  }
}
