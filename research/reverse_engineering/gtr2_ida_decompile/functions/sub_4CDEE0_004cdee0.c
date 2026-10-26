int __thiscall sub_4CDEE0(_BYTE *this)
{
  int v2; // eax
  int i; // esi

  v2 = *(_DWORD *)this;
  this[282] = 0;
  if ( (*(int (**)(void))(v2 + 148))() )
    return 0;
  for ( i = *((_DWORD *)this + 63); i; i = *(_DWORD *)(i + 24) )
    sub_4E3B60(this, 0);
  return 0;
}
