void __thiscall sub_5697A0(int this, double *a2)
{
  qmemcpy((void *)(this + 188), a2, 0x18u);
  *(double *)(this + 212) = 1.0 / *a2;
  *(double *)(this + 220) = 1.0 / a2[1];
  *(double *)(this + 228) = 1.0 / a2[2];
  InertiaTensorWorldSpaceTransform(this);
}
