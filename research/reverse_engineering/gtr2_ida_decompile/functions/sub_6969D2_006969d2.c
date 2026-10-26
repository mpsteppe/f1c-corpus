int __thiscall sub_6969D2(void *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v7; // edx
  int v9; // eax
  int v10; // ecx
  _DWORD v11[3]; // [esp+8h] [ebp-1Ch] BYREF
  _DWORD v12[4]; // [esp+14h] [ebp-10h] BYREF

  v5 = *(_DWORD *)(a2 + 28);
  v12[3] = this;
  if ( (a3 == 0) != (v5 == 0) )
    return -1;
  if ( a3 )
  {
    if ( sub_6460B4(*(const char **)(v5 + 24), 0, v12) < 0 || sub_6460B4(*(const char **)(a3 + 24), 0, v11) < 0 )
    {
      if ( strcmp(*(const char **)(a3 + 24), *(const char **)(*(_DWORD *)(a2 + 28) + 24)) )
        return -1;
    }
    else if ( v12[1] != v11[1] )
    {
      return -1;
    }
  }
  v7 = *(_DWORD *)(a2 + 36);
  while ( v7 )
  {
    if ( !a4 )
      return -1;
    v9 = *(_DWORD *)(*(_DWORD *)(v7 + 8) + 24);
    v10 = *(_DWORD *)(*(_DWORD *)(a4 + 8) + 24);
    if ( *(_DWORD *)(v9 + 28) != *(_DWORD *)(v10 + 28) || !sub_695259(*(_DWORD **)(v9 + 32), *(_DWORD **)(v10 + 32)) )
      return -1;
    do
      v7 = *(_DWORD *)(v7 + 12);
    while ( v7 && *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4) != 6 );
    do
      a4 = *(_DWORD *)(a4 + 12);
    while ( a4 && *(_DWORD *)(*(_DWORD *)(a4 + 8) + 4) != 6 );
  }
  if ( a4 )
    return -1;
  return 0;
}
