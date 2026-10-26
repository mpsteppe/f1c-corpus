int __stdcall sub_598180(int a1)
{
  double v1; // st7
  int result; // eax
  float v3; // [esp+0h] [ebp-4h]

  if ( !dword_7E8E34 )
    return 0;
  switch ( dword_7E8E2C )
  {
    case 1:
      v1 = (1.0 - (double)dword_7E8E1C / (double)dword_7E8E24) * 20.0;
      if ( v1 < 0.25 )
        return 0;
      goto LABEL_4;
    case 2:
      v1 = (1.0 - (double)Addend / (double)dword_7E8E28) * 80.0 + 20.0;
      if ( v1 < 0.25 )
        return 0;
LABEL_4:
      v3 = v1;
      dword_7E8E34(0, LODWORD(v3));
      result = 0;
      break;
    case 3:
      dword_7E8E34(0, 1120403456);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
