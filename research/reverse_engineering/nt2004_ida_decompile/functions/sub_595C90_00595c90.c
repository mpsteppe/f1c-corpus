int __thiscall sub_595C90(_BYTE *this, char *FileName)
{
  void *v3; // eax
  int v4; // eax
  void *v5; // eax
  int v6; // eax

  if ( !FileName )
    return 0;
  if ( (this[240] & 4) == 0 )
  {
    v3 = operator new(0x40u);
    if ( v3 )
      v4 = sub_59F160(v3);
    else
      v4 = 0;
    dword_7E8CD0 = v4;
    if ( sub_59F580(dword_7E8D08, dword_7E8D08, dword_7E8D0C, 262152) )
    {
      if ( dword_7E8CD0 )
      {
        j_nullsub_6((void *)dword_7E8CD0);
        sub_5BE8AE();
      }
      dword_7E8CD0 = 0;
    }
    v5 = operator new(0x40u);
    if ( v5 )
      v6 = sub_59F160(v5);
    else
      v6 = 0;
    dword_7E8CD4 = v6;
    if ( sub_59F580(dword_7E8D08, dword_7E8D08, dword_7E8D0C, 262152) )
    {
      if ( dword_7E8CD4 )
      {
        j_nullsub_6((void *)dword_7E8CD4);
        sub_5BE8AE();
      }
      dword_7E8CD4 = 0;
    }
  }
  if ( !sub_5B3910((int)this, FileName) )
  {
    *((_DWORD *)this + 60) |= 0x10800u;
    return 0;
  }
  if ( dword_7E8CD0 )
  {
    sub_59FA90(dword_7E8CD0);
    if ( dword_7E8CD0 )
    {
      j_nullsub_6((void *)dword_7E8CD0);
      sub_5BE8AE();
    }
    dword_7E8CD0 = 0;
  }
  if ( dword_7E8CD4 )
  {
    sub_59FA90(dword_7E8CD4);
    if ( dword_7E8CD4 )
    {
      j_nullsub_6((void *)dword_7E8CD4);
      sub_5BE8AE();
    }
    dword_7E8CD4 = 0;
  }
  return -1;
}
