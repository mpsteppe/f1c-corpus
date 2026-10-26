_DWORD *__thiscall sub_6801A2(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = (_DWORD *)sub_65B229(24);
  if ( v2 )
    v3 = sub_67F96B(v2);
  else
    v3 = 0;
  if ( v3
    && (!this[4] || (v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[4] + 4))(this[4]), (v3[4] = v4) != 0))
    && (!this[5] || (v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[5] + 4))(this[5]), (v3[5] = v5) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
