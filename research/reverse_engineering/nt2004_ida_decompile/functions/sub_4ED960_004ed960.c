int __thiscall sub_4ED960(int this, char a2)
{
  void *v3; // edi

  if ( *(_BYTE *)(this + 8) )
  {
    v3 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      j_nullsub_6(*(void **)this);
      sub_5BE8AE(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
