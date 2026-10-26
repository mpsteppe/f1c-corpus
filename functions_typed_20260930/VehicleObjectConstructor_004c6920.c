F1CVehicle *__thiscall VehicleObjectConstructor(F1CVehicle *this)
{
  RaceStructInit(this);
  this->VehicleSceneSlotId = -1;
  VehicleDriverInfoClear(this);
  LargeStructFieldSetterWithStoredReference(this, (int)this);
  return this;
}

