void sub_4BA7F0()
{
  double v0; // st7
  double v1; // st7
  float v2; // [esp+0h] [ebp-8h]
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+4h] [ebp-4h]

  if ( dword_766180 == 2 && dword_75CBB0 == 7 && !(unsigned __int8)sub_4D9AE0(&unk_7D5DAC) )
  {
    if ( flt_766170 >= 1.0 )
    {
LABEL_13:
      sub_506960(0);
      goto LABEL_14;
    }
    v0 = dbl_7DA9C0 * 6.0 + flt_766170;
LABEL_8:
    flt_766170 = v0;
    if ( v0 >= 0.0 )
    {
      if ( flt_766170 > 1.0 )
        flt_766170 = 1.0;
    }
    else
    {
      flt_766170 = 0.0;
    }
    v4 = 0.2 * flt_766170;
    v2 = 0.60000002 * flt_766170;
    sub_5069A0(v2, v4);
    sub_506AE0(0.5, 0.5, 1.0, 8);
    goto LABEL_13;
  }
  if ( flt_766170 > 0.0 )
  {
    v0 = flt_766170 - dbl_7DA9C0 * 6.0;
    goto LABEL_8;
  }
LABEL_14:
  if ( !byte_766185 || dword_75CBB0 != 7 || *(_DWORD *)dword_7689CC == 5 || (unsigned __int8)sub_4D9AE0(&unk_7D5DAC) )
  {
    if ( flt_766174 <= 0.0 )
      return;
    v1 = flt_766174 - dbl_7DA9C0 * 6.0;
    goto LABEL_22;
  }
  if ( flt_766174 < 1.0 )
  {
    v1 = dbl_7DA9C0 * 6.0 + flt_766174;
LABEL_22:
    flt_766174 = v1;
    if ( v1 >= 0.0 )
    {
      if ( flt_766174 > 1.0 )
        flt_766174 = 1.0;
    }
    else
    {
      flt_766174 = 0.0;
    }
    v5 = 0.2 * flt_766174;
    v3 = 0.60000002 * flt_766174;
    sub_5069A0(v3, v5);
    sub_506AE0(0.5, 0.5, 1.0, 8);
  }
  sub_506960(0);
}
