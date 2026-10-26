int __thiscall sub_6A0E46(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // eax
  int v7; // ebx
  int result; // eax
  int v9; // eax

  v4 = *(_DWORD *)(a2 + 4);
  if ( v4 != this[32] && v4 != this[33] )
    return sub_6866FF(this, a2, a3, a4);
  v6 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(a2 + 108));
  v7 = sub_6C6925(&off_91A0A8, v6);
  if ( *(_DWORD *)(v7 + 16) == -1 )
    return sub_6866FF(this, a2, a3, a4);
  v9 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, *(_DWORD *)(a2 + 108));
  result = sub_632041(a3, a4, "%s%s%u", **(const char ***)(this[4] + 4 * *(_DWORD *)(a2 + 4)), *(const char **)v7, v9);
  *(_BYTE *)(a3 + a4 - 1) = 0;
  return result;
}
