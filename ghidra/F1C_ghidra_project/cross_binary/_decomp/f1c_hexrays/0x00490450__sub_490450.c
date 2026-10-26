// f1c  0x00490450  size=229
int __thiscall sub_490450(int *this)
{
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  v7 = 0;
  sub_498880(&v8, &v7);
  switch ( sub_486720(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(int *, _DWORD))(*this + 64))(this, 0);
      sub_490660(this);
      return 0;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(int *, _DWORD))(*this + 64))(this, 0);
      v3 = 0;
      if ( this[59] <= 0 )
        goto LABEL_15;
      break;
    default:
LABEL_15:
      sub_490660(this);
      return 0;
  }
  while ( 1 )
  {
    v4 = v3;
    if ( v3 >= 0 && v3 < this[59] )
    {
      v5 = this[56];
      if ( v3 <= 0 )
      {
LABEL_9:
        if ( v5 )
        {
          v6 = *(_DWORD **)v5;
          if ( v6 )
          {
            if ( sub_48EA60(v6, v8, v7) )
            {
              (*(void (__thiscall **)(int *, int))(*this + 64))(this, 4);
              goto LABEL_15;
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
            goto LABEL_9;
        }
      }
    }
    if ( ++v3 >= this[59] )
      goto LABEL_15;
  }
}
