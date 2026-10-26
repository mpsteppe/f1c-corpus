_DWORD *__thiscall F_5LoopInitCall(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx

  v2 = this + 6;
  v3 = 5;
  do
  {
    StructInitializer(v2);
    v2 += 16;
    --v3;
  }
  while ( v3 );
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  UIComponentCleanup((int)this);
  return this;
}
