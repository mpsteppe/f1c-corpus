int __thiscall sub_49EBB0(int *this)
{
  int v2; // eax

  v2 = *this;
  *((_BYTE *)this + 281) = 0;
  if ( !(*(int (**)(void))(v2 + 148))() )
    sub_49D120(this);
  return 0;
}
