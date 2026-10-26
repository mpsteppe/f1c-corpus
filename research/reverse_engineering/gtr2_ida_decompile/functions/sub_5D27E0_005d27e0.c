float *__thiscall sub_5D27E0(_DWORD *this, int a2, int a3, int a4, int a5, float *a6)
{
  int v6; // esi
  float *result; // eax
  double v8; // st6
  double v9; // st7
  float v10; // [esp+20h] [ebp-54h]
  _BYTE v11[16]; // [esp+24h] [ebp-50h] BYREF
  float v12; // [esp+34h] [ebp-40h]
  float v13; // [esp+38h] [ebp-3Ch]
  float v14; // [esp+3Ch] [ebp-38h]
  _BYTE v15[16]; // [esp+4Ch] [ebp-28h] BYREF
  float v16; // [esp+5Ch] [ebp-18h]
  float v17; // [esp+60h] [ebp-14h]
  float v18; // [esp+64h] [ebp-10h]

  v6 = *(_DWORD *)(this[1] + 4);
  (*(void (__thiscall **)(_DWORD, _BYTE *, int, int, int))(**(_DWORD **)(a2 + 60) + 12))(
    *(_DWORD *)(a2 + 60),
    v11,
    v6,
    a3,
    a4);
  (*(void (__thiscall **)(_DWORD, _BYTE *, int, int, int))(**(_DWORD **)(a2 + 60) + 12))(
    *(_DWORD *)(a2 + 60),
    v15,
    v6,
    a3,
    a5);
  result = a6;
  v10 = v14 - v18;
  v8 = v12 - v16;
  v9 = v13 - v17;
  a6[6] = v10;
  a6[4] = v8;
  a6[5] = v9;
  return result;
}
