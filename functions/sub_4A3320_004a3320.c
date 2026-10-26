int __thiscall sub_4A3320(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax
  float v5[3]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v6[36]; // [esp+10h] [ebp-24h] BYREF

  result = this[5];
  if ( result )
  {
    EulerToRotationMatrix(a3, v6);
    RotationMatrixY(3.1415927, (int)v5);
    ThreeFieldSetterWithSubCall(*a2, a2[1], a2[2]);
    result = sub_54B450(v5[0], v5[1], v5[2]);
    this[2] = 2;
  }
  return result;
}
