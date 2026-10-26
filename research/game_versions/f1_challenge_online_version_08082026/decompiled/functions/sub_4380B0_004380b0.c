void __thiscall sub_4380B0(double *this, double a2, double a3)
{
  double v3; // st7
  int v4; // ecx
  double v5; // [esp+0h] [ebp-8h]

  v5 = this[63] - a2;
  this[61] = v5;
  this[62] = -a3;
  v3 = sub_436610(this, v5, -a3);
  *(double *)(v4 + 516) = v3;
}
