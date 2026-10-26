int __thiscall SetupIntegerFormatDS(_DWORD *this, float a2, _BYTE *a3)
{
  const char *v3; // eax
  float v5; // [esp+8h] [ebp+4h]

  v5 = a2 - 273.16;
  if ( this[1] == 1 )
  {
    v3 = &byte_5C3738;
    v5 = (v5 - -40.0) * 1.8 - 40.0;
  }
  else
  {
    v3 = &byte_5C3734;
  }
  return StringFormatWithBufferOverflowCheck(a3, (int)"%d %s", (int)v5, v3);
}
