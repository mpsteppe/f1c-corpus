char __thiscall sub_412870(_DWORD *this, int a2, int a3)
{
  char result; // al
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  BOOL v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  int v21; // ecx
  int v22; // ecx
  int v23; // edx
  _DWORD *v24; // edx
  int v25; // ecx
  int v26; // edx
  _DWORD *v27; // edx
  int v28; // ecx
  int v29; // ebx
  int v30; // edi
  int i; // edx
  int v32; // eax
  int v33; // ecx

  result = 0;
  if ( !a2 )
    return result;
  if ( a2 != this[4] )
  {
    if ( a2 == this[5] )
    {
      sub_412520(1, 1, 1);
      goto LABEL_105;
    }
    if ( a2 == this[6] )
    {
      sub_412520(2, 1, 1);
      goto LABEL_105;
    }
    if ( a2 == this[7] )
    {
      v7 = 1;
      v8 = 3;
      if ( !byte_B71B34 && dword_91E07C[15572] && dword_BE1204 != 2 )
      {
        v8 = 2;
        v7 = 0;
      }
      switch ( v8 )
      {
        case 0:
        case 1:
        case 2:
          this[13] = 2;
          v9 = dword_B71890 != 0;
          this[20] = 2;
          v10 = v9 ? 0 : 2;
          if ( dword_91E07C )
            sub_56AE80(v10, 1);
          if ( !byte_B722CC && !byte_B722FC )
          {
            v11 = this[13];
            if ( !v11 || v11 == 2 )
            {
              if ( !this[2] )
                break;
              goto LABEL_44;
            }
          }
          sub_4124A0();
          sub_40E2C0(this, this[13]);
          goto LABEL_105;
        case 3:
          this[13] = 3;
          goto LABEL_41;
        case 4:
          if ( this[13] == 4 && v7 )
          {
            v12 = this[14];
            v13 = this[15] + 1;
            this[15] = v13;
            if ( v13 >= v12 )
              this[15] = 0;
          }
          else if ( (int)this[14] > 0 )
          {
            this[13] = 4;
LABEL_41:
            if ( dword_91E07C )
              sub_56AE80(0, 1);
          }
          if ( !this[2] )
            break;
LABEL_44:
          sub_5E5190(0);
          v14 = this[3];
          if ( v14 )
            goto LABEL_57;
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          this[13] = v8;
          v15 = v8 - 7;
          if ( !v15 )
          {
            v19 = this[11];
            if ( !v19 )
              goto LABEL_53;
            v20 = (_DWORD *)(v19 + 192);
            *v20 = dword_91BF0C;
            v20[1] = dword_91BF10;
            v20[2] = dword_91BF14;
            dword_757714 = 0;
            v18 = this[11];
            goto LABEL_52;
          }
          if ( v15 == 1 )
          {
            v16 = this[12];
            if ( v16 )
            {
              v17 = (_DWORD *)(v16 + 192);
              *v17 = dword_91BF00;
              v17[1] = dword_91BF04;
              v17[2] = dword_91BF08;
              dword_757714 = 0;
              v18 = this[12];
LABEL_52:
              (*(void (__thiscall **)(int))(*(_DWORD *)v18 + 28))(v18);
            }
          }
LABEL_53:
          if ( dword_91E07C )
            sub_56AE80(0, 1);
          if ( this[2] )
          {
            sub_5E5190(0);
            v14 = this[3];
            if ( v14 )
LABEL_57:
              sub_5E6F50(0, 0, *(_DWORD *)(v14 + 4), *(_DWORD *)(v14 + 8), -13421773);
          }
          break;
      }
    }
    else if ( a2 == this[9] )
    {
      this[13] = 5;
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( this[2] )
      {
        sub_5E5190(0);
        v21 = this[3];
        if ( v21 )
          sub_5E6F50(0, 0, *(_DWORD *)(v21 + 4), *(_DWORD *)(v21 + 8), -13421773);
      }
    }
    else if ( a2 == this[10] )
    {
      this[13] = 6;
      if ( dword_91E07C )
        sub_56AE80(0, 1);
      if ( this[2] )
      {
        sub_5E5190(0);
        v22 = this[3];
        if ( v22 )
          sub_5E6F50(0, 0, *(_DWORD *)(v22 + 4), *(_DWORD *)(v22 + 8), -13421773);
      }
    }
    else
    {
      v23 = this[11];
      if ( a2 == v23 )
      {
        this[13] = 7;
        if ( v23 )
        {
          v24 = (_DWORD *)(v23 + 192);
          *v24 = dword_91BF0C;
          v24[1] = dword_91BF10;
          v24[2] = dword_91BF14;
          dword_757714 = 0;
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[11] + 28))(this[11]);
        }
        if ( dword_91E07C )
          sub_56AE80(0, 1);
        if ( this[2] )
        {
          sub_5E5190(0);
          v25 = this[3];
          if ( v25 )
            sub_5E6F50(0, 0, *(_DWORD *)(v25 + 4), *(_DWORD *)(v25 + 8), -13421773);
        }
      }
      else
      {
        v26 = this[12];
        if ( a2 != v26 )
        {
          v29 = this[14];
          v30 = 0;
          if ( v29 <= 0 )
            return result;
          for ( i = this[8]; i != a2; i += 204 )
          {
            if ( ++v30 >= this[14] )
              return result;
          }
          if ( this[13] == 4 )
          {
            v32 = this[15] + 1;
            this[15] = v32;
            if ( v32 >= v29 )
              this[15] = 0;
          }
          else
          {
            this[13] = 4;
            if ( dword_91E07C )
              sub_56AE80(0, 1);
          }
          if ( this[2] )
          {
            sub_5E5190(0);
            v33 = this[3];
            if ( v33 )
              sub_5E6F50(0, 0, *(_DWORD *)(v33 + 4), *(_DWORD *)(v33 + 8), -13421773);
          }
          sub_40E2C0(this, this[13]);
          this[15] = v30;
          goto LABEL_105;
        }
        this[13] = 8;
        if ( v26 )
        {
          v27 = (_DWORD *)(v26 + 192);
          *v27 = dword_91BF00;
          v27[1] = dword_91BF04;
          v27[2] = dword_91BF08;
          dword_757714 = 0;
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[12] + 28))(this[12]);
        }
        if ( dword_91E07C )
          sub_56AE80(0, 1);
        if ( this[2] )
        {
          sub_5E5190(0);
          v28 = this[3];
          if ( v28 )
            sub_5E6F50(0, 0, *(_DWORD *)(v28 + 4), *(_DWORD *)(v28 + 8), -13421773);
        }
      }
    }
    sub_40E2C0(this, this[13]);
    goto LABEL_105;
  }
  this[13] = 0;
  this[20] = 0;
  if ( dword_91E07C )
    sub_56AE80(3, 1);
  if ( byte_B722CC || byte_B722FC || (v5 = this[13]) != 0 && v5 != 2 )
  {
    sub_4124A0();
LABEL_13:
    sub_40E2C0(this, this[13]);
    goto LABEL_105;
  }
  if ( !this[2] )
    goto LABEL_13;
  sub_5E5190(0);
  v6 = this[3];
  if ( !v6 )
    goto LABEL_13;
  sub_5E6F50(0, 0, *(_DWORD *)(v6 + 4), *(_DWORD *)(v6 + 8), -13421773);
  sub_40E2C0(this, this[13]);
LABEL_105:
  if ( (_BYTE)a2 )
    (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
  return 1;
}
