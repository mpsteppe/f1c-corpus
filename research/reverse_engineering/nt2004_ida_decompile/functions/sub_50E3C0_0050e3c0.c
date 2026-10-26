int __thiscall sub_50E3C0(int *this)
{
  int *v1; // esi
  int v2; // edi
  int result; // eax
  bool v4; // zf

  v1 = this + 129;
  v2 = 4;
  do
  {
    result = *v1;
    v4 = *v1 == 0;
    *(v1 - 1) = 0;
    if ( !v4 )
      result = sub_5BE8AE();
    *v1 = 0;
    v1 += 76;
    --v2;
  }
  while ( v2 );
  return result;
}
