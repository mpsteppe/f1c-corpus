char __thiscall sub_57E940(_DWORD *this, _DWORD *a2)
{
  char v2; // bl
  void *v4; // eax
  _DWORD *v5; // ebp
  DWORD v6; // eax
  _DWORD *v7; // edi
  _DWORD **v8; // eax
  bool v9; // zf
  _DWORD *v10; // esi
  int v11; // eax
  _DWORD **v12; // eax
  _DWORD v14[4]; // [esp+14h] [ebp-10h] BYREF

  v2 = 0;
  LOWORD(v14[0]) = 2;
  v14[1] = htonl(0);
  HIWORD(v14[0]) = htons(0);
  sub_57B9F0(this + 673, v14);
  v4 = (void *)this[694];
  v5 = this + 690;
  if ( v4 && ((v6 = WaitForSingleObject(v4, this[695])) == 0 || v6 == 128) )
    v7 = this + 690;
  else
    v7 = 0;
  v8 = (_DWORD **)*v7;
  v9 = *v7 == 0;
  v7[2] = *v7;
  if ( !v9 )
  {
    v10 = *v8;
    if ( *v8 )
    {
      while ( !sub_57B840(v10, v14) )
      {
        v11 = v7[2];
        if ( v11 )
        {
          v12 = *(_DWORD ***)(v11 + 4);
          v7[2] = v12;
          if ( v12 )
          {
            v10 = *v12;
            if ( *v12 )
              continue;
          }
        }
        v2 = 0;
        goto LABEL_13;
      }
      v2 = 1;
      *a2 = sub_5871F0(v10);
    }
  }
LABEL_13:
  if ( v5[4] )
    ReleaseMutex((HANDLE)v5[4]);
  return v2;
}
