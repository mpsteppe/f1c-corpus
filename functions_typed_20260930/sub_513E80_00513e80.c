int __thiscall sub_513E80(float *this)
{
  double v1; // st6
  double v2; // st6
  double v3; // st7
  int v4; // ecx
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+8h] [ebp-10h]
  float v9; // [esp+10h] [ebp-8h]
  float v10; // [esp+10h] [ebp-8h]
  float v11; // [esp+14h] [ebp-4h]

  if ( *this < 0.0 )
  {
    v1 = 0.0;
LABEL_3:
    v6 = v1;
    goto LABEL_7;
  }
  if ( *this > 1.0 )
  {
    v1 = 1.0;
    goto LABEL_3;
  }
  v6 = *this;
LABEL_7:
  if ( this[1] < 0.0 )
  {
    v2 = 0.0;
LABEL_9:
    v7 = v2;
    goto LABEL_13;
  }
  if ( this[1] > 1.0 )
  {
    v2 = 1.0;
    goto LABEL_9;
  }
  v7 = this[1];
LABEL_13:
  if ( this[2] >= 0.0 )
  {
    if ( this[2] <= 1.0 )
    {
      v8 = this[2];
      goto LABEL_19;
    }
    v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  v8 = v3;
LABEL_19:
  FPUControlWordMerger();
  v11 = v6 * 31.0 + 0.5;
  v9 = v7 * 63.0 + 0.5;
  v4 = (int)v9;
  v10 = v8 * 31.0 + 0.5;
  return (int)v10 | (32 * (v4 | ((int)v11 << 6)));
}

