void __thiscall sub_44F0E0(unsigned __int16 *this, int a2, float a3)
{
  unsigned int v3; // eax
  unsigned __int16 *v4; // edx

  *((_BYTE *)this + a2 + 892) = 0;
  v3 = 0;
  v4 = this + 1604;
  while ( *v4 != a2 )
  {
    ++v3;
    ++v4;
    if ( v3 >= 0x100 )
      goto LABEL_6;
  }
  this[v3 + 1604] = 0;
LABEL_6:
  if ( a3 <= 0.0 )
    *(_DWORD *)&this[2 * a2 + 1086] = 0;
  else
    *(float *)&this[2 * a2 + 1086] = dbl_8AFEA8 + a3;
}
