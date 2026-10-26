int __thiscall sub_51B0B0(int this, int a2)
{
  float v4; // edx
  int v5; // eax
  int result; // eax
  float v7; // [esp+0h] [ebp-18h]
  float v8; // [esp+0h] [ebp-18h]
  float v9; // [esp+0h] [ebp-18h]
  float v10; // [esp+Ch] [ebp-Ch] BYREF
  float v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  float v13; // [esp+1Ch] [ebp+4h]

  v4 = *(float *)(a2 + 32);
  v5 = *(_DWORD *)(a2 + 36);
  v10 = *(float *)(a2 + 28);
  v11 = v4;
  v12 = v5;
  sub_51A3B0((int *)this, &v10);
  v10 = *(float *)(a2 + 40);
  v11 = *(float *)(a2 + 44);
  v12 = *(_DWORD *)(a2 + 48);
  v13 = cos(v10);
  v7 = atan2(sin(v11) * v13, cos(v11) * v13) * 10.185916;
  *(_WORD *)(this + 12) ^= (*(_BYTE *)(this + 12) ^ (unsigned __int8)(4 * sub_4015C0(v7))) & 0xFC;
  sub_519E70((_DWORD *)(a2 + 16), &v10);
  sub_51AFB0(this, &v10);
  v8 = (double)((*(_DWORD *)a2 >> 12) & 0x1F) * 0.032258064;
  sub_51A2D0(this, v8);
  v9 = (double)(*(_DWORD *)a2 >> 18) * 0.14285715 * 0.02;
  result = sub_4015C0(v9) << 10;
  *(_WORD *)(this + 12) = result | *(_WORD *)(this + 12) & 0x3FF;
  return result;
}
