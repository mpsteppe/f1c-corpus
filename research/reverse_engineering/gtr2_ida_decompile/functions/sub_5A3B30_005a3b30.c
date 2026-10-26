int *__thiscall sub_5A3B30(double *this, int *a2, double a3)
{
  int v3; // eax
  int v4; // ecx
  int *result; // eax

  v3 = *(_DWORD *)this + 1;
  this[1] = a3;
  *(_DWORD *)this = v3;
  v4 = v3;
  result = a2;
  *a2 = v4;
  return result;
}
