int __thiscall sub_449F60(_DWORD *this, int a2)
{
  int v4; // eax
  char *v5; // ecx
  int v6; // eax
  int *v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // eax
  _DWORD v14[3]; // [esp+10h] [ebp-290h]
  int v15; // [esp+1Ch] [ebp-284h] BYREF
  char v16; // [esp+20h] [ebp-280h] BYREF
  __int16 v17; // [esp+36h] [ebp-26Ah]
  _DWORD v18[6]; // [esp+3Ch] [ebp-264h] BYREF
  unsigned int v19; // [esp+54h] [ebp-24Ch]
  unsigned int v20; // [esp+58h] [ebp-248h]
  __int16 v21; // [esp+5Ch] [ebp-244h]
  char v22; // [esp+60h] [ebp-240h] BYREF

  if ( FileWriteWithBackendDispatch(v18, 34) == 34 )
  {
    AABBCollisionBodyInitializer((int)&v15);
    v4 = 0;
    v5 = &v22;
    do
    {
      *(&v15 + v4++) = (int)v5;
      v5 += 96;
    }
    while ( v4 < 6 );
    v17 = v21;
    v6 = 0;
    v7 = (int *)&v16;
    do
    {
      v8 = *v7;
      *(_DWORD *)(v8 + 16) = v18[2 * v6];
      v9 = v18[2 * v6++ + 1];
      v7 += 2;
      *(_DWORD *)(v8 + 20) = v9;
    }
    while ( v6 < 3 );
    v14[0] = v19 & 0x1FFFFF;
    v14[1] = (v19 >> 21) + ((v20 & 0x3FF) << 11);
    v14[2] = v20 >> 10;
    v10 = 0;
    while ( 1 )
    {
      v11 = v14[v10];
      v12 = (_DWORD *)*(&v15 + 2 * v10);
      if ( v11 < 0 || v11 >= *(_DWORD *)(a2 + 52) )
        break;
      v13 = (_DWORD *)(*(_DWORD *)(a2 + 56) + 16 * v11);
      *v12 = *v13;
      v12[4] = v13[1];
      v12[5] = v13[2];
      ++v10;
      v12[3] = v13[3];
      if ( v10 >= 3 )
        return HATPolygonSurfaceFit(this, (int)&v15, 1);
    }
  }
  return -1;
}
