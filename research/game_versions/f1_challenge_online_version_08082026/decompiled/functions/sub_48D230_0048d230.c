int __thiscall sub_48D230(int this)
{
  int i; // esi
  _DWORD *v3; // ebp
  bool v4; // zf
  int result; // eax

  for ( i = *(_DWORD *)(this + 796); i; result = sub_587BCF(v3) )
  {
    v3 = (_DWORD *)i;
    v4 = *(_BYTE *)(i + 12) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
  }
  *(_DWORD *)(this + 796) = 0;
  *(_DWORD *)(this + 800) = 0;
  *(_DWORD *)(this + 804) = 0;
  *(_DWORD *)(this + 808) = 0;
  *(_DWORD *)(this + 812) = 0;
  *(_DWORD *)(this + 816) = 0;
  *(_DWORD *)(this + 820) = 0;
  *(_DWORD *)(this + 824) = 0;
  *(_DWORD *)(this + 832) = 0;
  *(_BYTE *)(this + 828) = 1;
  return result;
}
