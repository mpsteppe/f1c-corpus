int __thiscall sub_4992F0(int this)
{
  *(_DWORD *)(this + 300) = -1;
  sub_4CF4D0();
  flt_B6E07C = sqrt(*(float *)(this + 276) * *(float *)(this + 276) - flt_759F2C * flt_759F2C);
  flt_B6E080 = asin(flt_759F2C / *(float *)(this + 276));
  return 0;
}
