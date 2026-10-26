char __thiscall sub_522830(int this)
{
  float **v2; // eax
  void *v3; // ecx
  int v4; // edx
  float *i; // eax
  int v6; // eax
  float **v7; // eax
  int **v8; // ecx
  int *v10; // eax

  if ( *(int *)(this + 1756) <= 0 )
    return 0;
  v2 = *(float ***)(this + 1744);
  v3 = (void *)(this + 1744);
  v4 = 0;
  *(_DWORD *)(this + 1752) = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v7 )
    {
      if ( *(float *)(this + 2892852) + 2.0 < *i )
        break;
      v6 = *(_DWORD *)(this + 1752);
      ++v4;
      if ( v6 )
        *(_DWORD *)(this + 1752) = *(_DWORD *)(v6 + 4);
      v7 = *(float ***)(this + 1752);
      if ( !v7 )
        break;
    }
  }
  if ( v4 != *(_DWORD *)(this + 1756) )
  {
    v10 = (int *)sub_47F6E0(v3, v4);
    sub_520FF0((_DWORD *)this, *v10);
    return 0;
  }
  if ( *(int *)(this + 1756) <= 0 )
    *(_DWORD *)(this + 1752) = 0;
  else
    *(_DWORD *)(this + 1752) = *(_DWORD *)(this + 1744);
  v8 = *(int ***)(this + 1752);
  if ( v8 )
    sub_520FF0((_DWORD *)this, **v8);
  else
    sub_520FF0((_DWORD *)this, MEMORY[0]);
  return 0;
}
