int __userpurge sub_412525@<eax>(char a1@<al>, _DWORD *a2@<ecx>, int a3, int a4, int a5)
{
  bool v5; // zf
  int v6; // eax
  int v8; // ecx
  BOOL v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // eax

  v5 = a1 == 0;
  v6 = a3;
  if ( v5 && a3 == 3 && dword_91E07C[15572] && dword_BE1204 != 2 )
  {
    v6 = 2;
    v8 = 0;
  }
  else
  {
    v8 = a4;
  }
  switch ( v6 )
  {
    case 0:
    case 1:
    case 2:
      if ( a5 )
      {
        if ( v6 )
        {
          if ( v6 == 1 )
          {
            v10 = 1;
            a2[13] = 1;
            a2[20] = 1;
          }
          else
          {
            a2[13] = 2;
            v9 = dword_B71890 != 0;
            a2[20] = 2;
            v10 = v9 ? 0 : 2;
          }
LABEL_15:
          if ( dword_91E07C )
            sub_56AE80(v10, 1);
          if ( !byte_B722CC && !byte_B722FC )
          {
            v11 = a2[13];
            if ( !v11 || v11 == 2 )
            {
              if ( !a2[2] )
                return sub_40E2C0(a2, a2[13]);
              goto LABEL_58;
            }
          }
          sub_4124A0();
          return sub_40E2C0(a2, a2[13]);
        }
        a2[20] = 0;
        goto LABEL_14;
      }
      if ( v8 )
        v13 = 2 * (v8 > 0) - 1;
      else
        v13 = 0;
      if ( a2[13] <= 2u )
      {
        v14 = v13 + a2[20];
        a2[20] = v14;
        if ( v14 <= 2 )
        {
          if ( v14 < 0 )
            a2[20] = 2;
        }
        else
        {
          a2[20] = 0;
        }
      }
      if ( *(_DWORD *)dword_B72314 == 8
        || *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) == *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468) )
      {
        goto LABEL_39;
      }
      v15 = a2[20];
      if ( v15 == 1 )
      {
        if ( v13 > 0 && dword_B71890 )
        {
          a2[20] = 2;
          goto LABEL_39;
        }
      }
      else if ( v15 != 2 || dword_B71890 )
      {
LABEL_39:
        v16 = a2[20];
        if ( v16 )
        {
          if ( v16 == 1 )
          {
            a2[13] = 1;
            v10 = 1;
          }
          else
          {
            a2[13] = 2;
            v10 = dword_B71890 != 0 ? 0 : 2;
          }
          goto LABEL_15;
        }
LABEL_14:
        a2[13] = 0;
        v10 = 3;
        goto LABEL_15;
      }
      a2[20] = 0;
      goto LABEL_39;
    case 3:
      a2[13] = 3;
      goto LABEL_55;
    case 4:
      if ( a2[13] == 4 && v8 )
      {
        if ( v8 == 1 )
        {
          v17 = a2[14];
          v18 = a2[15] + 1;
          a2[15] = v18;
          if ( v18 >= v17 )
            a2[15] = 0;
        }
        else if ( --a2[15] < 0 )
        {
          a2[15] = a2[14] - 1;
        }
      }
      else if ( (int)a2[14] > 0 )
      {
        a2[13] = 4;
LABEL_55:
        if ( dword_91E07C )
          sub_56AE80(0, 1);
      }
      if ( !a2[2] )
        return sub_40E2C0(a2, a2[13]);
LABEL_58:
      sub_5E5190(0);
      v20 = a2[3];
      if ( v20 )
        goto LABEL_71;
      return sub_40E2C0(a2, a2[13]);
    case 5:
    case 6:
    case 7:
    case 8:
      a2[13] = v6;
      v21 = v6 - 7;
      if ( !v21 )
      {
        v25 = a2[11];
        if ( !v25 )
          goto LABEL_67;
        v26 = (_DWORD *)(v25 + 192);
        *v26 = dword_91BF0C;
        v26[1] = dword_91BF10;
        v26[2] = dword_91BF14;
        dword_757714 = 0;
        v24 = a2[11];
        goto LABEL_66;
      }
      if ( v21 == 1 )
      {
        v22 = a2[12];
        if ( v22 )
        {
          v23 = (_DWORD *)(v22 + 192);
          *v23 = dword_91BF00;
          v23[1] = dword_91BF04;
          v23[2] = dword_91BF08;
          dword_757714 = 0;
          v24 = a2[12];
LABEL_66:
          (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 28))(v24);
        }
      }
LABEL_67:
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( a2[2] )
      {
        sub_5E5190(0);
        v20 = a2[3];
        if ( v20 )
LABEL_71:
          sub_5E6F50(0, 0, *(_DWORD *)(v20 + 4), *(_DWORD *)(v20 + 8), -13421773);
      }
      return sub_40E2C0(a2, a2[13]);
    default:
      return sub_40E2C0(a2, a2[13]);
  }
}
