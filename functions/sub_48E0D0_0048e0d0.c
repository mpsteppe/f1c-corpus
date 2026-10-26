int __thiscall sub_48E0D0(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 224);
  *(_DWORD *)this = &off_5AC3E0;
  if ( v2 )
    ConditionalFreeWithBinkClose(v2);
  if ( *(_DWORD *)(this + 232) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 232));
  return sub_485EB0((LPVOID *)this);
}
