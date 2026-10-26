int __thiscall sub_541B70(int this, char a2)
{
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st6
  double v8; // st5
  int result; // eax
  double v10; // [esp+8h] [ebp-50h]
  double v11; // [esp+10h] [ebp-48h]
  float v12[16]; // [esp+18h] [ebp-40h] BYREF

  if ( (a2 & 4) != 0 )
  {
    sub_53AC70(2, 0);
    memset(v12, 0, sizeof(v12));
    if ( (a2 & 0x10) != 0 )
    {
      v3 = *(float *)(this + 8);
      v12[0] = 0.2;
      v4 = v3 - *(float *)(this + 4);
      v12[5] = 0.2;
      v12[11] = 0.0;
      v12[15] = 1.0;
      v5 = 1.0 / v4;
      v12[10] = v5;
      v12[14] = *(float *)(this + 4) * v5;
    }
    else
    {
      v10 = 1.0 / *(float *)(this + 28);
      v6 = 1.0 / *(float *)(this + 32);
      v7 = *(float *)(this + 8) / (*(float *)(this + 8) - *(float *)(this + 4));
      v11 = -(*(float *)(this + 4) * v7);
      if ( (*(_BYTE *)(this + 128) & 0x10) != 0 )
        v8 = -v10;
      else
        v8 = v10;
      v12[0] = v8;
      v12[11] = 1.0;
      v12[15] = 0.0;
      v12[5] = v6;
      v12[10] = v7;
      v12[14] = v11;
    }
    sub_53AC70(1, 0);
    result = sub_55CA40(4, v12);
  }
  if ( (a2 & 2) != 0 )
    result = sub_55CA40(2, this + 348);
  if ( (a2 & 8) != 0 )
    return sub_55CC20(this);
  return result;
}
