_DWORD *__thiscall sub_5E88B0(int this, int a2, int a3)
{
  _DWORD *result; // eax

  sub_5D86C0(a2, a3, (_DWORD *)this, this + 136);
  sub_5D88C0(*(float *)&a3, (_DWORD *)this, this + 152);
  sub_5D89B0(*(float *)&a3, (_DWORD *)this, (float *)(this + 184));
  result = (_DWORD *)(this + 196);
  if ( this != -196 )
    *result = *(_DWORD *)(this + 244);
  return result;
}
