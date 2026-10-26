int __thiscall sub_6CB86E(_DWORD *this)
{
  _DWORD *v2; // ecx
  int v3; // esi
  _DWORD *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  _DWORD *v7; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v8; // [esp+18h] [ebp-4h] BYREF

  v2 = (_DWORD *)this[64];
  v6 = v2[3];
  v5 = (_DWORD *)v2[4];
  v3 = *v2 & 0xFFFFF;
  sub_680D41(v2, 0, &v8);
  sub_680D41((_DWORD *)this[64], 1, &v7);
  return sub_6CB29C(this, 66, v5, v6, v7, v8, 0, v3, 0, 0, 0, 0);
}
