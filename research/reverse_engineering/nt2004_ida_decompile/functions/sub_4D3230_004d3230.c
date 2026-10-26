char __stdcall sub_4D3230(int a1, float a2, float *Buffer)
{
  float *v3; // esi

  v3 = Buffer;
  sub_57A3A0(Buffer, 4u);
  if ( (*(_DWORD *)v3 & 0xF0000000) == 0x10000000 && (*((_BYTE *)v3 + 2) & 0x3F) == 0 )
  {
    LOBYTE(Buffer) = (int)((v3[1] - a2) / 0.0001670000056037679);
    sub_57A3A0(&Buffer, 1u);
  }
  sub_57A3A0(v3 + 2, (*(_DWORD *)v3 >> 6) & 0x3FF);
  return 1;
}
