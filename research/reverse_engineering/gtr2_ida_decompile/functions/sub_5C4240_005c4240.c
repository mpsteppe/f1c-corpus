int __thiscall sub_5C4240(_DWORD *this, double a2, int a3)
{
  int result; // eax
  int v5; // ebx
  int i; // esi
  int v7; // ecx

  result = sub_5D14F0(a2, a3);
  if ( this[9] )
    result = sub_5D2690(a2);
  if ( (_BYTE)a3 )
  {
    result = sub_5C4160(this);
    v5 = this[6];
    for ( i = 0; i < v5; ++i )
    {
      v7 = *(_DWORD *)(this[8] + 4 * i);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(v7);
    }
  }
  return result;
}
