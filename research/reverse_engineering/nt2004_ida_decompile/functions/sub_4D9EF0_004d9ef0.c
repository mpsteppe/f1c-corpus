char __thiscall sub_4D9EF0(int *this, int a2)
{
  char result; // al
  const char *v4; // eax
  char Buffer[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v6; // [esp+85h] [ebp-3h]
  char v7; // [esp+87h] [ebp-1h]

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
      *(_DWORD *)(*this + 2164) = a2;
      result = 1;
      break;
    case 5:
      if ( *(_DWORD *)(*this + 2164) != 5 )
        sub_4EFA70(&byte_7D6B78);
      *(_DWORD *)(*this + 2164) = 5;
      result = 1;
      break;
    case 6:
      if ( *(_DWORD *)(*this + 2164) == 5 && flt_767898 > 0.0 )
      {
        Buffer[0] = byte_629120;
        memset(&Buffer[1], 0, 0x7Cu);
        v6 = 0;
        v7 = 0;
        v4 = *(const char **)dword_62A070;
        if ( !*(_DWORD *)dword_62A070 )
          v4 = &byte_629120;
        sub_405480(Buffer, 0x7Fu, "%s%s", v4, aAmbientReplayM);
        sub_4EF930(Buffer);
      }
      *(_DWORD *)(*this + 2164) = 6;
      result = 1;
      break;
    case 9:
      sub_4D7DA0((_DWORD *)*this, 0);
      result = 1;
      break;
    case 10:
      sub_4D7F60(*this);
      result = 1;
      break;
    case 11:
      sub_4D8080(*this);
      result = 1;
      break;
    case 12:
      sub_4D80F0(*this);
      result = 1;
      break;
    case 13:
      sub_4D81D0(*this);
      goto LABEL_17;
    default:
LABEL_17:
      result = 1;
      break;
  }
  return result;
}
