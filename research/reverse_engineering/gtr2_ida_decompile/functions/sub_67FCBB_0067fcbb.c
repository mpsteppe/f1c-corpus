int __thiscall sub_67FCBB(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // esi
  int v4; // eax

  v2 = (_DWORD *)sub_65B229(24);
  if ( v2 )
    v3 = sub_67F23A(v2);
  else
    v3 = 0;
  if ( v3
    && ((*(_DWORD *)(v3 + 20) = this[5], !this[4])
     || (v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[4] + 4))(this[4]), (*(_DWORD *)(v3 + 16) = v4) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
