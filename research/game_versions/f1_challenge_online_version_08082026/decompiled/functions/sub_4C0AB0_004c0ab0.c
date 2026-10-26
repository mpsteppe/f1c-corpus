int __thiscall sub_4C0AB0(int this)
{
  _DWORD *v2; // edi
  int v3; // ebx

  v2 = (_DWORD *)this;
  v3 = 103;
  do
  {
    sub_4C03C0(v2);
    v2 += 109;
    --v3;
  }
  while ( v3 );
  sub_4C03C0((_DWORD *)(this + 44908));
  sub_4C0370((_DWORD *)(this + 45344));
  *(_DWORD *)(this + 45380) = 0;
  *(_BYTE *)(this + 45392) = 0;
  *(_DWORD *)(this + 45384) = -1;
  *(_DWORD *)(this + 45388) = 1;
  return this;
}
