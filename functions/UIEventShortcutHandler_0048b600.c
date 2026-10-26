int __thiscall UIEventShortcutHandler(void *this, int a2, int a3)
{
  int v5; // eax
  int v6; // edi
  UINT v7; // ecx
  unsigned __int8 v8; // bl
  _BYTE *v9; // ecx
  int v10; // eax
  char *v11; // ecx
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // [esp+4h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-Ch] BYREF
  int v18; // [esp+10h] [ebp-8h] BYREF
  int v19; // [esp+14h] [ebp-4h] BYREF

  if ( !*((_BYTE *)this + 748) )
    return 0;
  v5 = 0;
  v6 = 0;
  v16 = 0;
  if ( a3 > 0 )
  {
    while ( 1 )
    {
      v7 = *(unsigned __int16 *)(a2 + 2 * v5);
      if ( v7 == 1 )
        break;
      if ( v7 == 14 )
      {
        v14 = *((_DWORD *)this + 189);
        if ( v14 != *((_DWORD *)this + 188) )
          *((_DWORD *)this + 189) = v14 - 1;
        **((_BYTE **)this + 189) = 0;
        v6 = 1;
        goto LABEL_26;
      }
      if ( v7 == 28 )
        break;
      v8 = TranslateVirtualKey(v7);
      if ( sub_48B560((int)this, v8) )
      {
        if ( *((_DWORD *)this + 189) - *((_DWORD *)this + 188) < *((_DWORD *)this + 190) - 1 )
        {
          **((_BYTE **)this + 189) = v8;
          v9 = (_BYTE *)(*((_DWORD *)this + 189) + 1);
          *((_DWORD *)this + 189) = v9;
          *v9 = 0;
          if ( *((_DWORD *)this + 191) )
          {
            v10 = *((_DWORD *)this + 50);
            if ( v10 )
            {
              v11 = (char *)*((_DWORD *)this + 16);
              if ( v11 )
              {
                v12 = *(const char **)(v10 + 64);
                if ( !v12 )
                  v12 = byte_5EA438;
                sub_498560(v11, v12);
                TextRenderToSurface(*((const char **)this + 16), *((const char **)this + 191), &v19, &v17, 1);
                TextRenderToSurface(*((const char **)this + 16), *((const char **)this + 188), &v18, &v17, 1);
                if ( v18 > v19 )
                {
                  v13 = *((_DWORD *)this + 189);
                  if ( v13 != *((_DWORD *)this + 188) )
                    *((_DWORD *)this + 189) = v13 - 1;
                  **((_BYTE **)this + 189) = 0;
                }
              }
            }
          }
        }
        v6 = 1;
LABEL_26:
        v15 = (const char *)*((_DWORD *)this + 40);
        if ( !v15 )
          v15 = byte_5EA438;
        StringReverseCopyLookup((_DWORD *)(*((_DWORD *)this + 16) + 5772), v15, *((_DWORD *)this + 188));
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 1);
        goto LABEL_29;
      }
      if ( v6 )
        goto LABEL_26;
LABEL_29:
      v5 = ++v16;
      if ( v16 >= a3 )
        return v6;
    }
    if ( !*((_BYTE *)this + 229) )
      SetterVTableIDCheck(0);
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 176))(this);
    v6 = 1;
    goto LABEL_26;
  }
  return v6;
}
