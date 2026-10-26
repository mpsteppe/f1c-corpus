int __thiscall sub_49D460(int this)
{
  int v2; // eax
  int *v3; // eax
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // edx
  int v8; // ebp
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  float v12; // edx
  int v13; // eax
  int v15; // [esp-4h] [ebp-20h]
  int v16; // [esp+8h] [ebp-14h] BYREF
  int v17; // [esp+Ch] [ebp-10h] BYREF
  int v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h] BYREF

  if ( *(_BYTE *)(this + 108) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 152))(this);
    *(_BYTE *)(this + 108) = 0;
  }
  sub_49D230(this);
  if ( *(_BYTE *)(this + 101) )
  {
    v2 = sub_4AB570(&unk_765B00);
    v15 = *(_DWORD *)(this + 132);
    v18 = v2;
    v3 = (int *)sub_49CB60((_DWORD *)this, v15);
    v4 = *(_DWORD *)(this + 136);
    if ( v4 > 0 )
    {
      do
      {
        if ( v3 )
          v3 = (int *)v3[9];
        --v4;
      }
      while ( v4 );
    }
    if ( v3 )
    {
      v5 = *(_DWORD *)(this + 4);
      v16 = *(_DWORD *)(this + 12);
      v17 = v5;
      v6 = v3[1];
      v7 = v3[3];
      v8 = v3[2];
      v9 = *v3;
      v10 = v3[7];
      v11 = v6 - v9;
      LODWORD(v12) = v7 - v8;
      if ( v11 > *(_DWORD *)(v10 + 20) )
        v11 = *(_DWORD *)(v10 + 20);
      if ( SLODWORD(v12) > *(_DWORD *)(v10 + 24) )
        v12 = *(float *)(v10 + 24);
      sub_49CB80((char **)v10, v9, v8, v18, (char **)v16, v17, v11, v12, 0, 0);
    }
    v13 = *(_DWORD *)this;
    v17 = 600;
    v20 = 0;
    v16 = 800;
    v19 = 0;
    (*(void (__thiscall **)(int, int *, int *, int *, int *))(v13 + 24))(this, &v17, &v20, &v16, &v19);
  }
  return 0;
}
