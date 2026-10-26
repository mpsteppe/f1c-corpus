int __thiscall sub_5AA3F0(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  int result; // eax

  v3 = this;
  switch ( a2 )
  {
    case 1:
      goto LABEL_9;
    case 2:
      v3 = this + 1;
      goto LABEL_9;
    case 3:
      v3 = this + 2;
      goto LABEL_9;
    case 4:
      v3 = this + 5;
      goto LABEL_9;
    case 5:
      v3 = this + 6;
      goto LABEL_9;
    case 6:
      v3 = this + 7;
      goto LABEL_9;
    case 13:
      v3 = this + 3;
      goto LABEL_9;
    case 14:
      v3 = this + 4;
LABEL_9:
      if ( !v3 || *v3 == a3 )
        goto LABEL_12;
      *v3 = a3;
      result = 1;
      break;
    default:
LABEL_12:
      result = 0;
      break;
  }
  return result;
}
