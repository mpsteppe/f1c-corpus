int __thiscall sub_4AFF20(int *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // ecx
  int result; // eax
  float v7; // [esp+0h] [ebp-54h]
  float v8; // [esp+0h] [ebp-54h]
  float v9; // [esp+4h] [ebp-50h]
  float v10; // [esp+4h] [ebp-50h]
  int v11; // [esp+1Ch] [ebp-38h] BYREF
  float v12; // [esp+20h] [ebp-34h] BYREF
  float v13; // [esp+24h] [ebp-30h]
  float v14; // [esp+28h] [ebp-2Ch] BYREF
  float v15; // [esp+2Ch] [ebp-28h]
  int v16; // [esp+30h] [ebp-24h] BYREF
  float v17; // [esp+34h] [ebp-20h]
  float v18; // [esp+38h] [ebp-1Ch]
  float v19; // [esp+3Ch] [ebp-18h] BYREF
  float v20; // [esp+40h] [ebp-14h] BYREF
  float v21; // [esp+44h] [ebp-10h] BYREF
  int v22; // [esp+48h] [ebp-Ch] BYREF
  int v23; // [esp+4Ch] [ebp-8h] BYREF
  int v24; // [esp+50h] [ebp-4h] BYREF

  v4 = *this;
  if ( v4 )
  {
    v17 = (double)dword_6152E8 * 0.00125;
    v18 = (double)dword_6152EC * 0.0016666667;
    sub_5A17A0(v4, 0, (int)&v19, (int)&v20, (int)&v21, (int)&v16, (int)&v16, (int)&v11);
    sub_5A17A0(*this, 2, (int)&v22, (int)&v23, (int)&v24, (int)&v14, (int)&v12, (int)&v11);
    v15 = *(float *)&v22 - v19;
    v5 = *this;
    v13 = *(float *)&v23 - v20;
    v19 = (double)a2 * v17;
    v20 = (double)a3 * v18;
    sub_5A16E0(v5, 0, v19, v20, v21, 0.0, 0.0, v11);
    v9 = v20 + v13;
    sub_5A16E0(*this, 1, v19, v9, v21, 0.0, v12, v11);
    v10 = v20 + v13;
    v7 = v19 + v15;
    sub_5A16E0(*this, 2, v7, v10, v21, v14, v12, v11);
    v8 = v19 + v15;
    return sub_5A16E0(*this, 3, v8, v20, v21, v14, 0.0, v11);
  }
  return result;
}
