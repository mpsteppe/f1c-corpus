// f1c  0x004363f0  size=121
int __thiscall sub_4363F0(_DWORD *this, int a2)
{
  int result; // eax
  bool v3; // zf

  result = a2;
  v3 = *(_BYTE *)a2 == 0;
  *(_BYTE *)this = *(_BYTE *)a2;
  if ( !v3 )
  {
    this[1] = *(_DWORD *)(a2 + 28);
    this[2] = *(_DWORD *)(a2 + 32);
    this[3] = *(_DWORD *)(a2 + 36);
    this[4] = *(_DWORD *)(a2 + 40);
    this[5] = *(_DWORD *)(a2 + 44);
    this[6] = *(_DWORD *)(a2 + 48);
    this[7] = *(_DWORD *)(a2 + 4);
    this[8] = *(_DWORD *)(a2 + 8);
    this[9] = *(_DWORD *)(a2 + 12);
    this[10] = *(_DWORD *)(a2 + 16);
    this[11] = *(_DWORD *)(a2 + 20);
    this[12] = *(_DWORD *)(a2 + 24);
    this[17] = *(_DWORD *)(a2 + 52);
    result = *(_DWORD *)(a2 + 56);
    this[18] = result;
    this[19] = 0;
    this[20] = 0;
    this[21] = 0;
    this[22] = 0;
    this[23] = 0;
    this[24] = 0;
  }
  return result;
}
