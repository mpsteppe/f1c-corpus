int __thiscall sub_40A150(_DWORD *this)
{
  int result; // eax

  result = dword_7681E0;
  switch ( dword_7681E0 )
  {
    case 0:
      result = sub_40A1B0(aCockpit);
      goto LABEL_6;
    case 1:
      result = sub_40A1B0(aRoofcam);
      goto LABEL_6;
    case 2:
      result = sub_40A1B0(aSwingman);
      goto LABEL_6;
    case 3:
      result = sub_40A1B0(aNosecam);
LABEL_6:
      if ( (_BYTE)result )
        this[6] = 0;
      break;
    default:
      return result;
  }
  return result;
}
