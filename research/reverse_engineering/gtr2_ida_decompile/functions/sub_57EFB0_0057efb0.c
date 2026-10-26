void __thiscall sub_57EFB0(int this, float a2)
{
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  double v7; // st7
  float *v8; // eax
  int v9; // ecx
  float *v10; // eax
  double v11; // st7
  float v12; // [esp+0h] [ebp-8h]
  float v13; // [esp+4h] [ebp-4h]
  float v14; // [esp+4h] [ebp-4h]

  v3 = a2 / *(float *)(this + 18044);
  v12 = v3;
  *(float *)(this + 16304) = v3 * *(float *)(this + 16304);
  *(float *)(this + 16556) = v12 * *(float *)(this + 16556);
  *(float *)(this + 16808) = v12 * *(float *)(this + 16808);
  *(float *)(this + 17060) = v12 * *(float *)(this + 17060);
  if ( (byte_B71FFC & 1) != 0 )
  {
    v4 = *(_DWORD *)(this + 17240);
    v5 = 0;
    v13 = pow(v12, 0.449999988079071);
    if ( v4 > 0 )
    {
      do
      {
        v6 = *(_DWORD *)(this + 17228);
        v7 = *(float *)(v6 + 8 * v5);
        v8 = (float *)(v6 + 8 * v5++);
        v8[1] = (v7 + v8[1]) * v13 - *v8;
      }
      while ( v5 < *(_DWORD *)(this + 17240) );
    }
  }
  if ( (byte_B71FFC & 2) != 0 )
  {
    v9 = 1;
    v14 = 1.0 / pow(v12, 0.2700000107288361);
    if ( *(int *)(this + 17312) >= 1 )
    {
      v10 = (float *)(this + 17272);
      do
      {
        ++v9;
        v11 = v14 * *v10++;
        *(v10 - 1) = v11;
      }
      while ( v9 <= *(_DWORD *)(this + 17312) );
    }
  }
  if ( (byte_B71FFC & 4) != 0 )
    *(float *)(this + 17192) = pow(v12, 0.25) * *(float *)(this + 17192);
  *(float *)(this + 18044) = a2;
  sub_579710(this, 0);
}
