int __thiscall sub_51C15E(_DWORD *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // ecx
  float v3; // edx
  int result; // eax
  float v5; // ecx
  int v6; // [esp+0h] [ebp-2Ch]
  float v7; // [esp+4h] [ebp-28h]
  float v8; // [esp+8h] [ebp-24h]
  float v9[3]; // [esp+Ch] [ebp-20h] BYREF
  _BYTE v10[4]; // [esp+18h] [ebp-14h] BYREF

  v1 = this;
  v2 = this[7];
  v7 = (double)(int)(v2 << 10) * 0.000015258789;
  v6 = v1[8] << 10;
  v8 = (double)(int)((v1[8] & 0xFFC00000) + ((v2 >> 10) & 0x3FF000)) * 0.0000019073486;
  v9[0] = (double)v6 * 0.000015258789;
  sub_51A6F0(v1 + 9);
  sub_614DB0(v10, v9);
  v1[7] = v6;
  v3 = v9[0];
  *((float *)v1 + 8) = v7;
  result = LODWORD(v9[1]);
  *((float *)v1 + 9) = v8;
  v5 = v9[2];
  v1 += 10;
  *(float *)v1 = v3;
  v1[1] = result;
  *((float *)v1 + 2) = v5;
  return result;
}
