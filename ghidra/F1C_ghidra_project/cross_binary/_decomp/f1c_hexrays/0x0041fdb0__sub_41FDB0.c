// f1c  0x0041fdb0  size=63
bool __thiscall sub_41FDB0(void *this)
{
  char **v2; // eax
  char *v4; // eax
  int v5; // edi

  v2 = sub_41F340((int)this, 0);
  if ( !v2 )
    return 0;
  v4 = *v2;
  if ( !v4 )
    v4 = &byte_5EA438;
  v5 = sub_41F220((int)v4, -1);
  return sub_41F220((int)this, -1) - v5 >= 16;
}
