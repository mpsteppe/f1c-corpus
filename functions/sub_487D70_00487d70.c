char __thiscall sub_487D70(_BYTE *this)
{
  int *v2; // edi
  char result; // al
  int v4; // eax
  bool v5; // dl
  char v6; // dl
  char v7; // [esp+8h] [ebp-4h]

  v2 = (int *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
  if ( !v2 )
    return (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 56))(this, 1);
  (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 56))(this, 0);
  v4 = *v2;
  if ( this[228] )
    v5 = v4 == 0;
  else
    v5 = v4 != 0;
  v7 = v5;
  result = ShortComputation_7720(this);
  if ( result != v6 )
  {
    sub_487260(this, v7);
    return (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
  }
  return result;
}
