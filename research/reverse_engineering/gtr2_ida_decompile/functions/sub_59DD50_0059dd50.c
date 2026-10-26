char __thiscall sub_59DD50(_DWORD *this, int a2)
{
  int v3; // ebp
  _DWORD *v4; // edi
  void *v5; // eax
  DWORD v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  void *v13; // edi
  int v15; // [esp+14h] [ebp-1Ch]
  int v16; // [esp+18h] [ebp-18h]
  int v17; // [esp+1Ch] [ebp-14h]
  _DWORD v18[4]; // [esp+20h] [ebp-10h] BYREF

  htonl(0);
  htons(0);
  v3 = this[680];
  v4 = this + 711;
  v17 = this[683];
  v5 = (void *)this[715];
  v15 = this[681];
  v16 = this[682];
  if ( !v5 )
    return 0;
  v6 = WaitForSingleObject(v5, this[716]);
  if ( v6 )
  {
    if ( v6 != 128 )
      return 0;
  }
  v7 = (_DWORD *)*v4;
  if ( !*v4 )
    goto LABEL_8;
  while ( !*v7 || (_DWORD *)*v7 != v18 )
  {
    v7 = (_DWORD *)v7[1];
    if ( !v7 )
      goto LABEL_8;
  }
  v9 = (_DWORD *)*v7;
  if ( *v7 )
  {
    v10 = a2;
    v9[1] = a2;
  }
  else
  {
LABEL_8:
    v8 = operator new(0x10u);
    if ( v8 )
    {
      v18[2] = v16;
      v18[0] = v3;
      v18[3] = v17;
      *v8 = v15;
      v8[1] = 0;
      v8[2] = 0;
      v8[3] = 0;
    }
    else
    {
      v8 = 0;
    }
    v9 = v8;
    sub_5FDFB0(v8, 1);
    v10 = a2;
  }
  v11 = v10 + v9[2];
  v12 = v9[3] + 1;
  v9[1] = v10;
  v9[2] = v11;
  v9[3] = v12;
  v13 = (void *)v4[4];
  if ( v13 )
    ReleaseMutex(v13);
  return 1;
}
