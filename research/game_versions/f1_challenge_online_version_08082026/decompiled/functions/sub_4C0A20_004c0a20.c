void __thiscall sub_4C0A20(_DWORD *this, _BYTE *a2, unsigned int a3)
{
  char *v3; // eax
  int v4; // eax

  if ( a2 )
  {
    *a2 = 0;
    v3 = (char *)this[2];
    if ( !v3 )
      v3 = byte_5EA438;
    sub_4C3F80(v3);
    v4 = sub_4C4080(&unk_8AC388);
    if ( v4 )
    {
      if ( a3 > 1 )
      {
        sub_587DD0(a2, v4 + 124, a3 - 1);
        a2[a3 - 1] = 0;
      }
    }
  }
}
