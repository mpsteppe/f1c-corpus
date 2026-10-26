int __thiscall sub_52DF10(_BYTE *this, int a2)
{
  int v3; // edi

  v3 = 0;
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this) )
    return -1;
  if ( this[9360] == 1 )
    return CompressedAudioDecoder(a2);
  if ( this[9360] == 2 )
    return TextureDecompression_1250(a2);
  return v3;
}
