int __thiscall sub_496840(_DWORD *this)
{
  int v2; // edi
  int *v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = 0;
  this[3] = this[1];
  while ( 1 )
  {
    v3 = (int *)this[3];
    if ( !v3 )
      break;
    v4 = *v3;
    if ( !v4 )
      break;
    v2 += ShortComputation_58d0(v4);
    v5 = this[3];
    if ( v5 )
      this[3] = *(_DWORD *)(v5 + 4);
  }
  return v2;
}

