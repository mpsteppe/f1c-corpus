char __thiscall sub_4CD8A0(_DWORD *this, int a2)
{
  _DWORD *v4; // esi
  char result; // al
  int v6; // eax
  _DWORD *i; // esi
  char v8; // [esp+10h] [ebp+4h]

  v4 = (_DWORD *)this[36];
  for ( *((_BYTE *)this + 100) = a2; v4; v4 = (_DWORD *)v4[35] )
    (*(void (__thiscall **)(_DWORD *, int))(*v4 + 36))(v4, a2);
  if ( (_BYTE)a2 )
  {
    result = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
  }
  else
  {
    v6 = this[33];
    if ( v6 < 2 || (v8 = 1, v6 > 3) )
      v8 = 0;
    result = sub_4CD800(this, v8);
  }
  for ( i = (_DWORD *)this[36]; i; i = (_DWORD *)i[35] )
    result = (*(int (__thiscall **)(_DWORD *, int))(*i + 36))(i, a2);
  return result;
}
