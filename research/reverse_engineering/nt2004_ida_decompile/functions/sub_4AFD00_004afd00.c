int __thiscall sub_4AFD00(CHAR **this, CHAR **a2)
{
  CHAR *v4; // eax

  if ( a2 == this )
    return -1;
  v4 = *a2;
  if ( !*a2 )
    v4 = &byte_629120;
  sub_578600(v4);
  this[2] = a2[2];
  return 0;
}
