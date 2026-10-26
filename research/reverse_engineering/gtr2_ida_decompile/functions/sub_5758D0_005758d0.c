int __thiscall sub_5758D0(float *this, int a2, float *a3, float *a4)
{
  int v4; // edi
  float *v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *v10; // [esp-4h] [ebp-7Ch]
  double v12; // [esp+10h] [ebp-68h]
  double v13; // [esp+18h] [ebp-60h]
  _BYTE v14[76]; // [esp+20h] [ebp-58h] BYREF
  int v15; // [esp+74h] [ebp-4h]

  v4 = 0;
  *a3 = 0.0;
  *a4 = 0.0;
  sub_61E6A0(v14);
  v15 = 0;
  if ( !sub_61E750(a2, 0) )
  {
    v5 = this;
    v6 = (int)this;
    v13 = 0.0;
    v12 = 0.0;
    do
    {
      switch ( v4 )
      {
        case 0:
          v7 = sub_61DB10("fl_wheel");
          v10 = "fl_spindle";
          goto LABEL_8;
        case 1:
          v7 = sub_61DB10("fr_wheel");
          v10 = "fr_spindle";
          goto LABEL_8;
        case 2:
          v7 = sub_61DB10("rl_wheel");
          v10 = "rl_spindle";
          goto LABEL_8;
        case 3:
          v7 = sub_61DB10("rr_wheel");
          v10 = "rr_spindle";
LABEL_8:
          v5 = (float *)v7;
          v6 = sub_61DB10(v10);
          break;
        default:
          break;
      }
      if ( v5 )
      {
        *a3 = *((double *)v5 + 22) + *a3;
        *a4 = this[63 * v4 + 4041] * *((double *)v5 + 22) + *a4;
        if ( v4 == 2 )
        {
          v13 = *((double *)v5 + 2);
        }
        else if ( v4 == 3 )
        {
          v12 = *((double *)v5 + 2);
        }
      }
      if ( v6 )
      {
        *a3 = *(double *)(v6 + 176) + *a3;
        *a4 = this[63 * v4 + 4041] * *(double *)(v6 + 176) + *a4;
      }
      ++v4;
    }
    while ( v4 < 4 );
    v8 = sub_61DB10("rear_axle");
    if ( v8 )
    {
      *a3 = *(double *)(v8 + 176) + *a3;
      *a4 = (*(double *)(v8 + 16) - (v12 + v13) * 0.5 + (this[4230] + this[4167]) * 0.5) * *(double *)(v8 + 176) + *a4;
    }
    if ( *a3 > 0.0 )
      *a4 = *a4 / *a3;
  }
  v15 = -1;
  return sub_61E700(v14);
}
