_DWORD *__thiscall sub_67FB62(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (_DWORD *)sub_65B229(36);
  if ( v2 )
    v3 = sub_67F007(v2);
  else
    v3 = 0;
  if ( !v3 )
    return 0;
  v3[4] = *(_DWORD *)(this + 16);
  v3[5] = *(_DWORD *)(this + 20);
  if ( *(_DWORD *)(this + 24) )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 24) + 4))(*(_DWORD *)(this + 24));
    v3[6] = v4;
    if ( !v4 )
      return 0;
  }
  if ( (!*(_DWORD *)(this + 28)
     || (v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 28) + 4))(*(_DWORD *)(this + 28)), (v3[7] = v5) != 0))
    && (!*(_DWORD *)(this + 32)
     || (v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 32) + 4))(*(_DWORD *)(this + 32)), (v3[8] = v6) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
