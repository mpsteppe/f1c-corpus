int __thiscall DestructorWithFreeCondition(int this, char a2)
{
  if ( *(_DWORD *)(this + 344) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 344));
  ConditionalDualCleanup((_DWORD *)(this + 292));
  ConditionalDualCleanup((_DWORD *)(this + 224));
  sub_485EB0((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
