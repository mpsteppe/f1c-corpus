void __thiscall sub_55ED10(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v5; // eax
  int i; // ecx
  int v7; // edx
  char v9; // c0
  int v10; // [esp+Ch] [ebp-Ch] BYREF
  int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  if ( (*(_BYTE *)(a3 + 20) & 0x20) == 0 )
  {
    if ( (*(_BYTE *)(a2 + 60) & 0x10) == 0 )
      SceneNodePositionGetter((_DWORD *)a2, &v10, &v11, &v12);
    v5 = *(_DWORD **)(a3 + 284);
    *(_DWORD *)(a3 + 268) = 0;
    if ( (*v5 & 0x100) != 0 )
    {
      for ( i = this[74]; i; i = *(_DWORD *)(i + 108) )
      {
        v7 = *(_DWORD *)(a3 + 268);
        if ( v7 >= 8 )
          break;
        if ( (*(_BYTE *)i & 0xA0) == 0x80 && !v9 )
        {
          *(_DWORD *)(56 * v7 + *(_DWORD *)(a3 + 272)) = i;
          *(float *)(56 * (*(_DWORD *)(a3 + 268))++ + *(_DWORD *)(a3 + 272) + 16) = 1.0 / *(float *)(i + 80);
        }
      }
    }
  }
}

