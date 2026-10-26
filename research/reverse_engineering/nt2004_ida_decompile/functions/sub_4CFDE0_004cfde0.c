int __thiscall sub_4CFDE0(_DWORD *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // ecx
  int v3; // edx
  int result; // eax
  int v5; // ecx
  float v6; // [esp+8h] [ebp-28h]
  float v7; // [esp+Ch] [ebp-24h]
  float v8; // [esp+10h] [ebp-20h]
  _DWORD v9[3]; // [esp+14h] [ebp-1Ch] BYREF
  float v10[4]; // [esp+20h] [ebp-10h] BYREF

  v1 = this;
  v2 = this[7];
  v6 = (double)(int)(v2 << 10) * 0.000015258789;
  v7 = (double)(int)((v1[8] & 0xFFC00000) + ((v2 >> 10) & 0x3FF000)) * 0.0000019073486;
  v8 = (double)(int)(v1[8] << 10) * 0.000015258789;
  sub_4CF950(v1 + 9, v10);
  sub_579430(v10, v9);
  *((float *)v1 + 7) = v6;
  v3 = v9[0];
  *((float *)v1 + 8) = v7;
  result = v9[1];
  *((float *)v1 + 9) = v8;
  v5 = v9[2];
  v1 += 10;
  *v1 = v3;
  v1[1] = result;
  v1[2] = v5;
  return result;
}
