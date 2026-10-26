int __thiscall sub_5A0010(int *this, int a2, int a3, float a4, float a5, int a6)
{
  double v7; // st7
  double v8; // st6
  int result; // eax
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h] BYREF

  v7 = (double)this[7];
  v8 = (double)this[8];
  v11 = (__int64)(*(float *)&a2 * v7);
  *(float *)&a2 = v8;
  v10 = (__int64)(v8 * *(float *)&a3);
  a3 = (__int64)(v7 * a4);
  a2 = (__int64)(*(float *)&a2 * a5);
  result = sub_5A00B0(&v11, &v10, &a3, &a2);
  if ( a3 > 0 )
  {
    result = a2;
    if ( a2 > 0 )
    {
      result = sub_5A7610(this, v11, v10, a3, a2, a6);
      this[14] &= ~0x400u;
    }
  }
  return result;
}
