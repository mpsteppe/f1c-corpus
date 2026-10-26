char __thiscall sub_4CDB30(_DWORD *this)
{
  int *v2; // edi
  char result; // al
  int v4; // eax
  char v5; // cl

  v2 = (int *)(*(int (__thiscall **)(_DWORD *))(*this + 164))(this);
  if ( !v2 )
    return (*(int (__thiscall **)(_DWORD *, int))(*this + 36))(this, 1);
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 36))(this, 0);
  v4 = *v2;
  if ( *((_BYTE *)this + 276) )
    v5 = v4 == 0;
  else
    v5 = v4 != 0;
  result = this[33] == 1 || this[33] == 3;
  if ( result != v5 )
    return sub_4CD740(this, v5);
  return result;
}
