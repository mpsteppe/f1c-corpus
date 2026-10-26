int __thiscall sub_419E80(_DWORD *this, int a2)
{
  unsigned int v4; // edx
  int v5; // ecx
  int v6; // esi
  double v7; // st7
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  double v11; // st7
  int v12; // edx
  double v13; // st7
  int result; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  int v17; // edi
  unsigned int v18; // ebp
  _DWORD *v19; // ecx
  int v20; // ebp
  _DWORD *v21; // ecx
  char v22[4]; // [esp+1Ch] [ebp-48h] BYREF
  char v23[12]; // [esp+20h] [ebp-44h] BYREF
  char v24[4]; // [esp+2Ch] [ebp-38h] BYREF
  int v25; // [esp+30h] [ebp-34h]
  float v26; // [esp+34h] [ebp-30h]
  float v27; // [esp+38h] [ebp-2Ch]
  float v28[10]; // [esp+3Ch] [ebp-28h] BYREF
  int retaddr; // [esp+64h] [ebp+0h]
  signed int v30; // [esp+68h] [ebp+4h]
  int v31; // [esp+68h] [ebp+4h]

  v4 = *(_DWORD *)(a2 + 10);
  v5 = *(_DWORD *)(a2 + 14);
  v6 = *(__int16 *)(a2 + 8);
  v25 = *(_DWORD *)(a2 + 4);
  v30 = (*(_DWORD *)(a2 + 14) & 0xFFC00000) + ((v4 >> 10) & 0x3FF000);
  v26 = (double)(int)(v4 << 10) * 0.000015258789;
  v7 = (double)v30;
  v31 = v5 << 10;
  v27 = v7 * 0.0000019073486;
  v28[0] = (double)(v5 << 10) * 0.000015258789;
  sub_51A6F0(a2 + 18, v23);
  sub_614DB0(v22, v28);
  v8 = *(__int16 *)(a2 + 26);
  v9 = *(__int16 *)(a2 + 28);
  retaddr = *(__int16 *)(a2 + 24);
  v10 = *(__int16 *)(a2 + 30);
  v28[3] = (double)*(__int16 *)(a2 + 22) * 0.015625;
  v11 = (double)retaddr;
  retaddr = v8;
  v12 = *(__int16 *)(a2 + 32);
  v28[4] = v11 * 0.015625;
  v13 = (double)retaddr;
  retaddr = v9;
  result = ((*(_DWORD *)a2 >> 18) & 0x3F) - 1;
  v28[5] = v13 * 0.015625;
  v28[6] = (double)retaddr * 0.0078125;
  retaddr = v12;
  v28[7] = (double)v10 * 0.0078125;
  v28[8] = (double)v12 * 0.0078125;
  switch ( result )
  {
    case 0:
      if ( v6 >= 0 && v6 < this[9] )
      {
        v15 = this[10];
        goto LABEL_38;
      }
      return result;
    case 1:
      if ( v6 >= 0 && v6 < this[12] )
      {
        v15 = this[13];
        goto LABEL_38;
      }
      return result;
    case 2:
      if ( v6 >= 0 && v6 < this[15] )
      {
        v15 = this[16];
        goto LABEL_38;
      }
      return result;
    case 3:
      if ( v6 >= 0 && v6 < this[18] )
      {
        if ( v6 >= 420 )
        {
          return sub_419950((_DWORD *)(this[19] + 40 * v6), (int)v24);
        }
        else
        {
          v16 = (_DWORD *)(this[19] + 40 * v6);
          if ( *v16 == -1 )
          {
            result = dword_921100[5654 * (v6 / 4) + 74 * (v6 & 3)];
            if ( !result )
              return result;
            sub_417E90(v16, result, 1);
          }
          return off_16C95A8(v6 / 4, v31);
        }
      }
      return result;
    case 4:
      if ( v6 < 0 || v6 >= this[21] )
        return result;
      if ( v6 >= 210 )
        return sub_419950((_DWORD *)(this[22] + 40 * v6), (int)v24);
      v17 = v6 / 2;
      v18 = v6 & 0x80000001;
      v19 = (_DWORD *)(this[22] + 40 * v6);
      if ( *v19 != -1 )
        goto LABEL_28;
      if ( v18 )
        result = dword_9215E4[5654 * v17];
      else
        result = dword_9215A0[5654 * v17];
      if ( result )
      {
        sub_417E90(v19, result, 1);
LABEL_28:
        sub_57C120((v18 != 0) + 4);
        return sub_419950((_DWORD *)(this[22] + 40 * v6), (int)v24);
      }
      break;
    case 5:
      if ( v6 < 0 || v6 >= this[24] )
        return result;
      if ( v6 >= 840 )
        goto LABEL_37;
      v20 = v6 & 7;
      v21 = (_DWORD *)(this[25] + 40 * v6);
      if ( *v21 != -1 )
        goto LABEL_36;
      result = dword_921628[5654 * (v6 / 8) + 17 * v20];
      if ( result )
      {
        sub_417E90(v21, result, 1);
LABEL_36:
        sub_57C120(v20 + 6);
LABEL_37:
        v15 = this[25];
LABEL_38:
        result = sub_419950((_DWORD *)(v15 + 40 * v6), (int)v24);
      }
      break;
    default:
      return result;
  }
  return result;
}
