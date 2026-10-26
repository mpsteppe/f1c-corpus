_DWORD *__thiscall sub_67FB10(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = (_DWORD *)sub_65B229(32);
  if ( v2 )
    v3 = sub_67EF72(v2);
  else
    v3 = 0;
  if ( v3
    && ((v3[4] = this[4], v3[5] = this[5], v3[6] = this[6], !this[7])
     || (v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[7] + 4))(this[7]), (v3[7] = v4) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
