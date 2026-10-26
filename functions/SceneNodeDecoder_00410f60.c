int __thiscall sub_410F60(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // eax
  int v5; // [esp+0h] [ebp-1Ch]
  int v6; // [esp+4h] [ebp-18h]
  int v7; // [esp+8h] [ebp-14h]
  float v8; // [esp+Ch] [ebp-10h]
  float v9; // [esp+10h] [ebp-Ch]
  float v10; // [esp+14h] [ebp-8h]

  result = *(__int16 *)(a2 + 8);
  switch ( (*(_DWORD *)a2 >> 18) & 0x3F )
  {
    case 1:
      if ( result >= 0 && result < this[9] )
      {
        result = *(_DWORD *)(792 * result + this[11] + 208);
        goto LABEL_22;
      }
      break;
    case 2:
      if ( result >= 0 && result < this[12] )
      {
        v3 = this[14];
        goto LABEL_20;
      }
      break;
    case 3:
      if ( result >= 0 && result < this[15] )
      {
        result = *(_DWORD *)(792 * result + this[17] + 208);
        goto LABEL_22;
      }
      break;
    case 4:
      if ( result >= 0 && result < this[18] )
      {
        v3 = this[20];
        v4 = 808 * result;
        goto LABEL_21;
      }
      break;
    case 5:
      if ( result >= 0 && result < this[21] )
      {
        result = *(_DWORD *)(792 * result + this[23] + 208);
        goto LABEL_22;
      }
      break;
    case 6:
      if ( result >= 0 && result < this[24] )
      {
        v3 = this[26];
LABEL_20:
        v4 = 792 * result;
LABEL_21:
        result = *(_DWORD *)(v4 + v3 + 208);
LABEL_22:
        if ( result )
        {
          v10 = (double)*(__int16 *)(a2 + 23) * 0.00048828125;
          v9 = (double)*(__int16 *)(a2 + 21) * 0.00048828125;
          v8 = (double)*(__int16 *)(a2 + 19) * 0.00048828125;
          *(float *)&v7 = (double)((*(unsigned __int8 *)(a2 + 18) << 24) + ((*(_DWORD *)(a2 + 14) >> 8) & 0xFFFF00))
                        * 0.000030517578;
          *(float *)&v6 = (double)((*(_DWORD *)(a2 + 14) << 16) + (*(_WORD *)(a2 + 12) & 0xFF00)) * 0.000030517578;
          *(float *)&v5 = (double)(int)(*(_DWORD *)(a2 + 10) << 8) * 0.000030517578;
          result = sub_54B4D0(v5, v6, v7, v8, v9, v10);
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
