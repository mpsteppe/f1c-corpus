int __stdcall sub_4DDEC0(int a1, int a2)
{
  double v2; // st7
  double v3; // st6
  float v5; // [esp+0h] [ebp-14h]
  float v6; // [esp+4h] [ebp-10h]
  float v7; // [esp+8h] [ebp-Ch]
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+10h] [ebp-4h]
  float v10; // [esp+18h] [ebp+4h]

  v2 = (double)*((int *)dword_FB2790 + 1);
  v5 = 0.0 * v2;
  v3 = (double)*((int *)dword_FB2790 + 2);
  v6 = 0.0 * v3;
  v9 = v2;
  v7 = v3;
  v8 = (double)a1 * 0.0009765625;
  v10 = (double)a2 * 0.0009765625;
  sub_5EDF20(dword_B6E2AC, 0, v5, v6, 1.0, 0.0, 0.0, (int)byte_FFFFFF);
  sub_5EDF20(dword_B6E2AC, 1, v5, v7, 1.0, 0.0, v10, (int)byte_FFFFFF);
  sub_5EDF20(dword_B6E2AC, 2, v9, v7, 1.0, v8, v10, (int)byte_FFFFFF);
  sub_5EDF20(dword_B6E2AC, 3, v9, v6, 1.0, v8, 0.0, (int)byte_FFFFFF);
  sub_5EDB10(16, 3136);
  sub_5EDAF0(dword_B6E2A8);
  return dword_B6E2A8;
}
