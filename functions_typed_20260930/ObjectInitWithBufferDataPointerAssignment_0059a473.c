int __thiscall sub_59A473(int this, int a2, int a3)
{
  int result; // eax

  *(_BYTE *)(this + 72) = a3 == 1;
  if ( !a3 )
  {
    NullCheckWithVirtualDispatch((_DWORD *)(this + 76));
    if ( this != -76 )
      LocaleRefcountAcquireUnderLock((_DWORD *)(this + 76));
    *(_DWORD *)(this + 68) = 0;
  }
  SelfReferentialPointerRingInit(this);
  *(_DWORD *)(this + 80) = a2;
  *(_DWORD *)(this + 64) = dword_8D5A60;
  result = dword_8D5A60;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = result;
  return result;
}

