int __thiscall FieldSetterWithVTableDispatch(_BYTE *this)
{
  int v1; // eax

  v1 = *(_DWORD *)this;
  this[383] = 0;
  *((_DWORD *)this + 92) = -1;
  (*(void (__stdcall **)(int))(v1 + 44))(1);
  return 0;
}
