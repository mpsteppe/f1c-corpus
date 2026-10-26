int __thiscall sub_4054A0(int this)
{
  sub_405630();
  if ( *(_DWORD *)(this + 12) )
  {
    sub_587D02(*(_DWORD *)(this + 12));
    *(_DWORD *)(this + 12) = 0;
  }
  if ( *(_DWORD *)(this + 24) )
    sub_587BCF(*(LPVOID *)(this + 24));
  return sub_405440((_DWORD *)this);
}
