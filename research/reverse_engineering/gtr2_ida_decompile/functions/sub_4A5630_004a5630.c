float *__thiscall sub_4A5630(_DWORD *this)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ebp
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // esi
  int v8; // edx
  float *result; // eax
  int v10; // [esp+10h] [ebp-4h]

  v1 = this[76];
  v2 = v1 - 623;
  switch ( v1 )
  {
    case 623:
    case 624:
      this[77] = &dword_B74838;
      goto LABEL_7;
    case 625:
    case 626:
      this[77] = &dword_B74800;
      goto LABEL_7;
    case 627:
    case 628:
      this[77] = &dword_B7481C;
      goto LABEL_7;
    case 629:
    case 630:
      this[77] = &dword_B748C4;
      goto LABEL_7;
    case 631:
    case 632:
    case 633:
    case 634:
    case 635:
    case 636:
    case 637:
      goto LABEL_7;
    case 638:
    case 639:
      this[77] = &dword_B74CEC;
LABEL_7:
      switch ( v1 )
      {
        case 623:
        case 625:
        case 627:
        case 629:
        case 638:
          v3 = 1;
          break;
        case 624:
        case 626:
        case 628:
        case 630:
        case 639:
          v3 = 0;
          break;
        default:
          goto LABEL_10;
      }
      break;
    default:
LABEL_10:
      v3 = v10;
      break;
  }
  v4 = (_DWORD *)this[77];
  v5 = v4[1];
  if ( (v5 < 1 || v5 > 12) && (v5 < 132 || v5 > 135) )
    v6 = v10;
  else
    v6 = 0;
  if ( v5 >= 40 && v5 <= 51 || v5 >= 136 && v5 <= 139 )
    v6 = 1;
  if ( v5 >= 140 && v5 <= 151 || v5 >= 196 && v5 <= 199 )
    v6 = 2;
  switch ( v5 )
  {
    case 1:
    case 2:
    case 40:
    case 41:
    case 140:
    case 141:
      v7 = 0;
      break;
    case 3:
    case 4:
    case 42:
    case 43:
    case 142:
    case 143:
      v7 = 1;
      break;
    case 5:
    case 6:
    case 44:
    case 45:
    case 144:
    case 145:
      v7 = 2;
      break;
    case 7:
    case 8:
    case 46:
    case 47:
    case 146:
    case 147:
      v7 = 3;
      break;
    case 9:
    case 10:
    case 48:
    case 49:
    case 148:
    case 149:
      v7 = 4;
      break;
    case 11:
    case 12:
    case 50:
    case 51:
    case 150:
    case 151:
      v7 = 5;
      break;
    case 132:
    case 133:
    case 136:
    case 137:
    case 196:
    case 197:
      v7 = 6;
      break;
    case 134:
    case 135:
    case 138:
    case 139:
    case 198:
    case 199:
      v7 = 7;
      break;
    default:
      v7 = 8;
      break;
  }
  if ( !*v4 || v7 == 8 )
  {
    this[73] = 1036831949;
    switch ( v2 )
    {
      case 0:
        result = &flt_B738DC;
        break;
      case 1:
      case 3:
      case 5:
      case 7:
      case 15:
      case 16:
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 40))(this, 0);
        goto LABEL_46;
      case 2:
        result = &flt_B73900;
        break;
      case 4:
        result = &flt_B73924;
        break;
      case 6:
        result = &flt_B73948;
        break;
      default:
LABEL_46:
        result = 0;
        break;
    }
  }
  else
  {
    v8 = *this;
    this[73] = 0;
    (*(void (__stdcall **)(int))(v8 + 40))(1);
    return (float *)(36 * (v7 + 8 * v6 + v3 + 2 * (v7 + 8 * v6)) + 12008136);
  }
  return result;
}
