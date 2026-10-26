void __thiscall sub_4DEB20(int *this, int a2)
{
  int v3; // eax

  v3 = this[12];
  if ( v3 != a2 )
  {
    sub_419F80(flt_629328, *this, v3, a2);
    this[12] = a2;
  }
}
