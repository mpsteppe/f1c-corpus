// f1c  0x00489e90  size=68
int __thiscall sub_489E90(int *this)
{
  int result; // eax

  result = this[88];
  this[84] = 0;
  if ( result )
  {
    result = sub_587BDC((double)this[83] / (double)result * (double)this[85] + 0.5);
    this[84] = result;
  }
  return result;
}
