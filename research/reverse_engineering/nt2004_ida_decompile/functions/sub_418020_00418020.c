int __thiscall sub_418020(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // esi
  int v4; // edx
  int v5; // [esp+0h] [ebp-3Ch]
  int v6; // [esp+4h] [ebp-38h]
  int v7; // [esp+8h] [ebp-34h]
  float v8[3]; // [esp+20h] [ebp-1Ch] BYREF
  _BYTE v9[16]; // [esp+2Ch] [ebp-10h] BYREF

  result = *(__int16 *)(a2 + 8);
  switch ( *(_BYTE *)(a2 + 2) & 0x3F )
  {
    case 1:
      if ( result >= 0 && result < this[9] )
      {
        result *= 796;
        v3 = *(_DWORD *)(result + this[11] + 212);
        goto LABEL_22;
      }
      break;
    case 2:
      if ( result >= 0 && result < this[12] )
      {
        v4 = this[14];
        goto LABEL_20;
      }
      break;
    case 3:
      if ( result >= 0 && result < this[15] )
      {
        result *= 796;
        v3 = *(_DWORD *)(result + this[17] + 212);
        goto LABEL_22;
      }
      break;
    case 4:
      if ( result >= 0 && result < this[18] )
      {
        v4 = this[20];
        result *= 812;
        goto LABEL_21;
      }
      break;
    case 5:
      if ( result >= 0 && result < this[21] )
      {
        result *= 796;
        v3 = *(_DWORD *)(result + this[23] + 212);
        goto LABEL_22;
      }
      break;
    case 6:
      if ( result >= 0 && result < this[24] )
      {
        v4 = this[26];
LABEL_20:
        result *= 796;
LABEL_21:
        v3 = *(_DWORD *)(result + v4 + 212);
LABEL_22:
        if ( v3 )
        {
          sub_4CF950(v9);
          sub_579430(v9, v8);
          *(float *)&v7 = (double)(int)(*(_DWORD *)(a2 + 14) << 10) * 0.000015258789;
          *(float *)&v6 = (double)(int)((*(_DWORD *)(a2 + 14) & 0xFFC00000) + ((*(_DWORD *)(a2 + 10) >> 10) & 0x3FF000))
                        * 0.0000019073486;
          *(float *)&v5 = (double)(int)(*(_DWORD *)(a2 + 10) << 10) * 0.000015258789;
          result = sub_59E170(v5, v6, v7, v8[0], v8[1], v8[2]);
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
