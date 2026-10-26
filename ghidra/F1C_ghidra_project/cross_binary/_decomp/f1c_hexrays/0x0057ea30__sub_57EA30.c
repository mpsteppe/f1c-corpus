// f1c  0x0057ea30  size=158
int __thiscall sub_57EA30(_DWORD *this, _DWORD *a2)
{
  int v2; // edi
  void *v4; // eax
  DWORD v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  void *v8; // esi
  int v10; // [esp+8h] [ebp-10h] BYREF
  u_long v11; // [esp+Ch] [ebp-Ch]

  v2 = 0;
  v11 = htonl(0);
  htons(0);
  sub_57B9F0(this + 673, &v10);
  v4 = (void *)this[708];
  if ( v4 )
  {
    v5 = WaitForSingleObject(v4, this[709]);
    if ( !v5 || v5 == 128 )
    {
      v6 = (_DWORD *)this[704];
      if ( v6 )
      {
        while ( !*v6 || *(_DWORD *)*v6 != v11 )
        {
          v6 = (_DWORD *)v6[1];
          if ( !v6 )
            goto LABEL_11;
        }
        v7 = (_DWORD *)*v6;
        if ( v7 )
        {
          v2 = 1;
          *a2 = v7[1];
        }
      }
LABEL_11:
      v8 = (void *)this[708];
      if ( v8 )
        ReleaseMutex(v8);
    }
  }
  return v2;
}
