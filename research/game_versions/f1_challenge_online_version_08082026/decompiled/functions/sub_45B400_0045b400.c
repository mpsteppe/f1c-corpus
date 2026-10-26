int __thiscall sub_45B400(_DWORD *this)
{
  _DWORD *v1; // esi

  v1 = this + 1;
  *this = &off_59F080;
  sub_4DD000(this + 1);
  if ( v1[10] )
    sub_587BCF((LPVOID)v1[10]);
  return sub_4DCD10(v1);
}
