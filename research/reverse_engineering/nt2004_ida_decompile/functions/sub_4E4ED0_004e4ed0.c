int __thiscall sub_4E4ED0(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 30972) - 1;
  switch ( *(_DWORD *)(this + 30972) )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      *(_DWORD *)(this + 30972) = 5;
      *(_BYTE *)(this + 30976) = 0;
      break;
    case 5:
      *(_DWORD *)(this + 30972) = 6;
      *(_BYTE *)(this + 30976) = 0;
      break;
    case 6:
      *(_DWORD *)(this + 30972) = 7;
      *(_BYTE *)(this + 30976) = 0;
      break;
    case 7:
      sub_4E4F60((_BYTE *)this);
      result = sub_4E4F70(this);
      goto LABEL_6;
    default:
LABEL_6:
      *(_BYTE *)(this + 30976) = 0;
      break;
  }
  return result;
}
