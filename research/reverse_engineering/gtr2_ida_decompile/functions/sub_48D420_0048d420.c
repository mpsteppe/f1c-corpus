void __thiscall sub_48D420(void **this)
{
  void *v2; // esi

  *this = &off_6F9040;
  if ( this[13] )
    j_j__free(this[13]);
  *this = &off_6F9024;
  v2 = this[5];
  if ( v2 )
    j_j__free(v2);
}
