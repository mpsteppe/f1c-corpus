int __stdcall sub_545F50(int a1)
{
  double v1; // st7
  int result; // eax
  float v3; // [esp+0h] [ebp-4h]

  if ( !dword_8B8F00 )
    return 0;
  switch ( dword_8B8EF8 )
  {
    case 1:
      v1 = (1.0 - (double)dword_8B8EE8 / (double)dword_8B8EF0) * 20.0;
      if ( v1 < 0.25 )
        return 0;
      goto LABEL_4;
    case 2:
      v1 = (1.0 - (double)Addend / (double)dword_8B8EF4) * 80.0 + 20.0;
      if ( v1 < 0.25 )
        return 0;
LABEL_4:
      v3 = v1;
      dword_8B8F00(0, LODWORD(v3));
      result = 0;
      break;
    case 3:
      dword_8B8F00(0, 1120403456);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}

