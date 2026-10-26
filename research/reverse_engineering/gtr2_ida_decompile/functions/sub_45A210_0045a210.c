int __thiscall sub_45A210(int this)
{
  char *v2; // eax
  char *v3; // edi
  int result; // eax

  if ( *(_DWORD *)this )
  {
    j_j__free(*(void **)this);
    *(_DWORD *)this = 0;
  }
  v2 = *(char **)(this + 4);
  if ( v2 )
  {
    v3 = v2 - 4;
    `eh vector destructor iterator'(v2, 0x10u, *((_DWORD *)v2 - 1), nullsub_7);
    j_j__free(v3);
    *(_DWORD *)(this + 4) = 0;
  }
  *(double *)(this + 8) = 0.0;
  result = 0;
  *(double *)(this + 24) = 0.0;
  *(double *)(this + 16) = 0.0;
  memset((void *)(this + 40), 0, 0x1000u);
  return result;
}
