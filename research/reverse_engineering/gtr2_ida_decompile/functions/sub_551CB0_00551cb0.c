int __thiscall sub_551CB0(int this, int a2)
{
  double v3; // st7
  double v4; // st7
  int result; // eax
  int i; // edi

  *(_BYTE *)(this + 244) = 0;
  *(_DWORD *)(this + 284) = *(_DWORD *)(a2 + 8);
  v3 = *(float *)(a2 + 12);
  *(float *)(this + 220) = *(float *)(a2 + 12);
  v4 = v3 + *(float *)(this + 228);
  *(_BYTE *)(this + 253) = 0;
  *(float *)(this + 224) = v4;
  sub_430250(&dword_B640C0, 4u);
  result = dword_757C10;
  for ( i = 0; i < dword_757C10; ++i )
  {
    sub_52B890((_DWORD *)(*(&dword_91E088 + i) + 19272), *(_DWORD *)(this + 220));
    result = dword_757C10;
  }
  return result;
}
