// f1c  0x0049e9a0  size=107
int __thiscall sub_49E9A0(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  void *v5; // edi

  v3 = sub_587C03(96);
  if ( v3 )
    v4 = sub_54FE10(v3);
  else
    v4 = 0;
  this[3] = v4;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 68) |= 1u;
    if ( sub_550080(a2, 0, 2052) )
    {
      v5 = (void *)this[3];
      if ( v5 )
      {
        j_nullsub_3(this[3]);
        sub_587BCF(v5);
      }
      this[3] = 0;
    }
  }
  return this[3];
}
