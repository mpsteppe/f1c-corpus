int __thiscall sub_48E360(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 228);
  *(_DWORD *)this = &off_5AC490;
  if ( v2 )
    sub_551F80(v2);
  if ( *(_DWORD *)(this + 252) )
    sub_587BCF(*(LPVOID *)(this + 252));
  return sub_487250((LPVOID *)this);
}
