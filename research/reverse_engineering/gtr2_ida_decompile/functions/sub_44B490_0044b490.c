double *__thiscall sub_44B490(double *this)
{
  double *v2; // ecx

  v2 = this + 68;
  *((_DWORD *)v2 + 40) = 0;
  sub_43B2D0(v2);
  sub_431700((_DWORD *)this + 1544);
  sub_61E6A0((char *)this + 6244);
  memset(this + 922, 0, 0x80u);
  memset(this + 938, 0, 0x80u);
  memset(this, 0, 0x2590u);
  sub_442F40((int)this);
  return this;
}
