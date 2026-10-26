// f1c  0x00465c30  size=59
char __thiscall sub_465C30(int *this, _DWORD *a2)
{
  int *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  v2 = *(int **)(*this + 58824);
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !v3 )
    return 0;
  *a2 = v3;
  v4 = *this;
  v5 = *(_DWORD *)(*this + 58824);
  v6 = v4 + 58816;
  if ( v5 )
    *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 4);
  return 1;
}
