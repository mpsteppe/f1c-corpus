int __thiscall UIListObjectDestructor(int this, char a2)
{
  if ( *(_DWORD *)(this + 352) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 352));
  if ( *(_DWORD *)(this + 344) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 344));
  if ( *(_DWORD *)(this + 336) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 336));
  ConditionalDualCleanup((_DWORD *)(this + 280));
  ConditionalDualCleanup((_DWORD *)(this + 224));
  sub_485EB0((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
