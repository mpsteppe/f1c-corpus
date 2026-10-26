int __thiscall PhysicsStateInitIndexed(_BYTE *this, int a2, float a3)
{
  this[6564] = 0;
  *this = 1;
  *(float *)&this[4 * a2 + 7336] = a3;
  return PressureForceFieldMapping((int)this);
}

