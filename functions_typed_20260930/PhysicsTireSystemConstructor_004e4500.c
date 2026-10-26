_DWORD *__thiscall PhysicsTireSystemConstructor(_DWORD *this)
{
  _BYTE *v2; // edi
  int v3; // ebx

  sub_4F6F20(this + 2);
  sub_4DFBB0((int)(this + 441));
  F_5LoopInitCall(this + 3248);
  v2 = this + 3806;
  v3 = 4;
  do
  {
    sub_4DFB90(v2);
    v2 += 28;
    --v3;
  }
  while ( v3 );
  ConstructorZeroInitSubCalls(this + 3934);
  this[3247] = -1;
  this[3689] = 0;
  sub_4E4790((int)this);
  return this;
}

