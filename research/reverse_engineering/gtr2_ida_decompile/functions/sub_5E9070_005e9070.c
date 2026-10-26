int __thiscall sub_5E9070(int this, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // edi
  int v6; // eax
  int *v7; // eax
  const char *retaddr; // [esp+10h] [ebp+0h]

  v4 = this + 36;
  v5 = sub_47F6E0((void *)(this + 36), a3);
  if ( !v5 )
    return 0;
  while ( (a3 & *(_DWORD *)v5) != 0 || strcmp((const char *)(v5 + 4), retaddr + 4) )
  {
    v6 = *(_DWORD *)(v4 + 8);
    if ( v6 )
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(v6 + 4);
    v7 = *(int **)(v4 + 8);
    if ( v7 )
    {
      v5 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  return v5;
}
