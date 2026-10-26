// positive sp value has been detected, the output may be wrong!
int __thiscall sub_5429CA(void *this, int a2, int a3, float *a4, int a5)
{
  int v5; // ebp
  int v7; // edi
  char v8; // [esp-70h] [ebp-80h] BYREF
  char v9; // [esp-6Fh] [ebp-7Fh] BYREF

  v5 = sub_6137E0(this);
  if ( !v5 )
    return v5;
  if ( v8 >= 48 && v8 <= 57 || v8 == 46 || v8 == 45 )
  {
    *a4 = atof(&v8);
    return v5;
  }
  if ( v8 == 40 )
  {
    *a4 = atof(&v9);
    return v5;
  }
  else
  {
    v7 = a5;
    if ( a5 )
    {
      while ( strcmp(&v8, (const char *)v7) )
      {
        v7 = *(_DWORD *)(v7 + 36);
        if ( !v7 )
          goto LABEL_11;
      }
      *a4 = *(float *)(v7 + 32);
      return v5;
    }
    else
    {
LABEL_11:
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\specialfx.cpp", 2853) )
        sub_561210(
          (int)byte_FAE910,
          "Could not find track variable \"%s\" referenced with keyword \"%s\" in terrain.ini",
          (char)&v8);
      return 0;
    }
  }
}
