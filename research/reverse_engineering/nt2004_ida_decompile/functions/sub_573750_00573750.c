int *__thiscall sub_573750(int *this, int *a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int *result; // eax

  this[1] = a3;
  v4 = *this + 1;
  this[2] = a4;
  *this = v4;
  v5 = v4;
  result = a2;
  *a2 = v5;
  return result;
}
