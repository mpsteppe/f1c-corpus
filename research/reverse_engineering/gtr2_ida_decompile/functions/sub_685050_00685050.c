int __thiscall sub_685050(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // eax

  v5 = a2 + 4 * (a4 + 4 * a3);
  if ( *(_DWORD *)v5 == -1 )
  {
    v6 = 4 * a5;
    v7 = *(_DWORD *)(4 * a5 + this[5]);
    if ( *(_DWORD *)(v7 + 12) == -1 )
    {
      *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 12) = a3;
      *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 16) = a4;
      v8 = a5;
    }
    else
    {
      v8 = sub_681AAA(this, this[30], a3, a4, *(double *)(v7 + 32));
    }
    *(_DWORD *)v5 = v8;
  }
  return *(_DWORD *)v5;
}
