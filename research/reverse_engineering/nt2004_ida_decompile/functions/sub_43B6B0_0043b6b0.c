int __thiscall sub_43B6B0(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  int result; // eax

  v3 = this + 1524;
  sub_5806C0(a2);
  this[1556] = operator new(48 * *v3);
  this[1541] = sub_581860(aBody_0);
  v4 = (_DWORD *)sub_5818C0(aFlSteering);
  if ( v4[1] == this[1541] )
    v5 = v4[2];
  else
    v5 = v4[4];
  this[1557] = v5;
  v6 = (_DWORD *)sub_5818C0(aFrSteering);
  if ( v6[1] == this[1541] )
    v7 = v6[2];
  else
    v7 = v6[4];
  this[1562] = v7;
  this[254] = sub_581860(aFlWheel);
  this[255] = sub_581860(aFlSpindle);
  this[568] = sub_581860(aFrWheel);
  this[569] = sub_581860(aFrSpindle);
  this[882] = sub_581860(aRlWheel);
  this[883] = sub_581860(aRlSpindle);
  this[1196] = sub_581860(aRrWheel);
  this[1197] = sub_581860(aRrSpindle);
  this[1423] = sub_581860(aRearAxle);
  this[121] = sub_581860(aFuelTank);
  result = sub_581860(aDriverHead);
  this[126] = result;
  return result;
}
