int __stdcall sub_5F2FD0(int a1, float *a2, int a3, int a4)
{
  int result; // eax
  float v5; // [esp+8h] [ebp-1Ch]
  float v6; // [esp+Ch] [ebp-18h]
  float v7; // [esp+10h] [ebp-14h]
  float v8; // [esp+14h] [ebp-10h]
  float v9; // [esp+18h] [ebp-Ch]
  float v10; // [esp+1Ch] [ebp-8h]

  v5 = *a2;
  v6 = a2[1];
  v7 = a2[2];
  sub_5A9859();
  result = a1;
  v8 = (v5 + 1.0) * 0.5;
  *(float *)a1 = v8;
  v9 = (v6 + 1.0) * 0.5;
  *(float *)(a1 + 4) = v9;
  v10 = (v7 + 1.0) * 0.5;
  *(float *)(a1 + 8) = v10;
  *(_DWORD *)(a1 + 12) = 1065353216;
  return result;
}
