_DWORD *__thiscall sub_67FA85(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = (_DWORD *)sub_65B229(24);
  if ( v2 )
    v3 = sub_67EDA4(v2);
  else
    v3 = 0;
  if ( v3
    && ((v3[5] = this[5], !this[2])
     || (v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[2] + 4))(this[2]), (v3[2] = v4) != 0))
    && (!this[3] || (v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[3] + 4))(this[3]), (v3[3] = v5) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
