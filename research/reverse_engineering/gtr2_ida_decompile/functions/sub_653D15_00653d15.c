int __thiscall sub_653D15(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax
  _BYTE *v6; // ecx
  float *v7; // edi
  float *v8; // edx
  char v9; // bl
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st2
  double v14; // st3
  unsigned int v15; // [esp+10h] [ebp+8h]
  float v16; // [esp+14h] [ebp+Ch]
  unsigned int v17; // [esp+18h] [ebp+10h]

  if ( this[21] )
    result = sub_64EB2A(this, a4);
  else
    result = a4;
  if ( this[4] )
    result = sub_650093(this, result);
  v6 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  v15 = 0;
  if ( this[26] )
  {
    v7 = (float *)(result + 8);
    do
    {
      v8 = (float *)this[14];
      v9 = 0;
      v17 = 0;
      v16 = 3.4028235e38;
      do
      {
        v10 = *(v7 - 1) - v8[1];
        v11 = *v7 - v8[2];
        v12 = v7[1] - v8[3];
        v13 = *(v7 - 2) - *v8;
        v14 = v12 * v12 + v11 * v11 + v10 * v10 + v13 * v13;
        if ( v14 < v16 )
        {
          v9 = v17;
          v16 = v14;
        }
        ++v17;
        v8 += 4;
      }
      while ( v17 < 0x100 );
      *v6++ = v9;
      result = ++v15;
      v7 += 4;
    }
    while ( v15 < this[26] );
  }
  return result;
}
