_DWORD *__thiscall sub_67FF63(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = (_DWORD *)sub_65B229(36);
  if ( v2 )
    v3 = sub_67F53B(v2);
  else
    v3 = 0;
  if ( !v3 )
    return 0;
  v3[4] = *(_DWORD *)(this + 16);
  if ( *(_DWORD *)(this + 20) )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 20) + 4))(*(_DWORD *)(this + 20));
    v3[5] = v4;
    if ( !v4 )
      return 0;
  }
  if ( (!*(_DWORD *)(this + 24)
     || (v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 24) + 4))(*(_DWORD *)(this + 24)), (v3[6] = v5) != 0))
    && (!*(_DWORD *)(this + 28)
     || (v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 28) + 4))(*(_DWORD *)(this + 28)), (v3[7] = v6) != 0))
    && (!*(_DWORD *)(this + 32)
     || (v7 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 32) + 4))(*(_DWORD *)(this + 32)), (v3[8] = v7) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
