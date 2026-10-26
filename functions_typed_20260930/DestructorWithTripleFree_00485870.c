int __thiscall DestructorWithTripleFree(int this, char a2)
{
  ConditionalDualCleanup((_DWORD *)(this + 304));
  if ( *(_DWORD *)(this + 296) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 296));
  if ( *(_DWORD *)(this + 288) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 288));
  if ( *(_DWORD *)(this + 280) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 280));
  ConditionalDualCleanup((_DWORD *)(this + 224));
  sub_485EB0((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}

