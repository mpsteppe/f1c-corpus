int __thiscall ConditionalConstructorDestructor(int this, char a2)
{
  *(_DWORD *)this = &off_5A9448;
  ConditionalDualCleanup((_DWORD *)(this + 224));
  sub_485EB0((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}

