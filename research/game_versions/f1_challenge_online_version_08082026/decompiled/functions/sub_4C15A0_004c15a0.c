int __thiscall sub_4C15A0(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 45388) - 1;
  switch ( *(_DWORD *)(this + 45388) )
  {
    case 1:
      *(_DWORD *)(this + 45388) = 2;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 2:
      *(_DWORD *)(this + 45388) = 3;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 3:
      *(_DWORD *)(this + 45388) = 4;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 4:
      *(_DWORD *)(this + 45388) = 5;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 5:
      *(_DWORD *)(this + 45388) = 6;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 6:
      *(_DWORD *)(this + 45388) = 7;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 7:
      sub_4C1660(this);
      result = sub_4C1670(this);
      goto LABEL_9;
    default:
LABEL_9:
      *(_BYTE *)(this + 45392) = 0;
      break;
  }
  return result;
}
