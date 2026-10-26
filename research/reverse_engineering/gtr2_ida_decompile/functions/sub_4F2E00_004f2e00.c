void __thiscall sub_4F2E00(_DWORD *this, int a2)
{
  int v3; // edi
  int v4; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // edx
  float v7[16]; // [esp+8h] [ebp-80h] BYREF
  _BYTE v8[64]; // [esp+48h] [ebp-40h] BYREF

  v3 = this[5];
  if ( v3 )
  {
    if ( *(_DWORD *)(v3 + 236) )
    {
      sub_42FB70(v7, 3.1415927);
      sub_42FBC0((char *)v7, v8, (float *)(this[4] + 68));
      qmemcpy((void *)(**(_DWORD **)(v3 + 232) + 4), v8, 0x40u);
    }
    else
    {
      qmemcpy((void *)(*(_DWORD *)(v3 + 136) + 76), (const void *)(this[4] + 68), 0x40u);
      **(_DWORD **)(this[5] + 136) |= 0x40u;
      v4 = *(_DWORD *)(this[3] + 160);
      if ( !v4 || !*(_BYTE *)(v4 + 80) )
      {
        v5 = (_DWORD *)this[5];
        v6 = (_DWORD *)(v5[34] + 124);
        v5 += 21;
        *v5 = *v6;
        v5[1] = v6[1];
        v5[2] = v6[2];
      }
    }
  }
}
