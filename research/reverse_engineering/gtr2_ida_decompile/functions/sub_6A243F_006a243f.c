int __thiscall sub_6A243F(_DWORD *this)
{
  unsigned int v1; // eax
  int v2; // esi
  int v3; // edi
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // edx
  int v8; // [esp+Ch] [ebp-10h]
  unsigned int v9; // [esp+10h] [ebp-Ch]
  int *i; // [esp+14h] [ebp-8h]
  unsigned int v11; // [esp+18h] [ebp-4h]

  v1 = this[19];
  v9 = v1;
  if ( v1 < this[137] )
  {
    for ( i = (int *)(this[140] + 4 * v1); ; ++i )
    {
      v2 = *i;
      if ( *i )
      {
        if ( *(_DWORD *)v2 )
        {
          v3 = this[5];
          if ( *(_DWORD *)(*(_DWORD *)(v3 + 4 * **(_DWORD **)(v2 + 16)) + 4) != this[33]
            || (*(_DWORD *)v2 & 0xFFF00000) != 0x10000000 )
          {
            v11 = 0;
            if ( *(_DWORD *)(v2 + 4) )
              break;
          }
        }
      }
LABEL_15:
      if ( ++v9 >= this[137] )
        return 0;
    }
    v4 = *(_DWORD **)(v2 + 8);
    while ( 1 )
    {
      v5 = *(_DWORD *)(v3 + 4 * *v4);
      v8 = *(_DWORD *)(v5 + 60);
      while ( 1 )
      {
        v6 = *(_DWORD *)(v5 + 56);
        if ( v6 == -1 )
          break;
        v5 = *(_DWORD *)(v3 + 4 * v6);
      }
      if ( *(_BYTE *)(v5 + 108) == 3 && (((unsigned __int16)v8 | *(_WORD *)(v5 + 60)) & 0x200) == 0 )
        break;
      ++v11;
      ++v4;
      if ( v11 >= *(_DWORD *)(v2 + 4) )
        goto LABEL_15;
    }
    sub_686816(
      (int)this,
      *(_DWORD *)(v2 + 60),
      (const char *)0x1263,
      "texcoord inputs used directly (that is, other than sampling from textures) in shader body in ps_1_%i are always cl"
      "amped from 0 to 1",
      (unsigned __int8)this[50]);
  }
  return 0;
}
