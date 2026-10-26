int __thiscall sub_499A70(char **this, char **a2)
{
  char *v4; // eax

  if ( a2 == this )
    return -1;
  v4 = *a2;
  if ( !*a2 )
    v4 = byte_5EA438;
  StringCopyWithBufferRealloc(v4);
  this[2] = a2[2];
  return 0;
}

