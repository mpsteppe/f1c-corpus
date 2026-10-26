int __thiscall sub_666F65(_DWORD *this, _DWORD *a2, unsigned int *a3, unsigned int a4)
{
  unsigned int *v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // ecx
  unsigned int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int result; // eax
  int v14; // [esp+14h] [ebp-8h]
  unsigned int v15; // [esp+18h] [ebp-4h]

  v14 = 1;
  if ( a4 )
  {
    v5 = a3;
    v15 = a4;
    do
    {
      v6 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * *v5);
      if ( v6[13] != -1 )
      {
        do
        {
          if ( v6[2] != -1 )
            break;
          v7 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * v6[13]);
          if ( !v7[24] )
          {
            v7[24] = v6[24];
            v7[25] = v6[25];
          }
          *v5 = v6[13];
          v6 = v7;
        }
        while ( v7[13] != -1 );
      }
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this[2] + 16) + 4 * v6[1]) + 5) & 1) == 0 || v6[2] != -1 )
        v14 = 0;
      ++v5;
      --v15;
    }
    while ( v15 );
  }
  v8 = 0;
  if ( !a2 || !v14 )
    return 0;
  if ( !a4 )
  {
LABEL_17:
    result = sub_666E91(this, a2, a3, *(_DWORD *)(this[2] + 120), 1, 1, 0, 0);
    if ( result < 0 )
      return result;
    return 0;
  }
  while ( 1 )
  {
    v9 = this[2];
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 20) + 4 * a3[v8]);
    v11 = sub_681AAA(*(_DWORD *)(v9 + 120), 0, 0, *(double *)(v10 + 32));
    a3[v8] = v11;
    if ( v11 == -1 )
      return -2147024882;
    v12 = *(_DWORD *)(*(_DWORD *)(this[2] + 20) + 4 * v11);
    *(_DWORD *)(v12 + 96) = *(_DWORD *)(v10 + 96);
    ++v8;
    *(_DWORD *)(v12 + 100) = *(_DWORD *)(v10 + 100);
    if ( v8 >= a4 )
      goto LABEL_17;
  }
}
