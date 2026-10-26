void __thiscall sub_41F560(int this, float *a2, int a3, float a4, char a5)
{
  float *v5; // esi
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  double v10; // st7
  double v11; // st5
  float v12; // [esp+0h] [ebp-Ch]
  float v13; // [esp+8h] [ebp-4h]

  if ( a5 )
  {
    v5 = *(float **)(this + 4);
    v6 = (v5[4401] - a2[49]) * a2[53] + (v5[4403] - a2[51]) * a2[55];
    v12 = a2[53] * v6;
    v13 = a2[55] * v6;
    v10 = sqrt(v13 * v13 + v12 * v12);
    if ( v8 | v9 )
      v10 = -v10;
    *(float *)(this + 76) = v10;
    v11 = a2[55] * a2[55] + a2[53] * a2[53];
    if ( v11 == 0.0 )
      *(_DWORD *)(this + 88) = 0;
    else
      *(float *)(this + 88) = ((a4 * v5[4425] + v5[4407]) * a2[53] + (a4 * v5[4427] + v5[4409]) * a2[55]) / v11;
  }
  else
  {
    *(float *)(this + 68) = a2[13] * (*(float *)(*(_DWORD *)(this + 4) + 17612) - a2[51])
                          + a2[11] * (*(float *)(*(_DWORD *)(this + 4) + 17604) - a2[49]);
  }
}
