bool __thiscall sub_57B840(_DWORD *this, _DWORD *a2)
{
  int v2; // ecx

  v2 = this[7];
  if ( !v2 )
    return 0;
  return *(_DWORD *)(v2 + 4) == a2[1] && *(_WORD *)(v2 + 2) == HIWORD(*a2)
      || *(_DWORD *)(v2 + 20) == a2[1] && *(_WORD *)(v2 + 18) == HIWORD(*a2);
}

