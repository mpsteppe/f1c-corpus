char __thiscall sub_410520(int this)
{
  int *v1; // eax
  char v2; // dl
  int i; // eax
  int v4; // eax
  int *v5; // eax

  v1 = *(int **)(this + 12);
  v2 = 0;
  *(_DWORD *)(this + 20) = v1;
  if ( v1 )
  {
    for ( i = *v1; i; i = *v5 )
    {
      if ( !sub_410500((_BYTE *)this, i) )
        ++v2;
      v4 = *(_DWORD *)(this + 20);
      if ( !v4 )
        break;
      v5 = *(int **)(v4 + 4);
      *(_DWORD *)(this + 20) = v5;
      if ( !v5 )
        break;
    }
  }
  return v2;
}
