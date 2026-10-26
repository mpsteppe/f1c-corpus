int __thiscall sub_459950(char *this, double a2, int a3)
{
  char *v3; // ecx

  v3 = this + 212;
  *(double *)(v3 + 172) = a2;
  *(double *)(v3 + 180) = 1.0 / a2;
  return StructCopyWithReciprocalDivision(a3);
}
