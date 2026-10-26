void __thiscall sub_4AE2C0(_DWORD *this, char *String2)
{
  const char **v3; // eax
  _DWORD *v4; // eax

  if ( String2 )
  {
    if ( strlen(String2) )
    {
      sub_4ADDF0(this, String2);
      v3 = sub_4AD420(this, String2);
      this[91] = v3;
      if ( !v3 )
      {
        if ( (int)this[90] > 0 && (v4 = (_DWORD *)this[87]) != 0 )
          this[91] = *v4;
        else
          this[91] = 0;
      }
    }
  }
}
