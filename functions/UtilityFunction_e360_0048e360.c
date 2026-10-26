int __thiscall sub_48E360(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 228);
  *(_DWORD *)this = &off_5AC490;
  if ( v2 )
    ConditionalFreeWithBinkClose(v2);
  if ( *(_DWORD *)(this + 252) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 252));
  return InitWithVTableCleanup((LPVOID *)this);
}
