char __thiscall sub_4B41E0(_DWORD *this, unsigned __int8 a2)
{
  const char *v3; // eax
  char *v4; // eax

  ConditionalDispatch_6bd0(this, 4);
  v3 = (const char *)this[1];
  if ( !v3 )
    v3 = byte_5EA438;
  a2 = strlen(v3);
  ConditionalDispatch_6bd0(&a2, 1);
  if ( a2 )
  {
    v4 = (char *)this[1];
    if ( !v4 )
      v4 = byte_5EA438;
    ConditionalDispatch_6bd0(v4, a2);
  }
  return 1;
}
