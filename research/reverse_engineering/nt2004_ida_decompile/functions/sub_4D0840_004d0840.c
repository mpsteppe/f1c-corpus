int __thiscall sub_4D0840(_DWORD *this, int a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  _WORD *v7; // ecx
  float v9; // [esp+0h] [ebp-18h]
  float v10; // [esp+0h] [ebp-18h]
  float v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 32);
  v4 = *(_DWORD *)(a2 + 36);
  v12 = *(_DWORD *)(a2 + 28);
  v13 = v3;
  v14 = v4;
  sub_4CF5A0(this, (float *)&v12);
  v5 = *(_DWORD *)(a2 + 44);
  v6 = *(_DWORD *)(a2 + 48);
  v12 = *(_DWORD *)(a2 + 40);
  v13 = v5;
  v14 = v6;
  v9 = sub_4D0810((float *)&v12);
  sub_4D06E0(v7, v9);
  sub_4CFBA0((_DWORD *)(a2 + 16), (float *)&v12);
  sub_4D0560((int)this, (float *)&v12);
  v10 = sub_4D0370((_WORD *)a2);
  sub_4D0720((int)this, v10);
  v11 = sub_4D0310((_DWORD *)a2);
  return sub_4D07D0(this, v11);
}
