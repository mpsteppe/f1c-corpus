int __thiscall sub_6736EA(_DWORD *this, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = this[5];
  if ( !v3 )
    return 0;
  result = ((int (__stdcall *)(int, int, int, _DWORD, _DWORD))this[7])(
             a2,
             a3 + *((unsigned __int16 *)this + 5),
             4 * a3 * (*((_WORD *)this + 4) != 0 ? 4 : 1) + v3 + *(_DWORD *)(*this + 8),
             this[8],
             *((unsigned __int16 *)this + 6));
  if ( result >= 0 )
    return 0;
  return result;
}
