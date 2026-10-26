int __thiscall sub_5A46F0(_DWORD *this)
{
  int v2; // eax

  sub_5A78B0(this);
  v2 = this[1111];
  if ( v2 )
  {
    *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(this[1111]);
    this[1111] = 0;
  }
  return 0;
}
