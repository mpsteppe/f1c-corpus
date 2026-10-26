int __thiscall sub_59EAD0(int *this)
{
  int v1; // esi
  _DWORD *v2; // edi
  char v3; // al

  v1 = *this;
  while ( v1 )
  {
    v2 = (_DWORD *)v1;
    v3 = *(_BYTE *)(v1 + 8);
    v1 = *(_DWORD *)(v1 + 4);
    if ( v3 && *v2 )
      (**(void (__thiscall ***)(_DWORD, int))*v2)(*v2, 1);
    j__free(v2);
  }
  return off_16C9610();
}
