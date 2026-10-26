// f1c  0x005864e0  size=32
char __thiscall sub_5864E0(_BYTE *this)
{
  char result; // al
  void *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      sub_5867B0(*(_DWORD *)this);
      return sub_587BCF(v2);
    }
  }
  return result;
}
