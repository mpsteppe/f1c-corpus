int __thiscall sub_441450(int *this)
{
  int v2; // ecx

  SuspensionDataCopyToPhysicsEngine((int)(this + 163), this[251]);
  SuspensionDataCopyToPhysicsEngine((int)(this + 444), this[532]);
  v2 = (int)(this + 725);
  if ( this[1287] )
  {
    SuspensionDataCopyToPhysicsEngine(v2, this[1287]);
    return SuspensionDataCopyToPhysicsEngine((int)(this + 1006), this[1287]);
  }
  else
  {
    SuspensionDataCopyToPhysicsEngine(v2, this[813]);
    return SuspensionDataCopyToPhysicsEngine((int)(this + 1006), this[1094]);
  }
}
