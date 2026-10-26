int __thiscall sub_686341(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // ebx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int result; // eax
  int v13; // esi

  v4 = a3;
  while ( 1 )
  {
    v7 = *(_DWORD *)(this[6] + 4 * v4);
    v8 = *(_DWORD **)(this[5] + 4 * a2);
    if ( a4 && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v8[1]) + 4) & 2) != 0 )
    {
      v9 = *(_DWORD *)(v7 + 24);
      if ( v9 )
      {
        *(_DWORD *)(v9 + 4 * *(_DWORD *)(v7 + 20)) = v8[18];
        v4 = a3;
      }
      ++*(_DWORD *)(v7 + 20);
      v10 = *(_DWORD *)(this[6] + 4 * v8[18]);
      v11 = *(_DWORD *)(v10 + 32);
      if ( v11 )
        *(_DWORD *)(v11 + 4 * *(_DWORD *)(v10 + 28)) = v4;
      ++*(_DWORD *)(v10 + 28);
    }
    result = v8[2];
    if ( result != -1 )
      result = sub_686341(result, v4, 1);
    v13 = v8[5];
    if ( v13 == -1 )
      break;
    a4 = 1;
    a2 = v13;
  }
  return result;
}
