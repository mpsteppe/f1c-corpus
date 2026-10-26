int __thiscall sub_4D2B30(void *this, int a2, int a3, int a4, int a5)
{
  const char *v6; // esi
  const char *v7; // eax
  _DWORD *v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // edi
  float v14; // [esp+4h] [ebp-4h]

  if ( *((float *)this + 72) > 0.0 )
  {
    v14 = *((float *)this + 72);
    *((float *)this + 72) = v14 - sub_4DE460(*((_DWORD *)this + 12));
  }
  v6 = (const char *)*((_DWORD *)this + 40);
  if ( !v6 )
    v6 = WindowName;
  v7 = (const char *)*((_DWORD *)this + 68);
  if ( !v7 )
    v7 = WindowName;
  if ( !strcmp(v7, v6) )
  {
    if ( !*((_DWORD *)this + 74) )
    {
      if ( *((_DWORD *)this + 67) )
      {
        if ( *((float *)this + 72) <= 0.0 && *((int *)this + 24) > 0 )
        {
          v9 = (_DWORD *)*((_DWORD *)this + 21);
          if ( v9 )
          {
            v10 = *v9;
            if ( *v9 )
            {
              v11 = sub_4E3120(*v9);
              if ( v11 )
              {
                v12 = sub_4E3DF0(v11);
                if ( v12 )
                {
                  v13 = sub_5F4990(v12, 0, 0, 64);
                  sub_4E40C0(v10);
                  if ( v13 == 1 )
                    *((_DWORD *)this + 72) = *((_DWORD *)this + 73);
                }
              }
            }
          }
        }
      }
    }
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 152))(this);
    return 0;
  }
}
