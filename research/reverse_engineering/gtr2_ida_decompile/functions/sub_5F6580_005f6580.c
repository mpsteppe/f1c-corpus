int __thiscall sub_5F6580(int this, const char *a2, int a3, const char *a4, const char *a5)
{
  signed int v6; // edi
  void *v7; // eax

  if ( a4 )
    sub_5D8EF0(this + 268, a4, 63);
  if ( a2 )
    sub_5D8EF0(this + 204, a2, 63);
  *(_DWORD *)(this + 336) = a3;
  if ( a5 )
  {
    v6 = strlen(a5);
    if ( *(_DWORD *)(this + 332) )
      j__free(*(void **)(this + 332));
    v7 = operator new(v6 + 1);
    *(_DWORD *)(this + 332) = v7;
    sub_5D8EF0((int)v7, a5, v6);
  }
  return 0;
}
