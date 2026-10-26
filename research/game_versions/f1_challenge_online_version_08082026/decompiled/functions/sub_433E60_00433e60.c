int __thiscall sub_433E60(int this, char a2)
{
  sub_432CC0((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    sub_587BCF(*(LPVOID *)(this + 20));
  if ( *(_DWORD *)(this + 8) )
    sub_587BCF(*(LPVOID *)(this + 8));
  if ( *(_DWORD *)this )
    sub_587BCF(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_587BCF((LPVOID)this);
  return this;
}
