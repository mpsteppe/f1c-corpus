int __thiscall sub_614530(int this, int Offset)
{
  int v2; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // esi

  v2 = *(_DWORD *)(this + 20);
  if ( !v2 )
    return fseek(*(FILE **)(this + 4), Offset, 1);
  if ( v2 != 5 )
    return sub_62AFD0(*(_DWORD *)(this + 4), Offset, 1);
  *(_DWORD *)(*(_DWORD *)(this + 4) + 24) += Offset;
  v4 = *(_DWORD *)(this + 4);
  v5 = *(_DWORD *)(this + 84);
  v6 = *(_DWORD *)(v4 + 24);
  v7 = *(_DWORD *)(v4 + 20);
  if ( v6 >= v5 )
  {
    if ( v6 > v7 )
      *(_DWORD *)(v4 + 24) = v7;
    return 0;
  }
  else
  {
    *(_DWORD *)(v4 + 24) = v5;
    return 0;
  }
}
