char __thiscall sub_4DEB90(_DWORD *this)
{
  signed int v1; // esi
  char i; // bl

  v1 = 0;
  for ( i = 1; v1 < (int)NumOfElements; ++v1 )
  {
    if ( this[43] < sub_4DEBD0(dword_75AAD0[v1] + 20836) )
      i = 0;
  }
  return i;
}
