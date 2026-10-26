int __thiscall sub_488BA0(_DWORD *this)
{
  char v1; // bl
  char *v3; // edi
  int v4; // eax
  int result; // eax
  int i; // edi
  char *v7; // eax
  int v8; // eax
  int v9; // ecx
  char v10; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v10 = 0;
  v3 = (char *)sub_49D1F0(0);
  switch ( sub_49D1E0(this) )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
      v1 = 0;
      goto LABEL_4;
    case 5:
      v1 = 1;
LABEL_4:
      v10 = v1;
      break;
    default:
      break;
  }
  if ( v3 )
  {
    v4 = sub_4AD520(v3);
    if ( v4 )
      (*(void (__thiscall **)(int, char))(*(_DWORD *)v4 + 40))(v4, v10);
  }
  result = this[20];
  for ( i = 1; i < result; ++i )
  {
    v7 = (char *)sub_49D1F0(i);
    if ( v7 )
    {
      v8 = sub_4AD520(v7);
      if ( v8 )
      {
        LOBYTE(v9) = v1 == 0;
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 40))(v8, v9);
      }
    }
    result = this[20];
  }
  return result;
}
