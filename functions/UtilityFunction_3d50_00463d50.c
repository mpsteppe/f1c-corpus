char __thiscall sub_463D50(int *this, int a2, int a3, float a4)
{
  int v6; // edx
  char v7; // bl
  float v9; // [esp+14h] [ebp+4h]

  v9 = *((float *)&unk_5F0708 + 4656 * a2);
  v7 = CollisionTestWithThreshold(a4, a2, a3, v9, 0);
  if ( v7 )
  {
    PhysicsIntegrationStep_e620(*this, v6, a3);
    PhysicsFloatUpdateWithCompare(a3, v9);
  }
  return v7;
}
