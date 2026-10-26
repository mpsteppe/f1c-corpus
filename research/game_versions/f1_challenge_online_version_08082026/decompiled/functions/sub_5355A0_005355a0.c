int __thiscall sub_5355A0(int this)
{
  if ( !this )
    return -2;
  if ( *(_BYTE *)(this + 92) == 119 && !sub_5352D0(this, 4) )
  {
    sub_5355F0(*(_DWORD *)(this + 64), *(_DWORD *)(this + 76));
    sub_5355F0(*(_DWORD *)(this + 64), *(_DWORD *)(this + 8));
  }
  return sub_534EE0((LPVOID *)this);
}
