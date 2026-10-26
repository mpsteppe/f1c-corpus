// Address: 0x00490550
// Size: 229 bytes
// Name: sub_490550
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_490550(_DWORD *this)
{
  int v2; // eax
  int i; // esi
  int v4; // ecx
  _DWORD *v5; // eax
  int v7; // [esp+Ch] [ebp-8h] BYREF
  int v8; // [esp+10h] [ebp-4h] BYREF

  v2 = sub_486720(this);
  if ( v2 >= 3 && v2 <= 5 )
  {
    v8 = 0;
    v7 = 0;
    sub_498880(&v8, &v7);
    if ( !(*(int (__thiscall **)(_DWORD *, int, int))(*this + 48))(this, v8, v7) )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
      for ( i = 0; i < this[59]; ++i )
      {
        v4 = i;
        if ( i >= 0 && i < this[59] )
        {
          v5 = (_DWORD *)this[56];
          if ( i <= 0 )
          {
LABEL_10:
            if ( v5 && *v5 && (unsigned __int8)sub_48EA60(v8, v7) )
            {
              (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
              break;
            }
          }
          else
          {
            while ( v5 )
            {
              v5 = (_DWORD *)v5[1];
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
