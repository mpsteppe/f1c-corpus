int *__thiscall sub_45DD60(int *this, float a2)
{
  double v2; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  double v6; // st7
  double v7; // st6
  double v8; // st6
  int *result; // eax
  int v10; // ecx

  v2 = a2 + *(float *)this;
  *(float *)this = v2;
  if ( !(v4 | v5) )
  {
    v6 = 1.0 / v2;
    *this = 0;
    v7 = (double)this[1];
    this[1] = 0;
    *((float *)this + 3) = v7 * v6;
    v8 = (double)this[2];
    this[2] = 0;
    *((float *)this + 4) = v8 * v6;
  }
  result = this + 54;
  v10 = 49;
  do
  {
    ++result;
    --v10;
    *((float *)result - 50) = a2 + *((float *)result - 50);
    *((float *)result - 1) = a2 + *((float *)result - 1);
  }
  while ( v10 );
  return result;
}
