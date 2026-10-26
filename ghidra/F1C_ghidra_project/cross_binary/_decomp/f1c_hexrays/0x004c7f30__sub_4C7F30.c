// f1c  0x004c7f30  size=531
void __thiscall sub_4C7F30(float *this, float a2)
{
  double v2; // st7
  double v4; // st7
  double v5; // st6
  double v6; // st7
  int v7; // eax
  double v8; // st6
  double v9; // st6
  double v10; // st6
  double v11; // st6

  v2 = 0.25;
  switch ( dword_7C56A4 )
  {
    case 3:
      v2 = 0.28;
      goto LABEL_24;
    case 4:
      v2 = 0.31;
      goto LABEL_24;
    case 5:
      v2 = 0.34;
      if ( dword_7C56A8 == 5 )
      {
        v5 = (dbl_8AFEA0 - flt_8ACF90) / (flt_8ACF94 - flt_8ACF90);
        v6 = v5 * v5 * 0.60000002;
LABEL_8:
        v2 = v6 + 0.5;
LABEL_9:
        if ( v2 < 0.5 )
        {
LABEL_10:
          v2 = 0.5;
          goto LABEL_24;
        }
      }
      else
      {
        if ( dword_7C56A8 != 8 )
          goto LABEL_24;
        v4 = (dbl_8AFEA0 - flt_8ACF94) * 0.0080000004;
LABEL_20:
        v2 = 1.0 - v4;
        if ( v2 < 0.25 )
        {
          v2 = 0.25;
          goto LABEL_24;
        }
      }
      if ( v2 > 1.0 )
        v2 = 1.0;
LABEL_24:
      v9 = a2 * 0.125;
      if ( v9 >= 0.050000001 )
        v9 = 0.050000001;
      if ( this[2] >= v2 )
      {
        v11 = this[2] - v9;
        this[2] = v11;
        if ( v11 < v2 )
          this[2] = v2;
      }
      else
      {
        v10 = v9 + this[2];
        this[2] = v10;
        if ( v10 > v2 )
          this[2] = v2;
      }
      return;
    case 6:
      v2 = 0.31999999;
      goto LABEL_24;
    case 7:
      v2 = 0.38;
      switch ( dword_7C56A8 )
      {
        case 1:
        case 2:
          v2 = 0.44;
          break;
        case 3:
          goto LABEL_10;
        case 4:
          v2 = 1.0 - (flt_8ACFB8 + 5.0 - dbl_8AFEA0) * 0.029999999;
          goto LABEL_9;
        case 5:
          v7 = sub_4D1B50(0);
          if ( dword_8ACF8C <= 1 )
            v8 = 0.5 - 1.0;
          else
            v8 = 0.5 - (double)dword_5F0714[4656 * v7] / (double)(dword_8ACF8C - 1);
          v6 = v8 * v8 + v8 * v8;
          goto LABEL_8;
        case 8:
          v4 = (dbl_8AFEA0 - flt_8ACF94) * 0.003;
          goto LABEL_20;
        default:
          goto LABEL_24;
      }
      goto LABEL_24;
    default:
      goto LABEL_24;
  }
}
