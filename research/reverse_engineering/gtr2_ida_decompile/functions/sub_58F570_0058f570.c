void __thiscall sub_58F570(int *this, int a2)
{
  float v3; // edx
  int v4; // eax
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  double v8; // st7
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int64 v12; // rax
  int v13; // eax

  v3 = *(float *)this;
  if ( *this )
  {
    v4 = this[3] + 1;
    this[3] = v4;
    switch ( this[1] )
    {
      case 0:
        if ( sub_5F5900(this[6]) >= 1.0 )
        {
          v5 = (double)this[3];
          if ( v5 < *((float *)this + 4) )
            *((float *)this + 4) = v5;
          if ( v5 > *((float *)this + 5) )
            *((float *)this + 5) = v5;
          sub_5F5C70(1);
          this[3] = 0;
        }
        return;
      case 1:
        if ( v4 % 2 )
          goto LABEL_35;
        v6 = 2.0 / sub_5F5870(this[6]);
        if ( *this != 2 )
          goto LABEL_31;
        sprintf((char *const)this + 44, "Ins: %3.2f", v6);
        goto LABEL_34;
      case 2:
        if ( sub_5F5900(this[6]) >= 1.0 )
        {
          v7 = this[3];
          v8 = (double)v7;
          if ( v8 < *((float *)this + 4) )
            *((float *)this + 4) = v8;
          if ( v8 > *((float *)this + 5) )
            *((float *)this + 5) = v8;
          if ( *this == 2 )
          {
            if ( (byte_B72254 & 4) != 0 )
            {
              v9 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 164))(dword_FB27A4);
              v10 = (*(int (__stdcall **)(int))(*(_DWORD *)v9 + 16))(v9);
              if ( v10 <= 0 )
                v10 = 0;
              sprintf((char *const)this + 44, "%d fps, %d mb", this[3], v10 / 0x100000);
            }
            else
            {
              sprintf((char *const)this + 44, "%d", v7);
            }
          }
          else
          {
            v11 = v7;
            if ( v7 >= 999 )
              v11 = 999;
            this[2] = v11;
          }
          sub_5F5C70(1);
          this[3] = 0;
        }
        this[7] = 992;
        goto LABEL_35;
      case 3:
        v6 = (double)dword_FB1D00 / dbl_FB1D20;
        if ( LODWORD(v3) == 2 )
        {
          sprintf((char *const)this + 44, "Ovr: %d", (unsigned int)(unsigned __int64)v6);
        }
        else
        {
LABEL_31:
          v12 = (unsigned __int64)v6;
          if ( (int)(unsigned __int64)v6 >= 999 )
            LODWORD(v12) = 999;
          this[2] = v12;
        }
LABEL_34:
        this[7] = 900;
        goto LABEL_35;
      default:
LABEL_35:
        if ( !byte_FB1CED )
        {
          byte_FB1CED = 1;
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 460))(dword_FB27A4, 0);
        }
        v13 = this[7];
        if ( (byte_B72254 & 4) != 0 )
          v13 -= 100;
        sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)(this + 11), v13, this[8], (int)dword_FB2790);
        if ( byte_FB1CED )
        {
          byte_FB1CED = 0;
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 464))(dword_FB27A4, 0);
        }
        break;
    }
  }
}
