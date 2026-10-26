// f1c  0x004d2e20  size=43
int __thiscall sub_4D2E20(int **this)
{
  int *v2; // esi
  int result; // eax

  v2 = this[41];
  if ( v2 )
  {
    sub_4D0080(this[41]);
    result = sub_587BCF(v2);
    this[41] = 0;
  }
  return result;
}
