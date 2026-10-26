bool __thiscall sub_57A240(FILE **this, char *Source, FILE *a3, FILE *a4, char a5)
{
  bool result; // al
  FILE *v7; // eax
  bool v8; // bl
  char FileName[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( !a5 || (result = sub_57A0C0(Source)) )
  {
    this[3] = a4;
    this[4] = a3;
    sub_57B040(Source, 1024);
    if ( this[3] )
      v7 = fopen(FileName, aAt);
    else
      v7 = fopen(FileName, aAb);
    *this = v7;
    v8 = v7 != 0;
    *((_BYTE *)this + 24) = 0;
    if ( v7 )
      sub_578600((int)(this + 1), FileName);
    return v8;
  }
  return result;
}
