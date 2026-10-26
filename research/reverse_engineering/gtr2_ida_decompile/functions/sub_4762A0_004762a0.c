int *__thiscall sub_4762A0(int *this, int *a2)
{
  int v2; // edx
  int v3; // esi
  int *result; // eax
  int v5; // ecx
  bool v6; // cc

  v2 = *a2;
  v3 = this[8];
  result = this + 5;
  v5 = this[7];
  v6 = *a2 < v5;
  *result = *a2;
  if ( v6 )
  {
    *result = v5;
  }
  else if ( v2 > v3 )
  {
    *result = v3;
  }
  return result;
}
