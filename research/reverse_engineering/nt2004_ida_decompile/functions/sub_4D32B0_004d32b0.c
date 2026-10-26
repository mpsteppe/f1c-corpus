bool __stdcall sub_4D32B0(int a1, float a2, float *Buffer)
{
  float *v3; // edi
  size_t v5; // esi

  v3 = Buffer;
  if ( sub_57A3D0(Buffer, 4u) != 4 )
    return 0;
  if ( (*(_DWORD *)v3 & 0xF0000000) != 0x10000000 || (*((_BYTE *)v3 + 2) & 0x3F) != 0 )
  {
    v3[1] = a2;
  }
  else
  {
    sub_57A3D0(&Buffer, 1u);
    Buffer = (float *)(unsigned __int8)Buffer;
    v3[1] = (double)(unsigned __int8)Buffer * 0.0001670000056037679 + a2;
  }
  v5 = (*(_DWORD *)v3 >> 6) & 0x3FF;
  return v5 == sub_57A3D0(v3 + 2, v5);
}
