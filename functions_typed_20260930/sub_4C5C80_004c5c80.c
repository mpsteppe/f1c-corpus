_DWORD *__thiscall sub_4C5C80(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // ecx

  v4 = this + 1;
  *v4 = 0;
  v4[1] = -1;
  *this = a2;
  StringCopyWithBufferRealloc(a3);
  SceneOrderSlotFinder(this);
  return this;
}

