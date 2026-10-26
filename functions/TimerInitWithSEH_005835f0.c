_DWORD *__thiscall sub_5835F0(_DWORD *this)
{
  double *v2; // edi

  v2 = (double *)(this + 1);
  StructZeroInit_8ba0(this + 1);
  QPCTimerInitialization(v2, 1u);
  FloatSetWithTimingCall(0);
  return this;
}
