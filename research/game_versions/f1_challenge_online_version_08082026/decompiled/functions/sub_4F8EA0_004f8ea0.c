int __thiscall sub_4F8EA0(_DWORD *this)
{
  void *v2; // edi
  int v3; // eax

  v2 = (void *)this[6];
  if ( v2 )
  {
    j_nullsub_3(this[6]);
    sub_587BCF(v2);
  }
  v3 = sub_53D1F0(aFtframerate);
  if ( v3 )
    sub_53D130(v3);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[5] = 0;
  this[4] = 0;
  this[6] = 0;
  this[8] = 0;
  this[7] = 0;
  this[10] = 0;
  this[9] = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 108) = 0;
  return 0;
}
