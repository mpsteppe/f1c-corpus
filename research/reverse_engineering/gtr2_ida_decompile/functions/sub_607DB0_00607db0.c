char __thiscall sub_607DB0(float *this, int a2)
{
  int *v2; // eax
  int v4; // esi
  int v5; // eax
  int *v6; // eax

  v2 = *(int **)(a2 + 532);
  *(_DWORD *)(a2 + 540) = v2;
  if ( v2 )
  {
    v4 = *v2;
    if ( *v2 )
    {
      while ( sqrt(sub_5D7980(this + 12, (float *)(v4 + 228))) + *(float *)(v4 + 20) <= this[5] )
      {
        if ( sub_607CE0(this, (float *)(v4 + 228)) )
          return 1;
        v5 = *(_DWORD *)(a2 + 540);
        if ( v5 )
          *(_DWORD *)(a2 + 540) = *(_DWORD *)(v5 + 4);
        v6 = *(int **)(a2 + 540);
        if ( v6 )
        {
          v4 = *v6;
          if ( *v6 )
            continue;
        }
        return 0;
      }
    }
  }
  return 0;
}
