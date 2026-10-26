// f1c  0x00564530  size=67
int __fastcall sub_564530(__int16 *a1, const char *a2, int a3)
{
  int *v4; // eax

  if ( !strcmp(a2, aPing) )
    return sub_564480(a1);
  v4 = sub_5644F0((int)a1, (int)a2);
  if ( v4 )
    return sub_587F59(v4[1]);
  else
    return a3;
}
