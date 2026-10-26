int __thiscall sub_414450(_DWORD *this, int a2)
{
  int v3; // eax

  sub_42C8A0(a2);
  sub_412180();
  sub_414110();
  v3 = this[2];
  if ( v3 )
    (*(void (**)(void))(*(_DWORD *)v3 + 16))();
  if ( dword_FB1D04 )
    sub_5E5AE0();
  return sub_562430(&dword_FAE988, 1, 0);
}
