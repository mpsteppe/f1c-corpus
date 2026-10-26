int __thiscall sub_4DFA60(int *this, int a2, char a3, int a4)
{
  int v5; // ecx

  v5 = *this;
  *((_BYTE *)this + 66) = a2;
  if ( v5 )
  {
    if ( a3 )
      AudioPhysicsMixWithLerp(v5, a4);
    DualMatrixTransformMultiply(this + 1, this + 2, this + 3, this + 4, this + 5, this + 6);
    *((_BYTE *)this + 64) = 1;
    BitFlagReader(&a3, &a2);
    *((_BYTE *)this + 65) = a2 != 0;
    return EulerToRotationMatrix(this + 4, this + 7);
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
    return EulerToRotationMatrix(this + 4, this + 7);
  }
}

