// Address: 0x0044f73c
// Size: 122 bytes
// Name: sub_44F73C
// Type: int __thiscall(float *this, int, int, int, int)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_44F73C(float *this, int a2, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // eax
  float v7; // eax
  int result; // eax
  int v9; // [esp+14h] [ebp+10h]

  v9 = a3 - *((_DWORD *)this + 5);
  v5 = *((_DWORD *)this + 2);
  this[8] = (double)(a2 - *((_DWORD *)this + 4)) * this[6];
  *((_DWORD *)this + 4) = a2;
  this[9] = (double)v9 * this[7];
  if ( a2 < v5 )
    *((_DWORD *)this + 4) = v5;
  v6 = *((_DWORD *)this + 3);
  if ( *((_DWORD *)this + 4) > v6 )
    *((_DWORD *)this + 4) = v6;
  v7 = *this;
  *((_DWORD *)this + 5) = a3;
  if ( a3 < SLODWORD(v7) )
    this[5] = v7;
  result = *((_DWORD *)this + 1);
  if ( *((_DWORD *)this + 5) > result )
    *((_DWORD *)this + 5) = result;
  this[10] = (double)*((int *)this + 4) * this[6];
  this[11] = (double)*((int *)this + 5) * this[7];
  return result;
}
