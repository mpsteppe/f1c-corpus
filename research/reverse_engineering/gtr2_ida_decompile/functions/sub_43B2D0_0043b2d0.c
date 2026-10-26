void __thiscall sub_43B2D0(double *this)
{
  void *v2; // eax

  *(_DWORD *)this = 0;
  this[1] = 0.0;
  this[2] = 0.0;
  this[3] = 0.0;
  this[4] = 0.0;
  this[5] = 0.0;
  this[6] = 0.0;
  this[7] = 0.0;
  this[8] = 0.0;
  this[9] = 0.0;
  this[10] = 0.0;
  this[11] = 0.0;
  this[12] = 0.0;
  this[13] = 0.0;
  this[14] = 0.0;
  this[15] = 0.0;
  this[16] = 0.0;
  this[17] = 0.0;
  this[18] = 0.0;
  v2 = (void *)*((_DWORD *)this + 40);
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  if ( v2 )
  {
    j_j__free(v2);
    *((_DWORD *)this + 40) = 0;
  }
}
