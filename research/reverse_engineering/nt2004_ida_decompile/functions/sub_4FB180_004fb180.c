size_t __thiscall sub_4FB180(int this, int a2)
{
  double v3; // st7
  double v4; // st6
  size_t result; // eax
  signed int i; // edi

  *(_BYTE *)(this + 161) = 0;
  *(_DWORD *)(this + 196) = *(_DWORD *)(a2 + 8);
  v3 = *(float *)(a2 + 12);
  *(float *)(this + 148) = *(float *)(a2 + 12);
  v4 = (double)*(int *)dword_768CB4;
  *(_BYTE *)(this + 162) = 0;
  *(float *)(this + 152) = v4 * 60.0 + v3;
  sub_42F950(&dword_75CBA8, 4);
  result = NumOfElements;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    sub_4DD120((_DWORD *)(dword_75AAD0[i] + 20836), *(_DWORD *)(this + 148));
    result = NumOfElements;
  }
  return result;
}
