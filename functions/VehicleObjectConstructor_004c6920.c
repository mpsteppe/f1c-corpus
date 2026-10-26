_DWORD *__thiscall VehicleObjectConstructor(_DWORD *this)
{
  RaceStructInit(this);
  this[4645] = -1;
  VehicleDriverInfoClear((int)this);
  LargeStructFieldSetterWithStoredReference(this, (int)this);
  return this;
}
