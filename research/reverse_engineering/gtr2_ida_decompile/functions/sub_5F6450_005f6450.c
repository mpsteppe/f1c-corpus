int __thiscall sub_5F6450(int *this, int a2)
{
  int v3; // esi
  int *v4; // edi
  void *v5; // eax
  int v6; // eax

  if ( a2 <= 0 || a2 > 8 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid sampler count for pixel shader %s", (_BYTE)this - 52);
    return -1;
  }
  else
  {
    v3 = 0;
    this[85] = a2;
    v4 = this + 86;
    do
    {
      v5 = operator new(0xF8u);
      if ( v5 )
        v6 = sub_60A7C0(v5);
      else
        v6 = 0;
      *v4 = v6;
      ++v3;
      ++v4;
    }
    while ( v3 < this[85] );
    return 0;
  }
}
