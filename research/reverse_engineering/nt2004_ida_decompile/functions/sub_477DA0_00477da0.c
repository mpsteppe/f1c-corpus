int __thiscall sub_477DA0(_DWORD *this)
{
  int v1; // edi
  const char *v3; // esi
  int v4; // edi
  _DWORD *v5; // esi
  int i; // ebx
  int v7; // edi
  int v9; // [esp+10h] [ebp-58h] BYREF
  int v10; // [esp+14h] [ebp-54h] BYREF
  char String[80]; // [esp+18h] [ebp-50h] BYREF

  v1 = 0;
  if ( dword_769E78 > 0 )
  {
    while ( 1 )
    {
      v3 = (const char *)sub_49FC20(v1);
      sub_477BC0(v1, String, 0);
      if ( !v3 )
        v3 = &byte_629120;
      if ( strcmp(String, v3) )
        break;
      if ( ++v1 >= dword_769E78 )
        goto LABEL_8;
    }
    ((void (__thiscall *)(_DWORD *))loc_477CF0)(this);
  }
LABEL_8:
  v4 = this[94];
  v5 = (_DWORD *)this[36];
  sub_4AE870(&v9, &v10);
  for ( i = 0; v4 > 0; ++i )
  {
    if ( !v5 )
      break;
    v5 = (_DWORD *)v5[35];
    --v4;
  }
  sub_49FF10(this);
  if ( (int)this[97] < 1 || (int)this[102] < 1 )
    return -1;
  v7 = this[100];
  if ( v5 )
  {
    while ( v7 > 0 )
    {
      if ( (*(int (__thiscall **)(_DWORD *))(*this + 4))(this) > 0 )
        (*(void (__thiscall **)(_DWORD *))(*this + 4))(this);
      if ( v9 > v5[3] && v9 < v5[4] && v10 > v5[1] && v10 < v5[2] )
      {
        this[101] = i;
        return 0;
      }
      v5 = (_DWORD *)v5[35];
      ++i;
      if ( !v5 )
        return 0;
    }
  }
  return 0;
}
