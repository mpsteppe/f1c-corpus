int __thiscall sub_4AF7B0(int this)
{
  char v1; // al
  int v2; // ecx
  int v3; // eax

  v1 = *(_BYTE *)(this + 276);
  v2 = *(_DWORD *)(this + 48);
  if ( v1 )
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 28))(v2, 51);
  else
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 28))(v2, 47);
  if ( v3 && sub_4CE170(v3) )
  {
    sub_4ABA50();
    sub_4363E0();
  }
  return 0;
}
