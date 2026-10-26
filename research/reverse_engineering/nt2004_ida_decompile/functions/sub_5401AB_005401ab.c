int __thiscall sub_5401AB(_DWORD *this)
{
  _DWORD *v1; // edi
  unsigned int v2; // esi
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // edx
  unsigned int v7; // ecx
  int v8; // esi
  unsigned int v9; // eax
  _DWORD *v10; // edx
  char *v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // [esp-8h] [ebp-28h]
  unsigned int v15; // [esp+8h] [ebp-18h]
  unsigned int v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+Ch] [ebp-14h]
  unsigned int v18; // [esp+10h] [ebp-10h]
  unsigned int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+14h] [ebp-Ch]
  unsigned int v22; // [esp+18h] [ebp-8h]
  char *i; // [esp+1Ch] [ebp-4h]

  v1 = (_DWORD *)*this;
  v2 = *(_DWORD *)(*this + 4148);
  v18 = *(_DWORD *)(*this + 4144);
  if ( (((unsigned __int8)v2
       | (unsigned __int8)(*(_BYTE *)(*this + 4144) | *(_BYTE *)(*this + 4152) | *(_BYTE *)(*this + 4156)))
      & 3) != 0 )
    return -2147467259;
  v4 = this[1];
  v5 = *(_DWORD *)(v4 + 4148);
  v16 = *(_DWORD *)(v4 + 4144);
  if ( (((unsigned __int8)v5 | (unsigned __int8)(v16 | *(_BYTE *)(v4 + 4152) | *(_BYTE *)(v4 + 4156))) & 3) != 0 )
    return -2147467259;
  v6 = *(_DWORD *)(v4 + 4);
  if ( v6 == 827611204 )
  {
    v14 = 8;
  }
  else
  {
    if ( v6 != 844388420 && v6 != 861165636 && v6 != 877942852 && v6 != 894720068 )
      return -2147467259;
    v14 = 16;
  }
  v15 = v14 * (*(_DWORD *)(v4 + 4184) >> 2);
  v20 = *(_DWORD *)(v4 + 24)
      + v14 * (v16 >> 2)
      + *(_DWORD *)(v4 + 4160) * *(_DWORD *)(v4 + 4180)
      + *(_DWORD *)(v4 + 4176) * (v5 >> 2);
  v7 = v18;
  v19 = 0;
  v8 = v1[6] + v14 * (v7 >> 2) + v1[1040] * v1[1045] + v1[1044] * (v2 >> 2);
  v17 = v8;
  if ( *(_DWORD *)(v4 + 4192) )
  {
    v9 = *(_DWORD *)(v4 + 4188);
    v10 = this;
    do
    {
      v22 = 0;
      v11 = (char *)v20;
      for ( i = (char *)v8; v22 < v9; i += *(_DWORD *)(*v10 + 4176) )
      {
        v22 += 4;
        qmemcpy(v11, i, v15);
        v12 = v10[1];
        v11 += *(_DWORD *)(v12 + 4176);
        v9 = *(_DWORD *)(v12 + 4188);
      }
      v13 = v10[1];
      v20 += *(_DWORD *)(v13 + 4180);
      v8 = *(_DWORD *)(*v10 + 4180) + v17;
      ++v19;
      v17 = v8;
    }
    while ( v19 < *(_DWORD *)(v13 + 4192) );
  }
  return 0;
}
