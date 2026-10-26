int __thiscall sub_4DC260(int *this, int a2, int a3)
{
  int v4; // ecx
  int *v5; // edx
  int result; // eax

  if ( this[1] != a3 )
  {
    v4 = *this;
    this[2] = 9;
    sub_421590(v4, 16, 0);
    *((_BYTE *)this + 36) = 1;
  }
  v5 = (int *)this[40];
  this[30] = a2;
  *v5 = a2;
  result = sub_42DBA0();
  if ( (_BYTE)result )
  {
    result = sub_4EED40(*this);
    if ( (_BYTE)result )
      return sub_51F3D0(0, 4);
  }
  return result;
}
