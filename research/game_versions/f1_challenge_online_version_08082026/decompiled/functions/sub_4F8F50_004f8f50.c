void __thiscall sub_4F8F50(float *this, int a2)
{
  float v3; // edx
  int v4; // eax
  double v5; // st7
  int v6; // ecx
  double v7; // st7
  int v8; // ecx
  double v9; // st7
  int v10; // eax
  int v11; // eax
  int v12; // eax

  v3 = *this;
  if ( *(_DWORD *)this )
  {
    v4 = *((_DWORD *)this + 3) + 1;
    *((_DWORD *)this + 3) = v4;
    switch ( *((_DWORD *)this + 1) )
    {
      case 0:
        if ( sub_5565B0(*((_DWORD *)this + 6)) >= 1.0 )
        {
          v5 = (double)*((int *)this + 3);
          if ( v5 < this[4] )
            this[4] = v5;
          if ( v5 <= this[5] )
          {
            sub_556440(*((_DWORD *)this + 6));
          }
          else
          {
            v6 = *((_DWORD *)this + 6);
            this[5] = v5;
            sub_556440(v6);
          }
          this[3] = 0.0;
        }
        return;
      case 1:
        if ( v4 % 2 )
          goto LABEL_31;
        v7 = 2.0 / sub_556510(*((_DWORD *)this + 6));
        if ( *(_DWORD *)this != 2 )
          goto LABEL_27;
        sub_58815F(this + 11, "Ins: %3.2f", v7);
        goto LABEL_30;
      case 2:
        if ( sub_5565B0(*((_DWORD *)this + 6)) >= 1.0 )
        {
          v8 = *((_DWORD *)this + 3);
          v9 = (double)v8;
          if ( v9 < this[4] )
            this[4] = v9;
          if ( v9 > this[5] )
            this[5] = v9;
          if ( *(_DWORD *)this == 2 )
          {
            sub_58815F(this + 11, "%d", v8);
          }
          else
          {
            v10 = v8;
            if ( v8 >= 999 )
              v10 = 999;
            *((_DWORD *)this + 2) = v10;
          }
          sub_556440(*((_DWORD *)this + 6));
          this[3] = 0.0;
        }
        *((_DWORD *)this + 7) = 992;
        goto LABEL_31;
      case 3:
        v7 = (double)dword_8AFE84 / dbl_8AFEA8;
        if ( LODWORD(v3) == 2 )
        {
          v11 = sub_587BDC(v7);
          sub_58815F(this + 11, "Ovr: %d", v11);
        }
        else
        {
LABEL_27:
          v12 = sub_587BDC(v7);
          if ( v12 >= 999 )
            v12 = 999;
          *((_DWORD *)this + 2) = v12;
        }
LABEL_30:
        *((_DWORD *)this + 7) = 900;
        goto LABEL_31;
      default:
LABEL_31:
        sub_4F9F00(&unk_8AFE18);
        sub_53D2E0(aFtframerate, this + 11, *((_DWORD *)this + 7), *((_DWORD *)this + 8), dword_8B8DC8);
        sub_4F9F30(&unk_8AFE18);
        break;
    }
  }
}
