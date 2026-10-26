int __thiscall sub_412EB0(_DWORD *this, int a2, char a3)
{
  BOOL v3; // edi
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  int v21; // ecx
  int v22; // eax
  _DWORD *v23; // eax
  char v24; // cl
  int v25; // eax
  int v26; // esi
  int v27; // eax
  _DWORD *v28; // esi
  int v29; // ecx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // esi
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  int v38; // eax
  _DWORD *v39; // eax
  int v40; // ecx
  int v41; // eax
  _DWORD *v42; // eax
  int v43; // ecx
  int result; // eax
  int v45; // [esp+4h] [ebp-Ch]
  int v46; // [esp+8h] [ebp-8h]

  v3 = 0;
  result = dword_16C9A2C;
  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
      v5 = 2;
      this[2] = this[8];
      if ( a2 )
      {
        if ( a2 == 1 )
          v5 = 1;
      }
      else
      {
        v5 = 0;
      }
      if ( a3 )
        sub_412520(v5, 1, 0);
      else
        sub_412520(v5, 1, 1);
      this[3] = v46;
      return 0;
    case 3:
      if ( a3 )
        v3 = this[2] == this[8];
      this[2] = this[8];
      sub_56AE80(0, 1);
      v6 = (_DWORD *)this[8];
      v7 = v3;
      v8 = 3;
      if ( !byte_B71B34 && dword_91E07C[15572] && dword_BE1204 != 2 )
      {
        v8 = 2;
        v7 = 0;
      }
      break;
    case 4:
      v25 = this[2];
      if ( v25 == this[11] )
      {
        v26 = this[8];
        if ( v26 )
        {
          if ( *(_DWORD *)(v26 + 8) )
          {
            sub_5E5190(0);
            v27 = *(_DWORD *)(v26 + 12);
            if ( v27 )
              sub_5E6F50(0, 0, *(_DWORD *)(v27 + 4), *(_DWORD *)(v27 + 8), -13421773);
          }
        }
        this[2] = this[11];
        sub_56AE80(0, 1);
        v28 = (_DWORD *)this[11];
        if ( (int)v28[14] > 0 )
        {
          v28[13] = 4;
          if ( dword_91E07C )
            sub_56AE80(0, 1);
        }
        if ( v28[2] )
        {
          sub_5E5190(0);
          v29 = v28[3];
          if ( v29 )
            sub_5E6F50(0, 0, *(_DWORD *)(v29 + 4), *(_DWORD *)(v29 + 8), -13421773);
        }
      }
      else
      {
        if ( a3 )
          v3 = v25 == this[8];
        this[2] = this[8];
        sub_56AE80(0, 1);
        v28 = (_DWORD *)this[8];
        if ( v28[13] == 4 && v3 )
        {
          v30 = v28[14];
          v31 = v28[15] + 1;
          v28[15] = v31;
          if ( v31 >= v30 )
            v28[15] = 0;
        }
        else if ( (int)v28[14] > 0 )
        {
          v28[13] = 4;
          if ( dword_91E07C )
            sub_56AE80(0, 1);
        }
        if ( v28[2] )
        {
          sub_5E5190(0);
          v32 = v28[3];
          if ( v32 )
            sub_5E6F50(0, 0, *(_DWORD *)(v32 + 4), *(_DWORD *)(v32 + 8), -13421773);
        }
      }
      goto LABEL_141;
    case 5:
      if ( *(int *)(this[10] + 16) > 0 || *(int *)(this[9] + 16) > 0 )
      {
        if ( !sub_40DDB0 || (v33 = this[9]) == 0 || this[2] != v33 )
        {
          v34 = this[8];
          if ( *(_DWORD *)(v34 + 8) )
          {
            sub_5E5190(0);
            v35 = *(_DWORD *)(v34 + 12);
            if ( v35 )
              sub_5E6F50(0, 0, *(_DWORD *)(v35 + 4), *(_DWORD *)(v35 + 8), -13421773);
          }
          this[2] = this[10];
        }
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[2] + 16))(this[2]);
      }
      sub_56AE80(0, 1);
      this[3] = a2;
      return 0;
    case 7:
      this[2] = this[8];
      sub_56AE80(0, 1);
      v28 = (_DWORD *)this[8];
      v28[13] = 5;
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( v28[2] )
      {
        sub_5E5190(0);
        v36 = v28[3];
        if ( v36 )
          sub_5E6F50(0, 0, *(_DWORD *)(v36 + 4), *(_DWORD *)(v36 + 8), -13421773);
      }
      goto LABEL_141;
    case 8:
      this[2] = this[8];
      sub_56AE80(0, 1);
      v28 = (_DWORD *)this[8];
      v28[13] = 6;
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( v28[2] )
      {
        sub_5E5190(0);
        v37 = v28[3];
        if ( v37 )
          sub_5E6F50(0, 0, *(_DWORD *)(v37 + 4), *(_DWORD *)(v37 + 8), -13421773);
      }
      goto LABEL_141;
    case 9:
      this[2] = this[8];
      sub_56AE80(0, 1);
      v28 = (_DWORD *)this[8];
      v38 = v28[11];
      v28[13] = 7;
      if ( v38 )
      {
        v39 = (_DWORD *)(v38 + 192);
        *v39 = dword_91BF0C;
        v39[1] = dword_91BF10;
        v39[2] = dword_91BF14;
        dword_757714 = 0;
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v28[11] + 28))(v28[11]);
      }
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( v28[2] )
      {
        sub_5E5190(0);
        v40 = v28[3];
        if ( v40 )
          sub_5E6F50(0, 0, *(_DWORD *)(v40 + 4), *(_DWORD *)(v40 + 8), -13421773);
      }
      goto LABEL_141;
    case 10:
      this[2] = this[8];
      sub_56AE80(0, 1);
      v28 = (_DWORD *)this[8];
      v41 = v28[12];
      v28[13] = 8;
      if ( v41 )
      {
        v42 = (_DWORD *)(v41 + 192);
        *v42 = dword_91BF00;
        v42[1] = dword_91BF04;
        v42[2] = dword_91BF08;
        dword_757714 = 0;
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v28[12] + 28))(v28[12]);
      }
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( v28[2] )
      {
        sub_5E5190(0);
        v43 = v28[3];
        if ( v43 )
          sub_5E6F50(0, 0, *(_DWORD *)(v43 + 4), *(_DWORD *)(v43 + 8), -13421773);
      }
LABEL_141:
      sub_40E2C0(v28, v28[13]);
      this[3] = a2;
      return 0;
    default:
      return result;
  }
  switch ( v8 )
  {
    case 0:
    case 1:
    case 2:
      v9 = 0;
      if ( v7 )
      {
        LOBYTE(v9) = v7 > 0;
        v9 = 2 * v9 - 1;
      }
      if ( v6[13] <= 2u )
      {
        v10 = v9 + v6[20];
        v6[20] = v10;
        if ( v10 <= 2 )
        {
          if ( v10 < 0 )
            v6[20] = 2;
        }
        else
        {
          v6[20] = 0;
        }
      }
      if ( *(_DWORD *)dword_B72314 == 8
        || *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) == *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468) )
      {
        goto LABEL_33;
      }
      v11 = v6[20];
      if ( v11 == 1 )
      {
        if ( v9 > 0 && dword_B71890 )
        {
          v6[20] = 2;
          goto LABEL_33;
        }
        goto LABEL_32;
      }
      if ( v11 == 2 && !dword_B71890 )
LABEL_32:
        v6[20] = 0;
LABEL_33:
      v12 = v6[20];
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          v13 = 1;
          v6[13] = 1;
        }
        else
        {
          v6[13] = 2;
          v13 = dword_B71890 != 0 ? 0 : 2;
        }
      }
      else
      {
        v6[13] = 0;
        v13 = 3;
      }
      if ( dword_91E07C )
        sub_56AE80(v13, 1);
      if ( byte_B722CC || byte_B722FC || (v14 = v6[13]) != 0 && v14 != 2 )
      {
        sub_4124A0();
      }
      else if ( v6[2] )
      {
        goto LABEL_57;
      }
      goto LABEL_71;
    case 3:
      v6[13] = 3;
      goto LABEL_54;
    case 4:
      if ( v6[13] == 4 && v7 )
      {
        v15 = v6[14];
        v16 = v6[15] + 1;
        v6[15] = v16;
        if ( v16 >= v15 )
          v6[15] = 0;
      }
      else if ( (int)v6[14] > 0 )
      {
        v6[13] = 4;
LABEL_54:
        if ( dword_91E07C )
          sub_56AE80(0, 1);
      }
      if ( !v6[2] )
        goto LABEL_71;
LABEL_57:
      sub_5E5190(0);
      v17 = v6[3];
      if ( v17 )
        goto LABEL_70;
      goto LABEL_71;
    case 5:
    case 6:
    case 7:
    case 8:
      v6[13] = v8;
      v18 = v8 - 7;
      if ( !v18 )
      {
        v22 = v6[11];
        if ( !v22 )
          goto LABEL_66;
        v23 = (_DWORD *)(v22 + 192);
        *v23 = dword_91BF0C;
        v23[1] = dword_91BF10;
        v23[2] = dword_91BF14;
        dword_757714 = 0;
        v21 = v6[11];
        goto LABEL_65;
      }
      if ( v18 == 1 )
      {
        v19 = v6[12];
        if ( v19 )
        {
          v20 = (_DWORD *)(v19 + 192);
          *v20 = dword_91BF00;
          v20[1] = dword_91BF04;
          v20[2] = dword_91BF08;
          dword_757714 = 0;
          v21 = v6[12];
LABEL_65:
          (*(void (__thiscall **)(int))(*(_DWORD *)v21 + 28))(v21);
        }
      }
LABEL_66:
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( v6[2] )
      {
        sub_5E5190(0);
        v17 = v6[3];
        if ( v17 )
LABEL_70:
          sub_5E6F50(0, 0, *(_DWORD *)(v17 + 4), *(_DWORD *)(v17 + 8), -13421773);
      }
LABEL_71:
      sub_40E2C0(v6, v6[13]);
      if ( !dword_91E07C[15572] || byte_B71B34 )
      {
        v24 = HIBYTE(v46);
      }
      else
      {
        sub_56AE80(0, 1);
        sub_412520(2, 0, 0);
        this[7] = 3;
        this[3] = 2;
        v24 = 1;
      }
      result = 0;
      if ( !v24 )
        this[3] = v45;
      return result;
  }
}
