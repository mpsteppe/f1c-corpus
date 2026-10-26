void __thiscall sub_46C4A0(char **this)
{
  char *v2; // eax
  char *v3; // edi

  v2 = *this;
  if ( *this )
  {
    v3 = v2 - 4;
    `eh vector destructor iterator'(v2, 0x1Cu, *((_DWORD *)v2 - 1), nullsub_7);
    j_j__free(v3);
    *this = 0;
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
}
