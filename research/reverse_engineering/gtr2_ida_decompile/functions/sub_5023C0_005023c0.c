char __thiscall sub_5023C0(_BYTE *this, const char *a2)
{
  const char *v2; // edi
  char result; // al
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  bool v7; // cf
  unsigned __int8 v8; // dl

  v2 = a2;
  result = 0;
  if ( a2 )
  {
    a2 = (const char *)strlen(a2);
    if ( a2 )
    {
      sub_4ED970(v2, (bool *)&a2);
      v5 = (unsigned __int8)a2;
      v6 = this[22];
      v7 = (unsigned __int8)a2 < v6;
      v8 = this[23];
      this[20] = (_BYTE)a2;
      if ( v7 )
      {
        this[20] = v6;
        return 1;
      }
      else
      {
        if ( v5 > v8 )
          this[20] = v8;
        return 1;
      }
    }
  }
  return result;
}
