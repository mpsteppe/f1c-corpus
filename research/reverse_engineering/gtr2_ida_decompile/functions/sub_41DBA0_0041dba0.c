double __thiscall sub_41DBA0(float *this)
{
  int *v1; // eax
  int i; // eax
  int v3; // eax
  int *v4; // eax

  this[15] = 0.0;
  v1 = (int *)*((_DWORD *)this + 9);
  *((_DWORD *)this + 11) = v1;
  if ( v1 )
  {
    for ( i = *v1; i; i = *v4 )
    {
      this[15] = *(float *)(i + 72) + this[15];
      v3 = *((_DWORD *)this + 11);
      if ( !v3 )
        break;
      v4 = *(int **)(v3 + 4);
      *((_DWORD *)this + 11) = v4;
      if ( !v4 )
        break;
    }
  }
  return this[15];
}
