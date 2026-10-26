// f1c  0x0057a070  size=72
int __thiscall sub_57A070(_BYTE *this, int a2, int a3, char a4, int a5)
{
  _BYTE *v6; // eax
  int v7; // edi

  sub_587DD0(this, a2, 9);
  v6 = this;
  v7 = 4;
  do
  {
    *v6 |= v6[&a4 - this];
    ++v6;
    --v7;
  }
  while ( v7 );
  return sub_587DD0(this + 16, a3, 4);
}
