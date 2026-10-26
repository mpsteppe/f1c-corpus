// f1c  0x0042a180  size=577
void __thiscall sub_42A180(float *this)
{
  float v2; // edx
  int v3; // ecx
  double v4; // st7
  double v5; // st7
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]

  v2 = *this;
  if ( *(_DWORD *)(*(_DWORD *)this + 13000) == 1 )
  {
    if ( dword_7C56A4 != 7 )
    {
      v3 = *((_DWORD *)this + 4111);
      v10 = 10;
      if ( v3 <= 10 )
        v10 = v3;
      v4 = this[4413] + this[4406];
      if ( v4 >= (double)v10 * 0.003 + this[4431] )
      {
        v11 = 10;
        if ( v3 <= 10 )
          v11 = v3;
        v4 = (double)v11 * 0.003 + this[4431];
      }
      this[4431] = v4;
    }
    v5 = 1.0 - flt_8AFEE8 * this[4402];
    if ( v5 < 0.5 )
      v5 = 0.5;
    v6 = *((_DWORD *)this + 4435);
    this[4448] = v5;
    if ( v6 != 1 )
    {
      if ( SLODWORD(this[4 * *((_DWORD *)this + 4472) + 4452]) <= *(_DWORD *)(LODWORD(v2) + 16444) )
        sub_42A110(this);
      v7 = sub_4F1630(this + 3);
      v8 = sub_4A4830(v7);
      if ( flt_8AFEE8 < 0.0099999998 )
      {
        v9 = *((_DWORD *)this + 4451);
        goto LABEL_17;
      }
      if ( flt_8AFEE8 < 0.33000001 )
      {
        v9 = 4;
        if ( v8 == 5 && flt_8AFEE8 > 0.2 )
          goto LABEL_20;
        if ( v8 == *((_DWORD *)this + 4451) && flt_8AFEE8 < 0.2 )
          v9 = *((_DWORD *)this + 4451);
LABEL_17:
        if ( v8 == v9 || !v9 )
          goto LABEL_20;
        goto LABEL_19;
      }
      if ( flt_8AFEE8 >= 0.66000003 )
      {
        v9 = 6;
        if ( v8 != 5 )
          goto LABEL_17;
        if ( flt_8AFEE8 >= 0.89999998 )
          goto LABEL_19;
      }
      else
      {
        v9 = 5;
        if ( v8 == 4 )
        {
          if ( flt_8AFEE8 < 0.55000001 )
            goto LABEL_20;
LABEL_19:
          sub_42A110(this);
          goto LABEL_20;
        }
        if ( v8 != 6 )
          goto LABEL_17;
        if ( flt_8AFEE8 <= 0.60000002 )
          goto LABEL_19;
      }
LABEL_20:
      if ( (this[3657] + this[3595] + this[3533] + this[3471]) * 0.25 < 0.89999998 )
        sub_42A110(this);
    }
  }
}
