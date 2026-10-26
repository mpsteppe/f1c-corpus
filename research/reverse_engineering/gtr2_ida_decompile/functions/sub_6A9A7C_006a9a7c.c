int __thiscall sub_6A9A7C(_DWORD *this, int a2, unsigned int a3, int a4, unsigned int a5, int a6)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // edi
  unsigned int v11; // ebx
  bool v12; // zf
  _DWORD *v13; // esi
  int *v14; // esi
  int v15; // eax
  unsigned int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  unsigned int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]

  v6 = 0;
  v21 = 0;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(a2 + 4 * v6);
    v19 = v7;
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 12) >= a5 )
        break;
    }
LABEL_25:
    v6 = ++v21;
    if ( v21 >= a3 )
      return 0;
  }
  v8 = 0;
  v22 = 1;
  v18 = 0;
  if ( !a5 )
    return *(_DWORD *)(a2 + 4 * v21);
  v20 = this[5];
  do
  {
    v9 = *(_DWORD *)(a4 + 4 * v8);
    v10 = *(_DWORD *)(v20 + 4 * v9);
    v11 = 0;
    if ( a6 )
    {
      v12 = *(_DWORD *)(v7 + 12) == 0;
      if ( !*(_DWORD *)(v7 + 12) )
        goto LABEL_21;
      v13 = *(_DWORD **)(v7 + 16);
      do
      {
        if ( *v13 == v9 )
          break;
        if ( *v13 == *(_DWORD *)(v10 + 56) )
          break;
        ++v11;
        ++v13;
      }
      while ( v11 < *(_DWORD *)(v7 + 12) );
    }
    else
    {
      v12 = *(_DWORD *)(v7 + 12) == 0;
      if ( !*(_DWORD *)(v7 + 12) )
        goto LABEL_21;
      v14 = *(int **)(v7 + 16);
      do
      {
        v15 = *v14;
        if ( *v14 == v9 && !*(_DWORD *)(v10 + 60) )
          break;
        if ( v15 == *(_DWORD *)(v10 + 56) )
        {
          v7 = v19;
          if ( !*(_DWORD *)(*(_DWORD *)(v20 + 4 * v15) + 60) )
            break;
        }
        ++v11;
        ++v14;
      }
      while ( v11 < *(_DWORD *)(v7 + 12) );
    }
    v12 = v11 == *(_DWORD *)(v7 + 12);
LABEL_21:
    if ( v12 )
      v22 = 0;
    v8 = ++v18;
  }
  while ( v18 < a5 );
  if ( !v22 )
    goto LABEL_25;
  return *(_DWORD *)(a2 + 4 * v21);
}
