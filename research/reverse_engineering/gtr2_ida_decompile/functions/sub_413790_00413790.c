int __usercall sub_413790@<eax>(_DWORD *a1@<ecx>, _DWORD *a2@<esi>)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // eax
  bool v6; // al
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // eax
  bool v17; // al
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // eax
  _DWORD *v28; // [esp+8h] [ebp-8h]

  result = sub_473630(off_16C9A8C);
  if ( !(_BYTE)result )
  {
    v4 = (_DWORD *)a1[8];
    if ( v4 )
    {
      switch ( dword_B71A4C )
      {
        case 1:
          sub_412520(1, 0, 1);
          return sub_412EB0(a2, 1, 0);
        case 2:
          sub_412520(0, 0, 1);
          return sub_412EB0(a1, 0, 0);
        case 3:
          v5 = 3;
          if ( !byte_B71B34 && dword_91E07C[15572] && dword_BE1204 != 2 )
            v5 = 2;
          switch ( v5 )
          {
            case 0:
            case 1:
            case 2:
              v4[13] = 2;
              v6 = dword_B71890 != 0;
              v4[20] = 2;
              v7 = v6 ? 0 : 2;
              if ( dword_91E07C )
                sub_56AE80(v7, 1);
              if ( byte_B722CC || byte_B722FC || (v8 = v4[13]) != 0 && v8 != 2 )
              {
                sub_4124A0();
              }
              else if ( v4[2] )
              {
                goto LABEL_27;
              }
              goto LABEL_41;
            case 3:
              v4[13] = 3;
              goto LABEL_24;
            case 4:
              if ( (int)v4[14] > 0 )
              {
                v4[13] = 4;
LABEL_24:
                if ( dword_91E07C )
                  sub_56AE80(0, 1);
              }
              if ( !v4[2] )
                goto LABEL_41;
LABEL_27:
              sub_5E5190(0);
              v9 = v4[3];
              if ( v9 )
                goto LABEL_40;
              goto LABEL_41;
            case 5:
            case 6:
            case 7:
            case 8:
              v4[13] = v5;
              v10 = v5 - 7;
              if ( !v10 )
              {
                v14 = v4[11];
                if ( !v14 )
                  goto LABEL_36;
                v15 = (_DWORD *)(v14 + 192);
                *v15 = dword_91BF0C;
                v15[1] = dword_91BF10;
                v15[2] = dword_91BF14;
                dword_757714 = 0;
                v13 = v4[11];
                goto LABEL_35;
              }
              if ( v10 == 1 )
              {
                v11 = v4[12];
                if ( v11 )
                {
                  v12 = (_DWORD *)(v11 + 192);
                  *v12 = dword_91BF00;
                  v12[1] = dword_91BF04;
                  v12[2] = dword_91BF08;
                  dword_757714 = 0;
                  v13 = v4[12];
LABEL_35:
                  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13);
                }
              }
LABEL_36:
              if ( dword_91E07C )
                sub_56AE80(0, 1);
              if ( v4[2] )
              {
                sub_5E5190(0);
                v9 = v4[3];
                if ( v9 )
LABEL_40:
                  sub_5E6F50(0, 0, *(_DWORD *)(v9 + 4), *(_DWORD *)(v9 + 8), -13421773);
              }
LABEL_41:
              sub_40E2C0(v4, v4[13]);
              result = sub_412EB0(v28, 3, 0);
              break;
          }
          return result;
        case 4:
          v16 = 3;
          if ( !byte_B71B34 && dword_91E07C[15572] && dword_BE1204 != 2 )
            v16 = 2;
          break;
        default:
          sub_412520(2, 0, 1);
          return sub_412EB0(a1, 2, 0);
      }
      switch ( v16 )
      {
        case 0:
        case 1:
        case 2:
          v4[13] = 2;
          v17 = dword_B71890 != 0;
          v4[20] = 2;
          v18 = v17 ? 0 : 2;
          if ( dword_91E07C )
            sub_56AE80(v18, 1);
          if ( byte_B722CC || byte_B722FC || (v19 = v4[13]) != 0 && v19 != 2 )
          {
            sub_4124A0();
          }
          else if ( v4[2] )
          {
            goto LABEL_63;
          }
          goto LABEL_77;
        case 3:
          v4[13] = 3;
          goto LABEL_60;
        case 4:
          if ( (int)v4[14] > 0 )
          {
            v4[13] = 4;
LABEL_60:
            if ( dword_91E07C )
              sub_56AE80(0, 1);
          }
          if ( !v4[2] )
            goto LABEL_77;
LABEL_63:
          sub_5E5190(0);
          v20 = v4[3];
          if ( v20 )
            goto LABEL_76;
          goto LABEL_77;
        case 5:
        case 6:
        case 7:
        case 8:
          v4[13] = v16;
          v21 = v16 - 7;
          if ( !v21 )
          {
            v25 = v4[11];
            if ( !v25 )
              goto LABEL_72;
            v26 = (_DWORD *)(v25 + 192);
            *v26 = dword_91BF0C;
            v26[1] = dword_91BF10;
            v26[2] = dword_91BF14;
            dword_757714 = 0;
            v24 = v4[11];
            goto LABEL_71;
          }
          if ( v21 == 1 )
          {
            v22 = v4[12];
            if ( v22 )
            {
              v23 = (_DWORD *)(v22 + 192);
              *v23 = dword_91BF00;
              v23[1] = dword_91BF04;
              v23[2] = dword_91BF08;
              dword_757714 = 0;
              v24 = v4[12];
LABEL_71:
              (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 28))(v24);
            }
          }
LABEL_72:
          if ( dword_91E07C )
            sub_56AE80(0, 1);
          if ( v4[2] )
          {
            sub_5E5190(0);
            v20 = v4[3];
            if ( v20 )
LABEL_76:
              sub_5E6F50(0, 0, *(_DWORD *)(v20 + 4), *(_DWORD *)(v20 + 8), -13421773);
          }
LABEL_77:
          sub_40E2C0(v4, v4[13]);
          result = sub_412EB0(v28, 5, 0);
          break;
      }
    }
  }
  return result;
}
