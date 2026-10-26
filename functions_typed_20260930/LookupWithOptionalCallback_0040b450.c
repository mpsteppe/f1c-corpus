char __thiscall sub_40B450(_DWORD *this, int a2, char a3)
{
  int v4; // eax

  if ( !a2 )
    return 0;
  v4 = LinearSearchWithStride0xA0(this, a2);
  if ( v4 < 0 )
    return 0;
  BoundedIndexSetter(this, v4);
  if ( a3 )
    (*(void (**)(void))(*this + 16))();
  return 1;
}

