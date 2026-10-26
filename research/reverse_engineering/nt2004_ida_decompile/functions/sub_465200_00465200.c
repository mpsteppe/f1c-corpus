int __thiscall sub_465200(int *this, char *Source)
{
  int result; // eax
  char *v4; // esi

  if ( Source )
  {
    v4 = (char *)(*this + 400);
    strncpy(v4, Source, 0x1Fu);
    v4[31] = 0;
    result = sub_4634D0(this);
    if ( (_BYTE)result )
      return sub_56A280(Source);
  }
  else
  {
    result = *this;
    *(_BYTE *)(*this + 400) = 0;
  }
  return result;
}
