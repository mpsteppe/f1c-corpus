int __stdcall sub_4AB450(int a1, int a2)
{
  double v2; // st7
  float v3; // edi
  double v4; // st6
  float v5; // esi
  float v6; // ebp
  float v7; // edi
  float v8; // ebx
  float v10; // [esp+10h] [ebp-14h] BYREF
  float v11; // [esp+14h] [ebp-10h] BYREF
  float v12; // [esp+18h] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp-8h]
  float v14; // [esp+20h] [ebp-4h]
  float v15; // [esp+28h] [ebp+4h]

  sub_4AB430(&v10, &v11);
  v2 = (double)SLODWORD(v10);
  v10 = 0.0 * v2;
  v3 = v10;
  v4 = (double)SLODWORD(v11);
  v11 = 0.0 * v4;
  v5 = v11;
  v14 = v2;
  v12 = v4;
  v13 = (double)a1 * 0.001953125;
  v15 = (double)a2 * 0.001953125;
  sub_5A16E0(dword_765B0C, 0, v10, v11, 1.0, 0.0, 0.0, 0xFFFFFF);
  v6 = v12;
  sub_5A16E0(dword_765B0C, 1, v3, v12, 1.0, 0.0, v15, 0xFFFFFF);
  v7 = v13;
  v8 = v14;
  sub_5A16E0(dword_765B0C, 2, v14, v6, 1.0, v13, v15, 0xFFFFFF);
  sub_5A16E0(dword_765B0C, 3, v8, v5, 1.0, v7, 0.0, 0xFFFFFF);
  sub_5A16C0(16, 3136);
  sub_5A16B0(dword_765B08);
  return *(_DWORD *)(dword_765B08 + 16);
}
