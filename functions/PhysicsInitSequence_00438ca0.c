void *__thiscall PhysicsInitSequence(int this)
{
  WheelDynamicsInit(this);
  PhysicsSubsystemInitDispatcher((LPVOID *)(this + 5548));
  return PhysicsBufferClear((_DWORD *)(this + 492));
}
