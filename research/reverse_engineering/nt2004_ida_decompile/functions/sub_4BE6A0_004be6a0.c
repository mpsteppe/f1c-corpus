double __thiscall sub_4BE6A0(float *this, int a2)
{
  bool v3; // bl
  char v4; // al
  float v6; // eax
  double v7; // st7
  long double v8; // st7
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+1Ch] [ebp+4h]

  v3 = dword_7D7928 == 1;
  v4 = sub_404F90(&flt_628F60);
  v10 = 10.0;
  if ( !v3 )
    v10 = 13.5;
  switch ( a2 )
  {
    case 0:
      v13 = 0.0;
      goto LABEL_20;
    case 1:
      v13 = 3.0;
      goto LABEL_20;
    case 2:
      if ( v3 )
        v13 = 6.0;
      else
        v13 = 7.0;
      goto LABEL_20;
    case 3:
      if ( !v3 )
        goto LABEL_12;
      v13 = 8.0;
      goto LABEL_20;
    case 4:
      if ( v3 )
LABEL_12:
        v13 = 10.5;
      else
        v13 = 14.0;
      goto LABEL_20;
    case 5:
    case 6:
      if ( !v4 )
        goto LABEL_15;
      goto LABEL_25;
    case 7:
      if ( v4 )
      {
        v6 = v10;
        goto LABEL_18;
      }
      v13 = v10 + 0.5;
      break;
    case 8:
    case 9:
      if ( v4 )
LABEL_15:
        v13 = 9.5;
      else
LABEL_25:
        v13 = 9.0;
      goto LABEL_20;
    case 10:
      if ( v4 )
      {
        v6 = v10 + 0.5;
LABEL_18:
        v13 = v6;
      }
      else
      {
        v13 = v10;
      }
      break;
    case 11:
    case 12:
    case 13:
      v13 = 14.1;
      goto LABEL_20;
    default:
      return 1.0;
  }
  if ( v13 < 0.0 )
    return 1.0;
LABEL_20:
  if ( this[16] <= 0.0 )
  {
    v7 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
    v12 = v7;
    v8 = pow(v12, 5.0) * 0.5 + 0.34999999;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    v11 = v13 * 0.2;
    this[16] = v8 * v11;
  }
  return this[a2 + 2] / (v13 + this[16]);
}
