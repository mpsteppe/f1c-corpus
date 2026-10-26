void __thiscall sub_54B450(int this, float a2, float a3, float a4)
{
  InterruptDispatch(a2);
  *(float *)(this + 44) = a2;
  InterruptDispatch(a3);
  *(float *)(this + 48) = a3;
  InterruptDispatch(a4);
  *(float *)(this + 52) = a4;
  BitmaskClear((_DWORD *)this, 64, 0, 0);
}

