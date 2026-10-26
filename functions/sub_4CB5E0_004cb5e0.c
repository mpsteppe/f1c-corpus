int __thiscall sub_4CB5E0(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // eax
  int *v5; // eax
  int v6; // edx

  for ( result = this[25]; result > 0; result = this[25] )
  {
    v3 = this[26];
    v4 = result - 1;
    this[25] = v4;
    v5 = *(int **)(v3 + 4 * v4);
    v6 = *v5;
    v5[1] = -1;
    sub_558B30(v6);
  }
  return result;
}
