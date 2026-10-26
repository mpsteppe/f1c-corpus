int __thiscall sub_4D23D0(int this, int a2)
{
  double v3; // st7
  double v4; // st7
  int result; // eax
  int i; // edi

  *(_BYTE *)(this + 193) = 0;
  *(_DWORD *)(this + 216) = *(_DWORD *)(a2 + 8);
  v3 = *(float *)(a2 + 12);
  *(float *)(this + 176) = *(float *)(a2 + 12);
  v4 = v3 + *(float *)(this + 184);
  *(_BYTE *)(this + 194) = 0;
  *(float *)(this + 180) = v4;
  sub_42D140(&dword_7C569C, 4u);
  result = dword_5C329C;
  for ( i = 0; i < dword_5C329C; ++i )
  {
    sub_4BC2D0((_DWORD *)(dword_7C54F0[i] + 16436), *(_DWORD *)(this + 176));
    result = dword_5C329C;
  }
  return result;
}

