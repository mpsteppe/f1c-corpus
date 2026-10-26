void __thiscall sub_42D790(_DWORD *this)
{
  char *v2; // eax
  int v3; // eax

  if ( this[4695] )
  {
    v2 = (char *)sub_51E210(this + 21);
    v3 = sub_500A20(v2);
    if ( v3 )
    {
      if ( !*(_BYTE *)(v3 + 20) )
      {
        sub_4271B0((int)this, 0);
        *(_BYTE *)this = 1;
      }
    }
  }
}
