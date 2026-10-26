int __thiscall sub_6BB7BD(_DWORD *this, _DWORD *a2)
{
  unsigned int v2; // eax
  _DWORD *v3; // edx
  int v4; // ecx
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // edx
  unsigned int v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v2 = *a2 + 1;
  v3 = (_DWORD *)(this[5] + 4 * v2);
  v11 = *v3;
  v10 = this[2];
  if ( v2 < v10 )
  {
    v4 = this[4];
    v5 = v3;
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)(*v5 + 4)) + 4);
      if ( ((v6 & 0x10) == 0 || (v6 & 0x200) != 0) && (v6 & 0x20) == 0 )
        break;
      v7 = *(_DWORD *)(v11 + 104);
      v8 = *(_DWORD *)(*v5 + 104);
      if ( *(_DWORD *)(v7 + 36) != *(_DWORD *)(v8 + 36) )
        break;
      if ( *(_DWORD *)(v7 + 32) != *(_DWORD *)(v8 + 32) )
        break;
      ++v2;
      ++v5;
    }
    while ( v2 < v10 );
  }
  *a2 = v2 - 1;
  return 0;
}
