_DWORD *__thiscall sub_680C88(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = (_DWORD *)sub_65B229(44);
  if ( v2 )
    v3 = sub_680B47(v2);
  else
    v3 = 0;
  if ( !v3 )
    return 0;
  v3[4] = this[4];
  v3[5] = this[5];
  v3[6] = this[6];
  v3[7] = this[7];
  v3[8] = this[8];
  v3[9] = this[9];
  if ( !this[10] )
    return v3;
  v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[10] + 4))(this[10]);
  v3[10] = v4;
  if ( v4 )
    return v3;
  else
    return 0;
}
