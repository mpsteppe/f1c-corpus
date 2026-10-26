void __thiscall sub_4D7FF0(float *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // st7
  float v5; // [esp+0h] [ebp-10h]
  float v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  float v9; // [esp+Ch] [ebp-4h]

  v1 = dbl_8AFE98 + this[3];
  this[3] = v1;
  v2 = v1 - (double)CRTFtol(v1) * 60.0;
  if ( v2 >= 0.2 )
  {
    v3 = v2 - 0.2;
    v9 = v3;
    if ( v3 < 0.5 )
    {
      v5 = 1.0 - (0.5 - v9 + 0.5 - v9);
      TimerClockFormat(v5, 1);
      return;
    }
    if ( v9 < 1.5 )
    {
      TimerClockFormat(1.0, 1);
      return;
    }
    if ( v9 < 2.0 )
    {
      v4 = 2.0;
      v8 = 1;
LABEL_14:
      v7 = v4 - v9 + v4 - v9;
      TimerClockFormat(v7, v8);
      return;
    }
    if ( v9 < 2.5 )
    {
      v6 = 1.0 - (2.5 - v9 + 2.5 - v9);
      TimerClockFormat(v6, 0);
      return;
    }
    if ( v9 < 3.5 )
    {
      TimerClockFormat(1.0, 0);
      return;
    }
    if ( v9 < 4.0 )
    {
      v4 = 4.0;
      v8 = 0;
      goto LABEL_14;
    }
  }
}
