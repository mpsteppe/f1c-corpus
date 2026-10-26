int __thiscall sub_433E60(int this, char a2)
{
  SessionConfigDefaultInit((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 20));
  if ( *(_DWORD *)(this + 8) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 8));
  if ( *(_DWORD *)this )
    FreeWrapper_7bcf(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
