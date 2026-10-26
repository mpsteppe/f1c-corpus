void __thiscall sub_52F220(void **this)
{
  void *v2; // eax
  void *v3; // eax

  if ( this[2] )
    j_j__free(this[2]);
  v2 = this[5];
  this[2] = 0;
  *this = 0;
  this[1] = 0;
  if ( v2 )
    j_j__free(v2);
  v3 = this[8];
  this[5] = 0;
  this[3] = 0;
  this[4] = 0;
  if ( v3 )
    j_j__free(v3);
  this[8] = 0;
  this[6] = 0;
  this[7] = 0;
}
