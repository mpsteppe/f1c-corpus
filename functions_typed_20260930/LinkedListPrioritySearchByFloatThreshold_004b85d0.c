char __thiscall sub_4B85D0(int this)
{
  int v1; // eax
  int v2; // esi
  float **v3; // eax
  int v4; // edx
  float *v5; // eax
  int v6; // eax
  float **v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  _DWORD **v11; // eax

  v1 = *(_DWORD *)(this + 1740);
  if ( v1 <= 0 )
    return 0;
  v2 = v1 - 1;
  v3 = *(float ***)(this + 1732);
  v4 = v2;
  *(_DWORD *)(this + 1736) = v3;
  if ( v3 && (v5 = *v3) != 0 )
  {
    while ( *(float *)(this + 3896) - 2.0 <= *v5 )
    {
      v6 = *(_DWORD *)(this + 1736);
      --v4;
      if ( v6 )
        *(_DWORD *)(this + 1736) = *(_DWORD *)(v6 + 8);
      v7 = *(float ***)(this + 1736);
      if ( v7 )
      {
        v5 = *v7;
        if ( v5 )
          continue;
      }
      goto LABEL_9;
    }
    if ( v4 >= 0 && v4 < *(_DWORD *)(this + 1740) )
    {
      for ( *(_DWORD *)(this + 1736) = *(_DWORD *)(this + 1728); v4 > 0; *(_DWORD *)(this + 1736) = *(_DWORD *)(v10 + 4) )
      {
        v10 = *(_DWORD *)(this + 1736);
        if ( !v10 )
          break;
        --v4;
      }
      goto LABEL_22;
    }
  }
  else
  {
LABEL_9:
    v8 = v2;
    if ( v2 >= 0 && v2 < *(_DWORD *)(this + 1740) )
    {
      *(_DWORD *)(this + 1736) = *(_DWORD *)(this + 1728);
      if ( v2 > 0 )
      {
        do
        {
          v9 = *(_DWORD *)(this + 1736);
          if ( !v9 )
            break;
          --v8;
          *(_DWORD *)(this + 1736) = *(_DWORD *)(v9 + 4);
        }
        while ( v8 > 0 );
      }
      goto LABEL_22;
    }
  }
  *(_DWORD *)(this + 1736) = 0;
LABEL_22:
  v11 = *(_DWORD ***)(this + 1736);
  if ( !v11 )
  {
    *(_DWORD *)(this + 3896) = MEMORY[0];
    return 0;
  }
  *(_DWORD *)(this + 3896) = **v11;
  return 0;
}

