double __fastcall sub_4BEA10(int a1, int a2, int a3, float a4)
{
  int v4; // ecx
  double v5; // st7
  int v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]

  if ( *(_DWORD *)(a1 + 864) == 7 )
  {
    v7 = *(int *)(a3 + 17604);
  }
  else
  {
    a1 = *(_DWORD *)(a3 + 17600);
    v7 = a1;
  }
  v8 = (double)(sub_5884ED(a1) % 40) * 0.0099999998 - 0.0099999998 + 1.0 - *(float *)&v7;
  if ( v8 <= 1.0 )
  {
    if ( v8 < 0.0 )
      v8 = 0.0;
  }
  else
  {
    v8 = 1.0;
  }
  sub_5881F0(v8);
  v5 = (double)(sub_5884ED(v4) % 50) * 0.0099999998 + 0.5;
  if ( v5 > 1.0 )
    v5 = 1.0;
  return 0.25 * a4 * (v5 * v8) - 0.25 + a4;
}
