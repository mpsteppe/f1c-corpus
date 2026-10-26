int __thiscall sub_5B5F10(_DWORD *this, int a2)
{
  int v3; // edi
  int result; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  float v9; // [esp+1Ch] [ebp-30h]
  float v10; // [esp+20h] [ebp-2Ch]
  float v11; // [esp+20h] [ebp-2Ch]
  float v12; // [esp+20h] [ebp-2Ch]
  __m64 v13; // [esp+24h] [ebp-28h]
  float v14[4]; // [esp+2Ch] [ebp-20h] BYREF
  float v15[4]; // [esp+3Ch] [ebp-10h] BYREF

  if ( (*(_BYTE *)(this[1] + 156) & 0x20) != 0 )
  {
    result = this[2];
    v7 = 0;
    if ( result > 0 )
    {
      v8 = 0;
      result = 0;
      do
      {
        *(_DWORD *)(v8 + this[8] + 24) = *(_DWORD *)(this[3] + result + 24);
        ++v7;
        result += 48;
        v8 += 64;
      }
      while ( v7 < this[2] );
    }
  }
  else
  {
    v3 = *(_DWORD *)(dword_7E8E5C + 292);
    (*(void (__thiscall **)(int, int, int, _DWORD, float *))(*(_DWORD *)dword_7E8E58 + 24))(
      dword_7E8E58,
      dword_7E8E5C,
      v3,
      this[1],
      v15);
    (*(void (__thiscall **)(int, int, _DWORD, float *))(*(_DWORD *)dword_7E8E58 + 20))(dword_7E8E58, v3, this[1], v14);
    v9 = *(float *)(this[1] + 80) * 255.0;
    v13.m64_i16[3] = (__int16)v9;
    v10 = v14[0] + v15[0];
    v13.m64_i16[0] = (__int16)v10;
    v11 = v14[1] + v15[1];
    v13.m64_i16[1] = (__int16)v11;
    v12 = v14[2] + v15[2];
    v13.m64_i16[2] = (__int16)v12;
    result = 0;
    v5 = _mm_cvtsi64_si32(_m_packuswb(v13, (__m64)qword_7E5EB0));
    _m_empty();
    if ( (int)this[2] > 0 )
    {
      v6 = 0;
      do
      {
        *(_DWORD *)(v6 + this[8] + 24) = v5;
        ++result;
        v6 += 64;
      }
      while ( result < this[2] );
    }
  }
  return result;
}
