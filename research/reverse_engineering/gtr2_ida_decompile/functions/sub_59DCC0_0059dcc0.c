int __thiscall sub_59DCC0(_DWORD *this, _DWORD *a2)
{
  int v2; // edi
  void *v4; // eax
  DWORD v5; // eax
  char **v6; // eax
  char *v7; // eax
  void *v8; // esi
  char v10; // [esp+8h] [ebp-10h] BYREF

  v2 = 0;
  htonl(0);
  htons(0);
  v4 = (void *)this[715];
  if ( v4 )
  {
    v5 = WaitForSingleObject(v4, this[716]);
    if ( !v5 || v5 == 128 )
    {
      v6 = (char **)this[711];
      if ( v6 )
      {
        while ( !*v6 || *v6 != &v10 )
        {
          v6 = (char **)v6[1];
          if ( !v6 )
            goto LABEL_11;
        }
        v7 = *v6;
        if ( v7 )
        {
          *a2 = *((_DWORD *)v7 + 1);
          v2 = 1;
        }
      }
LABEL_11:
      v8 = (void *)this[715];
      if ( v8 )
        ReleaseMutex(v8);
    }
  }
  return v2;
}
