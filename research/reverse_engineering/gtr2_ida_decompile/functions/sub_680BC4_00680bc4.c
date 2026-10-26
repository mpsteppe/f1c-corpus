_DWORD *__thiscall sub_680BC4(int this)
{
  _DWORD *v2; // eax
  _DWORD *result; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // esi
  char *v7; // edi
  int v8; // eax
  unsigned int v9; // [esp+4h] [ebp-8h]
  _DWORD *v10; // [esp+8h] [ebp-4h]

  v2 = (_DWORD *)sub_65B229(96);
  if ( v2 )
  {
    result = sub_680AB7(v2);
    v10 = result;
  }
  else
  {
    v10 = 0;
    result = 0;
  }
  if ( !result )
    return result;
  qmemcpy(result + 4, (const void *)(this + 16), 0x2Cu);
  result[21] = *(_DWORD *)(this + 84);
  result[22] = *(_DWORD *)(this + 88);
  if ( *(_DWORD *)(this + 60) )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 60) + 4))(*(_DWORD *)(this + 60));
    v10[15] = v4;
    if ( !v4 )
      return 0;
    result = v10;
  }
  if ( !*(_DWORD *)(this + 64) )
    goto LABEL_11;
  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 64) + 4))(*(_DWORD *)(this + 64));
  v10[16] = v5;
  if ( !v5 )
    return 0;
  result = v10;
LABEL_11:
  v9 = 0;
  v6 = (_DWORD *)(this + 68);
  v7 = (char *)result - this;
  do
  {
    if ( *v6 )
    {
      v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v6 + 4))(*v6);
      *(_DWORD *)((char *)v6 + (_DWORD)v7) = v8;
      if ( !v8 )
        return 0;
      result = v10;
    }
    ++v9;
    ++v6;
  }
  while ( v9 < 4 );
  return result;
}
