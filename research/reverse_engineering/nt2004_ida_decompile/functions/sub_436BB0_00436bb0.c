int __thiscall sub_436BB0(int this, char a2)
{
  sub_435A40((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    sub_5BE8AE(*(LPVOID *)(this + 20));
  if ( *(_DWORD *)(this + 8) )
    sub_5BE8AE(*(LPVOID *)(this + 8));
  if ( *(_DWORD *)this )
    sub_5BE8AE(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
