// f1c  0x0059a43c  size=16
int __thiscall sub_59A43C(int **this)
{
  int *v1; // ecx
  int result; // eax

  --*this[12];
  v1 = this[8];
  result = *v1;
  *v1 += 2;
  return result;
}
