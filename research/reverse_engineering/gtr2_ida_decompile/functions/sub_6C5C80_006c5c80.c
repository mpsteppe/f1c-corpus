int __thiscall sub_6C5C80(_DWORD *this, int a2, unsigned int *a3, _DWORD *a4)
{
  unsigned int v4; // eax

  *a4 = 1;
  v4 = *(_DWORD *)(a2 + 12);
  *a3 = v4;
  if ( v4 < this[10] )
    return 0;
  sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4506, "maximum input register index exceeded");
  return -2147467259;
}
