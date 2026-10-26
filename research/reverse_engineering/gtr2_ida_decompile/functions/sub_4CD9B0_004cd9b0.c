int __thiscall sub_4CD9B0(_BYTE *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-Ch] BYREF
  int v8; // [esp+4h] [ebp-8h] BYREF

  v2 = *((_DWORD *)this + 61);
  v3 = *((_DWORD *)this + 33);
  this[272] = 1;
  if ( v2 )
    v4 = sub_4E29F0(v3);
  else
    v4 = 0;
  if ( v4 && *(_DWORD *)(v4 + 36) && *((_DWORD *)this + 34) != *(_DWORD *)(v4 + 16) )
    return 0;
  v5 = *((_DWORD *)this + 33);
  this[272] = 0;
  switch ( v5 )
  {
    case 1:
      goto LABEL_12;
    case 3:
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 2);
      break;
    case 4:
      if ( !this[100] )
      {
        if ( (unsigned __int8)sub_4CD720() )
          (*(void (__cdecl **)(int))(*(_DWORD *)this + 44))(2);
        else
LABEL_12:
          (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 44))(this, 0);
      }
      break;
    default:
      break;
  }
  sub_4DE540(&v8, &v7);
  if ( !this[100]
    && (*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 20))(this, v8, v7)
    && !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 148))(this) )
  {
    sub_4CD5A0(this, (unsigned __int8)this[273]);
    return 0;
  }
  return -1;
}
