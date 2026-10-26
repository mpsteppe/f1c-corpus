unsigned int __thiscall sub_553A20(_DWORD *this, float *a2, int a3)
{
  unsigned int result; // eax
  int v5; // [esp-18h] [ebp-1Ch]
  int v6; // [esp-14h] [ebp-18h]

  if ( (this[6] & 0x40000) != 0 )
  {
    result = sub_55C860(this, a2, a2 + 3, a3);
    this[6] &= ~0x400u;
  }
  else
  {
    v6 = CRTFtol(a2[4]);
    v5 = CRTFtol(a2[3]);
    CRTFtol(a2[1]);
    CRTFtol(*a2);
    sub_553AA0(v5, v6, a3, this);
    result = this[6] & 0xFFFFFBFF;
    this[6] = result;
  }
  return result;
}
