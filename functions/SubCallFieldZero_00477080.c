int __thiscall SubCallFieldZero(int this)
{
  UIDimensionCapture((int *)this);
  *(_BYTE *)(this + 380) = 0;
  return 0;
}
