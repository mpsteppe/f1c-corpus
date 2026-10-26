_BYTE *__thiscall sub_4DAF10(_BYTE *this, char a2)
{
  int v3; // edi

  if ( this[8] )
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      nullsub_6((void *)(v3 + 148));
      sub_5BE8AE((LPVOID)v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
