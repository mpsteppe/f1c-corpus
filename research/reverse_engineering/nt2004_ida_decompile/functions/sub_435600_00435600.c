CHAR *__thiscall sub_435600(CHAR ***this)
{
  CHAR *v2; // eax
  CHAR *v3; // eax
  CHAR *result; // eax

  v2 = **this;
  if ( !v2 )
    v2 = &byte_629120;
  sub_578600(v2);
  v3 = (*this)[2];
  if ( !v3 )
    v3 = &byte_629120;
  sub_578560(v3);
  result = (*this)[4];
  if ( !result )
    return &byte_629120;
  return result;
}
