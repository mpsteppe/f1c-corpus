int __thiscall sub_5FDD80(int *this, int a2)
{
  _DWORD *v3; // eax
  int *v4; // edi

  if ( !a2 )
    return 0;
  sub_5FDBD0(a2, (__int32)this);
  v3 = (_DWORD *)this[165];
  if ( !v3 )
    goto LABEL_6;
  while ( !*v3 || *v3 != a2 )
  {
    v3 = (_DWORD *)v3[1];
    if ( !v3 )
      goto LABEL_6;
  }
  if ( !*v3 )
  {
LABEL_6:
    v4 = this + 169;
    if ( sub_59D540(this + 169, a2) || (v4 = this + 173, sub_59D540(this + 173, a2)) )
      sub_5DB730(v4, a2, 1);
    return 0;
  }
  sub_5DB730(this + 165, a2, 1);
  return 0;
}
