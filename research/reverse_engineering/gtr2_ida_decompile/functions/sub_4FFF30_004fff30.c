void __thiscall sub_4FFF30(float *this, int a2, char a3)
{
  float v4; // ecx

  v4 = *this;
  *((_DWORD *)this + 196) = a2;
  if ( *(_DWORD *)(LODWORD(v4) + 14820) )
    this[197] = sub_4FD860((char *)this, a3) + this[196] + 5.0;
  else
    this[197] = sub_4FD860((char *)this, a3) + this[196];
}
