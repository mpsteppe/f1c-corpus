int __thiscall sub_4B0090(int *this, int a2, int a3)
{
  int v4; // ecx
  int result; // eax
  float v6; // [esp+0h] [ebp-44h]
  float v7; // [esp+0h] [ebp-44h]
  float v8; // [esp+4h] [ebp-40h]
  float v9; // [esp+4h] [ebp-40h]
  float v10; // [esp+1Ch] [ebp-28h]
  float v11; // [esp+20h] [ebp-24h] BYREF
  float v12; // [esp+24h] [ebp-20h]
  int v13; // [esp+28h] [ebp-1Ch] BYREF
  float v14; // [esp+2Ch] [ebp-18h] BYREF
  float v15; // [esp+30h] [ebp-14h] BYREF
  float v16; // [esp+34h] [ebp-10h] BYREF
  int v17; // [esp+38h] [ebp-Ch] BYREF
  int v18; // [esp+3Ch] [ebp-8h] BYREF
  int v19; // [esp+40h] [ebp-4h] BYREF

  v4 = *this;
  if ( v4 )
  {
    v12 = (double)dword_6152E8 * 0.00125 * (double)a2;
    v10 = (double)dword_6152EC * 0.0016666667 * (double)a3;
    sub_5A17A0(v4, 0, (int)&v14, (int)&v15, (int)&v16, (int)&v13, (int)&v13, (int)&a2);
    sub_5A17A0(*this, 2, (int)&v17, (int)&v18, (int)&v19, (int)&v11, (int)&a3, (int)&a2);
    sub_5A16E0(*this, 0, v14, v15, v16, 0.0, 0.0, a2);
    v8 = v15 + v10;
    sub_5A16E0(*this, 1, v14, v8, v16, 0.0, *(float *)&a3, a2);
    v9 = v15 + v10;
    v6 = v14 + v12;
    sub_5A16E0(*this, 2, v6, v9, v16, v11, *(float *)&a3, a2);
    v7 = v14 + v12;
    return sub_5A16E0(*this, 3, v7, v15, v16, v11, 0.0, a2);
  }
  return result;
}
