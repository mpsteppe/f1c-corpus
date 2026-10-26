// f1c  0x0057d890  size=60
char __thiscall sub_57D890(_DWORD *this, unsigned int a2, int a3)
{
  int v4; // ebx
  void *v5; // ecx
  _DWORD *v6; // eax

  v4 = sub_585770(this);
  if ( (unsigned int)sub_5871F0(a3) != v4 )
  {
    v5 = *(void **)(a3 + 28);
    if ( v5 )
    {
      v6 = sub_4B3DB0(v5);
      sub_57D6C0(this, a2, v6);
    }
  }
  return 0;
}
