void __thiscall sub_59EBB0(int *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al

  v2 = *this;
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v3 + 4))(*v3, 1);
    j__free(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
