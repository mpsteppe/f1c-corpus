void __thiscall sub_526870(char *this, int a2)
{
  int v3; // edx
  int v4; // eax
  double v5; // st7
  double v6; // st7
  __int64 v7; // rax
  int v8; // ecx
  double v9; // st7
  int v10; // eax
  double v11; // st7

  if ( byte_76617C != 1 )
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      v4 = *((_DWORD *)this + 3) + 1;
      *((_DWORD *)this + 3) = v4;
      switch ( *((_DWORD *)this + 1) )
      {
        case 0:
          if ( sub_5AC8D0(*((_DWORD *)this + 6)) >= 1.0 )
          {
            v5 = (double)*((int *)this + 3);
            if ( v5 < *((float *)this + 4) )
              *((float *)this + 4) = v5;
            if ( v5 > *((float *)this + 5) )
              *((float *)this + 5) = v5;
            sub_5AC740(1);
            *((_DWORD *)this + 3) = 0;
          }
          return;
        case 1:
          if ( v4 % 2 )
            goto LABEL_34;
          v6 = 2.0 / sub_5AC830(*((_DWORD *)this + 6));
          if ( *(_DWORD *)this == 2 )
          {
            sprintf(this + 44, "Ins: %3.2f", v6);
            goto LABEL_33;
          }
          v7 = (__int64)v6;
          if ( (int)(__int64)v6 >= 999 )
            LODWORD(v7) = 999;
          goto LABEL_32;
        case 2:
          if ( sub_5AC8D0(*((_DWORD *)this + 6)) >= 1.0 )
          {
            v8 = *((_DWORD *)this + 3);
            v9 = (double)v8;
            if ( v9 < *((float *)this + 4) )
              *((float *)this + 4) = v9;
            if ( v9 > *((float *)this + 5) )
              *((float *)this + 5) = v9;
            if ( *(_DWORD *)this == 2 )
            {
              sprintf(this + 44, "%d", v8);
            }
            else
            {
              v10 = v8;
              if ( v8 >= 999 )
                v10 = 999;
              *((_DWORD *)this + 2) = v10;
            }
            sub_5AC740(1);
            *((_DWORD *)this + 3) = 0;
          }
          *((_DWORD *)this + 7) = 992;
          goto LABEL_34;
        case 3:
          v11 = (double)dword_7DA9AC / dbl_7DA9D8;
          if ( v3 == 2 )
          {
            sprintf(this + 44, "Ovr: %d", (unsigned int)(__int64)v11);
          }
          else
          {
            if ( v11 >= 999.0 )
              v11 = 999.0;
            v7 = (__int64)v11;
LABEL_32:
            *((_DWORD *)this + 2) = v7;
          }
LABEL_33:
          *((_DWORD *)this + 7) = 900;
          goto LABEL_34;
        default:
LABEL_34:
          sub_5278E0(&unk_7DA938);
          sub_592E10(aFtframerate, this + 44, *((_DWORD *)this + 7), *((_DWORD *)this + 8), dword_7E8CDC, 0);
          sub_527910(&unk_7DA938);
          break;
      }
    }
  }
}
