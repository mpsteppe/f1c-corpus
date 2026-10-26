void __thiscall sub_5782A0(int this, float *a2)
{
  int v3; // eax
  double v4; // st7
  float v5; // [esp+8h] [ebp-3Ch]
  double v6[6]; // [esp+Ch] [ebp-38h] BYREF
  int v7; // [esp+3Ch] [ebp-8h]
  float v8; // [esp+48h] [ebp+4h]

  v3 = *(_DWORD *)(this + 16888);
  v6[0] = *a2;
  v6[1] = a2[1];
  v6[2] = a2[2];
  v7 = v3;
  v6[3] = 2.0;
  v6[4] = 9.999999933815813e36;
  if ( sub_45D190(dbl_B68610, (int)v6) )
  {
    v4 = a2[1] - v6[5];
    v5 = *(float *)(this + 19236) + 0.1;
    v8 = *(float *)(this + 19236) - 0.1;
    if ( v4 >= v8 )
    {
      if ( v4 > v5 )
        v4 = v5;
    }
    else
    {
      v4 = v8;
    }
    *(float *)(this + 19240) = (v4 + *(float *)(this + 19236)) * 0.5;
  }
}
