int __thiscall sub_47EFE0(_DWORD **this)
{
  int v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 14);
  if ( v2 )
    v4 = sub_49FB30(v2) == 0;
  if ( !*((_BYTE *)this + 268) && !strlen(&byte_765558) )
    v4 = 1;
  ((void (__thiscall *)(_DWORD **, bool))(*this)[9])(this, v4);
  return 0;
}
