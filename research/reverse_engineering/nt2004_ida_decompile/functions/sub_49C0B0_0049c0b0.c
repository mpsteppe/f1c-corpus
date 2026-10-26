int __thiscall sub_49C0B0(int this, char a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  if ( *(_DWORD *)(this + 880) )
    sub_5BE8AE(*(LPVOID *)(this + 880));
  v3 = *(_DWORD *)(this + 864);
  while ( v3 )
  {
    v4 = (_DWORD *)v3;
    v5 = *(_BYTE *)(v3 + 12) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_5BE8AE(v4);
  }
  *(_DWORD *)(this + 864) = 0;
  *(_DWORD *)(this + 868) = 0;
  *(_DWORD *)(this + 872) = 0;
  *(_DWORD *)(this + 876) = 0;
  sub_4A2330(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
