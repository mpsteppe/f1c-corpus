_DWORD *__thiscall sub_67FFE8(int this)
{
  _DWORD *v2; // eax
  _DWORD *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // [esp+4h] [ebp-4h]

  v2 = (_DWORD *)sub_65B229(80);
  if ( v2 )
  {
    result = sub_67F5C5(v2);
    v7 = result;
  }
  else
  {
    v7 = 0;
    result = 0;
  }
  if ( !result )
    return result;
  result[5] = *(_DWORD *)(this + 20);
  result[6] = *(_DWORD *)(this + 24);
  result[7] = *(_DWORD *)(this + 28);
  result[10] = *(_DWORD *)(this + 40);
  qmemcpy(result + 12, (const void *)(this + 48), 0x20u);
  if ( *(_DWORD *)(this + 16) )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 16) + 4))(*(_DWORD *)(this + 16));
    v7[4] = v4;
    if ( !v4 )
      return 0;
    result = v7;
  }
  if ( *(_DWORD *)(this + 32) )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 32) + 4))(*(_DWORD *)(this + 32));
    v7[8] = v5;
    if ( v5 )
    {
      result = v7;
      goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  if ( !*(_DWORD *)(this + 36) )
    return result;
  v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 36) + 4))(*(_DWORD *)(this + 36));
  v7[9] = v6;
  if ( !v6 )
    return 0;
  return v7;
}
