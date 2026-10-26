int __thiscall sub_56EC70(_DWORD *this, int a2)
{
  int v3; // ecx
  int i; // edx
  int v5; // edi
  int j; // edx
  int v7; // edi
  int v8; // edx
  int result; // eax

  v3 = this[12];
  if ( v3 )
    return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 24))(v3, a2);
  for ( i = 0; i < this[8]; ++i )
  {
    v5 = *(_DWORD *)(this[10] + 4 * a2);
    *(_DWORD *)(v5 + 8 * i) = 0;
    *(_DWORD *)(v5 + 8 * i + 4) = 0;
  }
  for ( j = 0; j < this[8]; ++j )
  {
    v7 = *(_DWORD *)(this[10] + 4 * j);
    *(_DWORD *)(v7 + 8 * a2) = 0;
    *(_DWORD *)(v7 + 8 * a2 + 4) = 0;
  }
  v8 = *(_DWORD *)(this[10] + 4 * a2);
  *(_DWORD *)(v8 + 8 * a2) = 0;
  *(_DWORD *)(v8 + 8 * a2 + 4) = 1072693248;
  result = this[11];
  *(_DWORD *)(result + 8 * a2) = 0;
  *(_DWORD *)(result + 8 * a2 + 4) = 0;
  return result;
}

