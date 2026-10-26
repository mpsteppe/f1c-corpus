int __thiscall sub_417CB0(_DWORD *this, int a2)
{
  int v3; // edx
  unsigned int v5; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  double v10; // st7
  int v11; // ecx
  int v12; // edx
  int result; // eax
  int v14; // ebp
  _DWORD *v15; // ecx
  int v16; // eax
  int v17; // edi
  unsigned int v18; // ebp
  _DWORD *v19; // ecx
  int v20; // edi
  _DWORD *v21; // ecx
  _BYTE v22[16]; // [esp+10h] [ebp-44h] BYREF
  float v23[4]; // [esp+20h] [ebp-34h] BYREF
  char v24[12]; // [esp+30h] [ebp-24h] BYREF
  float v25; // [esp+3Ch] [ebp-18h]
  float v26; // [esp+40h] [ebp-14h]
  float v27; // [esp+44h] [ebp-10h]
  float v28; // [esp+48h] [ebp-Ch]
  float v29; // [esp+4Ch] [ebp-8h]
  float v30; // [esp+50h] [ebp-4h]
  int v31; // [esp+58h] [ebp+4h]
  int v32; // [esp+58h] [ebp+4h]

  v3 = *(_DWORD *)(a2 + 14);
  v5 = *(_DWORD *)(a2 + 10);
  v23[0] = *(float *)(a2 + 4);
  v6 = *(__int16 *)(a2 + 8);
  v23[1] = (double)(int)(v5 << 10) * 0.000015258789;
  v23[2] = (double)(int)((v3 & 0xFFC00000) + ((v5 >> 10) & 0x3FF000)) * 0.0000019073486;
  v23[3] = (double)(v3 << 10) * 0.000015258789;
  sub_4CF950(v22);
  sub_579430(v22, v24);
  v7 = *(__int16 *)(a2 + 26);
  v8 = *(__int16 *)(a2 + 28);
  v31 = *(__int16 *)(a2 + 24);
  v9 = *(__int16 *)(a2 + 30);
  v25 = (double)*(__int16 *)(a2 + 22) * 0.015625;
  v10 = (double)v31;
  v32 = v7;
  v11 = *(__int16 *)(a2 + 32);
  v26 = v10 * 0.015625;
  v27 = (double)v32 * 0.015625;
  v28 = (double)v8 * 0.0078125;
  v29 = (double)v9 * 0.0078125;
  v12 = *(_BYTE *)(a2 + 2) & 0x3F;
  result = v12 - 1;
  v30 = (double)v11 * 0.0078125;
  switch ( v12 )
  {
    case 1:
      if ( v6 >= 0 && v6 < this[9] )
        return sub_416060((_DWORD *)(this[10] + 40 * v6), v23);
      return result;
    case 2:
      if ( v6 >= 0 && v6 < this[12] )
        return sub_416060((_DWORD *)(this[13] + 40 * v6), v23);
      return result;
    case 3:
      if ( v6 >= 0 && v6 < this[15] )
        return sub_416060((_DWORD *)(this[16] + 40 * v6), v23);
      return result;
    case 4:
      if ( v6 < 0 || v6 >= this[18] )
        return result;
      if ( v6 >= 196 )
        goto LABEL_18;
      v14 = v6 & 3;
      v15 = (_DWORD *)(this[19] + 40 * v6);
      if ( *v15 != -1 )
        goto LABEL_17;
      result = dword_62C820[6326 * (v6 / 4) + 76 * v14];
      if ( result )
      {
        sub_415860(v15, result, 1);
LABEL_17:
        sub_519850(v14);
LABEL_18:
        v16 = this[19];
        return sub_416060((_DWORD *)(v16 + 40 * v6), v23);
      }
      return result;
    case 5:
      if ( v6 < 0 || v6 >= this[21] )
        return result;
      if ( v6 >= 98 )
        goto LABEL_29;
      v17 = v6 / 2;
      v18 = v6 & 0x80000001;
      v19 = (_DWORD *)(this[22] + 40 * v6);
      if ( *v19 != -1 )
        goto LABEL_28;
      if ( v18 )
        result = dword_62CD24[6326 * v17];
      else
        result = dword_62CCE0[6326 * v17];
      if ( !result )
        return result;
      sub_415860(v19, result, 1);
LABEL_28:
      sub_519850((v18 != 0) + 4);
LABEL_29:
      v16 = this[22];
      break;
    case 6:
      if ( v6 < 0 || v6 >= this[24] )
        return result;
      if ( v6 >= 588 )
        goto LABEL_37;
      v20 = v6 % 12;
      v21 = (_DWORD *)(this[25] + 40 * v6);
      if ( *v21 != -1 )
        goto LABEL_36;
      result = dword_62CD68[6326 * (v6 / 12) + 17 * v20];
      if ( !result )
        return result;
      sub_415860(v21, result, 1);
LABEL_36:
      sub_519850(v20 + 6);
LABEL_37:
      v16 = this[25];
      break;
    default:
      return result;
  }
  return sub_416060((_DWORD *)(v16 + 40 * v6), v23);
}
