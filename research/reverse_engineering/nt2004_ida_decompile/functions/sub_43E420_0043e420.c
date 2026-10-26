int __thiscall sub_43E420(char *this, int a2, int a3, double a4)
{
  int result; // eax

  result = a3 - 1;
  if ( a3 == 1 )
  {
    result = 1256 * a2;
    *(double *)&this[1256 * a2 + 1668] = a4;
  }
  return result;
}
