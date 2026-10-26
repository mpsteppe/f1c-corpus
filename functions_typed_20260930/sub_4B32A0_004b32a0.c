int __thiscall sub_4B32A0(_WORD *this, int a2, int a3)
{
  _DWORD *v5; // edi
  __int16 v6; // cx
  int v7; // edx
  int v8; // eax
  int result; // eax
  float v10; // [esp+0h] [ebp-28h]
  float v11; // [esp+0h] [ebp-28h]
  float v12; // [esp+10h] [ebp-18h] BYREF
  float v13; // [esp+14h] [ebp-14h]
  float v14; // [esp+18h] [ebp-10h]
  float v15[3]; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+2Ch] [ebp+4h]

  v5 = (_DWORD *)(a2 + 8);
  v12 = 0.0;
  v13 = 0.0;
  v14 = 0.0;
  UtilityFunction_2480((_WORD *)(a2 + 8), &v12);
  FloatToFixedConversionWithClamp(a2 + 8, &v12);
  FloatToShortClampedConversion((_WORD *)(a2 + 8), &v12);
  v6 = this[1];
  v7 = *((_DWORD *)this + 1) << 16;
  v8 = *((_DWORD *)this + 1) >> 8;
  v12 = (double)(int)(*(_DWORD *)this << 8) * 0.000030517578;
  v16 = (*((unsigned __int8 *)this + 8) << 24) + (v8 & 0xFFFF00);
  v13 = (double)(v7 + (v6 & 0xFF00)) * 0.000030517578;
  memset(v15, 0, sizeof(v15));
  v14 = (double)v16 * 0.000030517578;
  sub_4B2310(v5, &v12, v15);
  v10 = TernarySelectByBitfield((int)this);
  BitfieldInsert(v5, v10);
  v11 = sub_4B2C50((int)this);
  result = FloatToBitfieldPack(v5, v11);
  *(_DWORD *)(a2 + 4) = a3;
  return result;
}

