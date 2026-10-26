int __thiscall sub_4F2B80(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // eax
  int *v5; // eax
  int v6; // edx

  for ( result = this[27]; result > 0; result = this[27] )
  {
    v3 = this[28];
    v4 = result - 1;
    this[27] = v4;
    v5 = *(int **)(v3 + 4 * v4);
    v6 = *v5;
    v5[1] = -1;
    sub_5B0A10(v6);
  }
  return result;
}
