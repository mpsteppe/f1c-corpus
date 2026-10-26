_DWORD *__cdecl sub_595621(char a1, int a2, _DWORD *a3, int a4)
{
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // edi
  __int16 v8; // [esp-10h] [ebp-40h]
  __int16 v9; // [esp+8h] [ebp-28h] BYREF
  char v10; // [esp+Ah] [ebp-26h]
  _DWORD v11[2]; // [esp+24h] [ebp-Ch] BYREF
  __int16 v12; // [esp+2Ch] [ebp-4h]

  Float80ToFloat64Unpack(v11, &a1);
  v8 = v12;
  v4 = sub_5976E8(v11[0], v11[1], v8, 17, 0, &v9);
  v5 = a3;
  v6 = a4;
  a3[2] = v4;
  *v5 = v10;
  v5[1] = v9;
  sub_58FCA0();
  v5[3] = v6;
  return v5;
}
