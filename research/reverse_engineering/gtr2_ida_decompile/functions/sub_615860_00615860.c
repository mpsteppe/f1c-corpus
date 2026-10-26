int __thiscall sub_615860(int this, const char *a2)
{
  signed int v4; // edi

  if ( !a2 )
    return -1;
  v4 = strlen(a2);
  if ( !*(_DWORD *)this )
    goto LABEL_6;
  if ( *(_DWORD *)(this + 4) < v4 )
  {
    j__free(*(void **)this);
LABEL_6:
    *(_DWORD *)this = operator new(v4 + 1);
    *(_DWORD *)(this + 4) = v4;
  }
  strcpy(*(char **)this, a2);
  return 0;
}
