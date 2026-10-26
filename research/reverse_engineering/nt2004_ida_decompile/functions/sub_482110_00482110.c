int __thiscall sub_482110(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  char Destination[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v8; // [esp+105h] [ebp-3h]
  char v9; // [esp+107h] [ebp-1h]

  sub_49D1E0(this);
  v2 = this[216];
  if ( v2 < 0 || v2 >= this[220] )
    goto LABEL_7;
  v3 = (int *)this[217];
  if ( v2 > 0 )
  {
    while ( v3 )
    {
      v3 = (int *)v3[1];
      if ( --v2 <= 0 )
        goto LABEL_6;
    }
    goto LABEL_7;
  }
LABEL_6:
  if ( !v3 )
  {
LABEL_7:
    v4 = 0;
    goto LABEL_9;
  }
  v4 = *v3;
LABEL_9:
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0xFCu);
  v8 = 0;
  v9 = 0;
  sub_4CE010(Destination, 256);
  if ( v4 )
  {
    v5 = *(const char **)(v4 + 64);
    if ( !v5 )
      v5 = &byte_629120;
    if ( strcmp(v5, Destination) )
    {
      sub_482230(this);
      return 0;
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  return 0;
}
