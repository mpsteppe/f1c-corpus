int __thiscall sub_551440(_DWORD *this)
{
  int result; // eax

  this[1] = this[1] & 0xFFFE0FFF | 0x2000;
  PerEntityDataBlockCopyFromParameterTable(this, 0, 0);
  TimerStartViaQueryPerformanceCounter(*this);
  result = HighResolutionTimerReset(*this);
  this[4] = 0;
  return result;
}
