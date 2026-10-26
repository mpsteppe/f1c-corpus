char __thiscall sub_5024C0(float *this, char *String)
{
  char *v2; // esi
  char result; // al

  v2 = String;
  result = 0;
  if ( String )
  {
    String = (char *)strlen(String);
    if ( String )
    {
      sub_4ED930(v2, (float *)&String);
      sub_409B80(this, (float *)&String);
      return 1;
    }
  }
  return result;
}
