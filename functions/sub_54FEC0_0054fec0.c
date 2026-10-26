int __thiscall sub_54FEC0(int this, const char *a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  bool v8; // zf
  char v10[64]; // [esp+Ch] [ebp-40h] BYREF

  v7 = 0;
  if ( a3 > 128 )
  {
    if ( a3 > 1024 )
    {
      if ( a3 == 2048 )
        goto LABEL_12;
      v8 = a3 == 4096;
    }
    else
    {
      if ( a3 == 1024 || a3 == 256 )
        goto LABEL_12;
      v8 = a3 == 512;
    }
    if ( !v8 )
LABEL_11:
      v7 = 1;
  }
  else if ( a3 != 128 )
  {
    switch ( a3 )
    {
      case 1:
      case 2:
      case 4:
      case 8:
      case 16:
      case 32:
      case 64:
        break;
      default:
        goto LABEL_11;
    }
  }
LABEL_12:
  if ( a4 > 128 )
  {
    if ( a4 > 1024 )
    {
      if ( a4 != 2048 && a4 != 4096 )
        goto LABEL_23;
    }
    else if ( a4 != 1024 && a4 != 256 && a4 != 512 )
    {
      goto LABEL_23;
    }
  }
  else if ( a4 != 128 )
  {
    switch ( a4 )
    {
      case 1:
      case 2:
      case 4:
      case 8:
      case 16:
      case 32:
      case 64:
        break;
      default:
        goto LABEL_23;
    }
  }
  if ( v7 )
  {
LABEL_23:
    StringFormatWithBufferOverflowCheck(v10, "Texture %s size not power of 2", a2);
    sub_53C590(-1, v10);
    return -1;
  }
  sub_54FE50((const CHAR *)this, a2);
  if ( !UtilityFunction_2950(*(_DWORD **)(this + 84), a3, a4, a5, a6) )
    return 0;
  DestructorWithConditionalFreeFlagClear(this);
  return -1;
}
