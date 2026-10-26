int __thiscall sub_4A62E0(int *this)
{
  int v3; // edi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  v7 = 0;
  sub_4AE870(&v8, &v7);
  switch ( sub_49D1E0(this) )
  {
    case 1:
    case 2:
      (*(void (__thiscall **)(int *, _DWORD))(*this + 44))(this, 0);
      sub_4A64A0(this);
      return 0;
    case 4:
      (*(void (__thiscall **)(int *, int))(*this + 44))(this, 3);
      goto LABEL_16;
    case 5:
      (*(void (__thiscall **)(int *, int))(*this + 44))(this, 3);
      v3 = 0;
      if ( this[70] <= 0 )
        goto LABEL_16;
      break;
    default:
      goto LABEL_16;
  }
  while ( 1 )
  {
    v4 = v3;
    if ( v3 >= 0 && v3 < this[70] )
    {
      v5 = this[67];
      if ( v3 > 0 )
      {
        while ( v5 )
        {
          v5 = *(_DWORD *)(v5 + 4);
          if ( --v4 <= 0 )
            goto LABEL_10;
        }
        goto LABEL_13;
      }
LABEL_10:
      if ( v5 )
      {
        v6 = *(_DWORD **)v5;
        if ( v6 )
        {
          if ( sub_4A4680(v6, v8, v7) )
            break;
        }
      }
    }
LABEL_13:
    if ( ++v3 >= this[70] )
      goto LABEL_16;
  }
  (*(void (__thiscall **)(int *, int))(*this + 44))(this, 4);
LABEL_16:
  sub_4A64A0(this);
  return 0;
}
