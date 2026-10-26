char __thiscall sub_43B590(int this)
{
  int i; // edi
  char result; // al

  *(_BYTE *)(this + 146) = dword_7667F8[0];
  *(_BYTE *)(this + 147) = dword_766840[0];
  *(_BYTE *)(this + 148) = dword_766918[0];
  *(_BYTE *)(this + 149) = dword_7669CC[0];
  *(_BYTE *)(this + 150) = dword_766978[0];
  *(_BYTE *)(this + 151) = dword_766888[0];
  *(_BYTE *)(this + 152) = dword_7668F4[0];
  *(_BYTE *)(this + 153) = dword_7667B0[0];
  *(_BYTE *)(this + 154) = dword_76681C[0];
  *(_BYTE *)(this + 155) = dword_766864[0];
  *(_BYTE *)(this + 156) = dword_7668AC[0];
  *(_BYTE *)(this + 157) = dword_7668D0[0];
  if ( byte_76699C )
    *(_DWORD *)(this + 160) = 2 * (byte_7669B4 != 0) + 1;
  else
    *(_DWORD *)(this + 160) = byte_7669B4 != 0 ? 2 : 0;
  for ( i = 0; i < 12; ++i )
  {
    if ( !(unsigned __int8)sub_4CE6E0(i) )
      *(_BYTE *)(this + i + 146) = 0;
  }
  if ( *(_BYTE *)(this + 148) || *(_BYTE *)(this + 154) )
    *(_BYTE *)(this + 147) = 2;
  result = *(_BYTE *)(this + 149);
  if ( result )
    *(_BYTE *)(this + 150) = 1;
  *(double *)(this + 172) = flt_766A80 * 0.925;
  return result;
}
