float *__thiscall sub_569300(_DWORD *this, float *a2, _DWORD *a3, const void *a4)
{
  _DWORD *v5; // ecx
  float *v6; // edx
  float *result; // eax
  double v8; // st7
  float v9; // [esp+Ch] [ebp-18h]
  float v10; // [esp+10h] [ebp-14h]
  float v11; // [esp+14h] [ebp-10h]
  float v12; // [esp+20h] [ebp-4h]

  v5 = this + 6;
  *v5 = *a3;
  v5[1] = a3[1];
  v5[2] = a3[2];
  v6 = (float *)(this + 9);
  qmemcpy(this + 9, a4, 0x24u);
  this[22] = *(_DWORD *)a2;
  this[23] = *((_DWORD *)a2 + 1);
  this[24] = *((_DWORD *)a2 + 2);
  result = (float *)(this + 3);
  v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];
  v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;
  v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a2[1];
  v8 = v12 + a2[2];
  *result = v9;
  result[1] = v10;
  v11 = v8;
  result[2] = v11;
  return result;
}
