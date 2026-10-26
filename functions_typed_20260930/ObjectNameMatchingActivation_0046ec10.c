char __thiscall sub_46EC10(_BYTE *this, const char *a2)
{
  int v3; // edx

  if ( !strcmp(off_5C666C[0], a2) )
  {
    v3 = *(_DWORD *)this;
    this[372] = 1;
    (*(void (__thiscall **)(_BYTE *, int))(v3 + 44))(this, 1);
    return 1;
  }
  else
  {
    this[372] = 0;
    return 0;
  }
}

