int __thiscall sub_4B02C0(int *this, int a2)
{
  int v3; // ecx
  int result; // eax
  float v5; // [esp+4h] [ebp-28h] BYREF
  float v6; // [esp+8h] [ebp-24h] BYREF
  int v7; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-1Ch] BYREF
  float v9; // [esp+14h] [ebp-18h] BYREF
  float v10; // [esp+18h] [ebp-14h] BYREF
  float v11; // [esp+1Ch] [ebp-10h] BYREF
  float v12; // [esp+20h] [ebp-Ch] BYREF
  float v13; // [esp+24h] [ebp-8h] BYREF
  int v14; // [esp+28h] [ebp-4h] BYREF

  v3 = *this;
  if ( v3 )
  {
    sub_5A17A0(v3, 0, (int)&v9, (int)&v10, (int)&v11, (int)&v7, (int)&v7, (int)&v8);
    sub_5A17A0(*this, 2, (int)&v12, (int)&v13, (int)&v14, (int)&v6, (int)&v5, (int)&v8);
    sub_5A16E0(*this, 0, v9, v10, v11, 0.0, 0.0, a2);
    sub_5A16E0(*this, 1, v9, v13, v11, 0.0, v5, a2);
    sub_5A16E0(*this, 2, v12, v13, v11, v6, v5, a2);
    return sub_5A16E0(*this, 3, v12, v10, v11, v6, 0.0, a2);
  }
  return result;
}
