char __thiscall sub_49DF50(_BYTE *this)
{
  int *v2; // edi
  char result; // al
  int v4; // eax
  bool v5; // dl
  char v6; // dl
  char v7; // [esp+8h] [ebp-4h]

  v2 = (int *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this);
  if ( !v2 )
    return (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 36))(this, 1);
  (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
  v4 = *v2;
  if ( this[268] )
    v5 = v4 == 0;
  else
    v5 = v4 != 0;
  v7 = v5;
  result = ((int (__thiscall *)(_BYTE *))loc_49D980)(this);
  if ( result != v6 )
    return sub_49D9C0(this, v7);
  return result;
}
