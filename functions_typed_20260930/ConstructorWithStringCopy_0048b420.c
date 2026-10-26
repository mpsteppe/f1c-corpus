int __thiscall sub_48B420(int this, int a2, const char *a3, int a4, char a5, int a6, char a7)
{
  int v8; // eax

  ShortComputation_5e30((_DWORD *)this);
  v8 = a2;
  *(_DWORD *)this = &off_5ABED0;
  if ( !a2 )
    v8 = this + 230;
  *(_DWORD *)(this + 752) = v8;
  sub_48B4F0(this);
  if ( a4 > 0 )
    BoundedFieldSetter(a4);
  *(_DWORD *)(this + 764) = 0;
  if ( a3 && (int)strlen(a3) < a4 )
  {
    strcpy(*(char **)(this + 752), a3);
    strcpy((char *)(this + 487), a3);
  }
  *(_BYTE *)(this + 229) = a7;
  *(_BYTE *)(this + 226) = a5;
  *(_DWORD *)(this + 744) = a6;
  return this;
}

