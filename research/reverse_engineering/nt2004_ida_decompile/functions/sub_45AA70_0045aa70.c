int __thiscall sub_45AA70(char *this, double a2, int a3)
{
  char *v3; // ecx

  v3 = this + 216;
  *(double *)(v3 + 172) = a2;
  *(double *)(v3 + 180) = 1.0 / a2;
  return sub_57C530(a3);
}
