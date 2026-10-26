int __thiscall sub_5805C0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // ebp
  DWORD v3; // eax
  _DWORD *v4; // edi
  int *v5; // edi
  int v6; // esi
  int v7; // eax
  void *v8; // ebp
  void *v9; // eax
  _DWORD *v10; // ebx
  DWORD v11; // eax
  _DWORD *v12; // ebp
  int *v13; // eax
  int v14; // edi
  int *v15; // eax
  int v17; // [esp-8h] [ebp-24h]
  int v18; // [esp-8h] [ebp-24h]
  int v19; // [esp-8h] [ebp-24h]
  _DWORD *v20; // [esp+10h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-8h]

  v1 = (void *)this[741];
  v2 = this + 733;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[742])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v20 = v4;
  v5 = v4 + 4;
  v6 = 0;
  sub_4BA780(v5);
  v7 = v5[2];
  if ( v7 )
  {
    v6 = *(_DWORD *)v7;
    v17 = *(_DWORD *)v7;
    *(_BYTE *)(v7 + 8) = 0;
    if ( !(unsigned __int8)sub_583430(v17, 1) )
      v6 = 0;
  }
  v21 = v6;
  if ( !v6 )
  {
    sub_582780(v20);
    v21 = sub_582B10(v5);
  }
  v8 = (void *)v2[8];
  if ( v8 )
    ReleaseMutex(v8);
  v9 = (void *)this[730];
  v10 = this + 722;
  if ( v9 && ((v11 = WaitForSingleObject(v9, this[731])) == 0 || v11 == 128) )
    v12 = this + 722;
  else
    v12 = 0;
  v13 = (int *)v12[4];
  v14 = 0;
  v12[6] = v13;
  if ( v13 )
  {
    v14 = *v13;
    v18 = *v13;
    *((_BYTE *)v13 + 8) = 0;
    v10 = this + 722;
    if ( !(unsigned __int8)sub_5832E0(v18, 1) )
      v14 = 0;
  }
  if ( !v14 )
  {
    sub_5823C0(v12);
    sub_4BA780(v12 + 4);
    v15 = (int *)v12[6];
    if ( v15 )
    {
      v14 = *v15;
      v19 = *v15;
      *((_BYTE *)v15 + 8) = 0;
      if ( !(unsigned __int8)sub_5832E0(v19, 1) )
        v14 = 0;
    }
  }
  *(_DWORD *)(v21 + 72) = v14;
  if ( v10[8] )
    ReleaseMutex((HANDLE)v10[8]);
  return v21;
}
