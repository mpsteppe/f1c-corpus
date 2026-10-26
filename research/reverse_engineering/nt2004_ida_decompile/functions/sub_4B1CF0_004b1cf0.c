char __thiscall sub_4B1CF0(_BYTE *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  double v8; // st7
  char result; // al
  char v10; // [esp+4h] [ebp-4h]

  v10 = 0;
  switch ( a2 )
  {
    case 0:
      switch ( dword_75CBB4 )
      {
        case 5:
          v3 = 13;
          break;
        case 7:
          v3 = 10;
          break;
        case 8:
          v3 = 12;
          break;
        default:
          v3 = 7;
          break;
      }
      goto LABEL_9;
    case 1:
      this[36] = 1;
      v4 = *(_DWORD *)(dword_75AAC4 + 20892);
      if ( v4 < 2 || v4 > 3 )
      {
        v5 = 13;
        if ( *(int *)(dword_75AAC4 + 20900) <= 0 )
        {
          switch ( *(_DWORD *)(dword_75AAC4 + 20844) )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 9:
            case 0xA:
              v5 = 7;
              goto LABEL_18;
            case 7:
              goto LABEL_13;
            case 8:
              v5 = 12;
              break;
            case 0xB:
              v5 = 8;
              break;
            default:
LABEL_18:
              if ( (unsigned __int8)sub_4B3000(&unk_766074) )
                v5 = 11;
              break;
          }
        }
        else
        {
          v5 = 9;
        }
      }
      else
      {
LABEL_13:
        v5 = 10;
      }
      if ( v5 != *((_DWORD *)this + 3) )
      {
        *((_DWORD *)this + 3) = v5;
        v10 = 1;
      }
      v6 = sub_4B25B0(0);
      if ( !v6 || *(_DWORD *)(v6 + 12) != *((_DWORD *)this + 3) )
        goto LABEL_41;
      goto LABEL_43;
    case 2:
      if ( *(int *)(dword_75AAC4 + 20900) <= 0 )
        goto LABEL_43;
      this[36] = 1;
      if ( *(_DWORD *)(dword_75AAC4 + 20904) == 2 )
      {
        v7 = 6;
      }
      else if ( *(_DWORD *)(dword_75AAC4 + 20904) == 3 )
      {
        v7 = 5;
      }
      else
      {
        v7 = 4;
      }
      if ( *((_DWORD *)this + 3) == v7 )
        goto LABEL_41;
      *((_DWORD *)this + 3) = v7;
      sub_4B25D0(2.5, 1);
      goto LABEL_42;
    case 3:
      v3 = 16 - ((unsigned __int8)sub_4DE9D0(dword_75AAC4 + 20836) != 0);
LABEL_9:
      if ( v3 == *((_DWORD *)this + 3) )
        goto LABEL_41;
      *((_DWORD *)this + 3) = v3;
      sub_4B25D0(2.5, 1);
      goto LABEL_42;
    case 4:
      v8 = *(float *)(dword_75AAC4 + 17408);
      if ( v8 <= 0.0 || *(float *)(dword_75AAC4 + 18792) * v8 >= 1.5 )
        goto LABEL_43;
      *((_DWORD *)this + 3) = 14;
LABEL_41:
      sub_4B25D0(2.5, v10);
LABEL_42:
      result = *this;
      break;
    case 5:
      *((_DWORD *)this + 3) = 17;
      if ( (unsigned __int8)sub_4DEB10(dword_75AAC4 + 20836) || dword_75CBB4 < 5 )
        goto LABEL_41;
      goto LABEL_43;
    default:
LABEL_43:
      sub_4B2610(this);
      result = *this;
      break;
  }
  return result;
}
