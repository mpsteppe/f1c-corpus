// Address: 0x00509f0c
// Size: 100 bytes
// Name: sub_509F0C
// Type: unsigned __int8 *__thiscall(_DWORD *this, int, int, _DWORD *)
// Source: IDA Hex-Rays decompilation

unsigned __int8 *__thiscall sub_509F0C(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *i; // edx
  _DWORD *v7; // esi
  _DWORD *v8; // edi

  result = (unsigned __int8 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &result[this[1046]]; result < i; *v8 = v7[1] )
  {
    v7 = &this[4 * *result + 12];
    *a4 = *v7++;
    a4[1] = *v7++;
    a4[2] = *v7;
    v8 = a4 + 3;
    ++result;
    a4 += 4;
  }
  if ( this[4] )
    return (unsigned __int8 *)sub_507845(&a4[-4 * this[1046]]);
  return result;
}
