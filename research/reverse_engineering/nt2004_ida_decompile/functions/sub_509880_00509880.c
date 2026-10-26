int __thiscall sub_509880(int *this, int a2, char a3, int a4)
{
  int v5; // ecx

  v5 = *this;
  *((_BYTE *)this + 66) = a2;
  if ( v5 )
  {
    if ( a3 )
      sub_4153A0(v5, a4);
    sub_59E1D0(this + 1, this + 2, this + 3, this + 4, this + 5, this + 6);
    *((_BYTE *)this + 64) = 1;
    sub_59ED40(&a3, &a2);
    *((_BYTE *)this + 65) = a2 != 0;
    return sub_579100(this + 4, this + 7);
  }
  else
  {
    this[1] = 0;
    this[2] = 0;
    this[3] = 0;
    this[4] = 0;
    this[5] = 0;
    this[6] = 0;
    *((_BYTE *)this + 64) = 0;
    *((_BYTE *)this + 65) = 0;
    return sub_579100(this + 4, this + 7);
  }
}
