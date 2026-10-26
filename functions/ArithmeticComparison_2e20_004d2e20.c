int __thiscall sub_4D2E20(int **this)
{
  int *v2; // esi
  int result; // eax

  v2 = this[41];
  if ( v2 )
  {
    sub_4D0080(this[41]);
    result = FreeWrapper_7bcf(v2);
    this[41] = 0;
  }
  return result;
}
