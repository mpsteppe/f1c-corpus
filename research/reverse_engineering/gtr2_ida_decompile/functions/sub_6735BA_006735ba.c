int __thiscall sub_6735BA(_DWORD *this, int a2)
{
  int v3; // eax
  int v5; // ebx
  unsigned int v7; // [esp+10h] [ebp+8h]

  v3 = this[6];
  v7 = 0;
  this[8] = a2;
  if ( *(_WORD *)(v3 + 10) )
  {
    do
    {
      v5 = 4 * v7;
      sub_6735BA(a2);
      ++v7;
      a2 += 4
          * *(_DWORD *)(*(_DWORD *)(this[14] + v5) + 44)
          * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(this[14] + v5) + 24) + 8)
          * (*(_WORD *)(*(_DWORD *)(this[14] + v5) + 8) != 0 ? 4 : 1);
    }
    while ( v7 < *(unsigned __int16 *)(this[6] + 10) );
  }
  return 0;
}
