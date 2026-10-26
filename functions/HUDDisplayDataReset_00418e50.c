void __thiscall sub_418E50(_DWORD *this)
{
  int v2; // ecx
  _DWORD *v3; // eax

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    v2 = 0;
    v3 = this + 212;
    do
    {
      *(v3 - 212) = -1;
      *(v3 - 104) = 0x7FFFFFFF;
      *v3 = 0;
      v3[107] = -1082130432;
      v3[211] = 0;
      v3[315] = 0;
      *((_BYTE *)this + v2++ + 2524) = 0;
      ++v3;
    }
    while ( v2 < 104 );
    AITargetDriverSelection(this);
    this[316] = 0;
    this[317] = 0;
    this[318] = 0;
  }
}
