char __thiscall sub_5228F0(int this)
{
  int v2; // eax
  void *v3; // ecx
  int v4; // edi
  float **v5; // eax
  int v6; // edx
  float *v7; // eax
  int v8; // eax
  float **v9; // eax
  int *v10; // eax
  int *v12; // eax

  v2 = *(_DWORD *)(this + 1756);
  if ( v2 > 0 )
  {
    v3 = (void *)(this + 1744);
    v4 = v2 - 1;
    v5 = *(float ***)(this + 1748);
    v6 = v4;
    *(_DWORD *)(this + 1752) = v5;
    if ( !v5 || (v7 = *v5) == 0 )
    {
LABEL_9:
      v10 = (int *)sub_47F6E0(v3, v4);
      sub_520FF0((_DWORD *)this, *v10);
      return 0;
    }
    while ( *(float *)(this + 2892852) - 2.0 <= *v7 )
    {
      v8 = *(_DWORD *)(this + 1752);
      --v6;
      if ( v8 )
        *(_DWORD *)(this + 1752) = *(_DWORD *)(v8 + 8);
      v9 = *(float ***)(this + 1752);
      if ( v9 )
      {
        v7 = *v9;
        if ( v7 )
          continue;
      }
      goto LABEL_9;
    }
    v12 = (int *)sub_47F6E0(v3, v6);
    sub_520FF0((_DWORD *)this, *v12);
  }
  return 0;
}
