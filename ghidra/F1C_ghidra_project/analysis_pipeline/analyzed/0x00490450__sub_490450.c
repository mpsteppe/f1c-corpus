// Address: 0x00490450
// Size: 229 bytes
// Name: sub_490450
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_490450(_DWORD *this)
{
  int v3; // esi
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v7 = 0;
  v6 = 0;
  sub_498880(&v7, &v6);
  switch ( sub_486720(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
      sub_490660(this);
      return 0;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
      v3 = 0;
      if ( (int)this[59] <= 0 )
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
      v5 = (_DWORD *)this[56];
      if ( v3 <= 0 )
      {
LABEL_9:
        if ( v5 && *v5 && (unsigned __int8)sub_48EA60(v7, v6) )
        {
          (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
          goto LABEL_15;
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = (_DWORD *)v5[1];
          if ( --v4 <= 0 )
            goto LABEL_9;
        }
      }
    }
    if ( ++v3 >= this[59] )
      goto LABEL_15;
  }
}
