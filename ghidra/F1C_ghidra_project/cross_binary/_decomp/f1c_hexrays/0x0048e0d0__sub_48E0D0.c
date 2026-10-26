// f1c  0x0048e0d0  size=58
int __thiscall sub_48E0D0(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 224);
  *(_DWORD *)this = &off_5AC3E0;
  if ( v2 )
    sub_551F80(v2);
  if ( *(_DWORD *)(this + 232) )
    sub_587BCF(*(LPVOID *)(this + 232));
  return sub_485EB0((LPVOID *)this);
}
