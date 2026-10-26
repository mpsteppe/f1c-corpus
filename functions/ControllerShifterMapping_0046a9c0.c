int __thiscall ControllerShifterMapping(int *this)
{
  int *v2; // edi
  int result; // eax
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int *v7; // esi

  v2 = this + 128;
  IDPairMatchAndClear(this + 128);
  result = 28 * this[125];
  *(int *)((char *)dword_7D1B08 + result) = *v2;
  *(int *)((char *)&dword_7D1B0C + result) = v2[1];
  if ( *v2 == 1 )
  {
    v4 = this[129];
    result = v4 - 1;
    switch ( v4 )
    {
      case 1:
        result = 0;
        v5 = 2;
        v6 = 0;
        goto LABEL_37;
      case 2:
        result = 0;
        v5 = 1;
        v6 = 0;
        goto LABEL_37;
      case 3:
        v5 = 4;
        result = 0;
        v6 = 1;
        goto LABEL_37;
      case 4:
        v5 = 3;
        result = 0;
        v6 = 1;
        goto LABEL_37;
      case 5:
        v5 = 6;
        result = 0;
        v6 = 2;
        goto LABEL_37;
      case 6:
        v5 = 5;
        result = 0;
        v6 = 2;
        goto LABEL_37;
      case 7:
        v5 = 8;
        result = 0;
        v6 = 3;
        goto LABEL_37;
      case 8:
        v5 = 7;
        result = 0;
        v6 = 3;
        goto LABEL_37;
      case 9:
        v5 = 10;
        result = 0;
        v6 = 4;
        goto LABEL_37;
      case 10:
        v5 = 9;
        result = 0;
        v6 = 4;
        goto LABEL_37;
      case 11:
        v5 = 12;
        result = 0;
        v6 = 5;
        goto LABEL_37;
      case 12:
        v5 = 11;
        result = 0;
        v6 = 5;
        goto LABEL_37;
      case 30:
        v5 = 31;
        result = 1;
        v6 = 0;
        goto LABEL_37;
      case 31:
        v5 = 30;
        result = 1;
        v6 = 0;
        goto LABEL_37;
      case 32:
        result = 1;
        v5 = 33;
        v6 = 1;
        goto LABEL_37;
      case 33:
        result = 1;
        v5 = 32;
        v6 = 1;
        goto LABEL_37;
      case 34:
        v5 = 35;
        result = 1;
        v6 = 2;
        goto LABEL_37;
      case 35:
        v5 = 34;
        result = 1;
        v6 = 2;
        goto LABEL_37;
      case 36:
        v5 = 37;
        result = 1;
        v6 = 3;
        goto LABEL_37;
      case 37:
        v5 = 36;
        result = 1;
        v6 = 3;
        goto LABEL_37;
      case 38:
        v5 = 39;
        result = 1;
        v6 = 4;
        goto LABEL_37;
      case 39:
        v5 = 38;
        result = 1;
        v6 = 4;
        goto LABEL_37;
      case 40:
        v5 = 41;
        result = 1;
        v6 = 5;
        goto LABEL_37;
      case 41:
        v5 = 40;
        result = 1;
        v6 = 5;
        goto LABEL_37;
      case 102:
        v5 = 103;
        result = 0;
        v6 = 6;
        goto LABEL_37;
      case 103:
        v5 = 102;
        result = 0;
        v6 = 6;
        goto LABEL_37;
      case 104:
        v5 = 105;
        result = 0;
        goto LABEL_36;
      case 105:
        v5 = 104;
        result = 0;
        goto LABEL_36;
      case 106:
        v5 = 107;
        result = 1;
        v6 = 6;
        goto LABEL_37;
      case 107:
        v5 = 106;
        result = 1;
        v6 = 6;
        goto LABEL_37;
      case 108:
        v5 = 109;
        goto LABEL_35;
      case 109:
        v5 = 108;
LABEL_35:
        result = 1;
LABEL_36:
        v6 = 7;
LABEL_37:
        v7 = &dword_7D1B0C;
        do
        {
          if ( *(v7 - 1) == 1 && *v7 == v5 )
            dword_7D1490[216 * result + 27 * v6] = 1056964608;
          v7 += 7;
        }
        while ( (int)v7 < (int)dword_7D1FDC );
        break;
      default:
        return result;
    }
  }
  return result;
}
