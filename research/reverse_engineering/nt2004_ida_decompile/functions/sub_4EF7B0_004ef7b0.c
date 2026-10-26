_DWORD *__thiscall sub_4EF7B0(_DWORD *this, CHAR **a2)
{
  CHAR *v3; // eax

  *this = 0;
  this[1] = -1;
  v3 = *a2;
  if ( !*a2 )
    v3 = &byte_629120;
  sub_578600(v3);
  return this;
}
