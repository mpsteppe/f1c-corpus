int __usercall sub_4E4910@<eax>(int a1@<ecx>, double a2@<st0>)
{
  TireBrushModelForceSolver(1);
  PhysicsNodePropagationWithDistanceFalloff((float *)dword_5EA2C0, a2, a1);
  return TireBrushModelForceSolver(0);
}
