void __thiscall sub_441600(int *this, double a2)
{
  WheelStateHistoryShift(this);
  SuspensionWheelDynamicsSolver((int)this, a2);
  sub_56ECF0(this + 1387);
  sub_56EE40(this + 1387);
  IterateAndFindMinimumValueFromFunction(a2);
  PhysicsSubObjectFree(this);
}
