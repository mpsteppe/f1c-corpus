int __thiscall sub_438DA0(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  int result; // eax

  v3 = this + 1387;
  sub_56D930(a2);
  this[1419] = sub_587C03(48 * *v3);
  this[1404] = sub_56EAD0(aBody_0);
  v4 = (_DWORD *)sub_56EB30(aFlSteering);
  if ( v4[1] == this[1404] )
    v5 = v4[2];
  else
    v5 = v4[4];
  this[1420] = v5;
  v6 = (_DWORD *)sub_56EB30(aFrSteering);
  if ( v6[1] == this[1404] )
    v7 = v6[2];
  else
    v7 = v6[4];
  this[1425] = v7;
  this[250] = sub_56EAD0(aFlWheel);
  this[251] = sub_56EAD0(aFlSpindle);
  this[531] = sub_56EAD0(aFrWheel);
  this[532] = sub_56EAD0(aFrSpindle);
  this[812] = sub_56EAD0(aRlWheel);
  this[813] = sub_56EAD0(aRlSpindle);
  this[1093] = sub_56EAD0(aRrWheel);
  this[1094] = sub_56EAD0(aRrSpindle);
  this[1287] = sub_56EAD0(aRearAxle);
  this[117] = sub_56EAD0(aFuelTank);
  result = sub_56EAD0(aDriverHead);
  this[122] = result;
  return result;
}
