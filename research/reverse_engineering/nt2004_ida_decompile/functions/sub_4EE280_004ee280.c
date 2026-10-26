int __thiscall sub_4EE280(_DWORD *this)
{
  _DWORD *v2; // edi
  signed int i; // edi

  v2 = this + 21;
  sub_417C30(dword_6291D0, (int)(this + 21));
  sub_50FB70(v2);
  sub_50AAE0(this + 473);
  sub_525CA0(this + 23);
  sub_4DC3F0((int)(this + 5209));
  sub_41F400(flt_62BC28);
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_428040((_DWORD *)dword_75AAD0[i], (unsigned int)this);
  this[6316] = -1;
  this[6317] = -1;
  return sub_4EEBA0(this);
}
