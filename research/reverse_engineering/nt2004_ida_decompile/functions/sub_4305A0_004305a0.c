double __thiscall sub_4305A0(int *this, int a2, int a3)
{
  int v3; // esi
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // eax

  if ( a2 < 0 )
    return 0.0;
  if ( a2 >= *this )
    return 0.0;
  if ( a3 < 0 )
    return 0.0;
  if ( a3 >= this[2] )
    return 0.0;
  v3 = this[1];
  v4 = *(_DWORD *)(v3 + 8 * a2);
  v5 = v3 + 8 * a2;
  if ( v4 <= 0 )
    return 0.0;
  v6 = this[3];
  v7 = *(_DWORD *)(v6 + 8 * a3);
  v8 = v6 + 8 * a3;
  if ( v7 <= 0 )
    return 0.0;
  v9 = this[4];
  if ( v9 <= 0 )
    return 0.0;
  else
    return (double)(this[5] * *(_DWORD *)(v5 + 4) * *(_DWORD *)(v8 + 4)) / (double)(v4 * v7 * v9);
}
