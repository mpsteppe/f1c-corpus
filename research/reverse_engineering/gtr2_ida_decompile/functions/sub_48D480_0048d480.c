void __thiscall sub_48D480(void **this)
{
  void *v2; // esi

  *this = &off_6F905C;
  if ( this[18] )
    j_j__free(this[18]);
  if ( this[16] )
    j_j__free(this[16]);
  *this = &off_6F9040;
  if ( this[13] )
    j_j__free(this[13]);
  *this = &off_6F9024;
  v2 = this[5];
  if ( v2 )
    j_j__free(v2);
}
