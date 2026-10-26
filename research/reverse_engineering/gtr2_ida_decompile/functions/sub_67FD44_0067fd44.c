_DWORD *__thiscall sub_67FD44(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v2 = (_DWORD *)sub_65B229(64);
  if ( v2 )
    v3 = sub_67F351(v2);
  else
    v3 = 0;
  if ( !v3 )
    return 0;
  v3[4] = *(_DWORD *)(this + 16);
  v3[5] = *(_DWORD *)(this + 20);
  v3[6] = *(_DWORD *)(this + 24);
  v3[14] = *(_DWORD *)(this + 56);
  v3[15] = *(_DWORD *)(this + 60);
  if ( *(_DWORD *)(this + 28) )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 28) + 4))(*(_DWORD *)(this + 28));
    v3[7] = v4;
    if ( !v4 )
      return 0;
  }
  if ( *(_DWORD *)(this + 32) )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 32) + 4))(*(_DWORD *)(this + 32));
    v3[8] = v5;
    if ( !v5 )
      return 0;
  }
  if ( *(_DWORD *)(this + 36) )
  {
    v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 36) + 4))(*(_DWORD *)(this + 36));
    v3[9] = v6;
    if ( !v6 )
      return 0;
  }
  if ( *(_DWORD *)(this + 40) )
  {
    v7 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 40) + 4))(*(_DWORD *)(this + 40));
    v3[10] = v7;
    if ( !v7 )
      return 0;
  }
  if ( (!*(_DWORD *)(this + 44)
     || (v8 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 44) + 4))(*(_DWORD *)(this + 44)), (v3[11] = v8) != 0))
    && (!*(_DWORD *)(this + 48)
     || (v9 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 4))(*(_DWORD *)(this + 48)), (v3[12] = v9) != 0))
    && (!*(_DWORD *)(this + 52)
     || (v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 52) + 4))(*(_DWORD *)(this + 52)),
         (v3[13] = v10) != 0)) )
  {
    return v3;
  }
  else
  {
    return 0;
  }
}
