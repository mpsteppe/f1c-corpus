int __thiscall sub_4F0B80(_DWORD *this, int *a2, _DWORD *a3, char a4)
{
  int result; // eax
  int v5; // edx
  int v6; // edx
  long double v7; // st7
  float v8; // [esp+10h] [ebp-18h]
  float v9; // [esp+18h] [ebp-10h]

  result = (int)&this[15 * this[67] + 68];
  if ( *a2 > 1 )
  {
    *(_DWORD *)(result + 8) = *(_DWORD *)(result - 28);
    v5 = *(_DWORD *)(result - 28 + 8);
    *(_DWORD *)(result + 12) = *(_DWORD *)(result - 28 + 4);
    *(_DWORD *)(result + 16) = v5;
    *(_DWORD *)(result + 20) = *(_DWORD *)(result - 16);
    v6 = *(_DWORD *)(result - 16 + 8);
    *(_DWORD *)(result + 24) = *(_DWORD *)(result - 16 + 4);
    *(_DWORD *)(result + 28) = v6;
    *(_BYTE *)(result + 56) = a4;
  }
  *(_DWORD *)(result + 32) = *a3;
  *(_DWORD *)(result + 36) = a3[1];
  *(_DWORD *)(result + 40) = a3[2];
  v8 = *(float *)(result + 32) - *(float *)(result + 8);
  v9 = *(float *)(result + 40) - *(float *)(result + 16);
  *(_DWORD *)(result + 48) = 0;
  v7 = atan2(v8, v9);
  *(float *)(result + 44) = sin(v7);
  *(float *)(result + 52) = cos(v7);
  ++this[67];
  ++*a2;
  return result;
}
