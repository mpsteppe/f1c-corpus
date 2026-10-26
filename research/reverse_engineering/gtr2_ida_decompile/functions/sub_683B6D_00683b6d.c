int __thiscall sub_683B6D(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  unsigned int v5; // esi
  int v6; // eax
  int v7; // ebx
  int *v8; // esi
  int v9; // eax
  unsigned int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  unsigned int v13; // [esp+14h] [ebp-4h]
  int *v14; // [esp+20h] [ebp+8h]
  int v15; // [esp+28h] [ebp+10h]

  v5 = *a2 & 0xFFFFF;
  v13 = 0;
  v11 = a2[1] / v5;
  if ( !v11 )
    return 0;
  v6 = a2[2];
  v7 = this[5];
  v12 = 4 * v5;
  v14 = (int *)(v6 + 4 * a4);
  v8 = (int *)(v6 + 4 * a3);
  while ( 1 )
  {
    v15 = *v14;
    v9 = this[4];
    if ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v8) + 4)) + 4) & 0x40) != 0
      && (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * v15) + 4)) + 4) & 0x40) != 0
      && !sub_683ACB(this, *v8, v15) )
    {
      break;
    }
    ++v13;
    v14 = (int *)((char *)v14 + v12);
    v8 = (int *)((char *)v8 + v12);
    if ( v13 >= v11 )
      return 0;
  }
  return 1;
}
