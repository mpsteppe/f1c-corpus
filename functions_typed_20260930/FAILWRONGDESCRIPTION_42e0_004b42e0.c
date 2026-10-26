char __stdcall sub_4B42E0(int a1, float a2, int a3)
{
  int v3; // esi

  v3 = a3;
  ConditionalDispatch_6bd0(a3, 4);
  if ( (*(_DWORD *)v3 & 0xE0000000) == 0x20000000 && (*(_DWORD *)v3 & 0xFC0000) == 0 )
  {
    LOBYTE(a3) = CRTFtol((*(float *)(v3 + 4) - a2) / 0.0001670000056037679 + 0.5);
    ConditionalDispatch_6bd0(&a3, 1);
  }
  ConditionalDispatch_6bd0(v3 + 8, (*(_DWORD *)v3 >> 8) & 0x3FF);
  return 1;
}

