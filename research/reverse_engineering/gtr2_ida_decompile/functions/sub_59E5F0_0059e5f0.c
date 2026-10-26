char __thiscall sub_59E5F0(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  void *v5; // eax
  DWORD v6; // eax
  _DWORD *v7; // eax
  void *v8; // esi
  void *v9; // eax
  DWORD v10; // eax
  int v11; // edi
  _DWORD *v12; // esi
  int v13; // eax
  void *v14; // edi
  int v16; // [esp+4h] [ebp-38h]
  _DWORD *v17; // [esp+14h] [ebp-28h]
  _UNKNOWN *retaddr; // [esp+3Ch] [ebp+0h]

  htonl(0);
  htons(0);
  v5 = (void *)this[726];
  if ( v5 && ((v6 = WaitForSingleObject(v5, this[727])) == 0 || v6 == 128) )
    v7 = this + 725;
  else
    v7 = 0;
  *a2 = (*v7)++;
  v8 = (void *)this[726];
  if ( v8 )
    ReleaseMutex(v8);
  v9 = (void *)this[701];
  if ( v9 && ((v10 = WaitForSingleObject(v9, this[702])) == 0 || v10 == 128) )
    v17 = this + 697;
  else
    v17 = 0;
  v11 = v17[3];
  v12 = operator new(0x20u);
  if ( v12 )
  {
    sub_5A6CF0(v12, *a2, v11, a3);
    *v12 = &off_725FFC;
    v12[7] = 0;
  }
  else
  {
    v12 = 0;
  }
  if ( a3 > 0 && a3 <= 2 )
  {
    if ( (_BYTE)retaddr )
    {
      v13 = sub_59C350();
      sub_5A7010(v13, v12);
      v14 = (void *)this[404];
      if ( v14 )
        ReleaseMutex(v14);
    }
    else
    {
      sub_59CBF0();
    }
  }
  sub_5FDFB0(v12, 1);
  if ( *(_DWORD *)(v16 + 16) )
    ReleaseMutex(*(HANDLE *)(v16 + 16));
  return 1;
}
