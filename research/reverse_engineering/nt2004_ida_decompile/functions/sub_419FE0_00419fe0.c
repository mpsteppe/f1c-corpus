char __thiscall sub_419FE0(float *this, char a2)
{
  signed int v2; // esi
  float *v3; // edi

  if ( dbl_7DA9D0 <= flt_629D54
    && (!a2 || dbl_7DA9D0 + 0.1 == flt_629D54)
    && *((_DWORD *)this + 148) != -1082130432
    && dbl_7DA9D0 + 0.1 >= flt_629D54 )
  {
    return 0;
  }
  v2 = 0;
  flt_629D54 = dbl_7DA9D0 + 0.1;
  if ( (int)NumOfElements > 0 )
  {
    v3 = this + 148;
    do
      *v3++ = sub_51C7A0(dword_75AAD0[v2++] + 84);
    while ( v2 < (int)NumOfElements );
  }
  return 1;
}
