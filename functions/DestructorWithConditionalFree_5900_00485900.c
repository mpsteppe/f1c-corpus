int __thiscall DestructorWithConditionalFree_5900(int this, char a2)
{
  if ( *(_DWORD *)(this + 340) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 340));
  ConditionalDualCleanup((_DWORD *)(this + 288));
  if ( *(_DWORD *)(this + 280) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 280));
  ConditionalDualCleanup((_DWORD *)(this + 224));
  sub_485EB0((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
