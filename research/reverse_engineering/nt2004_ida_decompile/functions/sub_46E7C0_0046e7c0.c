char __thiscall sub_46E7C0(int this)
{
  int *v2; // ecx

  dword_600F40 = -1082130432;
  sub_4A44C0();
  sub_46EFD0(this);
  sub_46E8B0(this);
  ((void (__thiscall *)(int))((char *)&loc_46ED1F + 1))(this);
  v2 = *(int **)(this + 340);
  if ( v2 )
  {
    sub_459B30(v2);
    *(_BYTE *)(this + 360) = 0;
  }
  if ( *(_DWORD *)(this + 268) )
    sub_593430(1);
  *(_DWORD *)(this + 272) = *(_DWORD *)(this + 276);
  return 0;
}
