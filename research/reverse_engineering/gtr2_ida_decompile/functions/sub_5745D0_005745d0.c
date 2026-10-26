double __thiscall sub_5745D0(float *this)
{
  int v2; // eax
  double *v3; // eax
  float v5[3]; // [esp+8h] [ebp-44h] BYREF
  double v6[6]; // [esp+14h] [ebp-38h] BYREF
  int v7; // [esp+44h] [ebp-8h]

  v2 = *((_DWORD *)this + 59);
  v6[0] = *this;
  v6[1] = this[1];
  v6[2] = this[2];
  v7 = v2;
  v6[3] = 1.200000047683716;
  v6[4] = 9.999999933815813e36;
  v3 = sub_45D210(dbl_B68610, v6, v5);
  *((_DWORD *)this + 59) = v3;
  if ( v3 )
    return this[36]
         - (this[1]
          - ((sin(this[2] * *(float *)(*((_DWORD *)v3 + 21) + 24)) + sin(*this * *(float *)(*((_DWORD *)v3 + 21) + 24)))
           * *(float *)(*((_DWORD *)v3 + 21) + 20)
           + v6[5])
          - this[58])
         * v5[1];
  else
    return 0.0;
}
