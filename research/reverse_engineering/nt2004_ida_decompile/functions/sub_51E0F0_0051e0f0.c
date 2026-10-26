void __thiscall sub_51E0F0(int this, float a2)
{
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  int i; // ecx
  int v7; // eax
  double v8; // st7
  float *v9; // eax
  int v10; // ecx
  float *v11; // eax
  double v12; // st7
  float v13; // [esp+0h] [ebp-8h]
  float v14; // [esp+4h] [ebp-4h]
  float v15; // [esp+4h] [ebp-4h]

  v3 = a2 / *(float *)(this + 19356);
  v4 = this + 17848;
  v5 = 4;
  v13 = v3;
  do
  {
    v4 += 248;
    --v5;
    *(float *)(v4 - 248) = v13 * *(float *)(v4 - 248);
  }
  while ( v5 );
  if ( (byte_7686A8 & 1) != 0 )
  {
    v14 = pow(v13, 0.449999988079071);
    for ( i = 0; i < *(_DWORD *)(this + 18764); v9[1] = (v8 + v9[1]) * v14 - *v9 )
    {
      v7 = *(_DWORD *)(this + 18752);
      v8 = *(float *)(v7 + 8 * i);
      v9 = (float *)(v7 + 8 * i++);
    }
  }
  if ( (byte_7686A8 & 2) != 0 )
  {
    v10 = 1;
    v15 = 1.0 / pow(v13, 0.2700000107288361);
    if ( *(int *)(this + 18836) >= 1 )
    {
      v11 = (float *)(this + 18796);
      do
      {
        ++v10;
        v12 = v15 * *v11++;
        *(v11 - 1) = v12;
      }
      while ( v10 <= *(_DWORD *)(this + 18836) );
    }
  }
  if ( (byte_7686A8 & 4) != 0 )
    *(float *)(this + 18720) = pow(v13, 0.25) * *(float *)(this + 18720);
  *(float *)(this + 19356) = a2;
  sub_513830(this, 0);
}
