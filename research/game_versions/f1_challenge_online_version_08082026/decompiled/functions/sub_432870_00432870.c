char *__thiscall sub_432870(char ***this)
{
  char *v2; // eax
  char *v3; // eax
  char *result; // eax

  v2 = **this;
  if ( !v2 )
    v2 = &byte_5EA438;
  sub_566650(v2);
  v3 = (*this)[2];
  if ( !v3 )
    v3 = &byte_5EA438;
  sub_5665B0(v3);
  result = (*this)[4];
  if ( !result )
    return &byte_5EA438;
  return result;
}
