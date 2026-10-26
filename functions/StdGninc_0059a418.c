int __thiscall sub_59A418(int **this)
{
  int *v1; // ecx
  int result; // eax

  --*this[11];
  v1 = this[7];
  result = *v1;
  *v1 += 2;
  return result;
}
