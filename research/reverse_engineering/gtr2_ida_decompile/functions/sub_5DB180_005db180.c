int __thiscall sub_5DB180(_DWORD *this, float a2, float a3, float a4)
{
  int v5; // edi
  int result; // eax
  float v7; // [esp+0h] [ebp-20h]
  float v8; // [esp+4h] [ebp-1Ch]
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+14h] [ebp-Ch] BYREF
  float v11; // [esp+18h] [ebp-8h] BYREF
  float v12; // [esp+1Ch] [ebp-4h] BYREF

  v5 = (int)(this + 18);
  sub_5D75D0(this + 18, &v12, &v11, &v10);
  v9 = v10 + a4;
  v8 = v11 + a3;
  v7 = v12 + a2;
  sub_5D7330(v5, v7, v8, v9);
  result = *this | 0x40;
  *this = result;
  return result;
}
