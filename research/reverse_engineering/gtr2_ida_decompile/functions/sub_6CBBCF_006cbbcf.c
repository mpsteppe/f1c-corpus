int __thiscall sub_6CBBCF(_DWORD *this)
{
  int *v2; // ecx
  int v3; // esi
  _DWORD *v5; // [esp+Ch] [ebp-10h] BYREF
  _DWORD *v6; // [esp+10h] [ebp-Ch] BYREF
  _DWORD *v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v2 = (int *)this[64];
  v3 = *v2;
  v8 = v2[3];
  v7 = (_DWORD *)v2[4];
  sub_680D41(v2, 0, &v5);
  sub_680D41((_DWORD *)this[64], 1, &v6);
  return sub_6CB29C(this, 95, v7, v8, v6, v5, 0, v3 & 0xFFFFF, 0, 0, 0, 0);
}
