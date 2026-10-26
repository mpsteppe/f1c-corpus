int __thiscall sub_583660(_DWORD *this, int a2)
{
  *this = a2;
  return TimerResetUsingQueryPerformanceCounter(this + 1);
}
