void __thiscall sub_4196B0(_DWORD *this)
{
  _BYTE *v2; // edx
  int *v3; // ecx
  float *v4; // eax

  if ( dword_7688A0 && flt_7678BC != 0.0 && byte_6292D8 && sub_4633A0(&unk_764D70) != 1 )
  {
    v2 = this + 628;
    v3 = &dword_6310F4;
    v4 = (float *)(this + 100);
    do
    {
      *(v4 - 100) = NAN;
      if ( dword_75CBB0 == 7 )
      {
        *((_DWORD *)v4 - 48) = *v3;
        *v4 = dbl_7DA9D0;
      }
      else
      {
        *(v4 - 48) = NAN;
        *v4 = -1.0;
      }
      v4[192] = 0.0;
      v4[240] = -1.0;
      v4[288] = -1.0;
      v4[336] = 0.0;
      v4[384] = 0.0;
      v4[432] = 0.0;
      v4[480] = 0.0;
      ++v4;
      v3 += 6326;
      *v2++ = 0;
    }
    while ( (int)v3 < (int)dword_759974 );
    this[644] = 0;
  }
  this[645] = -1;
  this[646] = -1;
  this[647] = -1;
}
