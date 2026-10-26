int __fastcall sub_5357E0(unsigned __int8 **a1, int a2)
{
  int v3; // edi
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // ebx
  int v13; // ecx
  unsigned __int8 *v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // ecx
  unsigned __int8 *v19; // edx
  unsigned __int8 *v20; // edx
  unsigned __int8 *v21; // eax
  unsigned __int8 *v22; // ecx
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // ecx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // ecx
  int v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // edx
  unsigned __int8 *v31; // eax
  unsigned __int8 *v33; // ecx
  unsigned __int8 *v34; // ecx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // edx
  unsigned __int8 *v37; // edx
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // ecx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // ecx
  int v42; // edx
  unsigned __int8 *v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // eax
  unsigned int v46; // [esp+10h] [ebp-4h]

  if ( !a1 || !a1[7] || !*a1 )
    return -2;
  v3 = -5;
  v4 = a2 != 4 ? 0 : 0xFFFFFFFB;
  v46 = v4;
  while ( 2 )
  {
    v5 = a1[7];
    switch ( *(_DWORD *)v5 )
    {
      case 0:
        v6 = a1[1];
        if ( !v6 )
          return v3;
        a1[1] = v6 - 1;
        v3 = v4;
        ++a1[2];
        *((_DWORD *)v5 + 1) = **a1;
        v7 = a1[7];
        v8 = *((_DWORD *)v7 + 1) & 0xF;
        ++*a1;
        if ( (_BYTE)v8 != 8 )
        {
          *(_DWORD *)v7 = 13;
          v9 = a1[7];
          a1[6] = (unsigned __int8 *)aUnknownCompres_1;
          *((_DWORD *)v9 + 1) = 5;
          continue;
        }
        if ( (unsigned int)((*((_DWORD *)v7 + 1) >> 4) + 8) > *((_DWORD *)v7 + 4) )
        {
          *(_DWORD *)v7 = 13;
          v10 = a1[7];
          a1[6] = (unsigned __int8 *)aInvalidWindowS_0;
          *((_DWORD *)v10 + 1) = 5;
          continue;
        }
        *(_DWORD *)v7 = 1;
LABEL_12:
        v11 = a1[1];
        if ( !v11 )
          return v3;
        a1[1] = v11 - 1;
        v3 = v4;
        v12 = a1[7];
        ++a1[2];
        v13 = *(*a1)++;
        if ( (v13 + (*((_DWORD *)v12 + 1) << 8)) % 0x1Fu )
        {
          *(_DWORD *)v12 = 13;
          v14 = a1[7];
          v4 = v46;
          a1[6] = (unsigned __int8 *)aIncorrectHeade_0;
          *((_DWORD *)v14 + 1) = 5;
          continue;
        }
        if ( (v13 & 0x20) == 0 )
        {
          *(_DWORD *)v12 = 7;
          v4 = v46;
          continue;
        }
        v4 = v46;
        *(_DWORD *)a1[7] = 2;
LABEL_35:
        v31 = a1[1];
        if ( !v31 )
          return v3;
        v33 = *a1;
        ++a1[2];
        a1[1] = v31 - 1;
        v3 = v4;
        *((_DWORD *)a1[7] + 2) = *v33 << 24;
        v34 = a1[7];
        ++*a1;
        *(_DWORD *)v34 = 3;
LABEL_38:
        v35 = a1[1];
        if ( !v35 )
          return v3;
        v36 = *a1;
        a1[1] = v35 - 1;
        ++a1[2];
        v3 = v4;
        *((_DWORD *)a1[7] + 2) += *v36 << 16;
        v37 = a1[7];
        ++*a1;
        *(_DWORD *)v37 = 4;
LABEL_41:
        v38 = a1[1];
        if ( !v38 )
          return v3;
        v39 = *a1;
        a1[1] = v38 - 1;
        ++a1[2];
        v3 = v4;
        *((_DWORD *)a1[7] + 2) += *v39 << 8;
        ++*a1;
        *(_DWORD *)a1[7] = 5;
LABEL_44:
        v40 = a1[1];
        if ( !v40 )
          return v3;
        v41 = *a1;
        v42 = (int)(a1[2] + 1);
        a1[1] = v40 - 1;
        v43 = a1[7];
        a1[2] = (unsigned __int8 *)v42;
        *((_DWORD *)v43 + 2) += *v41;
        ++*a1;
        v44 = a1[7];
        a1[12] = (unsigned __int8 *)*((_DWORD *)v44 + 2);
        *(_DWORD *)v44 = 6;
        return 2;
      case 1:
        goto LABEL_12;
      case 2:
        goto LABEL_35;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_41;
      case 5:
        goto LABEL_44;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v45 = a1[7];
        a1[6] = (unsigned __int8 *)aNeedDictionary_0;
        *((_DWORD *)v45 + 1) = 0;
        return -2;
      case 7:
        v15 = sub_537110(v3);
        v3 = v15;
        if ( v15 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( !v15 )
            v3 = v4;
          if ( v3 != 1 )
            return v3;
          v3 = v4;
          StateResetWithCallback(a1[7] + 4);
          v16 = a1[7];
          if ( *((_DWORD *)v16 + 3) )
          {
            *(_DWORD *)v16 = 12;
          }
          else
          {
            *(_DWORD *)v16 = 8;
LABEL_25:
            v17 = a1[1];
            if ( !v17 )
              return v3;
            v18 = a1[7];
            ++a1[2];
            v19 = *a1;
            a1[1] = v17 - 1;
            v3 = v4;
            *((_DWORD *)v18 + 2) = *v19 << 24;
            v20 = a1[7];
            ++*a1;
            *(_DWORD *)v20 = 9;
LABEL_27:
            v21 = a1[1];
            if ( !v21 )
              return v3;
            v22 = *a1;
            ++a1[2];
            a1[1] = v21 - 1;
            v3 = v4;
            *((_DWORD *)a1[7] + 2) += *v22 << 16;
            ++*a1;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v23 = a1[1];
            if ( !v23 )
              return v3;
            v24 = *a1;
            ++a1[2];
            a1[1] = v23 - 1;
            v3 = v4;
            *((_DWORD *)a1[7] + 2) += *v24 << 8;
            ++*a1;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v25 = a1[1];
            if ( !v25 )
              return v3;
            v26 = *a1;
            v27 = (int)(a1[2] + 1);
            a1[1] = v25 - 1;
            v28 = a1[7];
            a1[2] = (unsigned __int8 *)v27;
            v3 = v4;
            *((_DWORD *)v28 + 2) += *v26;
            ++*a1;
            v29 = a1[7];
            if ( *((_DWORD *)v29 + 1) == *((_DWORD *)v29 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v29 = 13;
            v30 = a1[7];
            a1[6] = (unsigned __int8 *)aIncorrectDataC_0;
            *((_DWORD *)v30 + 1) = 5;
          }
        }
        continue;
      case 8:
        goto LABEL_25;
      case 9:
        goto LABEL_27;
      case 0xA:
        goto LABEL_29;
      case 0xB:
        goto LABEL_31;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

