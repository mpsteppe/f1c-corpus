int __thiscall sub_5648D0(int *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]

  if ( *this == this[1] )
    AccumulatorWithReallocOnGrowth(this);
  v3 = *this + 1;
  *this = v3;
  if ( a2 < v3 - 1 )
  {
    v8 = this[2] * (v3 - a2 - 1);
    v7 = LinearInterpolation((int)this, a2);
    v5 = LinearInterpolation(v4, a2 + 1);
    sub_58B130(v5, v7, v8);
  }
  return AlignedMemoryCopyFromStructBuffer(a2);
}
