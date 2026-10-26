int __thiscall sub_5514A0(_DWORD *this)
{
  this[1] = this[1] & 0xFFFE0FFF | 0x2000;
  return TimerStartViaQueryPerformanceCounter(*this);
}
