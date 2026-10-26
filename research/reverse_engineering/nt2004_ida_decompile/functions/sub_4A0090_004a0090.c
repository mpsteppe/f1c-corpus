int __thiscall sub_4A0090(int *this)
{
  __int64 v1; // rax

  LODWORD(v1) = this[99];
  this[95] = 0;
  if ( (_DWORD)v1 )
  {
    v1 = (__int64)((double)this[94] / (double)(int)v1 * (double)this[96] + 0.5);
    this[95] = v1;
  }
  return v1;
}
