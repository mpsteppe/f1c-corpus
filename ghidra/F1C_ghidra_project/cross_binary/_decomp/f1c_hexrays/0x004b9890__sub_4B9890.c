// f1c  0x004b9890  size=358
char __thiscall sub_4B9890(float **this, float a2, _DWORD *a3)
{
  char result; // al
  int v5; // eax
  int v6; // ebp
  float v7; // edx
  int v8; // edi
  double v9; // st7
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+0h] [ebp-14h]
  char v12; // [esp+10h] [ebp-4h]

  result = byte_7CE254;
  if ( !byte_7CE254 )
  {
    v12 = byte_7C56AC;
    sub_42D210(&dword_7C569C, 1);
    v5 = sub_40CD60(&dword_5EA510);
    v6 = *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580);
    v7 = a2;
    v8 = v5;
    *a3 = 2;
    (*this)[993] = v7;
    if ( sub_4B87C0((int)*this) )
    {
      v9 = a2;
      if ( a2 >= 10.0 )
      {
        if ( v9 > 180.0 )
          v9 = 180.0;
      }
      else
      {
        v9 = 10.0;
      }
      v10 = dbl_8AFEA0 - v9;
      sub_4B9CD0(v10);
      (*this)[994] = sub_4B9CE0(this);
      sub_40CDE0(&dword_5EA510, 5, 0);
      do
      {
        a2 = COERCE_FLOAT(sub_4B8BD0());
        sub_4C8650(-1.0);
      }
      while ( sub_4B8AE0(*this, &a2) );
      v11 = dbl_8AFEA0;
      sub_4B9CD0(v11);
      sub_42BBD0(v6);
      sub_40CDE0(&dword_5EA510, v8, 0);
      sub_4B8940(*this);
    }
    *a3 = 1;
    sub_42D210(&dword_7C569C, v12);
    if ( v12 )
      return sub_4C8D60(&byte_8AC494);
    else
      return sub_4C8D70(&byte_8AC494);
  }
  return result;
}
