int __thiscall sub_5086DD(float *this, int a2, int a3, int a4)
{
  int result; // eax
  _BYTE *v5; // edx
  float *v6; // esi
  char v7; // bl
  float *v8; // edi
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st2
  double v13; // st3
  unsigned int v14; // [esp+10h] [ebp+8h]
  float v15; // [esp+14h] [ebp+Ch]
  unsigned int v16; // [esp+18h] [ebp+10h]

  if ( *((_DWORD *)this + 1042) )
    result = DirectXVertexBufferFormatConversion(this, a4);
  else
    result = a4;
  v5 = (_BYTE *)(*((_DWORD *)this + 6) + a3 * *((_DWORD *)this + 1045) + a2 * *((_DWORD *)this + 1044));
  v14 = 0;
  if ( *((_DWORD *)this + 1046) )
  {
    v6 = (float *)(result + 8);
    do
    {
      v7 = 0;
      v15 = 3.4028235e38;
      v16 = 0;
      v8 = this + 14;
      do
      {
        v9 = *(v6 - 1) - *(v8 - 1);
        v10 = *v6 - *v8;
        v11 = v6[1] - v8[1];
        v12 = *(v6 - 2) - *(v8 - 2);
        v13 = v11 * v11 + v10 * v10 + v9 * v9 + v12 * v12;
        if ( v13 < v15 )
        {
          v7 = v16;
          v15 = v13;
        }
        ++v16;
        v8 += 4;
      }
      while ( v16 < 0x100 );
      *v5++ = v7;
      result = ++v14;
      v6 += 4;
    }
    while ( v14 < *((_DWORD *)this + 1046) );
  }
  return result;
}
