char __thiscall sub_46D970(int *this, _DWORD *a2)
{
  int *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  v2 = *(int **)(*this + 14280);
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !v3 )
    return 0;
  *a2 = v3;
  v4 = *this;
  v5 = *(_DWORD *)(*this + 14280);
  v6 = v4 + 14272;
  if ( v5 )
    *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 4);
  return 1;
}
