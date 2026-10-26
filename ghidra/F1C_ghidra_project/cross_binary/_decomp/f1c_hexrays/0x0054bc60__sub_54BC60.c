// f1c  0x0054bc60  size=109
void __thiscall sub_54BC60(int this, const char *a2, _DWORD *a3)
{
  if ( *(_DWORD *)(this + 68) )
    sub_54BC60(a2, a3);
  if ( *(_DWORD *)(this + 76) )
    sub_54BC60(a2, a3);
  if ( !*a3 && !strcmp((const char *)this, a2) )
    *a3 = this;
}
