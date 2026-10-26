void __thiscall sub_5401C0(float *this, float a2)
{
  double v3; // st7
  double v4; // st7
  double v5; // st6
  int v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  float v11; // [esp-8h] [ebp-10h]
  float v12; // [esp+4h] [ebp-4h] BYREF

  v12 = 0.25;
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 3:
    case 4:
      v12 = 0.34;
      if ( dword_B64134 == 5 )
      {
        v4 = (dbl_FB1D18 - flt_FADE1C) / (flt_FADE20 - flt_FADE1C);
        v5 = v4 * v4 * 0.60000002;
LABEL_15:
        v12 = v5 + 0.5;
        sub_401760(&v12, 0.5, 1.0);
      }
      else if ( dword_B64134 == 8 )
      {
        v3 = (dbl_FB1D18 - flt_FADE20) * 0.0080000004;
LABEL_17:
        v11 = 0.25;
LABEL_18:
        v12 = 1.0 - v3;
        sub_401760(&v12, v11, 1.0);
      }
      break;
    case 5:
      v12 = 0.31999999;
      break;
    case 6:
      v12 = 0.38;
      switch ( dword_B64134 )
      {
        case 1:
        case 2:
          v12 = 0.44;
          break;
        case 3:
          v12 = 0.5;
          break;
        case 4:
          v11 = 0.5;
          v3 = (flt_FADE5C + 5.0 - dbl_FB1D18) * 0.029999999;
          goto LABEL_18;
        case 5:
          v6 = sub_5511F0(&unk_FADD40, 0);
          if ( dword_FADE18 <= 1 )
            v7 = 1.0;
          else
            v7 = (double)dword_924FF4[5654 * v6] / (double)(dword_FADE18 - 1);
          v5 = (0.5 - v7) * (0.5 - v7) + (0.5 - v7) * (0.5 - v7);
          goto LABEL_15;
        case 8:
          v3 = (dbl_FB1D18 - flt_FADE20) * 0.003;
          goto LABEL_17;
        default:
          goto LABEL_19;
      }
      break;
    default:
      break;
  }
LABEL_19:
  v8 = a2 * 0.125;
  if ( v8 >= 0.050000001 )
    v8 = 0.050000001;
  if ( this[2] >= (double)v12 )
  {
    v10 = this[2] - v8;
    this[2] = v10;
    if ( v10 < v12 )
      this[2] = v12;
  }
  else
  {
    v9 = v8 + this[2];
    this[2] = v9;
    if ( v9 > v12 )
      this[2] = v12;
  }
}
