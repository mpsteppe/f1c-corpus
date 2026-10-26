char __thiscall sub_4D80F0(int this)
{
  float **v1; // eax
  int v2; // edx
  float *i; // eax
  int v4; // eax
  float **v5; // eax
  int v6; // eax
  int v7; // eax
  _DWORD **v8; // eax

  if ( *(int *)(this + 860) <= 0 )
    return 0;
  v1 = *(float ***)(this + 848);
  v2 = 0;
  *(_DWORD *)(this + 856) = v1;
  if ( v1 )
  {
    for ( i = *v1; i; i = *v5 )
    {
      if ( *i > (double)*(float *)(this + 2076) )
        break;
      v4 = *(_DWORD *)(this + 856);
      ++v2;
      if ( v4 )
        *(_DWORD *)(this + 856) = *(_DWORD *)(v4 + 4);
      v5 = *(float ***)(this + 856);
      if ( !v5 )
        break;
    }
  }
  v6 = *(_DWORD *)(this + 860);
  if ( v2 != v6 )
  {
    if ( v2 >= 0 && v2 < *(_DWORD *)(this + 860) )
    {
      for ( *(_DWORD *)(this + 856) = *(_DWORD *)(this + 848); v2 > 0; *(_DWORD *)(this + 856) = *(_DWORD *)(v7 + 4) )
      {
        v7 = *(_DWORD *)(this + 856);
        if ( !v7 )
          break;
        --v2;
      }
      goto LABEL_19;
    }
    goto LABEL_18;
  }
  if ( v6 <= 0 )
  {
LABEL_18:
    *(_DWORD *)(this + 856) = 0;
    goto LABEL_19;
  }
  *(_DWORD *)(this + 856) = *(_DWORD *)(this + 848);
LABEL_19:
  v8 = *(_DWORD ***)(this + 856);
  if ( !v8 )
  {
    *(_DWORD *)(this + 2076) = MEMORY[0];
    return 0;
  }
  *(_DWORD *)(this + 2076) = **v8;
  return 0;
}
