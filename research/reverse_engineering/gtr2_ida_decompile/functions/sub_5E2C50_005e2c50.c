int __thiscall sub_5E2C50(int this)
{
  int v2; // eax
  int result; // eax

  v2 = *(_DWORD *)(this + 96) - 2;
  *(_BYTE *)(this + 464) = 0;
  switch ( v2 )
  {
    case 0:
      sub_609BF0(13);
      goto LABEL_18;
    case 1:
      sub_609BF0(2);
      goto LABEL_18;
    case 2:
    case 9:
      if ( *(_DWORD *)(this + 100) == 2 )
      {
        sub_609BF0(8);
        result = sub_60A000(7);
        *(_BYTE *)(this + 464) = 1;
      }
      else
      {
        result = *(_DWORD *)(this + 100) - 5;
        if ( *(_DWORD *)(this + 100) != 5 )
          goto LABEL_19;
        sub_609BF0(17);
        result = sub_60A000(7);
        *(_BYTE *)(this + 464) = 1;
      }
      return result;
    case 10:
      sub_609BF0(8);
      result = sub_60A000(1);
      *(_BYTE *)(this + 464) = 1;
      return result;
    case 13:
      if ( *(_DWORD *)(this + 100) == 5 )
      {
LABEL_15:
        sub_609BF0(17);
LABEL_18:
        result = sub_60A000(2);
      }
      else
      {
        result = *(_DWORD *)(this + 100) - 6;
        if ( *(_DWORD *)(this + 100) == 6 )
        {
          sub_609BF0(14);
          result = sub_60A000(6);
          *(_BYTE *)(this + 464) = 1;
          return result;
        }
      }
LABEL_19:
      *(_BYTE *)(this + 464) = 1;
      return result;
    default:
      result = *(_DWORD *)(this + 100) - 1;
      switch ( *(_DWORD *)(this + 100) )
      {
        case 1:
          sub_609BF0(1);
          result = sub_60A000(3);
          *(_BYTE *)(this + 464) = 1;
          break;
        case 2:
          sub_609BF0(2);
          result = sub_60A000(7);
          *(_BYTE *)(this + 464) = 1;
          break;
        case 4:
        case 7:
          goto LABEL_19;
        case 5:
          goto LABEL_15;
        case 8:
          sub_609BF0(1);
          goto LABEL_18;
        default:
          sub_609BF0(4);
          goto LABEL_18;
      }
      return result;
  }
}
