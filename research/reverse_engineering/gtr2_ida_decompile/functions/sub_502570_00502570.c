char __thiscall sub_502570(_DWORD *this, const char *a2)
{
  char result; // al
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // [esp+8h] [ebp-4h]

  result = 0;
  if ( a2 && strlen(a2) )
  {
    sub_4ED9A0();
    v4 = this[7];
    v5 = this[8];
    this[5] = v6;
    if ( v6 >= v4 )
    {
      if ( v6 > v5 )
        this[5] = v5;
      return 1;
    }
    else
    {
      this[5] = v4;
      return 1;
    }
  }
  return result;
}
