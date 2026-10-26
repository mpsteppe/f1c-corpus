// f1c  0x0053d850  size=40
int __thiscall sub_53D850(_DWORD *this)
{
  int v2; // eax

  sub_540760(this);
  v2 = this[1087];
  if ( v2 )
  {
    *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(this[1087]);
    this[1087] = 0;
  }
  return 0;
}
