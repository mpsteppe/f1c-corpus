// f1c  0x004a5c80  size=138
int __thiscall sub_4A5C80(int this, int a2)
{
  int result; // eax
  int v3; // esi
  float v4; // [esp+0h] [ebp-14h]

  result = *(_DWORD *)(this + 388);
  if ( a2 != result )
  {
    if ( a2 == 1 || result != 1 && a2 == 2 )
      *(float *)(this + 396) = dbl_8AFEA0;
    v3 = dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 += 432;
    }
    v4 = dbl_8AFEA0;
    sub_4B33B0(6, 1, 1, *(_DWORD *)(this + 4), LODWORD(v4), 0);
    *(_BYTE *)(v3 + 8) = a2;
    return sub_4A5D10(v3);
  }
  return result;
}
