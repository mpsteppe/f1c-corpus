int __thiscall sub_67CD1D(float *this)
{
  double v1; // st6
  double v2; // st6
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  float v7; // [esp+0h] [ebp-1Ch]
  float v8; // [esp+4h] [ebp-18h]
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+14h] [ebp-8h]
  float v11; // [esp+14h] [ebp-8h]
  float v12; // [esp+14h] [ebp-8h]

  if ( *this < 0.0 )
  {
    v1 = 0.0;
LABEL_3:
    v7 = v1;
    goto LABEL_7;
  }
  if ( *this > 1.0 )
  {
    v1 = 1.0;
    goto LABEL_3;
  }
  v7 = *this;
LABEL_7:
  if ( this[1] < 0.0 )
  {
    v2 = 0.0;
LABEL_9:
    v8 = v2;
    goto LABEL_13;
  }
  if ( this[1] > 1.0 )
  {
    v2 = 1.0;
    goto LABEL_9;
  }
  v8 = this[1];
LABEL_13:
  if ( this[2] >= 0.0 )
  {
    if ( this[2] <= 1.0 )
    {
      v9 = this[2];
      goto LABEL_19;
    }
    v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  v9 = v3;
LABEL_19:
  v10 = v7 * 31.0 + 0.5;
  v4 = (int)v10;
  v11 = v8 * 63.0 + 0.5;
  v5 = (int)v11;
  v12 = v9 * 31.0 + 0.5;
  return (int)v12 | (32 * (v5 | (v4 << 6)));
}
