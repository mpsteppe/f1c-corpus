int __thiscall sub_4D5F60(_BYTE *this)
{
  int v2; // edx
  int v3; // eax
  int v4; // ecx
  int *v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // ebp
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v15; // [esp+28h] [ebp-14h] BYREF
  int v16; // [esp+2Ch] [ebp-10h] BYREF
  int v17; // [esp+30h] [ebp-Ch]
  int v18; // [esp+34h] [ebp-8h] BYREF
  int v19; // [esp+38h] [ebp-4h] BYREF

  if ( this[108] )
  {
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this);
    this[108] = 0;
  }
  sub_4CFA10((int)this);
  if ( this[101] )
  {
    v3 = sub_4DDFE0(&unk_B6E2A0, v2);
    v4 = *((_DWORD *)this + 61);
    v17 = v3;
    if ( v4 )
      v5 = (int *)sub_4E29F0(*((_DWORD *)this + 33));
    else
      v5 = 0;
    v6 = *((_DWORD *)this + 34);
    if ( v6 > 0 )
    {
      do
      {
        if ( v5 )
          v5 = (int *)v5[9];
        --v6;
      }
      while ( v6 );
    }
    if ( v5 )
    {
      v7 = *((_DWORD *)this + 1);
      v15 = *((_DWORD *)this + 3);
      v16 = v7;
      v8 = v5[1];
      v9 = v5[2];
      v10 = *v5;
      v11 = v5[7];
      v12 = v8 - v10;
      if ( v12 > *(_DWORD *)(v11 + 20) )
        v12 = *(_DWORD *)(v11 + 20);
      sub_4D5E10(this, v11, v10, v9, v17, v15, v16, v12);
    }
    v13 = *(_DWORD *)this;
    v16 = 600;
    v19 = 0;
    v15 = 800;
    v18 = 0;
    (*(void (__thiscall **)(_BYTE *, int *, int *, int *, int *))(v13 + 24))(this, &v16, &v19, &v15, &v18);
  }
  return 0;
}
