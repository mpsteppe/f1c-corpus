int __thiscall sub_492310(int this)
{
  char v1; // al

  if ( *(_DWORD *)(this + 596) )
    *(_BYTE *)(this + 600) = 1;
  else
    *(_BYTE *)(this + 600) = *(_BYTE *)(this + 600) == 0;
  v1 = *(_BYTE *)(this + 600);
  *(_DWORD *)(this + 596) = 0;
  if ( v1 )
    return sub_4D41C0(2, 0);
  else
    return sub_4D41C0(3, 0);
}
