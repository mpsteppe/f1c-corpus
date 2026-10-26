// Microsoft VisualC 2-14/net runtime
int __thiscall unknown_libname_195(int **this)
{
  int *v1; // ecx
  int result; // eax

  --*this[12];
  v1 = this[8];
  result = *v1;
  *v1 += 2;
  return result;
}
