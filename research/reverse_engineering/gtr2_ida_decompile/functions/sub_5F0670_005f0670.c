int __thiscall sub_5F0670(_DWORD *this)
{
  int result; // eax

  switch ( *(_DWORD *)(this[43] + 24) )
  {
    case 5:
    case 6:
      sub_5EFB30((int)this);
      *(_DWORD *)(this[43] + 28) = this[23];
      result = 0;
      break;
    case 7:
    case 8:
    case 0xE:
      sub_5EFD80((int)this);
      goto LABEL_4;
    default:
LABEL_4:
      *(_DWORD *)(this[43] + 28) = this[23];
      result = 0;
      break;
  }
  return result;
}
