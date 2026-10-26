int __thiscall sub_4A79D0(int this, char a2)
{
  int v3; // esi
  _DWORD *v4; // esi
  void *v5; // ebx

  v3 = this + 48;
  sub_506C70(this + 48);
  if ( *(_DWORD *)(v3 + 48) )
    sub_5BE8AE(*(LPVOID *)(v3 + 48));
  if ( *(_DWORD *)(v3 + 40) )
    sub_5BE8AE(*(LPVOID *)(v3 + 40));
  sub_506920(v3);
  v4 = *(_DWORD **)(this + 28);
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[1];
    sub_4A8310(v5);
    sub_5BE8AE(v5);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  if ( *(_DWORD *)(this + 16) )
    sub_5BE8AE(*(LPVOID *)(this + 16));
  if ( *(_DWORD *)(this + 8) )
    sub_5BE8AE(*(LPVOID *)(this + 8));
  if ( *(_DWORD *)this )
    sub_5BE8AE(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
