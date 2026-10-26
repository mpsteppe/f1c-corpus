int __thiscall sub_4B01D0(int *this, float a2, float a3)
{
  int v4; // ecx
  int result; // eax
  int v6; // [esp+4h] [ebp-20h] BYREF
  int v7; // [esp+8h] [ebp-1Ch] BYREF
  float v8; // [esp+Ch] [ebp-18h] BYREF
  float v9; // [esp+10h] [ebp-14h] BYREF
  float v10; // [esp+14h] [ebp-10h] BYREF
  float v11; // [esp+18h] [ebp-Ch] BYREF
  float v12; // [esp+1Ch] [ebp-8h] BYREF
  int v13; // [esp+20h] [ebp-4h] BYREF

  v4 = *this;
  if ( v4 )
  {
    sub_5A17A0(v4, 0, (int)&v8, (int)&v9, (int)&v10, (int)&v7, (int)&v7, (int)&v6);
    sub_5A17A0(*this, 2, (int)&v11, (int)&v12, (int)&v13, (int)&v7, (int)&v7, (int)&v6);
    sub_5A16E0(*this, 0, v8, v9, v10, 0.0, 0.0, v6);
    sub_5A16E0(*this, 1, v8, v12, v10, 0.0, a3, v6);
    sub_5A16E0(*this, 2, v11, v12, v10, a2, a3, v6);
    return sub_5A16E0(*this, 3, v11, v9, v10, a2, 0.0, v6);
  }
  return result;
}
