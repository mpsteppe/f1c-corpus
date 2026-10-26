CHAR *__thiscall sub_468AD0(CHAR **this)
{
  CHAR *v1; // eax
  CHAR **v2; // esi
  CHAR *result; // eax

  v1 = *(CHAR **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v1 = &byte_629120;
  v2 = this + 103;
  sub_578600(v1);
  sub_578560(aDedicatedserve);
  result = *v2;
  if ( !*v2 )
    return &byte_629120;
  return result;
}
