int __thiscall sub_438DA0(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  int result; // eax

  v3 = this + 1387;
  VehiclePhysicsJointSystemLoader(a2);
  this[1419] = OperatorNewNhMallocWrapper(48 * *v3);
  this[1404] = LinearSearchWithLargeStructStride(aBody_0);
  v4 = (_DWORD *)LinearSearchInStructArrayByString(aFlSteering);
  if ( v4[1] == this[1404] )
    v5 = v4[2];
  else
    v5 = v4[4];
  this[1420] = v5;
  v6 = (_DWORD *)LinearSearchInStructArrayByString(aFrSteering);
  if ( v6[1] == this[1404] )
    v7 = v6[2];
  else
    v7 = v6[4];
  this[1425] = v7;
  this[250] = LinearSearchWithLargeStructStride(aFlWheel);
  this[251] = LinearSearchWithLargeStructStride(aFlSpindle);
  this[531] = LinearSearchWithLargeStructStride(aFrWheel);
  this[532] = LinearSearchWithLargeStructStride(aFrSpindle);
  this[812] = LinearSearchWithLargeStructStride(aRlWheel);
  this[813] = LinearSearchWithLargeStructStride(aRlSpindle);
  this[1093] = LinearSearchWithLargeStructStride(aRrWheel);
  this[1094] = LinearSearchWithLargeStructStride(aRrSpindle);
  this[1287] = LinearSearchWithLargeStructStride(aRearAxle);
  this[117] = LinearSearchWithLargeStructStride(aFuelTank);
  result = LinearSearchWithLargeStructStride(aDriverHead);
  this[122] = result;
  return result;
}
