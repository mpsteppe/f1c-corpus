int __thiscall sub_487400(_BYTE *this, int a2)
{
  if ( (_BYTE)a2 != ByteFieldGetterAt100(this) )
    (*(void (__cdecl **)(int))(*(_DWORD *)this + 44))(1);
  return UIWidgetPropagateState(a2);
}
