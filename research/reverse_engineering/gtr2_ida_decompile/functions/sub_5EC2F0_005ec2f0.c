int __thiscall sub_5EC2F0(float *this, float *a2, int a3, int a4)
{
  double v5; // st3
  double v6; // st4
  double v7; // st3
  double v8; // st4
  int v9; // edx
  float *v10; // ecx
  double v11; // st7
  int result; // eax
  float v13; // [esp+0h] [ebp-18h]
  float v14; // [esp+4h] [ebp-14h]
  float v15; // [esp+8h] [ebp-10h]
  _BYTE v16[4]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+14h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  sub_5EA5A0((const char *)a3);
  *(_DWORD *)this &= 0xFFFFFFF0;
  sub_5E4D90(a2, (int)v16, (int)v17, (int)v18);
  v5 = v14 + *(float *)(a3 + 4);
  v6 = (v13 + *(float *)a3) * (v13 + *(float *)a3) + v5 * v5;
  v7 = v15 + *(float *)(a3 + 8);
  v8 = sqrt(v6 + v7 * v7);
  if ( (v8 - this[5] <= a2[10] || *((int *)this + 62) <= 4)
    && ((_BYTE)retaddr || v8 <= this[61] * a2[37] * 1.005)
    && v8 > this[60] * a2[37] )
  {
    v9 = 0;
    if ( *((int *)this + 62) <= 0 )
    {
LABEL_11:
      result = *(_DWORD *)this | 1;
      *(_DWORD *)this = result;
    }
    else
    {
      v10 = a2 + 63;
      while ( 1 )
      {
        v11 = v10[1] * *(float *)(a3 + 8) + *(v10 - 1) * *(float *)a3 + *(float *)(a3 + 4) * *v10 + v10[2];
        if ( v11 > this[5] )
        {
          result = *(_DWORD *)this | 4;
          *(_DWORD *)this = result;
          return result;
        }
        if ( v11 > -this[5] )
          break;
        ++v9;
        v10 += 4;
        if ( v9 >= *((_DWORD *)this + 62) )
          goto LABEL_11;
      }
      result = *(_DWORD *)this | 2;
      *(_DWORD *)this = result;
    }
  }
  else
  {
    result = *(_DWORD *)this | 8;
    *(_DWORD *)this = result;
  }
  return result;
}
