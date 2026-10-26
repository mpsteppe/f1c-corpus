void *__thiscall sub_5995B0(_DWORD *this, void *a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // edx
  void *result; // eax
  _DWORD v8[9]; // [esp+8h] [ebp-24h] BYREF

  v2 = this[3];
  v8[0] = *this;
  v8[2] = this[6];
  v8[4] = this[4];
  v3 = this[2];
  v8[1] = v2;
  v4 = this[1];
  v8[6] = v3;
  v5 = this[8];
  v8[3] = v4;
  v6 = this[7];
  v8[8] = v5;
  result = a2;
  v8[5] = v6;
  v8[7] = this[5];
  qmemcpy(a2, v8, 0x24u);
  return result;
}
