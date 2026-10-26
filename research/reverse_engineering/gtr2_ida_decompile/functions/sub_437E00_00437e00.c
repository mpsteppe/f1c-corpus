void __thiscall sub_437E00(char *this)
{
  void *v2; // edi
  void *v3; // esi

  sub_615860(WindowName);
  sub_615860(WindowName);
  sub_615860(WindowName);
  this[24] = 0;
  sub_437400((int *)this + 7);
  this[44] = 0;
  sub_525140(this + 48);
  sub_525140(this + 48);
  sub_437400((int *)this + 7);
  v2 = (void *)*((_DWORD *)this + 4);
  if ( v2 )
    j_j__free(v2);
  if ( *((_DWORD *)this + 2) )
    j_j__free(*((void **)this + 2));
  v3 = *(void **)this;
  if ( v3 )
    j_j__free(v3);
}
