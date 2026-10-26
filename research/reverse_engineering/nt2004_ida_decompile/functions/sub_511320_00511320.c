int __thiscall sub_511320(float *this, int a2, float *a3, float *a4)
{
  float *v4; // esi
  int v5; // eax
  int i; // edi
  int v7; // eax
  int v8; // eax
  char *v10; // [esp-4h] [ebp-6Ch]
  double v12; // [esp+10h] [ebp-58h]
  double v13; // [esp+18h] [ebp-50h]
  _BYTE v14[72]; // [esp+20h] [ebp-48h] BYREF

  *a3 = 0.0;
  *a4 = 0.0;
  sub_580170(v14);
  if ( !sub_5806C0(a2) )
  {
    v4 = this;
    v13 = 0.0;
    v12 = 0.0;
    v5 = (int)this;
    for ( i = 0; i < 4; ++i )
    {
      switch ( i )
      {
        case 0:
          v7 = sub_581860(aFlWheel);
          v10 = aFlSpindle;
          goto LABEL_8;
        case 1:
          v7 = sub_581860(aFrWheel);
          v10 = aFrSpindle;
          goto LABEL_8;
        case 2:
          v7 = sub_581860(aRlWheel);
          v10 = aRlSpindle;
          goto LABEL_8;
        case 3:
          v7 = sub_581860(aRrWheel);
          v10 = aRrSpindle;
LABEL_8:
          v4 = (float *)v7;
          v5 = sub_581860(v10);
          break;
        default:
          break;
      }
      if ( v4 )
      {
        *a3 = *(double *)(v4 + 43) + *a3;
        *a4 = this[62 * i + 4427] * *(double *)(v4 + 43) + *a4;
        if ( i == 2 )
        {
          v13 = *(double *)(v4 + 3);
        }
        else if ( i == 3 )
        {
          v12 = *(double *)(v4 + 3);
        }
      }
      if ( v5 )
      {
        *a3 = *(double *)(v5 + 172) + *a3;
        *a4 = this[62 * i + 4427] * *(double *)(v5 + 172) + *a4;
      }
    }
    v8 = sub_581860(aRearAxle);
    if ( v8 )
    {
      *a3 = *(double *)(v8 + 172) + *a3;
      *a4 = (*(double *)(v8 + 12) - (v12 + v13) * 0.5 + (this[4613] + this[4551]) * 0.5) * *(double *)(v8 + 172) + *a4;
    }
    if ( *a3 > 0.0 )
      *a4 = *a4 / *a3;
  }
  return sub_5801A0(v14);
}
