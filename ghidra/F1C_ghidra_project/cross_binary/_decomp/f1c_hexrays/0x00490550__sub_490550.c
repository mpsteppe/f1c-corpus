// f1c  0x00490550  size=229
int __thiscall sub_490550(_DWORD *this)
{
  int v2; // eax
  int i; // esi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int v9; // [esp+10h] [ebp-4h] BYREF

  v2 = sub_486720(this);
  if ( v2 >= 3 && v2 <= 5 )
  {
    v9 = 0;
    v8 = 0;
    sub_498880(&v9, &v8);
    if ( !(*(int (__thiscall **)(_DWORD *, int, int))(*this + 48))(this, v9, v8) )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
      for ( i = 0; i < this[59]; ++i )
      {
        v4 = i;
        if ( i >= 0 && i < this[59] )
        {
          v5 = this[56];
          if ( i <= 0 )
          {
LABEL_10:
            if ( v5 )
            {
              v6 = *(_DWORD **)v5;
              if ( v6 )
              {
                if ( sub_48EA60(v6, v9, v8) )
                {
                  (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
                  break;
                }
              }
            }
          }
          else
          {
            while ( v5 )
            {
              v5 = *(_DWORD *)(v5 + 4);
              if ( --v4 <= 0 )
                goto LABEL_10;
            }
          }
        }
      }
    }
  }
  sub_490660(this);
  return 0;
}
